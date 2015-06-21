#include<stdio.h>
#include<malloc.h>
#include<stack>
using namespace std;
 
// 定义单链表结点的结构
typedef struct Node
{
   int data;
   Node * next;
}Linklist;
 
/**
* 创建单链表
* @param n  单链表的结点数目
* @return head  返回链表的头指针
*/
Linklist * createLinklist(int n)
{
    Linklist * head = (Linklist *)malloc(sizeof(Linklist));
    head -> next = NULL;
    Linklist * p = head;               // p指针始终指向链表的最后一个结点
    Linklist * s;                      // s指针指向新构造的链表结点
    int i;
    int data;
    for(i = 1;i <= n;i++)
    {
        scanf("%d",&data);
        s = (Linklist *)malloc(sizeof(Linklist));
        s -> data = data;
        s -> next = p -> next;
        p -> next = s;          // 将s插入到p结点的后面
        p = s;                  // p指针指向当前链表的最后一个结点
    }
    return head;
}
 
/**
* 将两个链表按照尾部对齐，然后再从头到尾依次进行比较找出第一个公共结点
* @param linkhead1  链表1的头指针
* @param linkhead2  链表2的头指针
* @param m  链表1的结点个数
* @param n  链表2的结点个数
* @param commonNode  用于存放两个链表的公共结点
* @return bool  如果两个链表有公共结点，则返回true，否则返回false
*/
bool findCommonNode(Linklist * linkhead1,Linklist * linkhead2,int m,int n,int & commonNode)
{
   bool isFind = false;
   int gapLength;               // 两个链表之间的长度差
   // 对齐两个链表
   if(m > n)
   {
      gapLength  = m - n;
      while(gapLength--)
      {
          linkhead1 = linkhead1 -> next;
      }
   }
   else
   {
      gapLength = n - m;
      while(gapLength--)
      {
          linkhead2 = linkhead2 -> next;
      }
   }
   while(linkhead1 != NULL && linkhead2 != NULL)
   {
       if(linkhead1 -> data == linkhead2 -> data)
       {
           isFind = true;
           commonNode = linkhead1 -> data;
           break;
       }
       else
       {
           linkhead1 = linkhead1 -> next;
           linkhead2 = linkhead2 -> next;
       }
   }
   return isFind;
}
 
int main()
{
    bool isFind;
    int m,n;
    int commonNode;
    Linklist * linkhead1;
    Linklist * linkhead2;
    while(EOF != scanf("%d%d",&m,&n))
    {
       linkhead1 = createLinklist(m);
       linkhead2 = createLinklist(n);
       isFind = findCommonNode(linkhead1->next,linkhead2->next,m,n,commonNode);    // 传入两个链表的首元结点和各自的长度
       if(true == isFind)
            printf("%d\n",commonNode);
       else
            printf("My God\n");
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46453989
****************************************************************/