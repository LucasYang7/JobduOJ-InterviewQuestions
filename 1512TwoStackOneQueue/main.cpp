#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
 
/**
* 队列的入队元素直接压入s1栈,队列出队元素直接从s2栈弹出
* s1栈从栈底到栈顶依次保存队列的后半段,s2栈从栈顶到栈底依次保存队列的前半段
* 在执行出队操作时，只有当s2栈为空时，才将s1栈中的元素全部倒入s2栈中
* 这样就不会出现"倒来倒去"的现象
* @param n  代表队列操作的个数
* @return void
*/
void twoStackToOneQueue(int n)
{
 stack <int> s1;                   // s1的栈顶元素保存着队列的队尾元素
 stack <int> s2;                   // s2的栈顶元素保存着队列的队首元素
 int i = 0;
 int x;
 char operation[20];               // 记录操作
 while(i < n)
 {
     scanf("%s",operation);
     if(0 == strcmp(operation,"PUSH"))   // 将元素压入队尾 PUSH x
     {
        scanf("%d",&x);
        s1.push(x);                      // 执行入队操作
     }
     else                                // 将队首元素弹出 POP
     {
        if(true == s2.empty())           // 如果s2为空，则将s1中的元素全部弹入到s2中，否则直接跳过次语句块
        {
          while(true != s1.empty())
          {
              s2.push(s1.top());
              s1.pop();
          }
        }
 
        if(true != s2.empty())          // 如果s2不为空 则输出并弹出s2的栈顶元素
        {
            printf("%d\n",s2.top());
            s2.pop();
        }
 
        else                           // 如果s2为空，则输出-1
        {
            printf("-1\n");
        }
     }
     i++;
 }
}
 
int main()
{
    int n;
    scanf("%d",&n);
    twoStackToOneQueue(n);
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46327787
****************************************************************/