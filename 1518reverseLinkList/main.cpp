// 反转单链表
#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
 
// 定义链表结点
typedef struct LNode
{
  int data;                  // 数据域
  LNode * next;              // 指针域
}Linklist;
 
/**
* 构造长度为n的单链表
* @param n  表示链表有n个结点
* @param head  链表的头指针
*/
Linklist * createLinklist(int n)
{
  Linklist * head = (Linklist *)malloc(sizeof(LNode));   // 构造链表头结点
  head -> next = NULL;
  Linklist * p = head; // p指针始终指向链表的最后一个结点
  int i;
  int data;
  for(i = 1;i <= n;i++)
  {
      scanf("%d",&data);
      Linklist * s = (Linklist *)malloc(sizeof(LNode));
      s -> data = data;
      s -> next = p -> next;  // 将s结点插入到p结点后面
      p -> next = s;
      p = s;                  // p始终指向当前链表的最后一个结点
  }
  return head;
}
 
/**
* 反转单链表。注意:对于空链表和长度为1的链表，直接返回头指针，不需要进行反转操作
* @param head  链表的头指针
* @param head  返回链表的头指针
*/
Linklist * reverseLinklist(Linklist * head)
{
    Linklist *pPre,*pCur,*pNext;
    pPre = NULL;           // pPre指向当前结点的前一个结点
    pCur = head -> next;   // pCur指向当前正在被处理的结点
    if(NULL == pCur)       // 空链表直接返回头指针，不需要反转
    {
       return head;
    }
    pNext = pCur -> next;  // pNext指向当前结点的下一个结点
    if(NULL == pNext)      // 对于只有1个元素的链表，直接返回头指针，不需要反转
    {
       return head;
    }
    while(pNext -> next != NULL)  // 当pNext -> next == NULL 时，表示pNext指向的是链表中的最后一个元素
    {
        pCur -> next = pPre; // 将当前结点的next指针指向当前结点的前一个结点
        pPre = pCur;         // pPre,pCur,pNext都向右移一个位置
        pCur = pNext;
        pNext = pNext -> next;
    }
    pCur -> next = pPre;
    pNext -> next = pCur;
    head -> next = pNext;   // 将head的next指针指向原链表中的最后一个结点
    return head;
}
 
/**
* 打印单链表
* @param head  单链表的头指针
* @return void
*/
void printLinklist(Linklist * head)
{
  Linklist * p = head -> next;         // p指向链表的首元结点
  if(NULL == p)
  {
       printf("NULL\n");
  }
  else
  {
      while(NULL != (p -> next))      // 输出链表中的前n-1个结点
      {
          printf("%d ",p -> data);
          p = p -> next;
      }
      printf("%d\n",p -> data);       // 输出链表的最后一个结点
  }
}
 
int main()
{
    int n;
    Linklist * head;
    while(EOF != scanf("%d",&n))
    {
        head = createLinklist(n);
        head = reverseLinklist(head);    // 反转链表
        printLinklist(head);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46373375
****************************************************************/