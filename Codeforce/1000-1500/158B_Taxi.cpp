#include<iostream>
#include<vector>
#include<algorithm>

bool comp(int a, int b)
{
  return a > b;
}

int main(int argc, char *argv[])
{
  int n = 0, tmp = 0, count = 0;
  std::cin>>n;

  std::vector<int> v;
  
  for(int i=0; i<n; i++)
  {
    std::cin>>tmp;
    v.push_back(tmp);
  }

  sort(v.begin(), v.end(), comp);

  for(int i=0; i<n; i++)
  {
    if(v.at(i)==4)
    {
      count++;
    }
    else
    {
      for(int j=n-1; j>0; j--)
      {
        if(v.at(i) + v.at(j) <= 4)
        {
          v.at(i) += v.at(j);
          n--;
        }
        else if(v.at(i) + v.at(j) > 4)
        {
          break;
        }
        if(i==j)
        {
          break;
        }
      }
      count++; // solution code position (n==2, elements == 2,1)
    }
  }

  std::cout<<count;
  return 0;
}