#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double h, a_y;
    
    // Проверка верного ввода высоты
    do {
        cout << "Введите высоту h (м): ";
        cin >> h;
        if (h <= 0) {
            cout << "Ошибка: высота должна быть больше 0!"<<endl;
        }
    } while (h <= 0);
    
    // Проверка верного ввода ускорения
    do {
        cout << "Введите вертикальное ускорение a_y (м/с^2): ";
        cin>>a_y;
        if (a_y <= 0) {
            cout << "Ошибка: ускорение должно быть больше 0!"<<endl;
        }
        } while (a_y <= 0);
    
    
    double t = sqrt(2 * h / a_y);
    cout << "Высота h = " << h << " м\n";
    cout << "Ускорение a_y = " << a_y << " м/с^2\n";
    cout << "Время набора высоты t = " << t << " с\n";
    return 0;
}