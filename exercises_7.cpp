//给定二叉树和其中的一个节点，如何找出**中序遍历**序列的下一个节点？（树中的节点除了有指向左右子节点的指针，还有一个指向父节点的指针）
//分三中情况：
//1.节点有右子树，那么下一个节点就是右子树的最左节点；
//2.节点没有右子树，且是其父节点的左子节点，那么下一个节点就是其父节点；
//3.节点没有右子树，且是其父节点的右子节点，那么向上循环寻找父节点，直到找到一个节点是其父节点的左子节点，那么当前节点的父节点就是下一个节点。
#include <iostream>

using namespace std;

struct binaryTreeNode
{
    int nValue;
    binaryTreeNode* pLeft；
    binaryTreeNode* pRight;
    binaryTreeNode* pFather;
};

int main()
{
    return 0;
}

binaryTreeNode* getNextNode(binaryTreeNode* pNode)
{
    if(pNode = nullptr)
    {
        return nullptr;
    }
    
    binaryTreeNode* pNext = nullptr;
    
    if(pNode->pRight!=bullptr)
    {
        binaryTreeNode* pRight = pNode->pRight;
        while(pRight->pLeft!=nullptr)
        {
            pRight = pRight->pLeft;
        }
        pNext = pRight;
    }
    else if(pNode->pFather!=nullptr)
    {
        binaryTreeNode* pCurrent = pNode;
        binaryTreeNode* pDad = pNode->pFather;
        
        while(pDad!=nullptr && pCurrent==pDad->pRight)
        {
            pCurrent = pDad;
            pDad = pDad->pFather;
        }
    
        pNext = pDad;
    }
    
    return pNext;
}

