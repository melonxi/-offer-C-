//长度为n的绳子，减成m段，使得每段乘积最大，n，m都是整数
//动态规划思想:
//0.求一个问题的最优解
//1.整体最优解问题可以划分为子问题的最优解的集合
//2.部分子问题有重合最优解
//3.从上至下分析问题，从下往上求解问题
#include <iostream>
#include <sys/time.h>
#include <time.h>
#include <cmath>

using namespace std;
int maxProduct(int length);
int maxProduct_tl(int length);
double get_wall_time();


int main()
{
    double start_time = get_wall_time();
    int length = 50;
    int max =  maxProduct_tl(length);
    double end_time = get_wall_time();
    cout << "The max product is: " << max << endl << "using time is: " << end_time-start_time << endl; 
    return 0;
}

int maxProduct(int length)
{
    if(length < 2)
    {
        return 0;
    }
    if(length == 2)
    {
        return 1;
    }
    if(length == 3)
    {
        return 2;
    }
    
    int* products = new int[length + 1];
    products[0] = 0;//当n<=3时候不需要分隔，因为分隔了比本身还小
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    
    int max = 0;
    
    for(int i = 4; i <= length; ++i)
    {
        for(int j = 1; j <= i/2; ++j)
        {
            int product = products[i-j]*products[j];
            if(product > max)
            {
                max = product;
            }
        }
        products[i] = max;//这里放在内循环外面比较节省时间
        
    }
    max = products[length];
    
    delete[] products;
    
    return max;
}
//贪婪算法
//尽可能多的分出3，如果剩余4，就留出4
int maxProduct_tl(int length)
{
    if(length < 2)
    {
        return 0;
    }
    if(length == 2)
    {
        return 1;
    }
    if(length == 3)
    {
        return 2;
    }
    
    int count3Times = length/3;
    if(length - count3Times*3 == 1)
    {
        count3Times =count3Times -  1;
    }
    int count2Times = (length - 3*count3Times)/2;
    
    return (pow(3,count3Times))*(pow(2,count2Times));
}

double get_wall_time() 
{ 
  struct timeval time ; 
  if (gettimeofday(&time,NULL)){ 
    return 0; 
  } 
  return (double)time.tv_sec + (double)time.tv_usec * .000001; 
} 


 