#include <iostream>
#include <algorithm>
#include <vector>

bool comp(int a, int b)
{
  return a>b;
}

int main(int argc, char *argv[])
{
  int n = 0, tmp = 0, count = 0;
  std::cin>>n;

  std::vector<int> v;
  std::vector<int>::iterator iter;

  for(int i=0; i<n; i++)
  {
    std::cin>>tmp;
    v.push_back(tmp);
  }

  for(int i=0; i<v.size() i++)
  {
    for(int j=0; j<v.size(); j++)
    {
      if(v.at(j))
    }
  }

  std::cout<<count;
  
  return 0;
}