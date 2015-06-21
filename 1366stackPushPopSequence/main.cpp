// 判断栈的压入，弹出序列是否合法
#include<stdio.h>
#include<stack>
using namespace std;
 
#define MAX 100000
int inStackSequence[MAX];         // 压入序列
int outStackSequence[MAX];        // 弹出序列
stack <int> dataStack;            // 用于记录压入和弹出操作的数据栈
 
/**
* 输入压入序列和弹出序列 二者的长度都为 n
* @param n  表示压入序列和弹出序列的长度
* @return void
*/
void inputinStackSequenceAndoutStackSequence(int n)
{
   int i;
   for(i = 0;i < n;i++)
      scanf("%d",&inStackSequence[i]);
   for(i = 0;i < n;i++)
      scanf("%d",&outStackSequence[i]);
}
 
/**
* 清空数据栈
* @return void
*/
void clearStack()
{
  while(false == dataStack.empty())
  {
      dataStack.pop();
  }
}
 
/**
* 模拟栈的压入和弹出过程。
* 在模拟完之后，如果栈为空，则说明入栈和出栈序列是合法的;
* 反之则说面入栈和出栈序列不合法。
* @param inStackSequence  压入序列
* @param outStackSequence  弹出序列
* @param inLen  压入序列的长度
* @param outLen  弹出序列的长度
* @return bool  如果弹出序列合法，则返回true;否则返回false
*/
bool isLegalOutStackSequence(int inStackSequence[],int outStackSequence[],int inLen,int outLen)
{
  bool isLegal;
  int indexForIn = 0;
  int indexForOut = 0;
  clearStack();   // 清空数据栈 dataStack
  while(indexForIn < inLen && indexForOut < outLen)
  {
   // 如果当前的入栈元素不等于当前的出栈元素，则将入栈元素依次压入到数据栈中
   do
   {
     dataStack.push(inStackSequence[indexForIn]);
   }while(indexForIn < inLen && inStackSequence[indexForIn++] != outStackSequence[indexForOut]);
   // 如果数据栈的栈顶元素等于当前的出栈元素，则依次弹出数据栈的栈顶元素
   while(false == dataStack.empty() && dataStack.top() == outStackSequence[indexForOut])
   {
       dataStack.pop();
       indexForOut++;
   }
  }//while
  isLegal = dataStack.empty();    // 如果数据栈为空，则说明出栈序列是合法的，反之则说明出栈序列不合法
  return isLegal;
}
 
int main()
{
    int n;
    bool isLegal;
    while(EOF != scanf("%d",&n))
    {
        inputinStackSequenceAndoutStackSequence(n);
        isLegal = isLegalOutStackSequence(inStackSequence,outStackSequence,n,n);
        if(true == isLegal)
          printf("Yes\n");
        else
          printf("No\n");
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46409259
****************************************************************/
