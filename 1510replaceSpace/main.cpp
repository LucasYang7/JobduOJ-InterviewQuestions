#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAXLEN 1000000
 
/**
* 将一个字符串中的空格替换成对应的字符串
* @param inputString  输入的字符串
* @param lenOfInputString  输入字符串的长度
* @param replaceSpaceString  替换空格的字符串 也就是"%20"
* @param lenOfReplaceSpaceString  替换空格字符串的长度
* @return outputString  替换空格后生成的字符串
*/
char * replaceSpace(char * inputString,int lenOfInputString,char * replaceSpaceString,int lenOfReplaceSpaceString)
{
    //设置替换空格后所生成字符串长度为输入字符串的3倍 是为了考虑输入字符串中只包含空格这种特殊情况
    char * outputString = (char *)malloc((3 * lenOfInputString + 1)* sizeof(char));
    // i为遍历输入字符串的指针，j为遍历替换空格后所生成字符串的指针，t为遍历替换空格字符串"%20"的指针
    int i = 0,j = 0,t = 0;
    while(*(inputString + i) != '\0')
    {
         if(' ' != *(inputString + i))
         {
             *(outputString + j) = *(inputString + i);
             j++;
         }
         else
         {
             for(t = 0;t < lenOfReplaceSpaceString;t++)
             {
               *(outputString + j) = *(replaceSpaceString + t);
               j++;
             }
         }
         i++;
    }
    *(outputString + j) = '\0';
    return outputString;
}
 
int main()
{
   char inputString[MAXLEN];  // 用于存放输入的字符串
   char * outputString;       // 用于存放替换空格后所得到的字符串
   char * replaceSpaceString = "%20"; // 用于替换空格的字符串
   fgets(inputString,sizeof(inputString),stdin);
   outputString = replaceSpace(inputString,strlen(inputString),replaceSpaceString,strlen(replaceSpaceString));
   printf("%s\n",outputString);
   free(outputString);
   return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46315833
****************************************************************/