#include <iostream>

using namespace std;

int getDuplication(const int*, int);
int countRange(const int*, int, int, int);

int main()
{
    int arr[] = {2,3,5,4,3,2,6,7};
    
    int duNu = getDuplication(arr, 8);
    
    cout << "重复数字之一是：" << duNu << endl;
    
    return 0;
}
int getDuplication(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
    {
        return -1;
    }
    int start = 1;
    int end = length -1;
    
    while(start <= end)
    {
        int middle = (start + end)/2;
        int count = countRange(numbers, length, start, middle);  
        if(start == end)
        {
            if(count > 1)
            {
                return start;
            }
            else
                break;
        }
        if(count > (middle - start + 1))
        {
            end = middle;
        }
        else
        {
            start = middle + 1;
        }
    }
    
    return -1;
}

int countRange(const int* numbers, int length, int start, int end)
{
    if(numbers == nullptr)
    {
        return 0;
    }
    
    int count = 0;
    
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] >= start && numbers[i]<= end)
        {
            ++count;
        }
    }
    return count;
}