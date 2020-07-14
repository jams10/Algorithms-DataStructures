#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

int main(int argc, char *argv[])
{
  int n=0, tmp=0, count=0;
  scanf("%d",&n);

  std::vector<int> v;
  std::vector<int>::iterator upper;
  for(int i=0; i<n; i++)
  {
    scanf("%d",&tmp);
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());

  scanf("%d",&n);
  
  for(int i=0; i<n; i++)
  {
    scanf("%d",&tmp);
    upper = std::upper_bound(v.begin(), v.end(), tmp);
    printf("%d\n",(int)(upper-v.begin()));
    count=0;
  }
  return 0;
}

/*
  upper_bound : http://www.cplusplus.com/reference/algorithm/upper_bound/
                https://blockdmask.tistory.com/168
*/