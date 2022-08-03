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
#define POINTS {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}
// Function
int* calculateRandomPoint(int* refPoint, int xlim, int ylim)
{
    srand(time(NULL));
    int points[8][2] = POINTS;
    bool done = false;
    int tempX,tempY;
    while(!done)
    {
        int randomPointIndex = rand()%8; 

        std::cout<<randomPointIndex<<std::endl;
        tempX = refPoint[0] + points[randomPointIndex][0];
        tempY = refPoint[1] + points[randomPointIndex][1];

        if ((tempX >= xlim) || (tempY>=ylim) || (tempX <0) || (tempY <0)) 
        {
            done = false;
        }
        else 
        {
            refPoint[0] = tempX;
            refPoint[1] = tempY;
            done = true;
        }
        std::cout<<refPoint[0]<<":" << refPoint[1]<<std::endl;
    }  
    return refPoint;
}

/* ----------------------------------------------------- */
// Test function
bool designed_function(int a[], int b[],int size)
{
    bool equal = true;
    for (int i=0;i<size;i++)
    {
        if (a[i] != b[i]) equal = false;
    }
    return equal;
}

bool designed_function_bool(bool a)
{
    return a;
}
// Tests

void test_function()
{
    // Simple test case
    int lim = 10; 
 
    int trueOutput1[2];
    int trueOutput2[2];
    int trueOutput3[2];
    int trueOutput4[2];
    int trueOutput5[2];
    int trueOutput6[2];
    int trueOutput7[2];
    int trueOutput8[2];
   
    int ref_point[2];
    int random_point[2];
    // TEST 1
    std::cout<<"TEST 1:"<<std::endl;

    memcpy(ref_point, (int[2]){5,5}, 2*sizeof(int));
    memcpy(trueOutput1, (int[2]){6,5}, 2*sizeof(int));
    memcpy(trueOutput2, (int[2]){6,6}, 2*sizeof(int));
    memcpy(trueOutput3, (int[2]){5,6}, 2*sizeof(int));
    memcpy(trueOutput4, (int[2]){4,6}, 2*sizeof(int));
    memcpy(trueOutput5, (int[2]){4,5}, 2*sizeof(int));
    memcpy(trueOutput6, (int[2]){4,4}, 2*sizeof(int));
    memcpy(trueOutput7, (int[2]){5,4}, 2*sizeof(int));
    memcpy(trueOutput8, (int[2]){6,4}, 2*sizeof(int));
    
    memcpy(random_point, calculateRandomPoint(ref_point,lim,lim), 2*sizeof(int));


    IS_TRUE(designed_function(random_point,trueOutput1,2)
    ||designed_function(random_point,trueOutput2,2)
    ||designed_function(random_point,trueOutput3,2)
    ||designed_function(random_point,trueOutput4,2)
    ||designed_function(random_point,trueOutput5,2)
    ||designed_function(random_point,trueOutput6,2)
    ||designed_function(random_point,trueOutput7,2)
    ||designed_function(random_point,trueOutput8,2));

    //TEST 2
    std::cout<<"TEST 2:"<<std::endl;
    memcpy(ref_point, (int[2]){5,5}, 2*sizeof(int));
    memcpy(random_point, calculateRandomPoint(ref_point,lim,lim), 2*sizeof(int));
    IS_TRUE((random_point[0]<=lim)||(random_point[1]<=lim)||(random_point[0]>=0)||(random_point[1]>=0));

    //TEST 3
    std::cout<<"TEST 3:"<<std::endl;
    memcpy(ref_point, (int[2]){0,0}, 2*sizeof(int));
    memcpy(random_point, calculateRandomPoint(ref_point,lim,lim), 2*sizeof(int));
    IS_TRUE((random_point[0]<=lim)||(random_point[1]<=lim)||(random_point[0]>=0)||(random_point[1]>=0));
   
    //TEST 4
    std::cout<<"TEST 4:"<<std::endl;
    memcpy(ref_point, (int[2]){10,10}, 2*sizeof(int));
    memcpy(random_point, calculateRandomPoint(ref_point,lim,lim), 2*sizeof(int));
    IS_TRUE((random_point[0]<=lim)||(random_point[1]<=lim)||(random_point[0]>=0)||(random_point[1]>=0));
    
    //TEST 5
    std::cout<<"TEST 5:"<<std::endl;
    memcpy(ref_point, (int[2]){0,10}, 2*sizeof(int));
    memcpy(random_point, calculateRandomPoint(ref_point,lim,lim), 2*sizeof(int));
    IS_TRUE((random_point[0]<=lim)||(random_point[1]<=lim)||(random_point[0]>=0)||(random_point[1]>=0));
    
    //TEST 6
    std::cout<<"TEST 6:"<<std::endl;
    memcpy(ref_point, (int[2]){10,0}, 2*sizeof(int));
    memcpy(random_point, calculateRandomPoint(ref_point,lim,lim), 2*sizeof(int));
    IS_TRUE((random_point[0]<=lim)||(random_point[1]<=lim)||(random_point[0]>=0)||(random_point[1]>=0));







}

/* ----------------------------------------------------- */
int main(void)
{ 
    test_function();
    if (err == false) std::cout<<"All tests are passed\n";
}