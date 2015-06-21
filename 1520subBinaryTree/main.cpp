#include<stdio.h>
#define MAX 1002
// 定义二叉树的结点结构
typedef struct Node
{
   bool isRootNode;      // 标记结点是否为根结点
   int data;             // 数据域
   Node * lChild;        // 左孩子
   Node * rChild;        // 右孩子
}BinaryTreeNode;
 
BinaryTreeNode biTree[2][MAX];   // 定义二叉树的结点数组,BiTree[0][]表示二叉树A,BiTree[1][]表示二叉树B
bool ifBTreeIsSubOfATree;        // 标记二叉树B是否为二叉树A的子树
 
/**
*  初始化二叉树的各个结点的关系，将每个结点都看成是一棵只包含根结点而没有左右子树的二叉树
*  @param int numberOfNode  表示二叉树的结点个数
*  @param int index  index为0时，表示初始化的是二叉树A,index为1时，表示初始化的是二叉树B
*  @return void
*/
void initBinaryTree(int numberOfNode,int index)
{
  int i;
  // 初始状态下认为每个结点都是一颗只包含根结点的二叉树
  for(i = 1;i <= numberOfNode;i++)
  {
      scanf("%d",&biTree[index][i].data);
      biTree[index][i].lChild = NULL;
      biTree[index][i].rChild = NULL;
      biTree[index][i].isRootNode = true;
  }
}
 
/**
*  构造二叉树
*  @param int numberOfNode 表示二叉树的结点个数
*  @param int index  index为0时，表示构造的是二叉树A,index为1时，表示构造的是二叉树B
*  @return BinaryTreeNode * 返回二叉树的根结点
*/
BinaryTreeNode * createBinaryTree(int numberOfNode,int index)
{
  BinaryTreeNode * root = NULL;
  int i;
  int numberOfChild;             // 标记结点的孩子的个数
  int lChild,rChild;             // lChild为左孩子的结点编号，rChild为右孩子的结点编号
  initBinaryTree(numberOfNode,index); // 初始化二叉树中的各个结点之间的关系
  for(i = 1;i <= numberOfNode;i++)
  {
      scanf("%d",&numberOfChild);
      switch(numberOfChild)
      {
          case 0:
                break;
          case 1:        // 当输入1时，认为结点只有一个左孩子结点，网上搜来的，测试数据中没有孩子个数为1的情况
                scanf("%d",&lChild);
                biTree[index][i].lChild = &biTree[index][lChild];
                biTree[index][lChild].isRootNode = false;
                break;
          case 2:
                scanf("%d%d",&lChild,&rChild);
                biTree[index][i].lChild = &biTree[index][lChild];
                biTree[index][lChild].isRootNode = false;
                biTree[index][i].rChild = &biTree[index][rChild];
                biTree[index][rChild].isRootNode = false;
                break;
          default:
                break;
      }
  }
  // 寻找二叉树的根结点
  for(i = 1;i <= numberOfNode;i++)
  {
      if(true == biTree[index][i].isRootNode)
      {
          root = &biTree[index][i];
          break;
      }
  }
  return root;
}
 
/**
*  先序遍历二叉树
*  @param BinaryTreeNode * rootA  二叉树A的根结点
*  @param BinaryTreeNode * rootB  二叉树B的根结点
*  @return void
*/
void preOrderBinaryTree(BinaryTreeNode * rootA,BinaryTreeNode * rootB)
{
   if(NULL == rootA || NULL == rootB)
   {
       //当B树中的结点不为空，而A树的结点为NULL时，表示B树中的部分结点不在A树中，所以可以认为B不是A的子树
       if(NULL == rootA && NULL != rootB)
          ifBTreeIsSubOfATree = false;
       return;
   }
   else
   {
       if(rootA -> data == rootB -> data)
       {
           preOrderBinaryTree(rootA -> lChild,rootB -> lChild);    // 先序遍历左子树
           preOrderBinaryTree(rootA -> rChild,rootB -> rChild);    // 先序遍历右子树
       }
       else
       {
          ifBTreeIsSubOfATree = false;
          return;   // 如果两个值不相同的结点，则立即返回，无需再进行后面的遍历操作
       }
   }
}
 
/**
*  判断二叉树B是否为二叉树A的子树
*  @param BinaryTreeNode * rootA  二叉树A的根结点
*  @param BinaryTreeNode * rootB  二叉树B的根结点
*  @param int n  二叉树A的结点个数
*  @param int m  二叉树B的结点个数
*  @return 如果二叉树B是二叉树A的子树，则返回true;否则返回false
*/
bool isBTreeIsSubOfATree(BinaryTreeNode * rootA,BinaryTreeNode * rootB,int n,int m)
{
  int i;
  ifBTreeIsSubOfATree = false;
  // 遍历A树中的每一个结点，如果结点值与B树根结点的值相等则采用先序遍历进行比较
  for(i = 1;i <= n;i++)
  {
    if(biTree[0][i].data == rootB -> data)
    {
        ifBTreeIsSubOfATree = true;
        preOrderBinaryTree(&biTree[0][i],rootB);
        if(true == ifBTreeIsSubOfATree)
        {
            return true;
        }
    }
  }
  return ifBTreeIsSubOfATree;
}
 
int main()
{
    int n,m;
    BinaryTreeNode * rootA;    // 二叉树A的根结点
    BinaryTreeNode * rootB;    // 二叉树B的根结点
    while(EOF != scanf("%d%d",&n,&m))
    {
      rootA = createBinaryTree(n,0);
      rootB = createBinaryTree(m,1);
      if(NULL == rootA || NULL == rootB)
      {
          printf("NO\n");
      }
      else
      {
          ifBTreeIsSubOfATree = isBTreeIsSubOfATree(rootA,rootB,n,m);
          if(true == ifBTreeIsSubOfATree)
          {
              printf("YES\n");
          }
          else
          {
              printf("NO\n");
          }
      }
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46374453
****************************************************************/