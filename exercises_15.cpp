//实现pow函数
//考虑次方是负数
//次方是负数且底数是0
//次方是0，底数也是0
#include <iostream>
#include <cmath>
//全局变量是程序中定义在所有函数（包括 main 函数）之外的任何变量。
//全局变量的作用域是程序从变量定义到整个程序结束的部分。这意味着全局变量可以被所有定义在全局变量之后的函数访问。
bool g_InvalidInput = false;

using namespace std;
bool equal(double num1, double num2);
double power(int base, int exponent);
double powerWithUnsignedExp_1(int base, int absExpoent);
double powerWithUnsignedExp_2(int base, int absExpoent);

int main()
{
    double result = power(2,-2);
    cout <<"the result is: " << result << endl;
    cout <<"The input is invalid or not: " << g_InvalidInput << endl;
    
    return 0;
}

double power(int base, int exponent)
{
    g_InvalidInput = false;
    if(equal(base,0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }
    unsigned int absExponent = (unsigned int)(exponent);
    if(exponent < 0)
    {
        absExponent = (unsigned int)(-exponent);
    }
    double result = powerWithUnsignedExp_2(base, absExponent);
    if(exponent < 0)
    {
        result = 1/result;
    }
    return result;
}

double powerWithUnsignedExp_1(int base, int absExpoent)
{
    double result = 1.0;
    for(int i = 1; i <= absExpoent; ++i)
    {
        result = result*base;
    }
    return result;
}

bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

//递归版本
double powerWithUnsignedExp_2(int base, int absExponent)
{
    if(absExponent==0)
    {
        return 1;
    }
    if(absExponent==1)
    {
        return base;
    }
    double result = powerWithUnsignedExp_2(base,absExponent >> 1);
    result *=result;
    if(absExponent&0x1)
    {
        result*=base;
    }
    return result;
}
