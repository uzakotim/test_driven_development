#include "test.h"
bool err;
#define IS_TRUE(x) {if (!(x)) {\
    std::cerr<< __FUNCTION__ << " failed on line: " << __LINE__ << std::endl;\
    err = true;                                                             \
                                                                            }\
                                                                            }\


// Test function
bool designed_function(int a, int b)
{
    return a==b;
}
// Tests

void test_function()
{
    IS_TRUE(!designed_function(0,2));
    IS_TRUE(!designed_function(5,0));
    IS_TRUE(designed_function(10,10));
    IS_TRUE(!designed_function(11,10));
}

int main(void)
{
    test_function();
    if (err == false) std::cout<<"All tests are passed\n";
}