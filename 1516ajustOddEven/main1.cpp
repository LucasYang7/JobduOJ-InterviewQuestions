// 第一种算法:因为二路归并算法是稳定的，而且时间复杂度为O(logn*n)
// 所以采用模仿二路归并排序的算法，数据结构采用数组，归并算法采用非递归实现
#include<stdio.h>
#define MAX 1000000
int number[MAX];                  // 用于存放原始数据
int temp[MAX];                    // 用于模拟归并排序时所用的临时存储空间
 
/**
* 打印替换了奇偶后的数组
* @param n  数组的长度
* @return void
*/
void printResult(int n)
{
   int i;
   for(i = 0;i < n - 1;i++)
   {
     printf("%d ",number[i]);
   }
   printf("%d\n",number[i]);
}
 
/**
* 模仿归并排序 数据结构采用数组
* @param n  表示数组的长度
* @return void
*/
void getResultByMergeSort(int n)
{
   int k = 2;            // k表示进行一趟二路归并排序后，生成的子有序数组长度为k
   int i,j,t,s;
   int begin,middle,end; // 待排序的两个子序列为[begin,middle),[middle,end)
   while(1)
   {
       /*因为k表示进行一趟二路归并排序后生成的子有序数组长度,
       所以这里的条件不能是0 == n / k
       否则会遗漏掉最后一趟归并排序*/
       if(0 == (n * 2) / k)
            break;               // 表示二路归并排序完毕
       else
       {
         begin = 0;              // begin = 0表示新一趟归并排序的开始
         t = 0;                  // t是temp数组的下标
         while(begin < n)        // 如果begin >= n 则表示一趟归并排序完毕
         {
             end = (begin + k) < n?(begin + k):n;//当(begin + k) < n,也就是最后两组待排序列长度之和小于k时，end = n;
             /*注意middle = begin + k / 2,不是middle = (begin + end)/2;
             因为当(begin + k)>n时,(begin + end)/2 != (begin + begin + k)/2;*/
             middle = begin + k / 2;
             i = begin;          // i 是序列[begin,middle)的指针
             j = middle;         // j 是序列[middle,end)的指针
             while((1 == number[i] % 2) && (i < middle)) //将"有序"子序列[begin,middle)中的奇数全部拷入到临时数组中
             {
                temp[t++] = number[i++];
             }
             while((1 == number[j] % 2) && (j < end)) // 将"有序"子序列[middle,end)中的奇数全部拷入到临时数组中
             {
                 temp[t++] = number[j++];
             }
             while(i < middle)            // 将[begin,middle)中的偶数拷入到临时数组中
             {
                temp[t++] = number[i++];
             }
             while(j < end)              // 将[middle,end)中的偶数拷入到临时数组中
             {
                 temp[t++] = number[j++];
             }
             begin += k;     // 待数组[begin,begin + k)"排好序"后，紧接着就对数组[begin + k,begin + k + k)进行"排序"
         }//while(begin < n)
         // 每进行完一趟排序都要将临时数组中的数据拷贝到原始数组中
         for(s = 0;s < n;s++)
         {
             number[s] = temp[s];
         }
         /*每次经过一趟排序后，原始序列中的[0,k),[k,k+k),...[k*(m-1),end)等子序列内部是"有序"的
         采用二路归并，所以每次k的值都要乘以2*/
         k = 2 * k;
       }
   }
   printResult(n);
}
 
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        scanf("%d",&number[i]);
    }
    getResultByMergeSort(n);
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46358275
****************************************************************/
