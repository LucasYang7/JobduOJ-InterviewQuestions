#include<stdio.h>
#define MAX 1001
 
// 构建二叉树的结点
typedef struct Node
{
   int data;            // 数据域
   Node * lChild;       // 左子树
   Node * rChild;       // 右子树
}BinaryTreeNode;
BinaryTreeNode biTreeNode[MAX];
 
bool canRebuildBinaryTree; // 判断能否重构二叉树
int preOrder[MAX];      // 二叉树的前序遍历序列
int inOrder[MAX];       // 二叉树的中序遍历序列
 
/**
* 初始化二叉树中的每个结点，将每个结点都看成是只有一个根结点而左右子树都为NULL的二叉树
* @param int n  二叉树的结点数
* @return void
*/
void initBinaryTree(int n)
{
  int i;
  canRebuildBinaryTree = true;
  for(i = 0;i < n;i++)
  {
    biTreeNode[i].data = preOrder[i];  // 将前序遍历序列中的元素依次赋值给二叉树中的结点
    biTreeNode[i].lChild = NULL;
    biTreeNode[i].rChild = NULL;
  }
}
 
/**
* 重构二叉树
* @param int beginPreOrder  前序遍历序列的起点
* @param int endPreOrder  前序遍历序列的终点
* @param int beginInOrder  中序遍历序列的起点
* @param int endInOrder  中序遍历序列的终点
* @return void
*/
void reBuildBinaryTree(int beginPreOrder,int endPreOrder,int beginInOrder,int endInOrder)
{
   int i;
   int partion = -1;     // 前序遍历序列第一个结点在中序遍历序列中的相对位置
   bool isBeginPreOrderinInOrder = false; // 判断前序遍历序列中的第一个结点是否在中序遍历序列中，以此来判断是否能构成二叉树
   // 遍历二叉树的中序遍历序列，得到根结点在中序遍历序列中的位置
   for(i = beginInOrder;i <= endInOrder;i++)
   {
       if(preOrder[beginPreOrder] == inOrder[i])
       {
          partion = i - beginInOrder;
          isBeginPreOrderinInOrder = true;
          break;
       }
   }
   if(false == isBeginPreOrderinInOrder)
   {
       canRebuildBinaryTree = false;
       return;
   }
   else
   {
       // 以partion为分隔标识
       // 将前序遍历序列分为[beginPreOrder + 1,beginPreOrder + partion]
       // 和[beginPreOrder + partion + 1,endPreOrder]两个子序列
       // 将中序遍历序列分为[beginInOrder,beginInOrder + partion - 1]
       // 和[beginInOrder + partion + 1,endInOrder]两个子序列
 
       // 用前序遍历子序列[beginPreOrder + 1,beginPreOrder + partion]
       // 和中序遍历子序列[beginInOrder,beginInOrder + partion - 1]重构左子树
       if(beginPreOrder + 1 <= beginPreOrder + partion && beginInOrder <= beginInOrder + partion - 1)
       {
           biTreeNode[beginPreOrder].lChild = &biTreeNode[beginPreOrder + 1];
           reBuildBinaryTree(beginPreOrder + 1,beginPreOrder + partion,beginInOrder,beginInOrder + partion - 1);
       }
       // 用前序遍历子序列[beginPreOrder + partion + 1,endPreOrder]
       // 和中序遍历子序列[beginInOrder + partion + 1,endInOrder]重构右子树
       if(beginPreOrder + partion + 1 <= endPreOrder && beginInOrder + partion + 1 <= endInOrder)
       {
           biTreeNode[beginPreOrder].rChild = &biTreeNode[beginPreOrder + partion + 1];
           reBuildBinaryTree(beginPreOrder + partion + 1,endPreOrder,beginInOrder + partion + 1,endInOrder);
       }
   }
}
 
/**
* 后序遍历二叉树
* @param BinaryTreeNode * root  后序遍历的根结点
* @return void
*/
void postOrder(BinaryTreeNode * root)
{
  if(NULL == root)
    return;
  else
  {
     postOrder(root -> lChild);
     postOrder(root -> rChild);
     printf("%d ",root -> data);
  }
}
 
int main()
{
    int n;
    int i;
    while(EOF != scanf("%d",&n))
    {
      for(i = 0;i < n;i++)
      {
          scanf("%d",&preOrder[i]);
      }
      for(i = 0;i < n;i++)
      {
          scanf("%d",&inOrder[i]);
      }
      initBinaryTree(n);
      reBuildBinaryTree(0,n - 1,0,n - 1);
      if(false == canRebuildBinaryTree)
         printf("No\n");
      else
      {
         postOrder(&biTreeNode[0]); //因为 biTreeNode[0].data == preOrder[0]，所以biTreeNode[0]是重构二叉树的根结点
         printf("\n");
      }
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46325833
****************************************************************/
