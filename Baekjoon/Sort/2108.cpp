// #include <iostream>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// int main()
// {
//   int positive[4001]={0,};
//   int negative[4001]={0,};
//   int n=0, count=0;
//   double sum=0;
//   cin>>n;
//   int *pArr = new int[n];
//   int *pModeArr = new int[n];
  
//   for(int i=0; i<n; ++i)
//   {
//     cin>>pArr[i];
//     if(pArr[i] >= 0)
//     {
//       positive[pArr[i]]++;
//       // check number count
//       if(count <= positive[pArr[i]])
//       {
//         count = positive[pArr[i]];
//       }
//     }
//     else
//     {
//       negative[pArr[i]*-1]++;
//       // check number count
//       if(count <= negative[pArr[i]*-1])
//       {
//         count = negative[pArr[i]*-1];
//       }
//     }
//     sum+=pArr[i];
//   }
//   sort(pArr ,pArr+n);
  
//   // 1. Arithmetic mean
//   cout<<round(sum/n)<<endl;

//   // 2. Median
//   cout<<pArr[n/2]<<endl;

//   // 3. Mode
//   int modeCount=0;
//   for(int i=0; i<4001; ++i)
//   {
//     if(count == positive[i])
//     {
//       pModeArr[modeCount++]=i;
//     }
//     if(count == negative[i])
//     {
//       pModeArr[modeCount++]=i*-1;
//     }
//   }

//   if(modeCount > 1)
//   {
//     sort(pModeArr, pModeArr+modeCount);
//     cout<<pModeArr[1]<<endl;
//   }
//   else
//   {
//     cout<<pModeArr[0]<<endl;
//   }
 
//   // 4. Range
//   cout<<pArr[n-1]-pArr[0]<<endl;

//   delete[] pModeArr;
//   delete[] pArr;
// }

