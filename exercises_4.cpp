#include <iostream>

using namespace std;

void replaceSpace(char*, int);
void coutstr(char*, int);

int main()
{
    char wor[50] = " hello the world ";
    int length1 = strlen(wor);
    coutstr(wor, length1);
    replaceSpace(wor,50);
    int length2 = strlen(wor);
    coutstr(wor, length2);
    
    cout << wor[0] << wor[6] << wor[7];

    return 0;
}

void replaceSpace(char *str, int length)
{
    if(str == nullptr && length <= 0)
        return;

    /*originalLength 为字符串str的实际长度*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++ originalLength;

        if(str[i] == ' ')
            ++ numberOfBlank;

        ++ i;
    }

    /*newLength 为把空格替换成'%20'之后的长度*/
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(str[indexOfOriginal] == ' ')
        {
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        else
        {
            str[indexOfNew --] = str[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
}

void coutstr(char *str, int length)
{
    for(int i = 0; i < length; ++i)
    {
        cout << str[i];
    }
    cout << endl;
}