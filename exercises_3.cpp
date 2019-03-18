#include <iostream>

using namespace std;
bool found(int Mat[][4], int rows, int columns, int obj);

int main()
{
    int matrix[4][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int num = 17;
    bool res = found(matrix, 4, 4, num);
    cout << res << endl;
    return 0;
}

bool found(int Mat[][4], int rows, int columns, int obj)
{
    if(Mat == nullptr || rows > 0 || columns > 0)
    {
        return false;
    }
    int x = 0;
    int y = columns -1;
    while(x < rows && y >= 0)
    {
        if(Mat[x][y] > obj)
        {
            --y;
        }
        else if(Mat[x][y] < obj)
        {
            ++x;
        }
        else
        {
            return true;
        }
    }
    return false;
    
}