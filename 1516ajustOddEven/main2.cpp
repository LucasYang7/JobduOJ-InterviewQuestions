// 第二种算法:构建两个单链表,一个用来存放数组中奇数，一个用来存放数组中的偶数
// 然后先将所有奇数拷回到原数组中，再将所有偶数拷回到原数组中
// 算法的时间复杂度O(n)
#include<stdio.h>
#include<malloc.h>
#define MAX 1000000
 
// 创建链表结点
typedef struct LNode
{
 int data;             // 数据域
 LNode * next;         // 指针域
}Linklist;
 
/**
* 输出调整好奇偶顺序后的数组
* @param number[]  调整好奇偶顺序后的数组
* @param n  数组的长度
* @return void
*/
void printResult(int number[],int n)
{
  int i;
  for(i = 0;i < n - 1;i++)
  {
      printf("%d ",number[i]);
  }
  printf("%d\n",number[i]);
}
 
/**
* 调整数组中数字的奇偶顺序
* @param number[]  待调整奇偶顺序的数组
* @param n  数组的长度
* @return void
*/
void adjustOddEven(int number[],int n)
{
    int i;
    Linklist * s = NULL;     // s指向新构造的结点
    Linklist * oddNumber = (Linklist *)malloc(sizeof(Linklist));       // 用于存放奇数的链表
    Linklist * evenNumber = (Linklist *)malloc(sizeof(Linklist));      // 用于存放偶数的链表
    oddNumber -> next = NULL;
    evenNumber -> next = NULL;
    Linklist * p1 = oddNumber;    // p1始终指向奇数链表的最后一个结点
    Linklist * p2 = evenNumber;   // p2始终指向偶数链表的最后一个结点
    for(i = 0;i < n;i++)
    {
        s = (Linklist *)malloc(sizeof(Linklist));
        scanf("%d",&number[i]);
        if(1 == (number[i] & 1))      // 如果输入的数据是奇数，则插入到奇数链表的末尾
        {
          s -> data = number[i];
          s -> next = p1 -> next;
          p1 -> next = s;
          p1 = s;
        }
        else                     // 如果输入的数据是偶数，则插入到偶数链表的末尾
        {
          s -> data = number[i];
          s -> next = p2 -> next;
          p2 -> next = s;
          p2 = s;
        }
    }
    // 先将奇数链表中的元素全部放入到数组中，再将偶数链表中的元素全部放入数组中
    i = 0;
    p1 = oddNumber -> next;
    p2 = evenNumber -> next;
 
    while(p1 != NULL)
    {
        number[i] = p1 -> data;
        p1 = p1 -> next;
        i++;
    }
 
    while(p2 != NULL)
    {
        number[i] = p2 -> data;
        p2 = p2 -> next;
        i++;
    }
 
    printResult(number,n);
}
 
int main()
{
    int n;
    int number[MAX];
    scanf("%d",&n);
    adjustOddEven(number,n);
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46358275
****************************************************************/