/*
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
  int n = 0, k = 0;
  int count = 0; // the number of advanced contestants
  cin>>n>>k;
  
  int *p = new int[n];
  
  for(int i=0; i<n; i++)
  {
    scanf("%d",&p[i]);
  }
  
  for(int i=0; i<n; i++)
  {
    if(p[i] > 0 && p[i] >= p[k-1])
    {
      count++;
    }
    if(p[i] < p[k-1]) break;
  }
  cout << count;
  
  delete []p;
  return 0;
}
*/