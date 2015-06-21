#include<stdio.h>
#define MAX 10000
int sequence[MAX];             // 输入的序列
 
/**
* 判断序列是否为二叉搜索树的后序遍历序列
* @param n  序列的元素个数
* @return bool  如果序列是合法的二叉搜索树后续遍历序列，则返回true; 否则返回false。
*/
bool isPostTraverseofBinarySearchTree(int n)
{
  int i,j,t;
  int root;                    // 保存二叉搜索树的根结点
  for(i = 0;i < n;i++)
  {
      scanf("%d",&sequence[i]);
  }
  root = sequence[n - 1];
  j = 0;                       // 遍历题目所给后序遍历序列的起点
  t = n - 1;                   // 遍历题目所给后序遍历序列的终点
  while(j < t && sequence[j] < root)   // 遍历二叉搜索树的左子树,左子树中的所有元素都小于根结点
  {
      j++;
  }
  while(j < t && sequence[j] > root)   // 遍历二叉搜索树的右子树,右子树中的所有元素都大于根结点
  {
      j++;
  }
  if(j == t)        // 表示后序遍历序列满足{左子树，右子树，根结点}的要求，该后续遍历序列是合法的
      return true;
  else
      return false;
}
 
int main()
{
    int n;
    bool result;
    while(EOF != scanf("%d",&n))
    {
      result = isPostTraverseofBinarySearchTree(n);
      if(true == result)
         printf("Yes\n");
      else
         printf("No\n");
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46409745
****************************************************************/