#include "test.hh"
#include "stack.hh"

int main()
{
    test_block("overflow", {
        try{
            Stack<int> s(5);
            s.push(1);
            s.push(2);
            s.push(3);
            s.push(4);
            s.push(5);
            s.push(6);
        }catch(StackError e){
            assert(e == StackError::StackIsFull);
        }
    });

    test_block("underflow", {
        try{
            Stack<int> s(5);
            s.pop();
        }catch(StackError e){
            assert(e == StackError::StackIsEmpty);
        }
    });

    test_block("access out of bounds (underflow)", {
        try{
            Stack<int> s(5);
            s.push(1);
            s.push(2);
            s.push(3);
            s.push(4);
            s.push(5);
            s[-1];
        }catch(StackError e){
            assert(e == StackError::AccessOutOfBounds);
        }
    });

    test_block("access out of bounds (overflow)", {
        try{
            Stack<int> s(5);
            s.push(1);
            s.push(2);
            s.push(3);
            s.push(4);
            s.push(5);
            s[6];
        }catch(StackError e){
            assert(e == StackError::AccessOutOfBounds);
        }
    });

    return 0;
}