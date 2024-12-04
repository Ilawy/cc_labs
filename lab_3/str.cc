#include <iostream>
#include "str.h"
using namespace std;

int main()
{
    String sample_1 = "Mohammed";
    String sample_2 = "Amr";
    char sample_3[] = "Mohammed Ali";
    // Comparison
    cout << "COMPARISON" << endl;
    /* GT */ cout << "GT" << endl;
    cout << "(String > String) = " << ((sample_1 > sample_2)) << endl;
    cout << "(String > char[]) = " << ((sample_1 > sample_3)) << endl;
    cout << "(char[] > String) = " << ((sample_3 > sample_2)) << endl;
    /* GTE */ cout << "GTE" << endl;
    cout << "(String >= String) = " << ((sample_1 >= sample_2)) << endl;
    cout << "(String >= String) = " << ((sample_1 >= sample_3)) << endl;
    /* LT */ cout << "LT" << endl;
    cout << "(String < String) = " << ((sample_1 < sample_2)) << endl;
    cout << "(String < char[]) = " << ((sample_1 < sample_3)) << endl;
    cout << "(char[] < String) = " << ((sample_3 < sample_2)) << endl;
    /* LTE */ cout << "LTE" << endl;
    cout << "(String <= String) = " << ((sample_1 <= sample_2)) << endl;
    cout << "(String <= String) = " << ((sample_1 <= sample_3)) << endl;

    return 0;
}