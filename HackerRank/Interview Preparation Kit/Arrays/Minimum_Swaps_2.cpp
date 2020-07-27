#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int minimum_swap(vector<int> v)
{
  int count = 0, tmp = 0;
  vector<int> sorted_v = v;
  map<int,int> m;

  sort(sorted_v.begin(), sorted_v.end());
  for(int i=0; i<sorted_v.size(); i++)
  {
    m.insert(make_pair(sorted_v[i], i));
  }

  while(true)
  {
    for(int i=0; i<v.size(); i++)
    {
      if(v[i]!=sorted_v[i])
      {
        swap(v[i], v[m[v[i]]]);
        count++;
        break;
      }
      if(i==v.size()-1)
      {
        return count;
      }
    }
  }
}

int main()
{
  int n = 0, tmp = 0;
  vector<int> v;

  cin>>n;

  for(int i=0; i<n; i++)
  {
    cin>>tmp;
    v.push_back(tmp);
  }

  cout << minimum_swap(v);

  return 0;
}