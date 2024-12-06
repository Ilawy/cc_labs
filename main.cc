#include "./lib/flex_stack.hh"
#include "./lab_3/str.hh"
#include "iostream"

using namespace std;

int main(){
    FlexStack<int> list(8);
    for(int i = 0; i < 10; i++){
        list.push(i);
    }
    cout << "SIZE BEFORE = " << list.getSize() << endl;
    for(int i = 0; i < 6; i++){
        list.pop();
    }
  
    cout << "SIZE AFTER = " << list.getSize() << endl;

}