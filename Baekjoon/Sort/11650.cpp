// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <stdio.h>
// using namespace std;

// typedef struct Coordinate{
//   int x;
//   int y;
// }Coordinate;

// bool compare(Coordinate c1, Coordinate c2)
// {
//   if(c1.x==c2.x)
//   {
//     return c1.y < c2.y;
//   }
//   else
//   {
//     return c1.x < c2.x;
//   }
// }

// int main()
// {
//   int n=0,x=0,y=0;
//   Coordinate c;
//   vector<Coordinate> v;
//   scanf("%d",&n);

//   for(int i=0; i<n; ++i)
//   {
//     scanf("%d %d",&c.x,&c.y);
//     v.push_back(c);
//   }
//   sort(v.begin(), v.end(), compare);
  
//   for(const auto& element : v)
//   {
//     printf("%d %d\n",element.x,element.y);
//   }
// }