#include "test.h"
bool err;
#define IS_TRUE(x) {if (!(x)) {\
    std::cerr<< __FUNCTION__ << " failed on line: " << __LINE__ << std::endl;\
    err = true;                                                             \
                                                                            }\
                                                                            }\


// Tested function
bool designed_function(int a)
{
    return a>5;
}
// Tests

void test_function()
{
    IS_TRUE(!designed_function(0));
    IS_TRUE(!designed_function(5));
    IS_TRUE(designed_function(10));
}

int main(void)
{
    test_function();
    if (err == false) std::cout<<"All tests are passed\n";
}