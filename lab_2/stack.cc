#include <iostream>
#include <cstring>
#include "../lib/menu2.cc"
using namespace std;


class Employee{
    char name[128];
    int salary;


    public:
        Employee(){}
        Employee(const char *name, int salary){
            strcpy(this->name, name);
            this->salary = salary;
        }
        void print(){
            cout << "{\n";
            cout << "\tname: " << this->name << "," << endl;
            cout << "\tsalary: " << this->salary << "," << endl;
            cout << "}";
        }
};




enum StackErrorCode
{
    StackIsFull = -1,
    StackIsEmpty = 1,
};

class Stack
{
private:
    int size;
    int top;
    Employee *items;

public:
    static int all;

    Stack(int size)
    {   
        all++;
        this->size = size;
        this->items = new Employee[size];
        this->top = 0;
    }

    ~Stack(){
        all--;
    }

    static int getCount(){
        return all;
    }

    void push(Employee value)
    {
        if (top == size)
        {
            throw StackErrorCode::StackIsFull;
        }
        this->items[top++] = value;
    }

    Employee pop()
    {
        if (top == 0)
        {
            throw StackErrorCode::StackIsEmpty;
        }
        return this->items[top--];
    }

    void display()
    {
        if(top == 0){
            cout << "[ <empty> ]";
            return;
        }
        cout << "[ \n";
        for (int i = 0; i < top; i++)
        {
            this->items[i].print();
        }
        cout << endl;
        cout << "\n]";
    }
};
int Stack::all = 0;


void x1(AppState *state){}

int main()
{
    Stack mystack(3);
    try
    {
        Employee e1("Ahmed", 2500);
        Employee e2("Ramy", 2500);
        Employee e3("Saied", 2500);
        mystack.push(e1);
        mystack.push(e2);
        mystack.push(e3);
        mystack.pop();
        mystack.pop();
        mystack.pop();
        // mystack.push(10);
        // mystack.push(20);
        // mystack.push(30);
        // mystack.push(40);
    }
    catch (StackErrorCode error)
    {
        cout << "Error: Stack is";
        switch (error)
        {
        case StackIsEmpty:
            cout << "empty";
            break;
        case StackIsFull:
            cout << "full";
            break;
        }
        cout << endl;
    }
    mystack.display();

    // Menu main_menu(5);
    // main_menu.addItem(MenuItem("Home", &x1));
    // main_menu.addItem(MenuItem("Legal", &x1));
    // main_menu.addItem(MenuItem("LOL", &x1));

    // main_menu.render();

}