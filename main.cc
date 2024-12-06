#include "./lib/flex_stack.hh"
#include "./lab_3/str.hh"
#include "iostream"

using namespace std;

int main(){
    FlexStack<String> list(1024);
    for(int i = 0; i < 1900; i++){
        String result = "Mohammed ";
        // result += i;
        list.push(result + i);
    }
    cout << "SIZE BEFORE = " << list.getSize() << endl;
    for(int i = 0; i < 1900; i++){
        list.pop();
    }
  
    cout << "SIZE AFTER = " << list.getSize() << endl;

}