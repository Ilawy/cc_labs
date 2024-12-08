#include <iostream>
#include "str.hh"
using namespace std;

int main()
{
    // String sample_1 = "Mohammed";
    // String sample_2 = "Amr";
    // sample_1 += " ";
    // sample_1 += "Amr ";
    // cout << sample_1 << endl;
    // char sample_3[] = "Mohammed Ali";
    // // Comparison
    // cout << "COMPARISON" << endl;
    // /* GT */ cout << "GT" << endl;
    // cout << "(String > String) = " << ((sample_1 > sample_2)) << endl;
    // cout << "(String > char[]) = " << ((sample_1 > sample_3)) << endl;
    // cout << "(char[] > String) = " << ((sample_3 > sample_2)) << endl;
    // /* GTE */ cout << "GTE" << endl;
    // cout << "(String >= String) = " << ((sample_1 >= sample_2)) << endl;
    // cout << "(String >= String) = " << ((sample_1 >= sample_3)) << endl;
    // /* LT */ cout << "LT" << endl;
    // cout << "(String < String) = " << ((sample_1 < sample_2)) << endl;
    // cout << "(String < char[]) = " << ((sample_1 < sample_3)) << endl;
    // cout << "(char[] < String) = " << ((sample_3 < sample_2)) << endl;
    // /* LTE */ cout << "LTE" << endl;
    // cout << "(String <= String) = " << ((sample_1 <= sample_2)) << endl;
    // cout << "(String <= String) = " << ((sample_1 <= sample_3)) << endl;

    //reassigning
    String greeting = "Hello, ";
    String mage = "My age is: ";
    char* name = new char[32];
    cout << "Enter your name: ";
    scanf("%[^\n]*c", name);
    int age = 24;
    cout << greeting + name + " " + mage + age << endl;
    String countingString = "Hello ";
    for (int i = 0; i < 100; i++){
        cout << countingString + i << endl;
    }
    cout << countingString << -90 << endl;
    return 0;
}