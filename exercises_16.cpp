#include <iostream>

using namespace std;

void printAllTheNumber(int n);
bool increment(char* number);
void printNumber(char* number);
void printAllTheNumberRecursively(int n);
void printAllTheNumberRecursively(char* number, int length, int index);

int main()
{
    int n = 2;
    printAllTheNumberRecursively(n);
    
    return 0;
}

void printAllTheNumber(int n)
{
    if(n <= 0)
    {
        return;
    }
    char* number = new char[n+1];
    memset(number,'0',n);
    number[n] = '\0';
    
    while(!increment(number))
    {
        printNumber(number);
    }
    
    delete []number;
}

bool increment(char* number)
{
    bool isOver = false;
    int sum = 0;
    int length = strlen(number);
    int beforeFlag = 0;
    
    for(int i = length - 1; i >= 0; --i)
    {
        sum = number[i] - '0' + beforeFlag;
        
        if(i == length - 1)
        {
            sum++;
        }
        if(sum == 10)
        {
            if(i == 0)
            {
                isOver = true;
                
            }
            else
            {
                sum = sum - 10;
                beforeFlag = 1;
                number[i] = sum + '0';
            }
        }
        else
        {
            number[i] = sum + '0';
            break;
        }
    }
    
    return isOver;
}

void printNumber(char* number)
{
    bool flag = true;
    for(int i =0; i < strlen(number); ++i)
    {
        if(flag&&number[i] != '0')
        {
            flag = false;
        }
        if(!flag)
        {
            cout << number[i];
        }

    }
    cout << endl;
}
//递归方法
void printAllTheNumberRecursively(int n)
{
    if(n <= 0)
    {
        return;
    }
    
    char* number = new char[n + 1];
    number[n] = '\0';
    
    for(int i = 0; i < 10; ++i)
    {
        number[0] = '0' + i;
        printAllTheNumberRecursively(number,n,0);
    }
    
    delete[] number;
}

void printAllTheNumberRecursively(char* number, int length, int index)
{
    if(index == length - 1)
    {
        printNumber(number);
        return;
    }
    
    for(int i = 0; i < 10; ++i)
    {
        number[index + 1] = '0' + i;
        printAllTheNumberRecursively(number,length,index + 1);
    }
    
}