#include <iostream>
#include <vector>
using namespace std;

class Temperature 
{                             
public:                                       
    virtual double Celsius(double temp) = 0;    
    virtual double Fahrenheit(double temp) = 0; 
};                                              

class Conversion : public Temperature
{
public:
    Conversion() {}

    double Celsius(double temp)
    {
        return (temp - 32) / 1.8;
    }
    double Fahrenheit(double temp)
    {
        return temp * 1.8 + 32;
    }

    double ConvertTo(char ch, double num)
    {
        if (ch == 'C' || ch == 'c')
        {
            return Celsius(num);
        }
        else if (ch == 'F' || ch == 'f')
        {
            return Fahrenheit(num);
        }
        else
        {
            return -0.0001;
        }
    }
};

int main() {

    Conversion c;
    cout << c.ConvertTo('c', 212.0) << endl;
    cout << c.ConvertTo('C', 78.0) << endl;
    cout << c.ConvertTo('h', 23.0) << endl;
    cout << c.ConvertTo('F', 0.0) << endl;
    cout << c.ConvertTo('f', 29.0) << endl;
    cout << c.ConvertTo('3', 112.0) << endl;
    return 0;
}