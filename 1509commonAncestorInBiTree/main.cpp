#include<stdio.h>
#include<malloc.h>
#include<vector>
using namespace std;
 
// 定义二叉树的结点
typedef struct Node
{
   int data;             // 数据域
   Node * lChild;        // 左孩子
   Node * rChild;        // 右孩子
}BinaryTreeNode;
 
vector <int> preOrderSequence;   // 用于保存二叉树的先序遍历序列
 
/**
* 根据先序遍历序列构造二叉树
* @return 所构二叉树的根结点
*/
BinaryTreeNode * createBinaryTreeByPreOrder()
{
  int data;
  BinaryTreeNode * root = NULL;
  scanf("%d",&data);
  if(0 != data)
  {
      preOrderSequence.push_back(data);
      root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
      root -> data = data;
      root -> lChild = createBinaryTreeByPreOrder();   // 递归构造左子树
      root -> rChild = createBinaryTreeByPreOrder();   // 递归构造右子树
  }
  return root;
}
 
/**
* 从根结点从上自下寻找两个结点的最低公共祖先
* @param BianaryTreeNode * root  二叉树的根结点
* @param int m1  输入的结点m1
* @param int m2  输入的结点m2
* @return 返回m1和m2最低公共祖先结点，如果二者不存在最低公共祖先结点，则返回NULL
*/
BinaryTreeNode * findLatestCommonAncestor(BinaryTreeNode * root,int m1,int m2)
{
  if(NULL == root)
     return NULL;
  else
  {
     BinaryTreeNode * commonAncestor = NULL;    // commonAncestor指向m1和m2的最低公共祖先结点
     int rootNodeData = root -> data;           // 当前二叉树根结点的值
     // 如果m1是m2的祖先结点，则二者的最低公共祖先是m1;如果m2是m1的祖先结点，则二者的最低公共祖先是m2。
     if(rootNodeData == m1 || rootNodeData == m2)
     {
        commonAncestor = root;
     }
     else
     {
        //lChildCommonAncestor表示最低公共祖先出现在左子树中,rChildCommonAncestor表示最低公共祖先出现在右子树中
        BinaryTreeNode * lChildCommonAncestor = findLatestCommonAncestor(root -> lChild,m1,m2);
        BinaryTreeNode * rChildCommonAncestor = findLatestCommonAncestor(root -> rChild,m1,m2);
        //如果lChildCommonAncestor和rChildCommonAncestor都不为NULL
        //则说明m1,m2分别出现在root的左右子树中，此时root为m1和m2的最低公共祖先结点
        if(NULL != lChildCommonAncestor && NULL != rChildCommonAncestor)
        {
            commonAncestor = root;
        }
        else
        {
            if(NULL != lChildCommonAncestor) // m1和m2都出现在root的左子树中，lChildCommonAncestor是它们的最低公共祖先结点
            {
                commonAncestor = lChildCommonAncestor;
            }
            if(NULL != rChildCommonAncestor) // m1和m2都出现在root的右子树中，rChildCommonAncestor是它们的最低公共祖先结点
            {
                commonAncestor = rChildCommonAncestor;
            }
        }
     }
     return commonAncestor;
  }
 
}
 
/**
* 通过后序遍历释放二叉树中的所有结点
* @param BinaryTreeNode * root  二叉树的根结点
* @return void
*/
void deleteBinaryTreeByPostOrder(BinaryTreeNode * root)
{
   if(NULL == root)
      return;
   else
   {
       deleteBinaryTreeByPostOrder(root -> lChild);
       deleteBinaryTreeByPostOrder(root -> rChild);
       //printf("%d ",root -> data);
       free(root);
       root = NULL;
   }
}
 
int main()
{
    BinaryTreeNode * root;            // 二叉树的根结点
    BinaryTreeNode * commonAncestor;  // 最低公共祖先结点
    int i,n;
    int m1,m2;
    bool isM1inBinaryTree,isM2inBinaryTree;
    scanf("%d",&n);
    while(n--)
    {
        preOrderSequence.clear();
        root = createBinaryTreeByPreOrder();
        scanf("%d%d",&m1,&m2);
        isM1inBinaryTree = false;
        isM2inBinaryTree = false;
        // 判断m1和m2是否都在二叉树中
        for(i = 0;i < preOrderSequence.size();i++)
        {
            if(preOrderSequence[i] == m1)
            {
                isM1inBinaryTree = true;
            }
            if(preOrderSequence[i] == m2)
            {
                isM2inBinaryTree = true;
            }
        }
        if(isM1inBinaryTree && isM2inBinaryTree)
        {
           commonAncestor = findLatestCommonAncestor(root,m1,m2);
           if(NULL != commonAncestor)
           {
               printf("%d\n",commonAncestor -> data);
           }
           else
           {
               printf("My God\n");
           }
        }
        else
        {
            printf("My God\n");
        }
        deleteBinaryTreeByPostOrder(root);
    }
    return 0;
}
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46490771
****************************************************************/