#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

int main(int argc, char *argv[])
{
  int n = 0, tmp = 0;
  std::vector<int> v1;
  std::vector<int> v2;
  std::vector<int> v3;

  std::cin>>n;

  for(int i=0; i<n; i++)
  {
    scanf("%d",&tmp);
    v1.push_back(tmp);
  }
  for(int i=0; i<n-1; i++)
  {
    scanf("%d",&tmp);
    v2.push_back(tmp);
  }
  for(int i=0; i<n-2; i++)
  {
    scanf("%d",&tmp);
    v3.push_back(tmp);
  }

  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  sort(v3.begin(),v3.end());

  for(int i=0; i<n; i++)
  {
    if(i==n-1)
    {
      std::cout<<v1.at(i)<<std::endl;
      break;
    }
    if(v1.at(i)!=v2.at(i))
    {
      std::cout<<v1.at(i)<<std::endl;
      break;
    }
  }

  for(int i=0; i<n-1; i++)
  {
    if(i==n-2)
    {
      std::cout<<v2.at(i)<<std::endl;
      break;
    }
    if(v2.at(i)!=v3.at(i))
    {
      std::cout<<v2.at(i)<<std::endl;
      break;
    }
  }

  return 0;
}