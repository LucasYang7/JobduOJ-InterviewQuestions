#include<stdio.h>
#define MAX 11
 
typedef struct Node
{
   bool isRoot;           // 标记结点是否为根结点
   Node * lChild;         // 左孩子
   Node * rChild;         // 右孩子
}BinaryTreeNode;
 
BinaryTreeNode binaryTreeNode[MAX];
 
/**
* 初始化二叉树中的结点,将每个结点都看成是一棵只含有根结点，无孩子结点的二叉树
* @param n  二叉树的结点数目
* @return void
*/
void initBinaryTree(int n)
{
  int i;
  for(i = 1;i <= n;i++)
  {
      binaryTreeNode[i].isRoot = true;
      binaryTreeNode[i].lChild = NULL;
      binaryTreeNode[i].rChild = NULL;
  }
}
 
/**
* 构造有n个结点的二叉树
* @param n  二叉树的结点个数
* @return root  返回二叉树的根结点
*/
BinaryTreeNode * createBinaryTree(int n)
{
  BinaryTreeNode * root = NULL;
  int i;
  int leftChild,rightChild;
  initBinaryTree(MAX);
  // 构造各个二叉树结点的左右孩子，结点编号从1开始
  for(i = 1;i <= n;i++)
  {
     scanf("%d%d",&leftChild,&rightChild);
     if(leftChild != -1)
     {
         binaryTreeNode[i].lChild = &binaryTreeNode[leftChild];
         binaryTreeNode[leftChild].isRoot = false;
     }
     if(rightChild != -1)
     {
         binaryTreeNode[i].rChild = &binaryTreeNode[rightChild];
         binaryTreeNode[rightChild].isRoot = false;
     }
  }
  // 找到二叉树的根结点
  for(i = 1;i <= n;i++)
  {
      if(true == binaryTreeNode[i].isRoot)
      {
         root = &binaryTreeNode[i];
         break;
      }
  }
  return root;
}
 
/**
* 获取二叉树的高度
* @param root  二叉树的根结点
* @return h  返回二叉树的高度
*/
int getBinaryTreeHeight(BinaryTreeNode * root)
{
  int hl,hr,h;
  if(NULL == root)
     return 0;
  else               // 通过递归获取左右子树的高度，取二者的较大值加1做为二叉树的高度
  {
     hl = getBinaryTreeHeight(root -> lChild) + 1;
     hr = getBinaryTreeHeight(root -> rChild) + 1;
     h = hl > hr ? hl : hr;
     return h;
  }
}
 
int main()
{
    int n;
    int biTreeHeight;
    BinaryTreeNode * root;
    scanf("%d",&n);
    root = createBinaryTree(n);
    biTreeHeight = getBinaryTreeHeight(root);
    printf("%d\n",biTreeHeight);
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46454371
****************************************************************/
