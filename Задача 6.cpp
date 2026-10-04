#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

const double g = 9.81;

double lift(double ro, double v, double S, double C_L) {
    return 0.5 * ro * v * v * S * C_L;
}

int main() {
    double S, C_L;                  
    cout << "Введите площадь крыла и C_L: ";
    cin >> S >> C_L;

    const int mx = 100;
    double v[mx];
    double ro[mx];
    int n = 0;

    double x, y;

    cout << "Вводите пары: скорость / плотность. 0 — конец.";
    cout << "\nСкорость:  "; cin >> x;
    cout << "Плотность: "; cin >> y;

    while (x != 0 && y != 0 && n < mx) { 
        v[n]  = x;
        ro[n] = y;
        n++;
        cout << "Скорость:  "; cin >> x;
        cout << "Плотность: "; cin >> y;
    }

    
    cout << "\n" << left;
    cout << setw(6)  << "Шаг "
        << setw(2)  << "|"
         << setw(12) << "Скорость "
         << setw(2)  << "|"
         << setw(12) << "Плотность "
         << setw(2)  << "|"
         << setw(16) << "Подъёмная сила "
         << "\n";
    cout << string(46, '-') << "\n";

    for (int i = 0; i < n; i++) {
        double L = lift(ro[i], v[i], S, C_L);
        cout << setw(6)  << i + 1
             << setw(12) << v[i]
             << setw(12) << ro[i]
             << setw(16) << L
             << "\n";
    }
    return 0;
}