#include<stdio.h>
#include<string.h>
#define SENTENCElEN 50001             // 英文句子的长度
#define WOEDNUMBER 1201               // 单词数和两个单词中间的空格数目
#define WORDLEN 31                    // 单词的长度
 
char sentence[SENTENCElEN];
 
/**
* 翻转句子中的单词顺序
* @param sentence  输入的英语句子
* @param len  英语句子的长度
* @param words  保存单词和空格的二维数组
* @return void
*/
void overturnWordSequence(char sentence[],int len,char words[][WORDLEN])
{
  int i = 0;
  int count = 0;     // 统计单词的个数
  int letterIndexInWord = 0;  // 字符在单词中的位置
  while(i < len)
  {
      // 存放字符串中的单词和标点符号
      while(i < len && ' ' != sentence[i])
      {
          words[count][letterIndexInWord] = sentence[i];
          letterIndexInWord++;
          i++;
      }
 
      if(letterIndexInWord > 0)
      {
         words[count][letterIndexInWord] = '\0';
         count++;
         letterIndexInWord = 0;
      }
 
      // 存放字符串中的空格
      while(i < len && ' ' == sentence[i])
      {
          words[count][letterIndexInWord] = sentence[i];
          letterIndexInWord++;
          i++;
      }
 
      if(letterIndexInWord > 0)
      {
         words[count][letterIndexInWord] = '\0';
         count++;
         letterIndexInWord = 0;
      }
  }// while(i < len)
 
  // 逆序输出字符串中的单词和空格
  i = count - 1;
  while(i >= 0)
  {
      printf("%s",words[i]);
      i--;
  }
  printf("\n");
}
 
int main()
{
    char words[WOEDNUMBER][WORDLEN];
    int len;
    while(gets(sentence))
    {
        len = strlen(sentence);
        overturnWordSequence(sentence,len,words);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46472947
****************************************************************/