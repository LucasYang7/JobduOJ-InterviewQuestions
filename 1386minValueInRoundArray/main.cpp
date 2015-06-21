#include<stdio.h>
#define MAX 1000001
 
int array[MAX];
 
/**
* 通过遍历找到两个递增序列的交界处，第2个递增序列的首元素就是数组中的最小元素
* @param n  旋转数组的长度
* @return min  旋转数组中的最小值
*/
int findMinValueInRotateArray(int n)
{
    int i;
    int min = array[0];        // 如果序列中只有一个递增序列，那么array[0]就是最小元素
    for(i = 0;i < n - 1;i++)
    {
        if(array[i] > array[i + 1])
        {
            min = array[i + 1];
            break;
        }
    }
    return min;
}
 
int main()
{
    int i,n;
    int result;
    while(EOF != scanf("%d",&n))
    {
        for(i = 0;i < n;i++)
        {
            scanf("%d",&array[i]);
        }
        result = findMinValueInRotateArray(n);
        printf("%d\n",result);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46342001
****************************************************************/
