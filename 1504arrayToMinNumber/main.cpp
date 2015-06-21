#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
char numberString[100][10];      // 用于存放整数的字符串
 
/**
* 输入m个整数
* @param m  输入整数的个数
* @return void
*/
void inputNumbers(int m)
{
  int i;
  for(i = 0;i < m;i++)
  {
     scanf("%s",numberString[i]);
  }
}
 
/**
* 比较字符串numberString1numberString2和numberString2numberString1的大小
* @param numberString1  第1个整数所对应的字符串
* @param numberString2  第2个整数所对应的字符串
* @return result 返回strcmp(numberString1numberString2,numberString2numberString1)的结果
*/
int stringCmp(char numberString1[],char numberString2[])
{
 int result = 0;
 char tempString1[20]; // 字符串numberString1numberString2
 char tempString2[20]; // 字符串numberString2numberString1
 strcpy(tempString1,numberString1);
 strcat(tempString1,numberString2);
 strcpy(tempString2,numberString2);
 strcat(tempString2,numberString1);
 result = strcmp(tempString1,tempString2);
 return result;
}
 
/**
* 将m个整数排列生成一个最小的整数
* @param m  整数的个数
* @return void
*/
void generateMinNumber(int m)
{
  int i,j;
  char temp[10];
  for(i = 0;i < m;i++)
  {
      for(j = i;j < m;j++)
      {
          if(stringCmp(numberString[i],numberString[j]) > 0)  // 自己写一个判断两个字符串大小的函数
          {
             // 交换numberString[i]和numberString[j]
             strcpy(temp,numberString[i]);               // temp = numberString[i];
             strcpy(numberString[i],numberString[j]);    // numberString[i] = numberString[j];
             strcpy(numberString[j],temp);               // numberString[j] = temp;
          }
      }
  }
}
 
/**
* 输出m个整数排成生成的最小的数
* @param m  整数的个数
* @return void
*/
void printMinNumber(int m)
{
 int i;
 for(i = 0;i < m;i++)
 {
   printf("%s",numberString[i]);
 }
 printf("\n");
}
 
int main()
{
    int m;
    while(EOF != scanf("%d",&m))
    {
       inputNumbers(m);
       generateMinNumber(m);
       printMinNumber(m);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46439863
****************************************************************/