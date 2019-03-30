#include <iostream>

using namespace std;

int CountOne_1(int n);
int CountOne_2(int n);

int main()
{
    int n = 10;
    int count = CountOne_2(n);
    cout << "The number of one is:" << count << endl; 
    return 0;
}
//移动判断标识符
int CountOne_1(int n)
{
    int flag = 1;
    int count = 0;
    int N = sizeof(int)*8;//判断int最大储存几位二进制数，4个字节，每个字节8位
    while(N)
    {
        if(n&flag)
        {
            count++;
        }
        flag = flag<<1;
        N--;
    }
    return count;
}
//利用n&(n-1)使得最右边的1变为0，右边的1之后都变成0，1之前不变，达到纪录1个数的目的
int CountOne_2(int n)
{
    int count = 0;
    while(n)
    {
        count++;
        n=n&(n-1);
    }
    return count;
}