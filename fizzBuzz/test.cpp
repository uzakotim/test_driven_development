//Libraries for Function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>



/* ----------------------------------------------------- */
bool err;
#define IS_TRUE(x) {if (!(x)) {\
    std::cerr<<"⛔️ :"  <<" FAILED" <<std::endl;\
    err = true;}}
/* ----------------------------------------------------- */
// Function
std::string findFizzBuzz(int value)
{
    if ((0 == value%3) and (0==value%5))
        return "FizzBuzz";
    if (0 == value%3)
        return "Buzz";
    if (0 == value%5)
        return "Fizz";
    return std::to_string(value);
}

/* ----------------------------------------------------- */
// Tests
void handleTest(int test_number, int input, std::string check)
{
    std::string result = findFizzBuzz(input);
    std::cout<<"TEST "<<test_number<<":"<<std::endl;
    IS_TRUE(result==check);
    if (err==false)
        std::cout<<"✅ : PASSED\n";
}

void execute_tests()
{
    // handleTest(test number, input, reference)
    handleTest(1,1, "1");   
    handleTest(2,2, "2");   
    handleTest(3,3, "Buzz");   
    handleTest(4,5, "Fizz");   
    handleTest(5,6, "Buzz");   
    handleTest(6,15,"FizzBuzz");   
}

/* ----------------------------------------------------- */
int main(void)
{ 
    execute_tests();
    if (err == false) std::cout<<"All tests are passed\n";
}