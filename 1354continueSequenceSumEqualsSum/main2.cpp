// �ڶ��ֽⷨ
#include<stdio.h>
#include<math.h>
 
/**
* ��ӡ�͵���S����������
* @param begin  �������еĿ�ʼֵ
* @param end  �������е���ֵֹ
* @return void
*/
void printContinueSequence(int begin,int end)
{
    int i = begin;
    printf("%d",i);
    for(i = begin + 1;i <= end;i++)
    {
        printf(" %d",i);
    }
    printf("\n");
}
 
/**
* ��ȡ�͵���S����������
* @param S  �û������S
* @return numberOfSequence  �͵���S���������еĸ���
*/
int getContinueSequenceEqualsS(int S)
{
   int numberOfSequence = 0;
   int n;       // �͵���S���������еĳ���
   int a1;      // �͵���S���������еĵ�1��
   for(n = sqrt(2 * S); n >= 2; n--) // nԽ��a1ԽС�����n�ĳ�ʼֵΪsqrt(2 * S)������ֵΪ2
   {
     if((2 * S) % n == 0)  // ��֤2S / n������
     {
         if(0 == (2 * S / n - n + 1) % 2)  // ��֤a1������
         {
           a1 = (2 * S / n - n + 1) / 2;
           numberOfSequence++;
           printContinueSequence(a1,a1 + n - 1);
         }
     }
   }
   return numberOfSequence;
}
 
int main()
{
    int S;
    int number;
    while(EOF != scanf("%d",&S) && S >= 0)
    {
       number = getContinueSequenceEqualsS(S);
       if(0 == number)
       {
           printf("Pity!\n");
       }
       printf("#\n");
    }
    return 0;
}
 
/**************************************************************
���ⱨ�棺http://blog.csdn.net/pengyan0812/article/details/46472621
****************************************************************/