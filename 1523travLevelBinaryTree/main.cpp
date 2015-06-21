// 二叉树的层序遍历
#include<stdio.h>
#include<queue>
using namespace std;
#define MAX 1001
 
// 定义二叉树的结点
typedef struct Node
{
  bool isRoot;                   // 标记该结点是否为二叉树的根结点
  int data;                      // 数据域
  Node * lchild;                 // 左孩子
  Node * rchild;                 // 右孩子
}BiTreeNode;
 
// 定义二叉树中的各个结点
BiTreeNode biTreeNode[MAX];
 
/**
* 构造有n个结点的二叉树
* @param n  表示二叉树的结点个数
* @return root  返回二叉树的根结点
*/
BiTreeNode * createBinaryTree(int n)
{
  BiTreeNode * root = NULL;
  char Ci;
  int i;
  int data;          // 输入的二叉树结点的数据
  int leftChild;     // 二叉树结点的左孩子编号
  int rightChild;    // 二叉树结点的右孩子编号
  // (1)初始时各个结点都被看成是只有一个结点的二叉树
  for(i = 1;i <= n;i++)
  {
      scanf("%d",&data);
      biTreeNode[i].data = data;
      biTreeNode[i].lchild = NULL;
      biTreeNode[i].rchild = NULL;
      biTreeNode[i].isRoot = true;
  }
  // (2)构建各个结点的孩子
  for(i = 1;i <= n;i++)
  {
     while(getchar() != '\n');               // 清除前一个scanf留下的多余的字符
     scanf("%c",&Ci);
     switch(Ci)
     {
         case 'd':
               scanf("%d%d",&leftChild,&rightChild);
               biTreeNode[i].lchild = &biTreeNode[leftChild];
               biTreeNode[i].rchild = &biTreeNode[rightChild];
               biTreeNode[leftChild].isRoot = false;
               biTreeNode[rightChild].isRoot = false;
               break;
         case 'l':
               scanf("%d",&leftChild);
               biTreeNode[i].lchild = &biTreeNode[leftChild];
               biTreeNode[leftChild].isRoot = false;
               break;
         case 'r':
               scanf("%d",&rightChild);
               biTreeNode[i].rchild = &biTreeNode[rightChild];
               biTreeNode[rightChild].isRoot = false;
               break;
         case 'z':
               break;
         default:
               break;
     }//switch
  }//for
  //(3)寻找二叉树的根结点，如果某个结点没有父结点，则认为该结点是二叉树的根结点
  for(i = 1;i <= n;i++)
  {
      if(true == biTreeNode[i].isRoot)
      {
          root = &biTreeNode[i];
          break;
      }
  }
  return root;
}
 
/**
* 采用类似于广度优先遍历的方法来层序遍历二叉树
* @param root  二叉树的根结点
* @return void
*/
void travLevelBinaryTree(BiTreeNode * root)
{
   BiTreeNode * cur;              // 当前正在被遍历的二叉树结点
   queue <BiTreeNode *> q;
   q.push(root);                  // 将二叉树的根结点插入到队列末尾
   while(false == q.empty())
   {
    cur = q.front();
    q.pop();
    if(cur == root)
    {
       printf("%d",cur -> data);    // 输出当前结点的值
    }
    else
    {
       printf(" %d",cur -> data);    // 输出当前结点的值
    }
 
    if(NULL != cur -> lchild)     // 将当前结点的左孩子插入到队列末尾
    {
        q.push(cur -> lchild);
    }
    if(NULL != cur -> rchild)     // 将当前结点的右孩子插入到队列末尾
    {
        q.push(cur -> rchild);
    }
   }
   printf("\n");
}
 
int main()
{
    BiTreeNode * root;
    int n;
    while(EOF != scanf("%d",&n))
    {
        root = createBinaryTree(n);
        travLevelBinaryTree(root);             // 层序遍历二叉树
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46409541
****************************************************************/
