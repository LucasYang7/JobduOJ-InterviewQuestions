#include<stdio.h>
 
/**
* 0 ^ 0 = 0,0 ^ 1 = 1,1 ^ 0 = 1,1 ^ 1 = 0
* 0 & 0 = 0,0 & 1 = 0,1 & 0 = 0,1 & 1 = 1
* a + b 的结果由加法结果和加法进位组成
* (1)用 a ^ b 表示a + b的结果jg
* (2)用 (a & b) << 1 表示a + b的进位jw
* (3)再让结果jg与进位jw重复(1)(2)步骤，直至进位jw为0时，可以得到最后的求和运算结果jg
* @param a  用户输入的第一个整数
* @param b  用户输入的第二个整数
* @return jg  返回用户输入的两个整数之和
*/
int additionWithoutPlus(int a,int b)
{
  int jg = a;       // 存放"加法"的结果
  int jw = b;       // 存放"加法"的进位
  int temp_a,temp_b; // temp_a存放临时的求和结果，temp_b存放临时的求和进位
  while(jw)
  {
      temp_a = jg;
      temp_b = jw;
      jg = temp_a ^ temp_b;          // 通过异或得到两个二进制数字的和
      jw = (temp_a & temp_b) << 1;   // 通过按位与再向左移动一位得到两个二进制数字相加得到的进位
  }
  return jg;
}
 
int main()
{
    int sum;
    int m,n;
    while(EOF != scanf("%d%d",&m,&n))
    {
        sum = additionWithoutPlus(m,n);
        printf("%d\n",sum);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46483109
****************************************************************/
