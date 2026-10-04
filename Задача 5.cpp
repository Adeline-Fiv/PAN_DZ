#include <iostream>
#include <cmath>
using namespace std;

const double g = 9.81;
const int N = 3;
const double ro = 1.225;

struct Plane{
    double m;
    double S;
    double T;
    double V;
    double C_L;
    double C_D;
};

struct Result{
    double L;
    double D;
    double a;
    double t;
};

double power(const Plane& p){
    return 0.5*ro*(p.V*p.V)*p.S*p.C_L;
}

double resistance(const Plane& p){
    return 0.5*ro*(p.V*p.V)*p.S*p.C_D;
}

double acceleration(const Plane& p) {
    double L = power(p);
    return (L - p.m*g)/p.m;
}
double time(const Plane& p, double h){
    double a = acceleration(p);
    return sqrt(2 * h / a);
}

int main() {
    double h;
    cout<<"Введите высоту полёта: "<<endl;
    cin>>h;

    Plane p[N];
    for (int i = 0; i < N; i++) {
        cout << "\nСамолёт №" << i + 1 << "\n";
        do {
            cout << "Масса: ";
            cin >> p[i].m;
            if (p[i].m <= 0) {
            cout << "Ошибка: высота должна быть больше 0!"<<endl;
            }
        } while (h <= 0);
        cout << "Площадь: ";  cin >> p[i].S;
        cout << "Тяга: ";     cin >> p[i].T;
        cout << "Скорость: "; cin >> p[i].V;
        cout << "C_L: ";       cin >> p[i].C_L;
        cout << "C_D: ";       cin >> p[i].C_D;
    }
    double mntime = 10000;
    int num = 0;

    Result r[N];
    for (int i = 0; i < N; i++) {
        double L = power(p[i]);
        double D = resistance(p[i]);
        double a  = acceleration(p[i]);
        double t = time(p[i],h);
        if (t<mntime){
            mntime = t;
            num = i+1;
        }
        if(a<=0){
            cout << "\nCамолёт №" << i+1 
            << ": \nL=" << L << " \nD=" << D
            << " \na=" << a << " ускорение отрицательно, самолёт не наберёт нужной высоты\n";
        }
        else{
            cout << "самолёт №" << i+1 
        << ": \nL=" << L << " \nD=" << D
        << " \na=" << a << " \nt=" << t << " с\n";
        }
    }
    cout<<"Быстрее всех наберёт высоту "<< h << "самолёт № "<< num<<endl;
    return 0;
}