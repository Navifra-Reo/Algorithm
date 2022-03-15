#include<iostream>
using namespace std;

int main()
{
    float a;

    cout << "Please enter a Celsius value : ";
    cin >> a;

    cout << a << " degrees Celsius is " << 1.8*a+32.0 <<" degrees Fahrenheit.";

    return 0;
}