#include<stdio.h>
#include<stack>
using namespace std;
#define MAX 10001
 
// 采用三叉链表来存储二叉树的结点
typedef struct Node
{
   bool isRoot;    // 标记该结点是否为根结点
   int data;       // 数据
   int number;     // 编号
   Node * parent;  // 父指针
   Node * lchild;  // 左孩子指针
   Node * rchild;  // 右孩子指针
}BinaryTreeNode;
 
BinaryTreeNode binaryTreeNode[MAX];
 
/**
* 初始化二叉树，将二叉树中的每个结点都看成是只有一个根结点而左右子树为空的二叉树
* @param n  二叉树的结点个数
* @return void
*/
void initBinaryTree(int n)
{
  int i;
  for(i = 1;i <= n;i++)
  {
     binaryTreeNode[i].isRoot = true;
     binaryTreeNode[i].lchild = NULL;
     binaryTreeNode[i].rchild = NULL;
     binaryTreeNode[i].parent = NULL;
  }
}//initBinaryTree
 
/**
* 构造有n个结点的二叉树，结点编号从1到n。
* @param n  二叉树的结点个数
* @return root  返回二叉树的根结点
*/
BinaryTreeNode * createBinaryTree(int n)
{
  BinaryTreeNode * root = NULL;
  int i;
  int vi;
  int leftnode;
  int rightnode;
  //(1)销毁上一次生成的二叉树结构
  initBinaryTree(n);
  //(2)构造各个二叉树结点的值，编号，左右子树等信息
  for(i = 1;i <= n;i++)
  {
      scanf("%d%d%d",&vi,&leftnode,&rightnode);
      binaryTreeNode[i].data = vi;
      binaryTreeNode[i].number = i;
      if(leftnode != -1)            // 如果结点i存在左子树，则构造其左子树
      {
          binaryTreeNode[i].lchild = &binaryTreeNode[leftnode];
          binaryTreeNode[leftnode].isRoot = false;
          binaryTreeNode[leftnode].parent = &binaryTreeNode[i];
      }
      if(rightnode != -1)            // 如果结点i存在右子树，则构造其右子树
      {
          binaryTreeNode[i].rchild = &binaryTreeNode[rightnode];
          binaryTreeNode[rightnode].isRoot = false;
          binaryTreeNode[rightnode].parent = &binaryTreeNode[i];
      }
  }//for
  //(3)确定二叉树的根结点
  for(i = 1;i <= n;i++)
  {
     if(true == binaryTreeNode[i].isRoot)
     {
        root = &binaryTreeNode[i];
        break;
     }
  }
  return root;
}//createBinaryTree
 
/**
* 采用先序遍历的方式得到二叉树中所有和为k的路径
* @param root  当前被遍历的二叉树的结点
* @param sum  从二叉树根结点到当前正在被遍历的结点的路径和
* @param k  表示要求的路径和
* @return void
*/
void getSumEqualsKPathInBinaryTree(BinaryTreeNode * root,int sum,int k)
{
   if(NULL == root)
      return ;
   sum = sum + (root -> data);
   // root结点有左右两棵子树 则按照优先遍历编号小的子树的规则来进行先序遍历
   // 如果左子树的编号小于右子树的编号，则遍历顺序为"中左右"
   // 如果左子树的编号大于右子树的编号，则遍历顺序为"中右左"
   if(root->lchild != NULL && root->rchild != NULL)
   {
      if((root -> lchild -> number) < (root -> rchild -> number))
      {
          getSumEqualsKPathInBinaryTree(root -> lchild,sum,k);
          getSumEqualsKPathInBinaryTree(root -> rchild,sum,k);
      }
      else
      {
          getSumEqualsKPathInBinaryTree(root -> rchild,sum,k);
          getSumEqualsKPathInBinaryTree(root -> lchild,sum,k);
      }
   }
   // 如果root结点的子树数目不足两棵，则直接按"中左右"的顺序进行遍历
   else
   {
     if(NULL == root -> lchild && NULL == root -> rchild) // 如果root是叶子结点，则判断sum是否等于k
     {
       if(sum == k)                    // 表示找到了和等于k的路径，将该路径打印出来
       {
          BinaryTreeNode * p = root;   // p指针遍历寻找二叉树的根结点
          stack <int> pathStack;       // 用于存放路径的栈
          while(p != NULL)
          {
            pathStack.push(p -> number); // 将结点编号压入到用于存放路径的栈中
            p = p -> parent;
          }
          // 从根结点开始，向下打印路径
          printf("A path is found:");
          while(false == pathStack.empty())
          {
            printf(" %d",pathStack.top());
            pathStack.pop();
          }
          printf("\n");
       }
     }
     getSumEqualsKPathInBinaryTree(root -> lchild,sum,k);
     getSumEqualsKPathInBinaryTree(root -> rchild,sum,k);
   }
}//getSumEqualsKPathInBinaryTree
 
int main()
{
    int n,k,sum;
    BinaryTreeNode * root;
    while(EOF != scanf("%d%d",&n,&k))
    {
       root = createBinaryTree(n);
       sum = 0;
       printf("result:\n");
       getSumEqualsKPathInBinaryTree(root,sum,k);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46409949
****************************************************************/