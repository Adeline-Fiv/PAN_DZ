#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
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
    double L;
    double D;
    double a;
    double t;
};

// Подъёмная сила
double force(const Aircraft& p) {
    return 0.5 * ro * p.V * p.V * p.S * p.C_L;
}

double resistance(const Aircraft& p){
    return 0.5*ro*(p.V*p.V)*p.S*p.C_D;
}

// Ускорение (по вертикали)
double acceleration_Y(const Aircraft& p) {
    double L = force(p);
    return (L - p.m * g) / p.m;
}

// Ускорение по направлению
double acceleration(const Aircraft& p) {
    double D = resistance(p);
    return (p.T-D)/p.m;
}

double accel(const Aircraft& p){
    double a_y = acceleration_Y(p);
    double a_x = acceleration(p);
    return sqrt(a_x*a_x + a_y*a_y);
}

// Время подъёма на высоту h при равноускоренном движении: h = a*t^2/2
double time(const Aircraft& p, double h) {
    double a = acceleration_Y(p);
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
        r[i].L = force(p[i]);
        r[i].D = resistance(p[i]);
        r[i].a = accel(p[i]);
        r[i].t = time(p[i],h);
    }

    // Сортировка по возрастанию времени
    sort(r.begin(), r.end(), [](const Result& x, const Result& y) {
        return x.a < y.a;
    });

     cout << "\nРезультаты (по возрастанию ускорения):\n\n";

    // Шапка таблицы
    cout << left
         << setw(5) << "№"
         << setw(18) << "Подъём. сила, Н "
         << setw(18) << "Сопротивл., Н "
         << setw(18) << "Ускорение, м/с^2 "
         << endl;

    cout << fixed << setprecision(2);
    for (int i = 0; i < N; i++) {
        if (r[i].t < 0) {
            cout << left<< setw(5) << r[i].index
                << setw(18) << r[i].L
                << setw(18) << r[i].D
                << setw(18) << "не взлетит"
                << endl;


        } else {
            cout << left<< setw(5) << r[i].index
                << setw(18) << r[i].L
                << setw(18) << r[i].D
                << setw(15) << r[i].a
                << endl;

        }
    }
    return 0;
}