// #include <iostream>
// #include <cmath>

// int main() {
//   int x=0,y=0,w=0,h=0;
//   double result[6]={0,};
//   std::cin>>x>>y>>w>>h;

//   //1. (0,0),(x,y)
//   result[0]=sqrt(pow(x,2)+pow(y,2));
//   //2. (x,y),(w,h)
//   result[1]=sqrt(pow(w-x,2)+pow(h-y,2));
//   //3. left
//   result[2]=x;
//   //4. right
//   result[3]=w-x;
//   //5. top
//   result[4]=h-y;
//   //6. bottom
//   result[5]=y;

//   int min=result[0];
//   for(int i=1; i<6; ++i)
//   {
//     if(min>result[i])
//     {
//       min=result[i];
//     }
//   }

//   std::cout<<min;
// }