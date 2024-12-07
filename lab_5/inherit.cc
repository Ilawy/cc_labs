#include "iostream"

using namespace std;

class Base
{
protected:
    int a;

public:
    Base(int a) : a(a) {
        cout << "[BASE]: constructed" << endl;
    }
    ~Base() { cout << "[BASE]: destructed" << endl; }
    int get_a() { return a; }
    void greet(){
        cout << "[BASE]: Hello" << endl;
    }
};

class Derived : public Base
{
protected:
    int b;

public:
    Derived(int a, int b) : Base(a), b(b) {
        cout << "[DERIVED]: constructed" << endl;
    }
    ~Derived() { cout << "[DERIVED]: destructed" << endl; }
    int get_b() { return b; }
    void greet(){
        cout << "[DERIVED]: Hello" << endl;
    }
};

class Derived2 : public Derived
{
private:
    int c;

public:
    Derived2(int a, int b, int c) : Derived(a, b), c(c) {
        cout << "[DERIVED2]: constructed" << endl;
    }
    ~Derived2() { cout << "[DERIVED2]: destructed" << endl; }
    int get_c() { return c; }
    int getThemAll() { return a + b + c; }
    void greet(){
        cout << "[DERIVED2]: Hello" << endl;
    }
};


int main(){
    Derived2 d2 = Derived2(1, 2, 3);
    Derived* d1 = &d2;
    Base* b = &d2;
    b->greet();
    d2.greet();
    d1->greet();
    cout << d2.getThemAll() << endl;
}