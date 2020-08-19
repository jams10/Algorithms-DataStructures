#include<iostream>
#include<string>
#include<map>

using namespace std;

void checkAnagram(const string& s, const multimap<char,int>& m);

int main()
{
  int q = 0;
  string s;

  multimap<char,int>m;

  for(int i = 97; i < 123; i++)
  {
    m.insert(make_pair(char(i), i));
  }

  std::cin>>q;
  
  for(int i = 0; i < q; i++)
  {
    cin>>s;
    checkAnagram(s,m);
  }

  return 0;
}

void checkAnagram(const string& s, const multimap<char,int>& m)
{
  int count = 0, sum1 = 0, sum2 = 0;
  char c;

  for(int len = 1; len < s.length(); len++)
  {
    cout<<"len : "<<len<<endl;
    for(int i = 0; i <= s.length() - len; i++)
    {
      for(int j = i; j < len; j++)
      {
        sum1 += (int)s[j];
        cout<<"sum1 : "<<sum1<<endl;
      }
      for(int l = i + 1; l <= s.length() - len; l++)
      {
        for(int k = l; k <= len; k++)
        {
          sum2 += (int)s[k];
          cout<<"sum2 : "<<sum2<<endl;
        }
        if(sum1 == sum2)
        {
          count++;
        }
        sum2 = 0;
      }
      sum1 = 0;
    }
  }

  cout<<count;
}
