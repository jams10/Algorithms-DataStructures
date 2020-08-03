#include<iostream>
#include<string>
#include<map>
using namespace std;

void twoStrings(const string& s1, const string& s2);

int main()
{
  int p = 0;
  string s1, s2;

  cin >> p;

  for(int i = 0; i < p; i++)
  {
    cin >> s1;
    cin >> s2;
    twoStrings(s1, s2);
  }

  return 0;
}

void twoStrings(const string& s1, const string& s2)
{
  map<char,int>m;
  string s;
  
  for(int i = 0; i < s1.length(); i++)
  {
    m[s1[i]]++;
  }
  
  for(int i = 0; i < s2.length(); i++)
  {
    if(m[s2[i]] > 0)
    {
      cout<<"YES"<<endl;
      return;
    }
  }
  cout<<"NO"<<endl;
  return;
}
