#include<stdio.h>
#define MAX 1000
int array[MAX][MAX];              // 定义二维数组
 
/**
* 解法二:对二维数组中的每一行依次进行二分查找
* @param array[][MAX]  输入的二维数组
* @param t  待查找的元素
* @param m  二维数组的行数
* @param n  二维数组的列数
* @return isFind 如果t在二维数组array中，则返回1，否则返回0。
*/
int isFindInTwoArray(int array[][MAX],int t,int m,int n)
{
 int i,j;
 int isFind = 0;                    // 用于标记是否已经找到t
 for(i = 0;i < m;i++)               // 对输入矩阵的每一行依次进行二分查找
 {
   int low = 0;
   int high = n - 1;
   int mid;
   while(low <= high)
   {
       mid = (low + high) / 2;
       if(t == array[i][mid])        // 表示已经在二维数组中找到了t
       {
           isFind = 1;
           return isFind;
       }
       else if(t > array[i][mid])     // 在[mid + 1,high]区间中继续进行二分查找
       {
           low = mid + 1;
       }
       else                           // 在[low,mid - 1]区间中继续进行二分查找
       {
           high = mid - 1;
       }
   }//while
 }//for
 return isFind;
}
 
int main()
{
    int m,n,i,j;
    int t;
    while(EOF != scanf("%d%d%d",&m,&n,&t))
    {
        for(i = 0;i < m;i++)
        {
            for(j = 0;j < n;j++)
            {
                scanf("%d",&array[i][j]);
            }
        }
        if(1 == isFindInTwoArray(array,t,m,n))
        {
           printf("Yes\n");
        }
        else
        {
           printf("No\n");
        }
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46315419
****************************************************************/