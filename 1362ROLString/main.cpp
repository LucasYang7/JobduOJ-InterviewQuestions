#include<stdio.h>
#include<string.h>
#define MAX 1001
 
/**
* 左循环移动字符串
* @param S 待旋转的字符串
* @param K 旋转的位数
* @param len 字符串的长度
* @return void
*/
void ROLString(char S[],int K,int len)
{
   int i;
   int index = K % len;    // 旋转后得到字符串的起始位置
   char ROLS[MAX];         // 用于存放旋转后所得到的字符串
   strcpy(ROLS,S + index); // 将S[index, ... ,len - 1]拷贝到ROLS中
   S[index] = '\0';        // 截取S字符串得到子串S[0, ... ,index - 1]
   strcat(ROLS,S);         // 将字符串S[0, ... ,index - 1]连接到字符串ROLS的后面
   printf("%s\n",ROLS);
}
 
int main()
{
    char S[MAX];
    int K;
    int len;
    while(EOF != scanf("%s",S))
    {
        len = strlen(S);
        scanf("%d",&K);
        ROLString(S,K,len);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46473211
****************************************************************/
