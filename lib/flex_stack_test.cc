#include "test.hh"
#include "flex_stack.hh"
#include <iostream>

using namespace std;

int main(){
    
    test_block("normal", {
        FlexStack<int> f;
        f.push(1);
        f.push(2);
        f.push(3);
    });

    test_block("one element grower with 10k push", {
        FlexStack<int> f(1);
        for (int i = 0; i < 10000; i++)
        {
            cout << "PUSH " << i << endl;
            f.push(i);
        }
    });

    return 0;
}