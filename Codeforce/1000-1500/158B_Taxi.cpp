#include <iostream>
#include <algorithm>

bool comp(int a, int b)
{
  return a>b;
}

int main(int argc, char *argv[])
{
  int n = 0, sum = 0, count=0;
  std::cin>>n;

  int*p = new int[n];

  for(int i=0; i<n; i++)
  {
    std::cin>>p[i];
  }

  std::sort(p,p+n,comp);

  for(int i=0; i<n; i++)
  {
    //남은거 조건 체크 필요 ex) 1,1 남을시 어떻게 처리할 것인가?
    sum = p[i];
    for(int j=n-1; j>0; j--)
    {
      sum += p[j];
      if(sum <= 4)
      {
        n--;
      }
      else if(sum > 4) 
      { 
        count++;
        break; 
      }
      std::cout<<"i : "<<i<<" p[i] : "<<p[i]<<std::endl;
      std::cout<<"j : "<<j<<" p[j] : "<<p[j]<<std::endl;
    }
    sum = 0;
  }

  std::cout<<count;
  delete[]p;
  
  return 0;
}