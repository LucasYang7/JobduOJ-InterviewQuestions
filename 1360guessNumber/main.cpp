#include<stdio.h>
#include<math.h>
#define N 11                  // N表示骰子数的最大值
#define M 9                   // M表示单个骰子点数的最大值
#define MAX (M * N)           // MAX表示N个骰子点数和的最大值
 
double dicePointTimes[N][MAX];    //保存每种骰子点数出现的次数，dicePointTimes[i][j]表示i个骰子点数和为j的次数
double dicePointProbability[MAX]; //每个骰子点数出现的概率
bool isDicePointSelected[MAX];    //标记排序过程中某个骰子点数是否已经被选择过
 
/**
* 初始化每个点数之和的出现次数
* @param n  表示骰子的数目
* @param m  表示每个骰子的点数
* @return void
*/
void initDicePointTimes(int n,int m)
{
  int i,j;
  for(i = 1;i <= n;i++)
  {
      for(j = 1;j <= n * m;j++)
      {
          dicePointTimes[i][j] = 0;
      }
  }
}
 
/**
* 统计n个m点的骰子的每种点数之和所对应的出现次数
* @param n  表示骰子的数目
* @param m  表示每个骰子的点数
* @return void
*/
void getDicePointTimes(int n,int m)
{
  int i,j,t;
  initDicePointTimes(n,m);
  // 第1个骰子各个点数出现的次数都是1
  for(i = 1; i <= m;i++)
  {
      dicePointTimes[1][i] = 1;
  }
  // 依次添加第i(2 <= i <= n)个后，所得到的骰子点数和的出现次数
  for(i = 2; i <= n;i++)
  {
      for(j = i;j <= i * m;j++)  // j表示i个骰子点数和，j的范围是[i,i * m]
      {
          // dicePointTimes[i][j] = dicePointTimes[i - 1][j - m] + ... + dicePointTimes[i - 1][j - 1]
          for(t = j - m;t <= j - 1;t++)
          {
              if(t >= 1)  // 防止数组越界，因为骰子点数最小是1，所以t >= 1
                dicePointTimes[i][j] += dicePointTimes[i - 1][t];
          }
      }
  }
}
 
/**
* 统计每个骰子点数和出现的概率
* @param n  表示骰子的数目
* @param m  表示每个骰子的点数
* @return void
*/
void getDicePointProbability(int n,int m)
{
   int i;
   double totalDicePointTimes;         // 表示n个点数为m的骰子所有点数和出现的总次数
   totalDicePointTimes = pow(m,n);     // n个点数为m的骰子所有点数之和出现的总次数为 m ^ n
   for(i = n; i <= n * m;i++)          // n个点数为m的骰子的点数之和范围是[n,n * m]
   {
      dicePointProbability[i] = dicePointTimes[n][i] / totalDicePointTimes;
      dicePointProbability[i] = ((int)(100 * dicePointProbability[i] + 0.5)) / 100.0; //根据题目要求要对概率值按4舍5入要求保留2位小数
   }
}
 
/**
* 取出3个出现概率最大的点数和
* @param n  表示骰子的数目
* @param m  表示每个骰子的点数
* @return void
*/
void guessNumber(int n,int m)
{
  int i,j;
  double maxDicePointProbability;   // 用于某次选择过程中保存最大的骰子点数之和出现的最大概率
  int dicePoint;                    // 每次选择出来的骰子点数
  getDicePointProbability(n,m);
  for(i = n;i <= n * m;i++)
  {
      isDicePointSelected[i] = false;
  }
  // 选出3个出现概率最大的骰子点数之和
  for(i = 1;i <= 3;i++)
  {
    maxDicePointProbability = -1;
    for(j = n;j <= n * m;j++)
    {
      if(false == isDicePointSelected[j] && dicePointProbability[j] > maxDicePointProbability)
      {
          maxDicePointProbability = dicePointProbability[j];
          dicePoint = j;
      }
    }
    isDicePointSelected[dicePoint] = true;
    printf("%d %.2lf\n",dicePoint,dicePointProbability[dicePoint]);
  }
}
 
int main()
{
    int n,m;
    int nullLine = 0;         // 用于控制是否在数据末尾输出空行
    while(EOF != scanf("%d",&n) && 0 != n)
    {
        scanf("%d",&m);
        getDicePointTimes(n,m);
        getDicePointProbability(n,m);
        if(0 != nullLine)
           printf("\n");
        guessNumber(n,m);
        nullLine++;
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46473525
****************************************************************/
