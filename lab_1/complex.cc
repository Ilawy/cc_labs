#include "stdio.h"
#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    void setReal(int value)
    {
        real = value;
    }
    void setImag(int value)
    {
        imag = value;
    }
    void setAll(int rVal, int iVal)
    {
        real = rVal;
        imag = iVal;
    }

    int getReal()
    {
        return real;
    }
    int getImag()
    {
        return imag;
    }

    Complex add(Complex &rightOp)
    {
        Complex result;
        result.setAll(
            real + rightOp.real,
            imag + rightOp.imag);
        return result;
    }
    Complex sub(Complex &rightOp)
    {
        Complex result;
        result.setAll(
            real - rightOp.real,
            imag - rightOp.imag);
        return result;
    }

    void display()
    {
        if (real == 0 && imag == 0)
        {
            cout << "No Data" << endl;
            return;
        }
        else if (real)
        {
            cout << real;
        }
        if (imag != 0)
        {
            cout << ((imag > 0) ? "+" : "") << imag << "j";
           
        }
        cout << endl;
    }
};

int main()
{
    Complex num_1;
    num_1.setAll(13, 0);
    // real only
    num_1.display();

    Complex num_2;
    num_2.setAll(0, -49);
    //imag only
    num_2.display();


    Complex num_3;
    num_3.setAll(0, 0);
    // 0 0 case
    num_3.display();


    Complex result = num_1.add(num_2);
    //full case negative
    result.display();

    result.setImag(12);
    //full case positive
    result.display();
}