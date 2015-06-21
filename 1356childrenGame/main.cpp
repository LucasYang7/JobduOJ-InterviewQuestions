#include<stdio.h>
int main()
{
    int n,m;
    int result;               // 约瑟夫环中最后剩下的数字
    int i;
    while(EOF != scanf("%d",&n))
    {
        if(0 == n)
           break;
        scanf("%d",&m);
        result = 0;             // 当n == 1时，result = 0;
        for(i = 2;i <= n;i++)
        {
            result = (result + m) % i;  // 利用递推公式求出当问题规模为i时的解，最后得出问题规模为n的解
        }
        printf("%d\n",result + 1);      // 因为题目中的孩子编号从1开始，所以最后的结果要加1
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46482553
****************************************************************/