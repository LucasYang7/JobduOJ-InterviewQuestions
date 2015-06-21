#include<stdio.h>
 
class Add
{
private:
  // n和sum都定义为静态成员变量，这样能够被所有类的实例对象所共享，也就能保存累加的中间结果
  static long long n;
  static long long sum;
 
public:
  // Add类的构造函数，在这里面做加法操作
  Add()
  {
     n++;
     sum += n;
  }
 
  // 因为n和sum是static类型变量，会保留上次运算所得到的结果，所以在做的累加运算前，要对n和sum进行复位操作
  static void reset()
  {
    n = 0;
    sum = 0;
  }
 
  // 返回累加和sum
  static long long getSum()
  {
     return sum;
  }
};
 
// 使用静态成员变量必须先进行初始化操作，否则程序运行时会报错
// C++类的静态成员变量初始化操作只能在类的外面进行
long long Add::n = 0;
long long Add::sum = 0;
 
/**
*  获取1到n的和，在Add构造函数中进行加法操作，申请n个Add对象，则会调用n次Add的构造函数
*  @param n  n为输入的数
*  @return long long sum  返回1~n的累加和,因为n的数据很大，所以sum用long long存储，防止溢出
*/
long long getSumOfOneToN(int n)
{
   long long sum;
   Add::reset();
   Add * add = new Add[n];      // 申请一个大小为n的Add对象数组，这样会调用n次Add类的构造函数
   delete [] add;               // 释放Add对象数组，new[]/delete[] 要配对使用
   sum = Add::getSum();
   return sum;
}
 
int main()
{
    int n;
    long long sum;
    while(EOF != scanf("%d",&n))
    {
        sum = getSumOfOneToN(n);
        printf("%lld\n",sum);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46482997
****************************************************************/
