// farenhite temperature to celsius in function 
#include<iostream>
using namespace std;
float FahrenheitToCelsius(float);
int main()
{
    system("cls");
    float fahrenheit, celsius;
    cout<<"Enter the Temperature in Fahrenheit: ";
    cin>>fahrenheit;
    celsius = FahrenheitToCelsius(fahrenheit);
    cout<<endl<<fahrenheit<<"\370F = "<<celsius<<"\370C"; // \370F prints 1 degree and \ 370C prints 1 celsius 
    cout<<endl;
    return 0;
}
float FahrenheitToCelsius(float far)
{
    float cel;
    cel = (far-32)/1.8;
    return cel;  
}