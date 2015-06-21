#include<stdio.h>
#include<malloc.h>
#include<stack>
using namespace std;
 
// 定义链表结点
typedef struct LinkNode
{
  int data;              // 数据域
  LinkNode * next;       // 指针域
}LinkList;
 
/**
* 构建单链表
* @return head 单链表的头指针
*/
LinkList * createLinkList()
{
   LinkList * head = (LinkList *)malloc(sizeof(LinkList));  // 构造头结点
   head -> next = NULL;
   LinkList * p = head;      // p是遍历指针
   int number;               // 输入数字
   while(1)
   {
       scanf("%d",&number);
       if(-1 == number)
           break;
       else                          // 在链表尾部插入元素
       {
           LinkList * s = (LinkList *)malloc(sizeof(LinkList));
           s -> data = number;
           s -> next = NULL;
           p -> next = s;
           p = s;                   // p始终指向链表中的最后一个结点
       }
   }
   return head;
}
 
/**
* 从头到尾遍历链表，则将链表的元素保存到栈中，然后逆序打印链表的元素
* @param head  链表的头指针
* @return void
*/
void printLinklistFromTailToHead(LinkList * head)
{
   stack <int> saveStack;
   LinkList * p = head -> next;
   while(p != NULL)
   {
       saveStack.push(p -> data);         // 将元素压入栈中
       p = p -> next;
   }
   // 依次输出栈中的元素
   while(!saveStack.empty())
   {
       printf("%d\n",saveStack.top());
       saveStack.pop();
   }
}
 
int main()
{
    LinkList * head = createLinkList();   // 构造链表
    printLinklistFromTailToHead(head);
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46325343
****************************************************************/