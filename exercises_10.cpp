//寻找旋转数组中的最小数字。
//旋转数组定义：一个升序长度为n排列数组，取出前0<=x<=n放在数组尾部
//采用二分查找的思路，旋转后的数组可以分为两个排序好的数组，最小数字就是两个数组交接处的后一个数字
//设置连个Index，Index1在数组首，Index2在数组尾，每次比较IndexMiddle的大小，IndexMiddle在前面数组就移动index1到middle处，indexMiddle在后面数组，就移动index2到middle处。
//直到index1和index2碰头，输出index2位置的数，就是最小数。
//注意两个特殊情况：1.完全顺序，输出数组首。2，数组首==数组尾==数组中，遍历数组，输出最小值。
#include <iostream>
#include <exception>
using namespace std;
int getMin(int* arr, int length);

int main()
{
    int arr[] = {1,0,1,1,1} ;
    //int arr[] = {4,5,6,1,2,3};
    //int arr[] = {1,2,3,4,5};
    cout << getMin(arr, sizeof(arr)/sizeof(arr[0])) << endl;
    return 0;
}

int getMin(int* arr, int length)
{
    if(arr == nullptr && length <= 0)
    {
        logic_error ex("Invalid Input");
        throw new std::exception(ex);
    }
    int p1 = 0;
    int p2 = length-1;
    int middle = 0;
    while(arr[p1]>=arr[p2])
    {
        if(p2 - p1 == 1 )
        {
            middle = p2;
            break;
        }
        middle = (p2+p1)/2;
        
        if(arr[p1]==arr[p2] && arr[p2]==arr[middle])
        {
            int minNum = arr[p1];
            for(int i = p1; i < p2; ++i)
            {
                if(minNum > arr[i+1])
                {
                    minNum = arr[i+1];
                }
            }
            return minNum;
        }
        if(arr[middle] >= arr[p1])
        {
            p1 = middle;
        }
        else if(arr[middle] <= arr[p2])//如果上面的if条件符合，就不执行这里的else if判断
        {
            p2 = middle;
        }
    }
    
    return arr[middle];
}
