#include<iostream>

int main(int argc, char *argv[])
{
  int t = 0, angle = 0;
  std::cin>>t;

  for(int i=0; i<t; i++)
  {
    std::cin>>angle;
    if(360 % ( 180-angle ) == 0) // result is integer
    {
      std::cout<<"YES"<<Std::endl;
    }
    else
    {
      std::cout<<"NO"<<std::endl;
    }
  }

  return 0;
}

/*
The angle of the regular polygon 'a' is '180 * (n-2) / n'
where n is the number of sides in the polygon.

so, n should be an integer.

a = 180 * (n-2) / n
n = 360 / (180 - a)
*/