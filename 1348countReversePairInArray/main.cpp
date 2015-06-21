#include<stdio.h>
#define MAX 100001
int number[MAX];              // 整数数组
int temp[MAX];                // 合并过程中临时保存整数数组元素的数组
 
/**
* 输入数组
* @param n  数组的元素个数
* @return void
*/
void inputArray(int n)
{
  int i;
  for(i = 0;i < n;i++)
    scanf("%d",&number[i]);
}
 
/**
* 进行合并操作
* @param gap  合并操作后生成的有序数组的长度
* @param length  数组的总长度
* @return count  返回一趟归并排序过程中所统计到的逆序对的数目
*/
long long merge(int gap,int length)
{
  long long count = 0;    // 用于统计逆序对的数目
  int t = 0;              // 临时数组的下标
  int begin,middle,end;   // 将[begin,middle) 和 [middle,end)两个有序数组进行合并操作，合并后生成有序数组[begin,end)
  int i,j,s;
  begin = 0;
  while(begin < length)  // 如果begin >= length，则表示一趟归并排序完毕
  {
     /*当(begin + gap) < length,也就是最后两组待排序列长度之和小于gap时，end = length;*/
     end = (begin + gap) < length?(begin + gap):length;
     /*注意:因为经过之前的归并排序后，数组[begin,begin + gap / 2)和数组[begin + gap / 2,end)一定都是有序数组,
     所以middle = begin + gap / 2,不是middle = (begin + end)/2;
     因为当(begin + gap) > length时,end = length,此时(begin + end)/2 != (begin + begin + gap)/2;
     所以无法保证数组[begin,(begin + end) / 2)和数组[(begin + end) / 2,end)都是有序数组。*/
     middle = begin + gap / 2;
     i = begin;     // i是数组[begin,middle)中的指针
     j = middle;    // j是数组[middle,end)中的指针
     while(i < middle && j < end)
     {
        if(number[i] > number[j])
        {
            temp[t++] = number[j++];
            count += middle - i; //如果左边数组中还有剩余元素，则剩余数组number[i,middle)中的所有元素都大于number[j]
        }
        else
        {
            temp[t++] = number[i++];
        }
     }
     /*将[begin,middle)中的剩余元素拷入到temp数组中*/
     while(i < middle)
     {
        temp[t++] = number[i++];
     }
     /*将[middle,end)中的剩余元素拷入到temp数组中*/
     while(j < end)
     {
         temp[t++] = number[j++];
     }
     begin += gap;      // 对[begin,end) 数组排好序后，紧接着对[begin + gap,end + gap)数组进行排序
  }
  /* 一趟归并排序完成后，将temp数组拷回到整数数组number中 */
  for(s = 0;s < length;s++)
  {
     number[s] = temp[s];
  }
  return count;
}
 
/**
* 采用归并排序统计长度为n的数组中的逆序对的个数
* @param n  数组的长度
* @return count 数组中的逆序对个数
*/
long long countReversePair(int n)
{
  long long count = 0;
  int gap = 2;
  while(1)
  {
     if(0 == (n * 2) / gap)
        break;
     count += merge(gap,n);
     gap = 2 * gap;
  }
  return count;
}
 
int main()
{
    int n;
    /*用于统计逆序对的个数，注意因为数组最大为100000，所以逆序对最多有(100000 * 100000)/2，
    而这个数已经超出了int的表示范围，所以这里count要定义为long long类型*/
    long long count;
    while(EOF != scanf("%d",&n))
    {
       inputArray(n);
       count = countReversePair(n);
       printf("%lld\n",count);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46453507
****************************************************************/