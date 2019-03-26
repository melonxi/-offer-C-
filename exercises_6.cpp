//根据前序和中序遍历重建二叉树
//前序遍历确定根节点，中序遍历确定左子树和右子树
//递归实现

#include <iostream>
#include <exception>

using namespace std;

struct binaryTreeNode
{
    int nValue;
    binaryTreeNode* pLeft;
    binaryTreeNode* pRight;
};

binaryTreeNode* construct(int*, int*, int);
binaryTreeNode* constructCore(int*, int*, int*, int*);

int main()
{
    int pre[] = {1,2,4,7,3,5,6,8};
    int in[] = {4,7,2,1,5,3,8,6};
    binaryTreeNode* root = construct(pre, in, 8);
    binaryTreeNode* num2p = root->pLeft;
    cout << "左子树的根节点值是： " << num2p->nValue << endl;
    
    return 0;
}

binaryTreeNode* construct(int* preOrder, int* inOrder, int length)
{
    if(preOrder == nullptr||inOrder == nullptr||length <= 0)
    {
        return nullptr;
    }
    
    return constructCore(preOrder, preOrder+length-1, inOrder, inOrder+length-1);
}

binaryTreeNode* constructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder)
{
    int rootValue = startPreOrder[0];
    binaryTreeNode* root = new binaryTreeNode();
    root->nValue = rootValue;
    root->pLeft = nullptr;
    root->pRight = nullptr;
    
    if(startPreOrder == endPreOrder)
    {
        if(startInOrder == endInOrder && *startPreOrder == *startInOrder)
        {
            return root;
        }
        else
        {
            logic_error ex("Invilid input.");
            throw std::exception(ex);
        }
    }
    
    int* rootInOrder = startInOrder;
    while(rootInOrder <= endInOrder && *rootInOrder!=rootValue)
    {
        ++rootInOrder;
    }
    
    while(rootInOrder == endInOrder && *rootInOrder!=rootValue)
    {
        logic_error ex("Invilid input.");
        throw std::exception(ex);
    }
    
    int leftLength = rootInOrder - startInOrder;
    int* leftEndPreOrder = startPreOrder + leftLength;
    
    if(leftLength > 0)
    {
        root->pLeft = constructCore(startPreOrder+1, leftEndPreOrder, startInOrder, rootInOrder-1);
    }
    
    if(leftLength < endPreOrder-startPreOrder)
    {
        root->pRight = constructCore(leftEndPreOrder+1, endPreOrder, rootInOrder+1, endInOrder);
    }
    
    return root;
}