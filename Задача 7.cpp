#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double acceleration(double T, double D, double m) {
    return (T-D)/m;
}

int main() {
    double T;
    double D;  
    double m;  
    cout << "Введите силу тяги: ";
    cin>> T;
    cout << "Введите подъёмную силу: ";
    cin>> D;
    cout << "Введите массу ЛА: ";
    cin>> m;

    double a = acceleration(T,D,m);

    if (a>0.5){
        cout<<"ЛА переведён в режим 'набор высоты'"<<endl;
    }
    else if (a<=0.5 && a>=0){
        cout<<"ЛА переведён в режим 'горизонтальный полёт'"<<endl;
    }
    else if (a<0){
        cout<<"ЛА переведён в режим 'снижение'"<<endl;
    }
    return 0;
}