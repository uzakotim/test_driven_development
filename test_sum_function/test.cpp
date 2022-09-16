#include "test.h"
bool err;
#define IS_TRUE(x) {if (!(x)) {\
    std::cerr<< __FUNCTION__ << " failed on line: " << __LINE__ << std::endl;\
    err = true;                                                             \
                                                                            }\
                                                                            }\
/* ----------------------------------------------------- */
//Libraries for Function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Function
int calculateSum(int a, int b)
{
    return a+b;
}
/* ----------------------------------------------------- */
// Tests

void test_function()
{
    int reference;
    int result;
    //TEST 1
    std::cout<<"TEST 1:"<<std::endl;
    result = calculateSum(5,5);
    reference = 10;
    IS_TRUE(result==reference);
}

/* ----------------------------------------------------- */
int main(void)
{ 
    test_function();
    if (err == false) std::cout<<"All tests are passed\n";
}