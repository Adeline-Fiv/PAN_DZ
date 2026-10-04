#include <iostream>
using namespace std;

int main() 
{
    int S;
    cout<<"Введите площадь крыла (м^2):";
    cin>>S;
    int V;
    cout<<"Введите скорость полёта самолёта (м/с):";
    cin>>V;
    int p;
    cout<<"Введите плотность воздуха (кг/м^3):";
    cin>>p;
    int C_l;
    cout<<"Коэффициент подъёмной силы:";
    cin>>C_l;
    cout<<"Подъёмная сила L = "<<0.5*p*(V*V)*S*C_l<<endl;
    return 0;
    

}