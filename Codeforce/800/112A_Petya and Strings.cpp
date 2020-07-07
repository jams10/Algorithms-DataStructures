#include <iostream>
#include <string>

void SetString(std::string& s)
{
  for(int i=0; i<s.size(); i++)
  {
    if((int)s[i]>=65 && (int)s[i]<=90)
    {
      s[i] += 32;
    }
  }
}

int CompareString(const std::string& s1, const std::string& s2)
{
  for(int i=0; i<s1.size(); i++)
  {
    if(s1[i] < s2[i])
    {
      return -1;
    }
    else if(s1[i] > s2[i])
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  std::string s1,s2;
  std::cin>>s1>>s2;

  SetString(s1);
  SetString(s2);

  
  std::cout<<CompareString(s1, s2);

  return 0;
}