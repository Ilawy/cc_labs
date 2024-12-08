#include "./lib/flex_stack.hh"
#include "./lab_3/str.hh"
#include "iostream"

using namespace std;

int main(){
    FlexStack<int> list(1000);
    int X = 0;
    cout << "SIZE BEFORE = " << list.getSize() << endl;
    for(int i = 0; i < 20000; i++){
        cout << "PU " << i << endl;
        list.push(X);
        X++;
    }
    for(int i = 0; i < 20000; i++){
        cout << "X " << list.pop() << endl;
    }
    int* items = list.getItems();
    for(int i = 0; i < list.getSize(); i++){
        cout << "LOL " << items[i] << endl;
    }

    cout << "SIZE AFTER = " << list.getSize() << endl;

}