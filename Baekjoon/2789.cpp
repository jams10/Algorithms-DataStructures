// #include <iostream>
// #include <algorithm>

// int main()
// {
//   int n=0,m=0,result=0;
//   std::cin>>n>>m;
//   int *pCards=new int[n];

//   for(int i=0; i<n; ++i)
//   {
//     std::cin>>pCards[i];
//   }
//   std::sort(pCards,pCards+n);

//   result=-1;
//   for(int i=0; i<n; ++i)
//   {
//     for(int j=i+1; j<n; ++j)
//     {
//       for(int k=j+1; k<n; ++k)
//       {
//         if((result < pCards[i]+pCards[j]+pCards[k]) &&
//         (pCards[i]+pCards[j]+pCards[k] <= m))
//         {
//           result=result=pCards[i]+pCards[j]+pCards[k];
//         }
//       }
//     }
//   }
//   std::cout<<result;
// }