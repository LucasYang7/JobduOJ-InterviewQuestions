#include<stdio.h>
#include<malloc.h>
#define MAX 1001
 
// 定义链表结点结构
typedef struct LinkNode
{
  int data;
  LinkNode * next;                // 指向链表中的当前结点的下一个结点
  LinkNode * specialPoint;        // 特殊指针
}Linklist;
 
Linklist * LinkNodeAddress[MAX];  // 开一个指针数组，用于保存链表中各个的结点地址
 
/**
* 构造复杂链表
* @param n  复杂链表的结点个数
* @return head  复杂链表的头指针
*/
Linklist * createComplexLinklist(int n)
{
   Linklist * head = (Linklist *)malloc(sizeof(Linklist));   // 链表的头结点
   head -> data = 0;             // 将头结点的数据域赋值为0，head既当头结点，又当NULL
   head -> next = NULL;
   Linklist * p = head;          // p指针指向链表的最后一个结点
   Linklist * s = NULL;          // 新构造的链表结点
   int i;
   int data;
   int Ti;                       // 表示链表结点的另一个指针的指向
   // 构造链表结点的值和指向下一个结点的指针
   for(i = 1;i <= n;i++)
   {
     scanf("%d",&data);
     s = (Linklist *)malloc(sizeof(Linklist));
     s -> data = data;
     s -> next = p -> next;
     p -> next = s;             // 将s结点插入到链表末尾
     p = s;                     // p始终指向当前链表的最后一个结点
     LinkNodeAddress[i] = s;    // 将s结点的地址保存到链表结点地址数组中
   }
   // 构造链表结点的特殊指针值
   p = head -> next;
   for(i = 1;i <= n;i++)
   {
      scanf("%d",&Ti);
      if(0 != Ti)
      {
          p -> specialPoint = LinkNodeAddress[Ti];
      }
      else
      {
          p -> specialPoint = head;     // 如果Ti == 0，则将特殊指针指向头结点(此时头结点等价于NULL)
      }
      p = p -> next;
   }
   return head;
}
 
/**
*  打印复杂链表
*  @param head  复杂链表头指针
*  @return void
*/
void printComplexLinklist(Linklist * head)
{
    Linklist * p = head -> next;
    while(p != NULL)
    {
      printf("%d %d\n",p -> data,p -> specialPoint -> data);
      p = p -> next;
    }
}
 
int main()
{
    int n;
    Linklist * head = NULL;
    while(EOF != scanf("%d",&n))
    {
      head = createComplexLinklist(n);
      printComplexLinklist(head);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46423067
****************************************************************/
