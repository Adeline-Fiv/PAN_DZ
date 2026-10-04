#include <iostream>
using namespace std;

double acceleration(double T, double D, double m) {
    return (T-D)/m;
}
double acceleration_Y(double L, double m, double g) {
    return (L - m*g)/m;
}

int main() {
    double m;        
    double L;       
    double D;  
    double T;      

    cout << "Введите массу ЛА: ";
    cin >> m;
    cout << "Введите подъёмную силу: ";
    cin >> L;
    cout << "Введите сопротивление: ";
    cin >> D;
    cout << "Введите тягу двигателя: ";
    cin >> T;

    if (m>0){
        double a = acceleration(T,D,m);
        double a_y = acceleration_Y(T,D,m);
        cout <<"Ускорение по направлению движения a = "<<a<<endl;
        cout <<"Ускорение по вертикали a_y = "<<a_y<<endl;
        if(a>0){
            cout << "ЛА ускоряется по направлению движения"<<endl;
        }else{
            cout << "ЛА замедляется по направлению движения"<<endl;
        }
        if(a_y>0){
            cout << "ЛА ускоряется по вертикали"<<endl;
        }else{
            cout << "ЛА замедляется по вертикали"<<endl;
        }
    }else{
        cout << "Была введена отрицательная масса"<<endl;
    }
    return 0;
}