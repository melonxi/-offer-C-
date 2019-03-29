#include <iostream>

using namespace std;

int movingCount(int threshold, int cols, int rows);
int movingCountCore(int threshold,int cols, int rows, int col, int row, bool* visited);
bool check(int threshold,int rows,int cols,int row,int col,bool* visited);

int main()
{
    int threshold = 2;
    int rows = 3;
    int cols = 3;
    int count = movingCount(threshold,cols,rows);
    cout << "The counts of box is:" << count << endl;
    return 0;
}

int movingCount(int threshold, int cols, int rows)
{
    if(threshold < 0||cols < 0||rows < 0)
    {
        return 0;
    }
    bool* visited = new bool[rows*cols];
    memset(visited,0,rows*cols);
    
    int count = movingCountCore(threshold,cols,rows,0,0,visited);
    
    delete[] visited;
    
    return count;
}

int movingCountCore(int threshold,int cols, int rows, int col, int row, bool* visited)
{
    int count = 0;
    
    if(check(threshold,rows,cols,row,col,visited))
    {
        visited[row*cols+col] = true;
        
        count = 1 + movingCountCore(threshold,cols,rows,col-1,row,visited)+
                    movingCountCore(threshold,cols,rows,col+1,row,visited)+
                    movingCountCore(threshold,cols,rows,col,row-1,visited)+
                    movingCountCore(threshold,cols,rows,col,row+1,visited);
    }
    
    return count;
}

bool check(int threshold,int rows,int cols,int row,int col,bool* visited)
{
    if(col/10 + col%10 + row/10 + col%10 <= threshold && !visited[row*cols + col] && col >= 0 && col < cols && row >= 0 && row < rows)
    {
        return true;
    }
    return false;
}

