// 额外开一个栈MINVALUESTACKTYPE来保存数据栈的最小元素序列，MINVALUESTACKTYPE的栈顶元素就是当前数据栈的最小元素。
#include<stdio.h>
#define MAX 1000000
#define DATASTACKTYPE 0               // 0表示数据栈
#define MINVALUESTACKTYPE 1           // 1表示最小值栈
 
//用于存放栈中的元素,其中StackElement[0][MAX]用于保存数据，StackElement[1][MAX]用于保存当前数据栈的最小值。
int StackElement[2][MAX];
 
// 自定义栈 因为StackElement数组很大，所以无法做为类的成员变量，否则会发生段错误
class Stack
{
 private:
  int top[2];                     // 栈顶指针数组 top[0]表示数据栈的栈顶指针 top[1]表示最小值栈的栈顶指针
  //int StackElement[2][MAX];     // 存放栈中的元素 因为数组太大，会报段错误...
 public:
  /**
  * 清空当前的栈
  * @param type  用来标记数据栈和最小值栈，type为0表示数据栈，type为1表示最小值栈
  * @return void
  */
  void clearStack(int type)
  {
      top[type] = -1;
  }
 
  /**
  * 判断栈是否为空
  * @param type  用来标记数据栈和最小值栈，type为0表示数据栈，type为1表示最小值栈
  * @return bool  如果栈为空则返回true,否则返回false
  */
  bool isEmpty(int type)
  {
      return (-1 == top[type]);
  }
 
  /**
  * 将元素k压入栈 因为栈顶指针指向栈顶元素，所以要先将栈顶指针加1，再进行赋值操作
  * @param type  用来标记数据栈和最小值栈，type为0表示数据栈，type为1表示最小值栈
  * @param k  被压入栈的元素
  * @return void
  */
  void push(int type,int k)
  {
      top[type]++;
      StackElement[type][top[type]] = k;
  }
 
  /**
  * 返回栈顶元素的值
  * @param type  用来标记数据栈和最小值栈，type为0表示数据栈，type为1表示最小值栈
  * @return int  返回栈的栈顶元素
  */
  int topElement(int type)
  {
      if(top[type] >= 0)
      return StackElement[type][top[type]];
  }
 
  /**
  * 弹出栈顶元素
  * @param type  用来标记数据栈和最小值栈，type为0表示数据栈，type为1表示最小值栈
  * @return void
  */
  void pop(int type)
  {
      if(top[type] >= 0)
      top[type]--;
  }
 
  /**
  * 获取最小值栈的栈顶元素，也就是当前数据栈的最小元素值
  * @return void
  */
  void minValueInStack()
  {
      if(false == isEmpty(MINVALUESTACKTYPE))
      {
          printf("%d\n",topElement(MINVALUESTACKTYPE));
      }
      else
      {
          printf("NULL\n");
      }
  }
};
 
int main()
{
    int n;
    int k;
    char Ci;
    Stack stack;
    while(EOF != scanf("%d",&n))
    {
      stack.clearStack(DATASTACKTYPE);         // 清除数据栈
      stack.clearStack(MINVALUESTACKTYPE);     // 清除最小值栈
      while(n--)
      {
          while(getchar() != '\n');            // 清除缓冲区中的多余字符,防止其被后面的scanf(Ci)读入
          scanf("%c",&Ci);
          switch(Ci)
          {
              case 's':
                  scanf("%d",&k);
                  stack.push(DATASTACKTYPE,k);   // 将k压入到数据栈中
                  if((true == stack.isEmpty(MINVALUESTACKTYPE)) || (k <= stack.topElement(MINVALUESTACKTYPE)))
                  {
                      // 如果最小值栈为空或者k小于等于最小值栈的栈顶元素，则将k压入到最小值栈中
                      stack.push(MINVALUESTACKTYPE,k);
                  }
                  stack.minValueInStack();
                  break;
              case 'o':
                  if(true == stack.isEmpty(DATASTACKTYPE))      // 若数据栈为空，则直接输出NULL
                     printf("NULL\n");
                  else
                  {
                     // 如果数据栈栈顶元素等于最小值栈栈顶元素，则弹出最小值栈的栈顶元素
                     if(stack.topElement(DATASTACKTYPE) == stack.topElement(MINVALUESTACKTYPE))
                     {
                        stack.pop(MINVALUESTACKTYPE);
                     }
                     stack.pop(DATASTACKTYPE);
                     stack.minValueInStack();
                  }
                  break;
              default:
                  break;
          }//switch
      }//while(n--)
    }//while(EOF != scanf("%d",&n))
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46408741
****************************************************************/