// 顺时针方向打印矩阵
#include<stdio.h>
#define MAX 1000
int matrix[MAX][MAX];
 
/**
* 输入矩阵
* @param m  矩阵的行数
* @param n  矩阵的列数
* @return void
*/
void inputMatrix(int m,int n)
{
   int i,j;
   for(i = 0;i < m;i++)
   {
       for(j = 0;j < n;j++)
       {
          scanf("%d",&matrix[i][j]);
       }
   }
   return;
}
 
/**
* 顺时针输出矩阵 注意最后一个元素后面也要输出空格
* @param m  矩阵的行数
* @param n  矩阵的列数
* @return void
*/
void clockwisePrintMatrix(int m,int n)
{
   int i,j;
   int up,down,left,right;              // 上,下,左,右 边界
   up = 0,down = m - 1;
   left = 0,right = n - 1;              // 从matrix[0][1]开始遍历
   while(1)
   {
    // 从左往右遍历
    i = up;
    for(j = left;j <= right;j++)
    {
       printf("%d ",matrix[i][j]);
    }
    if(up < down)
    {
      up++;            // 表示第up行的元素已经遍历完了
    }
    else               // 表示已经遍历到了最后一个元素
    {
       break;
    }
    // 从上往下遍历
    j = right;
    for(i = up;i <= down;i++)
    {
      printf("%d ",matrix[i][j]);
    }
    if(right > left)
    {
      right--;           // 表示第right列的元素已经遍历完了
    }
    else                 // 表示已经遍历到了最后一个元素
    {
      break;
    }
    // 从右往左遍历
    i = down;
    for(j = right;j >= left;j--)
    {
      printf("%d ",matrix[i][j]);
    }
    if(down > up)
    {
      down--;              // 表示第down行的元素已经遍历完了
    }
    else                   // 表示已经遍历到了最后一个元素
    {
       break;
    }
    // 从下往上遍历
    j = left;
    for(i = down;i >= up;i--)
    {
       printf("%d ",matrix[i][j]);
    }
    if(left < right)
    {
      left++;            // 表示第left列的元素已经遍历完了
    }
    else                 // 表示已经遍历到了最后一个元素
    {
       break;
    }
   }//while(1)
   printf("\n");
   return;
}
 
int main()
{
    int m,n;
    while(EOF != scanf("%d%d",&m,&n))
    {
        inputMatrix(m,n);
        clockwisePrintMatrix(m,n);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46374981
****************************************************************/