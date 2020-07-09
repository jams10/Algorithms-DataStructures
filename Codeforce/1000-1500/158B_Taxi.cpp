#include <iostream>

int main(int argc, char *argv[])
{
  int n = 0, tmp = 0, count = 0;
  int nFour = 0, nThree = 0, nTwo = 0, nOne = 0;
  std::cin>>n;

  for(int i=0; i<n; i++)
  {
    std::cin>>tmp;
    if(tmp==4)
    {
      n_Four++;
    }
    else if(tmp==3)
    {
      n_Three++;
    }
    else if(tmp==2)
    {
      nTwo++;
    }
    else if(tmp==1)
    {
      nOne++;
    }
  }

  //4
  count+=nFour;

  //3
  if(nThree > 0)
  {
    if(nThree >= nOne)
    {
      count += (nThree / nOne);
      nThree = nThree % nOne ;
      count += nThree;
    }
    else
    {
      count += (nOne / nThree);
      nOne = nOne % nThree;
    }
  }

  //2
  if(nTwo > 0)
  {
    if(nTwo >= nOne)
    {
      if(nOne % 2 == 0)
      {
        count += (nTwo)
      }
    }
  }

  //1
  if(nOne > 0)
  {
    count+=nOne;
  }

  std::cout<<count;
  
  return 0;
}