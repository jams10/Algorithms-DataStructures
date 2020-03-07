#include <iostream>
#include <cmath>

int main() {
  int x1=0, y1=0, x2=0, y2=0, r1=0, r2=0;
  double distance=0;
  int n=0;
  std::cin>>n;
  for(int i=0; i<n; ++i)
  {
    std::cin>>x1>>y1>>r1>>x2>>y2>>r2;    
    distance = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

    if(x1==x2 && y1==y2)
    {
      if(r1!=r2)
      {
        std::cout<<0<<std::endl;
      }
      else
      {
        std::cout<<-1<<std::endl;
      }
    }
    else if((r1+distance) > r2 && (r2+distance) > r1 && (r1+r2) > distance)
    {
      std::cout<<2<<std::endl;
    }
    else if((r1+distance) == r2 || (r2+distance) == r1 || (r1+r2) == distance)
    {
      std::cout<<1<<std::endl;
    }
    else 
    {
      std::cout<<0<<std::endl;
    }
  }
}