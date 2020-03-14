// #include <iostream>
// #include <list>
// #include <stdio.h>

// #define MAX_SIZE 1000001
// int sortedArray[MAX_SIZE];

// void Merge(int *pArray, int left, int mid, int right)
// {
//   int leftStart = left;
//   int midStart = mid + 1;
//   int index = left;

//   while(leftStart <= mid && midStart <= right)
//   {
//     if(pArray[leftStart] <= pArray[midStart])
//     {
//       sortedArray[index] = pArray[leftStart];
//       leftStart++;
//     }
//     else
//     {
//       sortedArray[index] = pArray[midStart];
//       midStart++;
//     }
//     index++;
//   }

//   // copy remaining numbers
//   if(leftStart > mid)
//   {
//     for(int i = midStart; i<=right; ++i)
//     {
//       sortedArray[index++] = pArray[i];
//     }
//   }
//   else
//   {
//     for(int i = leftStart; i<=mid; ++i)
//     {
//       sortedArray[index++] = pArray[i];
//     }
//   }

//   // copy numbers in sortedArray to pArray
//   for(int i=left; i<=right; ++i)
//   {
//     pArray[i] = sortedArray[i];
//   }
// }
// void MergeSort(int *pArray, int left, int right)
// {
//   if(left < right)
//   {
//     int mid = (left + right)/2;
//     MergeSort(pArray, left, mid);
//     MergeSort(pArray, mid + 1, right);
//     Merge(pArray, left, mid, right);
//   }
// }

// int main()
// {
//   int n=0;
//   std::cin>>n;

//   int *pArray = new int [n];
//   for(int i=0; i<n; ++i)
//   {
//     scanf("%d",&pArray[i]);
//   }

//   MergeSort(pArray, 0, n-1);

//   for(int i=0; i<n; ++i)
//   {
//     printf("%d\n",pArray[i]);
//   }
//   delete[] pArray;
// }