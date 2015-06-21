#include<stdio.h>
#include<string.h>
#define MAX 10
 
/**
*  获取字符串的全排列
*  @param char result[]  用于存放构造排列的结果
*  @param char inputString[]  用户输入的字符串
*  @param bool flag[]  用于标记字符串中的某个字符是否已经在全排列中
*  @param int k  表示前面已经有k - 1个字符在排列中，正在构造排列的第k个数字
*  @param int len  表示输入字符串的长度
*  @return void
*/
void getStringPermulation(char result[],char inputString[],bool flag[],int k,int len)
{
   int i,j;
   bool tempFlag[MAX];          // 在递归过程中用于临时保存flag数组
   char tempResult[MAX];        // 在递归过程中用于临时保存result数组
   // 临时保存标记数组
   for(i = 0;i < len;i++)
   {
       tempFlag[i] = flag[i];
       tempResult[i] = result[i];
   }
   // 递归到最后一层后打印结果
   if(k == len)
   {
      tempResult[k] = '\0';
      printf("%s\n",tempResult);
   }
   else
   {
      for(j = 0;j < len;j++)
      {
         if(false == tempFlag[j])
         {
             tempFlag[j] = true;
             tempResult[k] = inputString[j];
             getStringPermulation(tempResult,inputString,tempFlag,k + 1,len);
             // 调用完getStringPermulation后，tempFlag数组的值会发生改变，所以需要对tempFlag数组重新赋值
             for(i = 0;i < len;i++)
             {
                tempFlag[i] = flag[i];
             }
             // 处理aab这样的出现重复字符的情况
             while(j < len && inputString[j + 1] == inputString[j])
             {
                j++;
             }
         }
      }
   }
}
 
int main()
{
    char inputString[MAX];              // 用于存放输入的字符串
    char result[MAX];                   // 用于存放结果
    char tempChar;                      // 冒泡排序的两个字符进行交换时，用于临时保存待交换的字符
    bool flag[MAX];                     // 用于标记某个字符已经被访问过
    int i,j,len;                        // 输入字符串的长度
    while(EOF != scanf("%s",inputString))
    {
        strcpy(result,"");
        len = strlen(inputString);
        // 对inputString排序,inputString中的字符处于字典升序状态
        for(i = len - 1;i > 0;i--)
        {
            for(j = 0;j < i;j++)
            {
                if(inputString[j] > inputString[j + 1])
                {
                   tempChar = inputString[j];
                   inputString[j] = inputString[j + 1];
                   inputString[j + 1] = tempChar;
                }
            }
        }
        // 给flag数组赋初始值
        for(i = 0;i < len;i++)
        {
            flag[i] = false;
        }
        getStringPermulation(result,inputString,flag,0,len);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46423387
****************************************************************/