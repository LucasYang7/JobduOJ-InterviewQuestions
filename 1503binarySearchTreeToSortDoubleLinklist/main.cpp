#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
#define MAX 3001
// 定义二叉树结点的结构
typedef struct Node
{
  int data;            // 数据域
  Node * lchild;       // 左子树指针
  Node * rchild;       // 右子树指针
  Node * pre;          // 中序遍历序列的前继指针
  Node * next;         // 中序遍历序列的后继指针
  bool isConstructLeftChild;    // 判断是否已经构造了结点的左孩子
  bool isConstructRightChild;   // 判断是否已经构造了结点的右孩子
}BinaryTreeNode;
 
BinaryTreeNode binaryTreeNode[MAX]; // 二叉树结点数组
BinaryTreeNode * lastVisitedinInOrderSequnce;    // 标记中序遍历过程中上一次被遍历的结点
char preOrderString[5 * MAX];       // 先序遍历字符串
int numberOfBinaryTreeNode;         // 二叉树的结点数目(包含了值为0的结点)
int preOrderSequence[MAX];          // 转换先序遍历字符串得到的整形数组
int indexOfPreOrderSequence;        // 先序遍历整形数组的下标
 
/**
*  将先序遍历字符串转化为对应的整形数组
*  @param char preOrderString[]  输入的先序遍历字符串
*  @param int preOrderStringLen  先序遍历序列字符串的长度
*  @return 二叉树的结点个数，注意：在这里0也算二叉树的结点
*/
int stringToIntArray(char preOrderString[],int preOrderStringLen)
{
   int i = 0;
   int indexForIntArray = 0;         // 整形数组的长度
   int nodeData;                     // 结点的数据
   while(i < preOrderStringLen)
   {
     nodeData = 0;
     while(preOrderString[i] >= '0' && preOrderString[i] <= '9')    // 从字符串中分隔出整数
     {
       nodeData = 10 * nodeData + preOrderString[i] - '0';
       i++;
     }
     preOrderSequence[indexForIntArray++] = nodeData;
     i++;       // 跳过字符串中的空格
   }
   return indexForIntArray;
}
 
/**
* 初始化二叉树中各个结点之间的关系，将先序遍历序列赋值给各个结点，
* 每个结点都看成是只有一个结点，左右子树都为NULL的二叉树
* @param int n  二叉树中的结点个数
* @return void
*/
void initBinaryTree(int n)
{
    int i;
    for(i = 0;i < n;i++)
    {
       binaryTreeNode[i].data = preOrderSequence[i];
       binaryTreeNode[i].isConstructLeftChild = false;
       binaryTreeNode[i].isConstructRightChild = false;
       binaryTreeNode[i].lchild = NULL;
       binaryTreeNode[i].rchild = NULL;
       binaryTreeNode[i].pre = NULL;
       binaryTreeNode[i].next = NULL;
    }
}
 
/**
*  根据先序遍历序列构造二叉树
*  @param BinaryTreeNode * root 表示当前二叉树的根结点
*  @param preOrderSequence  先序遍历整形数组
*  @param preOrderLen  先序遍历整形数组的长度
*  @return void
*/
void createBinaryTreeByPreOrder(BinaryTreeNode * root,int preOrderSequence[],int preOrderLen)
{
  if((indexOfPreOrderSequence + 1) < (preOrderLen - 1))
  {
    // 构造左子树
    do
    {
        if(binaryTreeNode[numberOfBinaryTreeNode + 1].data != 0)
        {
           root -> lchild = &binaryTreeNode[numberOfBinaryTreeNode + 1];
           numberOfBinaryTreeNode++;
           indexOfPreOrderSequence++;
           createBinaryTreeByPreOrder(root -> lchild,preOrderSequence,preOrderLen);
        }
        else     // 遇到0则当做NULL处理
        {
            root -> lchild = NULL;
            numberOfBinaryTreeNode++;
            indexOfPreOrderSequence++;
        }
        root -> isConstructLeftChild = true;
    }while(false == root -> isConstructLeftChild);
    // 构造右子树
    do
    {
        if(binaryTreeNode[numberOfBinaryTreeNode + 1].data != 0)
        {
          root -> rchild = &binaryTreeNode[numberOfBinaryTreeNode + 1];
          numberOfBinaryTreeNode++;
          indexOfPreOrderSequence++;
          createBinaryTreeByPreOrder(root -> rchild,preOrderSequence,preOrderLen);
        }
        else    // 遇到0则当做NULL处理
        {
            root -> rchild = NULL;
            numberOfBinaryTreeNode++;
            indexOfPreOrderSequence++;
        }
        root -> isConstructRightChild = true;
    }while(false == root -> isConstructRightChild);
  }
 
}// createBinaryTreeByPreOrder
 
/**
*  中序遍历二叉树排序树，根据中序遍历序列构造排好序的双向链表，这也是构造中序二叉线索树的过程
*  @param BinaryTreeNode * root  待遍历的二叉树排序树的根结点
*  @return void
*/
void createSortDuLinklistByInOrder(BinaryTreeNode * root)
{
  if(NULL == root)
     return ;
  else
  {
     createSortDuLinklistByInOrder(root -> lchild);
     root -> pre = lastVisitedinInOrderSequnce;  // 将root结点的pre指针指向中序遍历序列中的上一个被访问的结点
     if(NULL != lastVisitedinInOrderSequnce)
     {
         lastVisitedinInOrderSequnce -> next = root;  // 将root结点添加中序遍历上一个访问的结点后面
     }
     lastVisitedinInOrderSequnce = root;      // 将当前结点标记为最后访问的结点
     createSortDuLinklistByInOrder(root -> rchild);
  }
}
 
/**
*  遍历排好序的双向链表
*  @param int preOrderLen  先序遍历序列的长度(包括值为0的结点)
*  @return void
*/
void travelDoubleSortLinklist(int preOrderLen)
{
   int i;
   BinaryTreeNode * head = NULL;  // 排序双向链表的首元结点
   // 寻找双向链表的首元结点
   for(i = 0;i < preOrderLen;i++)
   {
       if(0 != binaryTreeNode[i].data)       //跳过值等于0的二叉树结点
       {
           //如果某个二叉树的结点无中序遍历前继结点，则可以证明该二叉树是中序遍历第一个遍历的结点
           //也就是二叉树排序树中值最小的结点，当然也就是排序双向链表中的第一个结点
           if(NULL == binaryTreeNode[i].pre)
           {
               head = &binaryTreeNode[i];
               break;
           }
       }
   }
   while(head != NULL)
   {
       printf("%d ",head -> data);
       head = head -> next;
   }
   printf("\n");
}
 
int main()
{
    int n;
    int preOrderStringLen;                 // 输入的先序遍历字符串长度
    int preOrderLen;                       // 先序遍历整形数组的长度
    BinaryTreeNode * root;                 // 二叉树的根结点
    while(EOF != scanf("%d\n",&n))
    {
       while(n--)
       {
        numberOfBinaryTreeNode = 0;   // 初始时二叉树的结点个数为0
        indexOfPreOrderSequence = 0;  // 指向先序遍历序列中的第0个元素
        gets(preOrderString);         // 输入先序遍历序列
        preOrderStringLen = strlen(preOrderString);
        preOrderLen = stringToIntArray(preOrderString,preOrderStringLen);   // 将先序遍历序列字符串转化为整形数组
        initBinaryTree(preOrderLen);   // 初始化二叉树中的各个结点之间的关系
        root = &binaryTreeNode[0];     // 因为是根据先序遍历构建的二叉树，所以根结点指针指向第0个二叉树结点
        createBinaryTreeByPreOrder(root,preOrderSequence,preOrderLen);
        lastVisitedinInOrderSequnce = NULL; // lastVisitedinInOrderSequnce的初始值赋为NULL
        createSortDuLinklistByInOrder(root);
        travelDoubleSortLinklist(preOrderLen);
       }
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46423241
****************************************************************/