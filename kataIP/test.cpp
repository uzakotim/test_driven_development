/* ----------------------------------------------------- */
bool err;
#define IS_TRUE(x) {if (!(x)) {\
    std::cerr<<"⛔️ :"  <<" FAILED" <<std::endl;\
    err = true;}}
/* ----------------------------------------------------- */

//Libraries for Function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <bitset>
#include <vector>

// Function
std::string uint32_to_ip(uint32_t ip)
{
  // your code here
    std::string str = std::bitset<32>(ip).to_string();
    std::vector<int> numbers;

    int k = 0;
    std::string result = "";
    for (int i =0;i<4;i++)
    {
        numbers.push_back(std::stoi(str.substr(k,8),0,2));
        k+=8;
    }
    for (int i=0;i<4;i++)
    {
        result += std::to_string(numbers[i]);
        if (i != 3)
            result+='.';
    }
    return result;
}

/* ----------------------------------------------------- */
// Tests
void handleTest(int test_number, uint32_t input, std::string check)
{
    std::string result = uint32_to_ip(input);
    std::cout<<"TEST "<<test_number<<":"<<std::endl;
    IS_TRUE(result==check);
    if (err==false)
        std::cout<<"✅ : PASSED\n";
}

void execute_tests()
{
    // handleTest(test number, input, reference)
    handleTest(1,2149583361, "128.32.10.1"); 
    handleTest(2,32, "0.0.0.32"); 
    handleTest(3,0, "0.0.0.0"); 
    
}
/* ----------------------------------------------------- */
int main(void)
{ 
    execute_tests();
    if (err == false) std::cout<<"All tests are passed\n";
}