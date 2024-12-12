enum StackError
{
    StackIsFull,
    StackIsEmpty,
    AccessOutOfBounds
};

template <typename T>
class Stack
{
private:
    int size;
    int top = 0;
    T *items;

public:
    Stack(int size)
    {
        this->size = size;
        this->items = new T[size];
    }
    Stack(Stack &original)
    {
        this->size = original.size;
        this->top = original.top;
        this->items = new T[original.size];
        for (int i = 0; i < original.size; i++)
        {
            this->items[i] = original.items[i];
        }
    }
    ~Stack()
    {
        delete[] this->items;
    }

    // methods
    void push(T &item)
    {
        if (this->top >= this->size)
            throw StackError::StackIsFull;
        this->items[top++] = item;
    }
    T &pop()
    {
        if (this->top <= 0)
            throw StackError::StackIsEmpty;
        return this->items[--top];
    }

    T &operator[](int idx)
    {
        if (idx >= this->top || idx < 0)
        {
            throw StackError::AccessOutOfBounds;
        }
        if (top == 0)
            throw StackError::StackIsEmpty;
        return this->items[idx];
    }
};