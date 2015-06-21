// 利用堆排序选择数组中最小的K个数
#include<stdio.h>
#define MAX 200001
 
int number[MAX];
 
/**
* 输入n个整数，数组下标从1开始，若根结点为root，则其左孩子为2 * root，右孩子为2 * root + 1。
* @param n  数组的元素个数
* @return void
*/
void inputNNumber(int n)
{
  int i;
  for(i = 1;i <= n;i++)
     scanf("%d",&number[i]);
}
 
/**
* 打印最小的k个整数
* @param n  表示数组的长度
* @param k  表示需要输出最小元素的个数
* @return void
*/
void printNMinNumber(int n,int k)
{
  int i;
  printf("%d",number[n]);
  for(i = n - 1;i > n - k;i--)
     printf(" %d",number[i]);
  printf("\n");
}
 
/**
* 交换两个数
* @param a  整数a的地址
* @param b  整数b的地址
* @return void
*/
void swap(int * a,int * b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
 
/**
* 调整生成小顶堆
* @param root  待调整堆的根结点
* @param n  待调整堆的元素个数
* @return void
*/
void adjustMinHeap(int root,int n)
{
   int min_index = root;
   int leftChild;           // 小顶堆的左孩子结点
   int rightChild;          // 小顶堆的右孩子结点
   // 挑选出root结点,root结点的左孩子,root结点的右孩子这3个结点中的最小值做为小顶堆的根结点
   // 调整后可能会破坏子小顶堆的结构，所以继续调整子堆的结构以使其满足小顶堆结构
   while(min_index <= n)
   {
     min_index = root;
     leftChild = 2 * root;
     rightChild = 2 * root + 1;
     if(leftChild <= n)  // 将根结点与左孩子进行比较,必须满足leftChild <= n这个条件，否则访问number[leftChild]会发生runtime error错误
     {
        if(number[leftChild] < number[min_index])
           min_index = leftChild;
     }
     if(rightChild <= n) // 将根结点与右孩子进行比较,必须满足rightChild <= n这个条件，否则访问number[rightChild]会发生runtime error错误
     {
        if(number[rightChild] < number[min_index])
           min_index = rightChild;
     }
     if(min_index != root)
     {
       swap(&number[root],&number[min_index]);
       root = min_index;                       // 继续调整以min_index为根结点的子堆
     }
     else                                      // 表明小顶堆已经调整好了
     {
         break;
     }
   } //while
}
 
/**
* 通过堆排序找出最小的k个元素
* @param n  堆中元素的个数
* @param k  找出堆中最小元素的个数
* @return void
*/
void heapSort(int n,int k)
{
  int i;
  // 从最后一个非叶子结点开始自下而上构建初始的小顶堆
  for(i = n / 2;i >= 1;i--)       // n / 2为最后一个非叶子结点
  {
    adjustMinHeap(i,n);
  }
  // 依次挑选出最小的k个元素
  for(i = n;i > n - k;i--)
  {
    swap(&number[1],&number[i]);    // 将堆的最后一个元素与第一个元素进行交换
    // 因为number[i]已经在排好序的序列中，所以将其剔除出堆
    // 再从剩余堆number[1,i-1]的堆顶元素开始自上而下重新调整小顶堆的堆结构
    adjustMinHeap(1,i - 1);
  }
  printNMinNumber(n,k);
}
 
int main()
{
  int n,k;
  while(EOF != scanf("%d%d",&n,&k))
  {
     inputNNumber(n);
     heapSort(n,k);
  }
  return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46424437
****************************************************************/