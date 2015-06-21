#include<stdio.h>
#include<malloc.h>
 
// 定义链表中的结点
typedef struct LNode
{
  int data;              // 数据域
  LNode * next;          // 指针域
}Linklist;
 
/**
* 构造长度为len的单链表
* @param len  链表中的元素个数
* @return head  返回单链表的头指针
*/
Linklist * createLinklist(int len)
{
   Linklist * head = (Linklist *)malloc(sizeof(Linklist));   // 创建头结点
   head -> next = NULL;
   Linklist * p = head;         // p始终指向链表中的最后一个结点
   Linklist * s = NULL;         // s指向当前构造的结点
   int i;
   int data;
   for(i = 1;i <= len;i++)
   {
       scanf("%d",&data);
       s = (Linklist *)malloc(sizeof(Linklist));
       s -> data = data;
       s -> next = p -> next;
       p -> next = s;           // 将s插入到p结点的后面
       p = s;                   // p指向s
   }
   return head;
}
 
/**
* 合并两个有序链表
* @param head1  有序链表head1的头指针
* @param head2  有序链表head2的头指针
* @return 返回合并后链表的头指针
*/
Linklist * mergeTwoOrderLinklist(Linklist * head1,Linklist * head2)
{
   Linklist * head3 = (Linklist *)malloc(sizeof(Linklist));  // 创建链表head3的头结点
   head3 -> next = NULL;
   Linklist * p1 = head1 -> next;  // p1始终指向链表head1中的最后一个结点
   Linklist * p2 = head2 -> next;  // p2始终指向链表head2中的最后一个结点
   Linklist * p3 = head3;          // p3始终指向链表head3中的最后一个结点
 
   // 当两个链表都不为空时，选择两个链表中较小的元素并入到链表head3中
   while((p1 != NULL) && (p2 != NULL))
   {
       if((p1 -> data) < (p2 -> data))
       {
           p3 -> next = p1;
           p1 = p1 -> next;
       }
       else
       {
           p3 -> next = p2;
           p2 = p2 -> next;
       }
       p3 = p3 -> next;
       p3 -> next = NULL;
   }
 
   // 将链表head1中的剩余结点全部并入到head3中
   if(NULL != p1)
   {
      p3 -> next = p1;
   }
 
   // 将链表head2中的剩余结点全部并入到head3中
   else
   {
      p3 -> next = p2;
   }
   return head3;
}
 
/**
* 打印单链表
* @param head  被打印链表的头指针
* @return void
*/
void printLinklist(Linklist * head)
{
   Linklist * p = head -> next;
   if(NULL == p)
   {
       printf("NULL\n");
   }
   else
   {
      while(p -> next != NULL)
      {
          printf("%d ",p -> data);
          p = p -> next;
      }
      printf("%d\n",p -> data);              // 输出链表的最后一个元素
   }
}
 
int main()
{
    int n,m;
    Linklist * head1;       // 第1个有序链表
    Linklist * head2;       // 第2个有序链表
    Linklist * head3;       // 合并后生成的链表
    while(EOF != scanf("%d%d",&n,&m))
    {
      head1 = createLinklist(n);
      head2 = createLinklist(m);
      head3 = mergeTwoOrderLinklist(head1,head2);
      printLinklist(head3);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46374159
****************************************************************/
