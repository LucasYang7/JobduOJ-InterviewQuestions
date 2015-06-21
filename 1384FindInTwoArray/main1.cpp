#include<cstdio>
#include<vector>
using namespace std;
 
/**
* 解法一:通过暴力法查看t是否在二维向量中
* @param input2Vec  输入的二维数组
* @param t  要查找的数字
* @return bool 如果t在二维数组中则返回true，否则返回false
*/
bool isFindInTwoArray(vector< vector <int> > input2Vec,int t)
{
  int i,j;
  for(i = 0;i < input2Vec.size();i++)
  {
      for(j = 0;j < input2Vec[i].size();j++)
      {
          if(t == input2Vec[i][j])
          return true;
      }
  }
  return false;
}
 
int main()
{
    int m,n,i,j;
    int number,t;
    vector <int> vec;
    vector <vector <int> >twoVec;         // 用于保存输入矩阵的二维向量
    while(EOF != scanf("%d%d%d",&m,&n,&t))
    {
        twoVec.clear();                           // 清空二维向量
        for(i = 0;i < m;i++)
        {
            vec.clear();                          // 清空一维向量
            for(j = 0;j < n;j++)
            {
                scanf("%d",&number);
                vec.push_back(number);
            }
            twoVec.push_back(vec);
        }
        if(true == isFindInTwoArray(twoVec,t))
        {
           printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46315419
****************************************************************/