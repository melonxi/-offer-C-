#include <iostream>

using namespace std;
bool duplicate(int arr[], int length, int* dupNum);

int main(){
    int a[] = {2,3,1,0,2,5,4};
    int dup;
    bool b = duplicate(a,7,&dup);
    cout << b << dup << endl;
    return 0;
}

bool duplicate(int arr[], int length, int* dupNum)
{
    if(arr == nullptr||length <= 0)
    {
        return false;
    }
    for(int j = 0; j < length; ++j)
    {
        if(arr[j] < 0 || arr[j] > length - 1)
        {
            return false;
        }
    }
    for(int i = 0; i < length; ++i)
    {
        while(arr[i] != i)
        {
            if(arr[i] == arr[arr[i]])
            {
                *dupNum = arr[i];
                return true;
            }
            int temp = arr[i];
            arr[i] = arr[temp];
            arr[temp] = temp;
        }
    }
    
    return false;
}