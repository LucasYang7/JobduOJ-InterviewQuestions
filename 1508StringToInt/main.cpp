#include<stdio.h>
#include<string.h>
 
/**
* 将字符串转化为整数
* @param numberString  输入的字符串
* @param lenOfNumberString  输入字符串的长度
* @return void
*/
void stringToInt(char numberString[],int lenOfNumberString)
{
  int i,start;
  int sign;            // 表示符号位：正数为1，负数为-1
  int countOfNumber;   // 用于统计输入字符串中的数字个数
  int number;          // 转化字符串得到的整型数
  if(numberString[0] < '0' && numberString[0] > '9' && numberString[i] != '+' && numberString[i] != '-')
  {
     printf("My God\n");
  }
  else
  {
    start = 0;
    sign = 1;
    countOfNumber = 0;
    number = 0;
    // 如果前面有符号位，则对符号位进行处理
    if('-' == numberString[0] || '+' == numberString[0])
    {
         if('-' == numberString[0])
            sign = -1;
         start++;
    }
    // 将字符串中的数字转化为整数
    for(i = start;i < lenOfNumberString;i++)
    {
       if(numberString[i] >= '0' && numberString[i] <= '9')
       {
           number = 10 * number + (numberString[i] - '0');
           countOfNumber++;
       }
       else
       {
           break;
       }
    }
 
    if(i >= lenOfNumberString - 1 && countOfNumber > 0) // 表示输入的字符串是一个合法的整数
    {
       number = sign * number;
       printf("%d\n",number);
    }
    else                                                // 表示输入的字符串不是合法的整数
    {
       printf("My God\n");
    }
  }
}
 
int main()
{
    char numberString[1000];
    int lenOfNumberString;
    while(gets(numberString))
    {
        lenOfNumberString = strlen(numberString);
        stringToInt(numberString,lenOfNumberString);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46483303
****************************************************************/
