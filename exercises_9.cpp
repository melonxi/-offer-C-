//写一个函数实现输入数字n，输出斐波那契数列的第n项，斐波那契数列的前两项是0，1
//方法1：递归；复杂度高，存在重复计算
//方法2：循环；复杂度低

#include <iostream>

using namespace std;
int Fibonacci_rec(int n);
int Fibonacci_cir(int n);

int main()
{
    cout << Fibonacci_cir(5)<< endl;
    return 0;
}

int Fibonacci_rec(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    
    return Fibonacci_rec(n-1) + Fibonacci_rec(n-2);
}

int Fibonacci_cir(int n)
{
    int cur = 0;
    int temp1 = 0;
    int temp2 = 1;
    
    if(n == 0)
    {
        return temp1;
    }
    if(n == 1)
    {
        return temp2;
    }
    for(int i=0; i < n - 1; ++i)
    {
        cur = temp1 + temp2;
        temp1 = temp2;
        temp2 = cur;
    }
    
    return cur;
}