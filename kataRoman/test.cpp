/* ----------------------------------------------------- */
bool err;
#define IS_TRUE(x) {if (!(x)) {\
    std::cerr<<"⛔️ :"  <<" FAILED" <<std::endl;\
    err = true;}}
/* ----------------------------------------------------- */

//Libraries for Function
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <string>

// Function
class RomanHelper{
  public:
    std::string to_roman(unsigned int n){
      std::string result = "";
      std::vector<unsigned int> separated = separate(n);
      result += to_roman_thousands(separated[0]);
      result += to_roman_hundreds(separated[1]);
      result += to_roman_decades(separated[2]);
      result += to_roman_digits(separated[3]);
      return result;
    }
    std::string to_roman_digits(unsigned int n){

        if (n==9) return "IX";
        if (n==8) return "VIII";
        if (n==7) return "VII";
        if (n==6) return "VI";
        if (n==5) return "V";
        if (n==4) return "IV";
        if (n==3) return "III";
        if (n==2) return "II";
        if (n==1) return "I";
        return "";
    }
    std::string to_roman_decades(unsigned int n){
        if (n==1) return "X";
        if (n==2) return "XX";
        if (n==3) return "XXX";
        if (n==4) return "XL";
        if (n==5) return "L";
        if (n==6) return "LX";
        if (n==7) return "LXX";
        if (n==8) return "LXXX";
        if (n==9) return "XC";
        return "";
    }
    std::string to_roman_hundreds(unsigned int n){
        if (n==1) return "C";
        if (n==2) return "CC";
        if (n==3) return "CCC";
        if (n==4) return "CD";
        if (n==5) return "D";
        if (n==6) return "DC";
        if (n==7) return "DCC";
        if (n==8) return "DCCC";
        if (n==9) return "CM";
        return "";
    }

    std::string to_roman_thousands(unsigned int n){
        if (n==1) return "M";
        if (n==2) return "MM";
        if (n==3) return "MMM";
        return "";
    }
    std::vector<unsigned int> separate(unsigned int n){
        return {n/1000,(n%1000)/100,(n%100)/10,n%10};
    }

    unsigned int from_roman(std::string rn){
        std::vector<std::string> result = separate_from(rn);
        unsigned int total = translate_from(result);
        return total;
    }
    std::vector<std::string> separate_from(std::string input){
        std::string result1 = "";
        std::string result2 = "";
        std::string result3 = "";
        std::string result4 = "";

        std::vector<std::string> digits = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        std::vector<std::string> decades = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        std::vector<std::string> hundreds = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        std::vector<std::string> thousands = {"","M","MM","MMM"};

        std::vector<std::vector<std::string>> conversion = {thousands,hundreds,decades,digits};
        std::vector<std::string> results = {result1,result2,result3,result4};

        std::vector<std::string>::iterator it;
        int i =0;
        int j =0;
        std::string cur_value = "";
        while(i<input.size())
        {
            cur_value+=input[i];
            it = std::find(conversion[j].begin(),conversion[j].end(),cur_value);
            if (it!=conversion[j].end()){
                i++;
                if (i < input.size())
                    continue;
                else
                    results[j] = cur_value;
                    cur_value = "";
                    break;
            }else 
            {
                cur_value.pop_back();
                results[j] = cur_value;
                cur_value = "";
                j++;
                i--;
            }
            i++;
        }
      
        return results;
    }
    unsigned int translate_from(std::vector<std::string> results){
        std::vector<std::string> digits = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        std::vector<std::string> decades = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        std::vector<std::string> hundreds = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        std::vector<std::string> thousands = {"","M","MM","MMM"};
        std::vector<std::vector<std::string>> conversion = {thousands,hundreds,decades,digits};
        int j = 0;
        int k = 1000;
        unsigned int total = 0;
        std::vector<std::string>::iterator it;

        for (auto x:results)
        {
            it = std::find(conversion[j].begin(),conversion[j].end(),x);
            if (it!=conversion[j].end()){
                total += std::distance(conversion[j].begin(),it)*k;
            }else 
            {
            }
            j++;
            k/=10;
        }
        return total;
    }


} RomanNumerals;
/* ----------------------------------------------------- */
// Tests
void handleTestToRoman(int test_number, unsigned int input, std::string check)
{
    RomanHelper rh;
    std::string result = rh.to_roman(input);
    std::cout<<"TEST "<<test_number<<":"<<std::endl;
    IS_TRUE(result==check);
    if (err==false)
        std::cout<<"✅ : PASSED\n";
}
void handleTestFromRoman(int test_number, std::string input, unsigned int check)
{
    RomanHelper rh;
    unsigned int result = rh.from_roman(input);
    std::cout<<"TEST "<<test_number<<":"<<std::endl;
    IS_TRUE(result==check);
    if (err==false)
        std::cout<<"✅ : PASSED\n";
}
void handleTestFromRomanSeparate(int test_number, std::string input, std::vector<std::string> check)
{
    RomanHelper rh;
    std::vector<std::string> result = rh.separate_from(input);
    std::cout<<"TEST "<<test_number<<":"<<std::endl;
    IS_TRUE(result==check);
    if (err==false)
        std::cout<<"✅ : PASSED\n";
}
void handleTestDigits(int test_number, unsigned int input, std::string check)
{
    RomanHelper rh;
    std::string result = rh.to_roman_digits(input);
    std::cout<<"TEST "<<test_number<<":"<<std::endl;
    IS_TRUE(result==check);
    if (err==false)
        std::cout<<"✅ : PASSED\n";
}
void handleTestSeparate(int test_number, unsigned int input, std::vector<unsigned int> check)
{
    RomanHelper rh;
    std::vector<unsigned int> result = rh.separate(input);
    std::cout<<"TEST "<<test_number<<":"<<std::endl;
    IS_TRUE(result==check);
    if (err==false)
        std::cout<<"✅ : PASSED\n";
}

void handleTestTranslate(int test_number, std::vector<std::string> input, unsigned int check)
{
    RomanHelper rh;
    unsigned int result = rh.translate_from(input);
    std::cout<<"TEST "<<test_number<<":"<<std::endl;
    IS_TRUE(result==check);
    if (err==false)
        std::cout<<"✅ : PASSED\n";
}

void handleTestDecades(int test_number, unsigned int input, std::string check)
{
    RomanHelper rh;
    std::string result = rh.to_roman_decades(input);
    std::cout<<"TEST "<<test_number<<":"<<std::endl;
    IS_TRUE(result==check);
    if (err==false)
        std::cout<<"✅ : PASSED\n";
}
void handleTestHundreds(int test_number, unsigned int input, std::string check)
{
    RomanHelper rh;
    std::string result = rh.to_roman_hundreds(input);
    std::cout<<"TEST "<<test_number<<":"<<std::endl;
    IS_TRUE(result==check);
    if (err==false)
        std::cout<<"✅ : PASSED\n";
}

void handleTestThousands(int test_number, unsigned int input, std::string check)
{
    RomanHelper rh;
    std::string result = rh.to_roman_thousands(input);
    std::cout<<"TEST "<<test_number<<":"<<std::endl;
    IS_TRUE(result==check);
    if (err==false)
        std::cout<<"✅ : PASSED\n";
}
void execute_tests()
{
    // handleTest(test number, input, reference)
    handleTestDigits(1, 1 ,"I"); 
    handleTestDigits(2, 2 ,"II"); 
    handleTestDigits(3, 3 ,"III"); 
    handleTestDigits(4, 4 ,"IV"); 
    handleTestDigits(5, 5 ,"V"); 
    handleTestDigits(6, 6 ,"VI"); 
    handleTestDigits(7, 7 ,"VII"); 
    handleTestDigits(8, 8 ,"VIII"); 
    handleTestDigits(9, 9 ,"IX"); 
    handleTestDigits(10, 0 ,""); 
    
    handleTestSeparate(11,32, std::vector<unsigned int> {0,0,3,2}); 
    
    handleTestDecades(12, 1 ,"X"); 
    handleTestDecades(13, 2 ,"XX"); 
    handleTestDecades(14, 3 ,"XXX"); 
    handleTestDecades(15, 4 ,"XL"); 
    handleTestDecades(16, 5 ,"L"); 
    handleTestDecades(17, 6 ,"LX"); 
    handleTestDecades(17, 7 ,"LXX"); 
    handleTestDecades(17, 8 ,"LXXX"); 
    handleTestDecades(17, 9 ,"XC"); 
    handleTestDecades(18, 0 ,""); 

    handleTestHundreds(19, 1 ,"C"); 
    handleTestHundreds(20, 2 ,"CC"); 
    handleTestHundreds(21, 3 ,"CCC"); 
    handleTestHundreds(22, 4 ,"CD"); 
    handleTestHundreds(23, 5 ,"D"); 
    handleTestHundreds(24, 6 ,"DC"); 
    handleTestHundreds(25, 7 ,"DCC"); 
    handleTestHundreds(26, 8 ,"DCCC"); 
    handleTestHundreds(27, 9 ,"CM"); 
    handleTestHundreds(28, 0 ,""); 
    

    handleTestThousands(29, 1 ,"M"); 
    handleTestThousands(30, 2 ,"MM"); 
    handleTestThousands(31, 3 ,"MMM"); 
    
    handleTestToRoman(32, 1990 ,"MCMXC"); 
    handleTestToRoman(33, 120 ,"CXX"); 
    handleTestToRoman(34, 4 ,"IV"); 

    handleTestFromRomanSeparate(35, "M", {"M","","",""});
    handleTestFromRomanSeparate(36, "MM", {"MM","","",""});
    handleTestFromRomanSeparate(37, "MCM", {"M","CM","",""});
    handleTestFromRomanSeparate(38, "MCMXC", {"M","CM","XC",""});
    handleTestFromRomanSeparate(39, "X", {"","","X",""});
    
    handleTestTranslate(39, std::vector<std::string> {"","","X",""}, 10);
    handleTestTranslate(40, std::vector<std::string> {"M","","X",""}, 1010);

    handleTestToRoman(41, 10,"X");
    handleTestFromRoman(42,"X",10);
}
/* ----------------------------------------------------- */
int main(void)
{ 
    execute_tests();
    if (err == false) std::cout<<"All tests are passed\n";
}