#include <iostream>
#include <string>

int main()
{
  int state = -1;
  int count = 0;
  std::string s;
  std::cin>>s;

  for(int i=0; i<s.size(); i++)
  {
    if(s[i]=='0')
    {
      if(state == 1)
      {
        count = 0;
      }
      state = 0;
      if(state == 0)
      {
        count++;
        if(count >= 7)
        {
          std::cout<<"YES";
          return 0;
        }
      }
    }
    else if(s[i]=='1')
    {
      if(state == 0)
      {
        count = 0;
      }
      state = 1;
      if(state == 1)
      {
        count++;
        if(count >= 7)
        {
          std::cout<<"YES";
          return 0;
        }
      }
    }
  }
  std::cout<<"NO";
  return 0;
}