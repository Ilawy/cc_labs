#include <iostream>
using namespace std;
void swap_ref(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swap_addr(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}



int main(){
    //swap by value
    int a = 5, b = 10, temp;
    cout << "FIRST STATE: a = " << a << " b = " << b << endl;
    temp = a;
    a = b;
    b = temp;
    cout << "AFTER VALUE: a = " << a << " b = " << b << endl;
    swap_addr(&a, &b);
    cout << "AFTER ADDRESS: a = " << a << " b = " << b << endl;
    swap_ref(a, b);
    cout << "AFTER REFERENCE: a = " << a << " b = " << b << endl;



}