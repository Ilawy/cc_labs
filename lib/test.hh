#include "iostream"


#define test_info(x) std::cout << "INFO:" << x << std::endl
#define test_error(x) std::cout << "ERROR:" << x << std::endl

#define test_block(name, block) do{             \
test_info(name);                                \
block;                                       \
std::cout << "PASS: " << name << std::endl;     \
}while(0)


#define assert(x) do{                           \
    if(!(x)){                                   \
        throw std::runtime_error(#x " failed"); \
    }                                           \
}while(0)