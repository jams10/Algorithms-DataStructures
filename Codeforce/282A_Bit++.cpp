/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n=0,value=0;
  string tmp;
  cin>>n;
  
  for(int i=0; i<n; i++)
  {
    cin>>tmp;
    // find function searches argument string
    // if there is no substring in given string(tmp),
    // return std::string::npos
    if(tmp.find("++") != std::string::npos)
    {
      ++value;
    }
    if(tmp.find("--") != std::string::npos)
    {
      --value;
    }
  }
  
  cout<<value;
  
  return 0;
}
*/