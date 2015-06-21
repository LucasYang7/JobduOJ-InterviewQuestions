#include<stdio.h>
#include<malloc.h>
 
// 构造链表结点
typedef struct LNode
{
  int data;       // 数据域
  LNode * next;   // 指针域
}LinkList;
 
/**
* 创建一个单链表
* @param n  表示单链表中结点数目
* @return head  单链表的头指针
*/
LinkList * createLinkList(int n)
{
    LinkList * head = (LinkList *)malloc(sizeof(LinkList));  // 构造链表的头结点
    head -> next = NULL;
    LinkList * p = head;        // p始终指向链表中的最后一个结点
    int i;
    int data;
    for(i = 1;i <= n;i++)
    {
      LinkList * s = (LinkList *)malloc(sizeof(LinkList));
      scanf("%d",&data);
      s -> data = data;
      s -> next = p -> next;
      p -> next = s;            // 将s结点插入到p结点的后面
      p = s;
    }
    return head;
}
 
/**
* 输出链表中倒数第k个结点
* 先用一个指针p1指向链表中的第k个结点;
* 然后让指针p2从头结点出发去"追赶"p1指针;
* 每"追赶"一次,p1和p2指针都向右移动一个位置
* 当p1指针指向链表中最后一个元素的下一个位置时,p2指向的就是当前链表中的倒数第k个结点
* @param head  链表的头指针
* @param k  该链表中倒数第k个结点
* @return void
*/
void printBackwordsNInLinklist(LinkList * head,int k)
{
  int i = 1;                          // 注意i的初始值是1，不是0
  LinkList * p1 = head;
  // 先将p1指针指向链表中的第k个结点
  while((p1 != NULL) &&(i <= k))
  {
      p1 = p1 -> next;
      i++;
  }
  if(NULL == p1)                    // 当 k > n(n为链表中的结点个数)时的情况
  {
      printf("NULL\n");
  }
  else
  {
      LinkList * p2 = head;  // p2指针从链表头结点开始去追赶p1指针
      while(p1 != NULL)
      {
          p1 = p1 -> next;
          p2 = p2 -> next;
      }
      if(NULL == p2)         // 当k == 0时的情况
      {
          printf("NULL\n");
      }
      else                   // 当p1指向链表的最后一个结点的next(p1 == NULL)时，p2刚好指向链表的倒数第k个结点
      {
          printf("%d\n",p2 -> data);
      }
  }
}
 
int main()
{
    int n,k;
    LinkList * head;
    while(EOF != scanf("%d%d",&n,&k))
    {
       head = createLinkList(n);
       printBackwordsNInLinklist(head,k);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46359085
****************************************************************/
