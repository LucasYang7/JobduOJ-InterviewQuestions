#include<stdio.h>
 
/**
*  统计整型数对应的二进制数中1的个数
*  将数字右移，每进行一次移位就查看最低位的值是否为1，因为int为32bit,所以一共移位32次
*  @param n  待统计的整数
*  @return count  整数所对应二进制数的1的个数
*/
int countOneInBinary(int n)
{
    int count = 0;
    int rightestBit;            // 用于保存n对应二进制数字的最低位
    int i = 0;
    while(i < 32)
    {
        rightestBit = 1 & n;   // 用1与n进行按位相与，得到数字n二进制最低位的值
        count = count + rightestBit;
        n = n >> 1;
        i++;
    }
    return count;
}
 
int main()
{
     int T;
     int n;
     int count;
     scanf("%d",&T);
     while(T--)
     {
         scanf("%d",&n);
         count = countOneInBinary(n);
         printf("%d\n",count);
     }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46357233
****************************************************************/