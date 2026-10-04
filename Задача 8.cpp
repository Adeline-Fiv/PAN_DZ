#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const double g = 9.81;
const double ro = 1.225;

struct Aircraft {
    double m;      
    double S;
    double T;
    double C_L;
    double C_D;
    double V;
};

struct Result {
    int index;
    double a;
    double t;
};

// Подъёмная сила
double Force(const Aircraft& p) {
    return 0.5 * ro * p.V * p.V * p.S * p.C_L;
}
// Ускорение (по вертикали): (L - mg) / m
double acceleration(const Aircraft& p) {
    double L = Force(p);
    return (L - p.m * g) / p.m;
}

// Время подъёма на высоту h при равноускоренном движении: h = a*t^2/2
double time(const Aircraft& p, double h) {
    double a = acceleration(p);
    if (a <= 0) return -1; // не взлетит
    return sqrt(2 * h / a);
}

int main() {
    double h;
    cout << "Введите высоту полёта: ";
    cin >> h;
    if (h <= 0) {
        cout << "Ошибка: высота должна быть больше 0!" << endl;
        return 1;
    }

    int N;
    cout << "Введите количество рассматриваемых ЛА: ";
    cin >> N;

    vector<Aircraft> p(N);
    for (int i = 0; i < N; i++) {
        cout << "\nСамолёт №" << i + 1 << "\n";

        do {
            cout << "Масса: ";
            cin >> p[i].m;
            if (p[i].m <= 0)
                cout << "Ошибка: масса должна быть больше 0!" << endl;
        } while (p[i].m <= 0);

        cout << "Площадь: "; cin >> p[i].S;
        cout << "Тяга: ";    cin >> p[i].T;
        cout << "C_L: ";     cin >> p[i].C_L;
        cout << "C_D: ";     cin >> p[i].C_D;
        // Устанавливаем скорость из условия: тяга = сопротивление
        // T = 0.5 * ro * V^2 * S * C_D
        p[i].V = sqrt((2.0 * p[i].T) / (ro * p[i].S * p[i].C_D));
    }

    vector<Result> r(N);
    for (int i = 0; i < N; i++) {
        r[i].index = i + 1;
        r[i].a = acceleration(p[i]);
        r[i].t = time(p[i], h);
    }

    // Сортировка по возрастанию времени
    sort(r.begin(), r.end(), [](const Result& x, const Result& y) {
        return x.t < y.t;
    });

    cout << "\n Результаты (по возрастанию времени)\n";
    cout << "№\tВремя (с)\tУскорение (м/с^2)\n";
    for (int i = 0; i < N; i++) {
        if (r[i].t < 0) {
            cout << r[i].index << "\t---\t\t" << r[i].a
                << "  (не взлетит)\n";
        } else {
            cout << r[i].index << "\t" << r[i].t << "\t\t" << r[i].a << "\n";
        }
}
    return 0;
}