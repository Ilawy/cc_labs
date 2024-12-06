#include <iostream>
using namespace std;
namespace strutil
{
    int length(const char str[])
    {
        int i = 0;
        while (str[i] != '\0')
            i++;
        return i;
    }

    void strcpy(char dest[], const char source[])
    {
        int i = 0;
        while (source[i] != '\0')
        {
            dest[i] = source[i];
            i++;
        }
        dest[i] = '\0';
    }

    void strcat_size(char dest[], int dsize, const char source[], int ssize)
    {
        for (int i = 0; i < ssize; i++)
        {
            dest[i + dsize] = source[i];
            std::cout << source[i] << " " << dsize << std::endl;
        }
        dest[ssize + dsize] = '\0';
    }

    void cpyat(char target[], int at, char source[])
    {
        int i = 0;
        while (source[i] != '\0')
        {
            target[at + i] = source[i];
            i++;
        }
    }

}



// class String
// {
// private:
//     int size;
//     char *pointer;

// public:
//     // friends
//     friend std::ostream &operator<<(std::ostream &o, String t);

//     // ctor | dtor
//     String();
//     String(const char value[]);
//     String(String &copied);
//     ~String();

// // operators
// String &operator+(String &right);
// String &operator+(char right[]);

// String &operator=(const String &replacer);
// String &operator=(const char replacer[]);

// bool operator>(const String &right);
// bool operator>(const char right[]);

// bool operator<(const String &right);
// bool operator<(const char right[]);

// bool operator==(const String &right);
// bool operator==(const char right[]);
// };

/*
    FEATURES
        COMPARING
            GT(E)
                String  >   String  (done)
                String  >   char[]  (done)
                char[]  >   String  (done)
            LT(E)
                String  <   String  (done)
                String  <   char[]  (done)
                char[]  <   String  (planned)
            EQ
                String  ==  String  (planned)
                String  ==  char[]  (planned)
                char[]  ==  String  (planned)
        Assigning
            =
                String  =   String  (done)
                String  +=  String  (done)
        Methods
            .length (done)
            .slice  (planned)
            .codeAt	(planned)
*/

class String
{

private:
    friend std::ostream &operator<<(std::ostream &o, String t);

    static String from(char str[], int size)
    {
    }
    int size;
    char *pointer;

public:
    String()
    {
        this->size = 1;
        this->pointer = new char[1];
        this->pointer[0] = '\0';
    }

    String(char c[])
    {
        this->size = strutil::length(c);
        this->pointer = new char[size - 1];
        strutil::strcpy(this->pointer, c);
    }

    String(String &copied)
    {
        // cout << "COPE" << endl;
        this->size = copied.size;
        this->pointer = new char[this->size];
        strutil::strcpy(this->pointer, copied.pointer);
    }

    ~String()
    {
        delete [] this->pointer;
    }

    //
    String &operator+(String &right)
    {
        int result_size = this->size + right.size;
        char *result = new char[result_size];
        String *final = new String;
        final->size = result_size;
        final->pointer = result;

        strutil::cpyat(result, 0, this->pointer);
        strutil::cpyat(final->pointer, this->size, right.pointer);
        final->pointer[this->size + right.size] = '\0';
        //? why there's no delete here?
        //? you're creating new string here, nothing should be deallocated
        //
        return *final;
    }
    void operator+=(char right[])
    {
        char *old = this->pointer;
        int new_size = this->size + strutil::length(right);
        char *new_pointer = new char[new_size];
        strutil::cpyat(new_pointer, 0, this->pointer);
        strutil::cpyat(new_pointer, this->size, right);
        new_pointer[new_size] = '\0';
        this->pointer = new_pointer;
        this->size = new_size;
        delete [] old;
    }
    void operator+=(String &right)
    {
        char *old = this->pointer;
        int new_size = this->size + right.size;
        char *new_pointer = new char[new_size];
        strutil::cpyat(new_pointer, 0, this->pointer);
        strutil::cpyat(new_pointer, this->size, right.pointer);
        new_pointer[new_size] = '\0';
        this->pointer = new_pointer;
        this->size = new_size;
        delete [] old;
    }

    void operator=(const String &right)
    {
        delete [] this->pointer;
        this->size = right.size;
        this->pointer = new char[right.size];
        strutil::strcpy(this->pointer, right.pointer);
    }

    // GT
    bool operator>(const String &right)
    {
        return this->size > right.size;
    }
    bool operator>(char right[])
    {
        return this->size > strutil::length(right);
    }
    friend bool operator>(const char left[], const String &right)
    {
        return strutil::length(left) > right.size;
    }
    // GTE
    bool operator>=(const String &right)
    {
        return this->size >= right.size;
    }
    bool operator>=(char right[])
    {
        return this->size >= strutil::length(right);
    }
    friend bool operator>=(const char left[], const String &right)
    {
        return strutil::length(left) >= right.size;
    }

    // LT
    bool operator<(const String &right)
    {
        return this->size < right.size;
    }
    bool operator<(char right[])
    {
        return this->size < strutil::length(right);
    }
    friend bool operator<(const char left[], const String &right)
    {
        return strutil::length(left) < right.size;
    }
    // LTE
    bool operator<=(const String &right)
    {
        return this->size <= right.size;
    }
    bool operator<=(char right[])
    {
        return this->size <= strutil::length(right);
    }
    friend bool operator<=(const char left[], const String &right)
    {
        return strutil::length(left) <= right.size;
    }


    int length(){
        return this->size;
    }

    // String& slice(int start){
    //     String *result = new String;
    //     delete result->pointer;
    //     result->size = this->size - start;
    //     result->pointer = new char[result->size];
    //     return *result;
    // }

    friend std::ostream &operator<<(std::ostream &o, String t)
    {
        // o << t.pointer;
        for(int i = 0; i < t.size; i++){
            o << t.pointer[i];
        }
        return o;
    }
};
