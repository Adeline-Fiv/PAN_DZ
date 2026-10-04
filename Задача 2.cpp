#include <iostream>
using namespace std;

double calcul(double C, double p, double V, double S) {
    return 0.5 * C * p * V * V * S;
}

int main() {
    double C;        
    double p;       
    double V;  
    double S;      

    cout << "Введите коэффициент сопротивления: ";
    cin >> C;

    cout << "Введите плотность воздуха (кг/м^3): ";
    cin >> p;

    cout << "Введите скорость полета V (м/с): ";
    cin >> V;

    cout << "Введите площадь крыла S (м^2): ";
    cin >> S;

    // вызов функции 
    double drag = calcul(C, p, V, S);

    cout << "Аэродинамическое сопротивление F = "<< drag << " Н"<<endl;
    return 0;
}