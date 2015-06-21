// 解法一:仔细分析二叉树的定义，就可以知道将原二叉树所有结点的左右子树进行对换即可得到二叉树的镜像
// 但是题目只要求输出二叉树镜像的前序遍历序列，所以只需要在前序遍历二叉树的时候将遍历顺序改为"中右左"即可
#include<stdio.h>
#define MAX 1001
 
// 定义二叉树的结点
typedef struct BNode
{
   bool isRootNode;       // 标记该结点是否为根结点
   int data;              // 数据域
   BNode * lchild;        // 左子树
   BNode * rchild;        // 右子树
}BinaryTreeNode;
 
BinaryTreeNode biTreeNode[MAX];      // 定义二叉树的结点数组
 
/**
* 构造有n个结点的二叉树
* @param n  表示二叉树的结点个数
* @return root  返回二叉树的根结点
*/
BinaryTreeNode * createBinaryTree(int n)
{
   BinaryTreeNode * root = NULL;     // root指向二叉树的根节点
   if(0 == n)                        // 对于空二叉树，直接返回NULL
        return root;
   char Ci;                          // Ci代表当前结点的孩子结点情况
   int i;
   int data;                         // 二叉树结点的数据域
   int leftChild,rightChild;         // 二叉树结点的左孩子和右孩子
   // 先构造各个结点，初始状态下，每个结点都看成是只有一个结点的二叉树
   for(i = 1;i <= n;i++)
   {
      scanf("%d",&data);
      biTreeNode[i].data = data;
      biTreeNode[i].lchild = NULL;
      biTreeNode[i].rchild = NULL;
      biTreeNode[i].isRootNode = true;
   }
   // 根据各个结点之间的链接关系构造二叉树
   for(i = 1;i <= n;i++)
   {
      char ch;
      while((ch = getchar()) != '\n');  //用getchar吃掉前面scanf输入的'\n'和该'\n'之前的多余字符
      scanf("%c",&Ci);
      switch(Ci)
      {
          case 'd':
               scanf("%d%d",&leftChild,&rightChild);
               biTreeNode[i].lchild = &biTreeNode[leftChild];
               biTreeNode[i].rchild = &biTreeNode[rightChild];
               biTreeNode[leftChild].isRootNode = false;       // 表示结点leftChild不是二叉树的根结点
               biTreeNode[rightChild].isRootNode = false;      // 表示结点rightChild不是二叉树的根结点
               break;
          case 'l':
               scanf("%d",&leftChild);
               biTreeNode[i].lchild = &biTreeNode[leftChild];
               biTreeNode[i].rchild = NULL;
               biTreeNode[leftChild].isRootNode = false;       // 表示结点leftChild不是二叉树的根结点
               break;
          case 'r':
               scanf("%d",&rightChild);
               biTreeNode[i].lchild = NULL;
               biTreeNode[i].rchild = &biTreeNode[rightChild];
               biTreeNode[rightChild].isRootNode = false;      // 表示结点rightChild不是二叉树的根结点
               break;
          case 'z':
               biTreeNode[i].lchild = NULL;
               biTreeNode[i].rchild = NULL;
               break;
          default:
               break;
      }//switch
   }//for
   // 如果某个结点不是任何结点的孩子结点，则该结点就是根结点
   for(i = 1;i <= n;i++)
   {
      if(true == biTreeNode[i].isRootNode)
      {
          root = &biTreeNode[i];                          // root指向根结点
          break;
      }
   }
   return root;
}
 
/**
* 按照"中右左"的顺序前序遍历二叉树就能得到二叉树镜像的前序遍历序列
* @param root  二叉树的根结点
* @return void
*/
void preOrderTraverseImage(BinaryTreeNode * root)
{
   if(NULL == root)
   return;
   printf(" %d",root -> data);
   preOrderTraverseImage(root -> rchild);
   preOrderTraverseImage(root -> lchild);
}
 
int main()
{
    int n;
    BinaryTreeNode * root;
    while(EOF != scanf("%d",&n))
    {
        root = createBinaryTree(n);
        if(NULL == root)
        {
           printf("NULL\n");
        }
 
        else
        {
           printf("%d",root -> data);
           preOrderTraverseImage(root -> rchild);
           preOrderTraverseImage(root -> lchild);
           printf("\n");
        }
    }
    return 0;
}
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46374817
****************************************************************/