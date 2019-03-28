#include <iostream>
using namespace std;

bool findPath(char* matrix, int rows, int cols, char* str);
bool findPathCore(char* matrix, char* str, bool* visited, int row, int rows, int col, int cols, int& pathlength);

int main()
{
    char matrix[]="abtgcfcsjdeh";
    char str[]= "bfce";
    int rows = 3;
    int cols = 4;
    cout <<"The result is "<< findPath(matrix, rows, cols, str) << endl;
    return 0;
}

bool findPath(char* matrix, int rows, int cols, char* str)
{
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
    {
        return false;
    }
    
    bool* visited = new bool[rows*cols];
    memset(visited, 0, rows*cols);
    int pathlength = 0;
    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col < cols; ++col)
        {
            if(findPathCore(matrix, str, visited, row, rows, col, cols, pathlength))
            {
                return true;
            }
        }
    }
    
    delete[] visited;
    
    return false;
}
//这里使用int& pathlength就是利用变量引用传参，避免了使用指针，做到了变量数据函数内外的双向传输
//因为变量引用和变量指向同一个地址，改变引用的值，就等于改变了变量的值。
bool findPathCore(char* matrix, char* str, bool* visited, int row, int rows, int col, int cols, int& pathlength)
{
    if(str[pathlength]=='\0')
    {
        return true;
    }
    bool hasPath = false;
    if(row>=0 && col>=0 && row < rows && col < cols && matrix[row*cols + col] == str[pathlength] && !visited[row*cols + col])
    {
        pathlength++;
    
        visited[row*cols+col] = true;
    
        hasPath =  findPathCore(matrix, str, visited, row - 1, rows, col, cols, pathlength)||
                   findPathCore(matrix, str, visited, row + 1, rows, col, cols, pathlength)||
                   findPathCore(matrix, str, visited, row, rows, col - 1, cols, pathlength)||
                   findPathCore(matrix, str, visited, row, rows, col + 1, cols, pathlength);
    
        if(!hasPath)
        {
            --pathlength;
            visited[row&cols+col] = false;
        }
    }
    return hasPath;
}