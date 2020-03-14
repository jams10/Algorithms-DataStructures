// // 1. Make input array into MAX or MIN Heap using push function.
// // 2. Sort array by popping Heap elements.
// // This code is using Max Heap

// #include <iostream>
// #include <stdio.h>

// // Max Heap
// void push(int *pArray, int& endIndex, int data)
// {
//   pArray[++endIndex] = data;

//   int childIndex = endIndex;
//   int parentIndex = childIndex / 2;

//   // child index goes UP
//   while( childIndex > 1 && data > pArray[parentIndex] )
//   {
//     std::swap(pArray[parentIndex],pArray[childIndex]);
//     childIndex = parentIndex;
//     parentIndex /= 2;
//   }
// }

// int pop(int *pArray, int& endIndex )
// {
//   int maxNumber = pArray[1];

//   int childIndex = 2;
//   int parentIndex = 1;

//   pArray[parentIndex] = pArray[endIndex--];

//   // parent index goes DOWN
//   while(childIndex <= endIndex)
//   {
//     // when right child index number is greater than left
//     if(childIndex < endIndex && (pArray[childIndex] < pArray[childIndex + 1]))
//     {
//       ++childIndex;
//     }
//     // when parent index number is greater than child index number
//     if(pArray[parentIndex] >= pArray[childIndex])
//     {
//       break;
//     }

//     std::swap(pArray[parentIndex], pArray[childIndex]);
//     parentIndex = childIndex;
//     childIndex *= 2;
//   }

//   return maxNumber;
// }

// int main()
// {
//   int n=0, input=0, count=0;
//   std::cin>>n;

//   int *pArray = new int [n+1];
//   int *pSorted = new int [n+1];

//   for(int i=1; i<=n; ++i)
//   {
//     scanf("%d",&input);
//     push(pArray, count, input);
//   }

//   for(int i=1; i<=n; ++i)
//   {
//     pSorted[n+1-i]=pop(pArray, count);
//   }

//   for(int i=1; i<=n; ++i)
//   {
//     printf("%d\n",pSorted[i]);
//   }
  
//   delete[] pSorted;
//   delete[] pArray;
// }

// // MAX Heap is for descening order sort
// // MIN Heap is for ascening order sort

// // This code is using MAX Heap and save elements backward for ascening order.
// // So, by using MIN heap code will be more simple.

// // MIN Heap sort

// // Min Heap
// // void push(int *pArray, int& endIndex, int data)
// // {
// //   pArray[++endIndex] = data;

// //   int childIndex = endIndex;
// //   int parentIndex = childIndex / 2;

// //   // child index goes UP
// //   while( childIndex > 1 && data < pArray[parentIndex] )
// //   {
// //     std::swap(pArray[parentIndex],pArray[childIndex]);
// //     childIndex = parentIndex;
// //     parentIndex /= 2;
// //   }
// // }

// // int pop(int *pArray, int& endIndex )
// // {
// //   int maxNumber = pArray[1];

// //   int childIndex = 2;
// //   int parentIndex = 1;

// //   pArray[parentIndex] = pArray[endIndex--];

// //   // parent index goes DOWN
// //   while(childIndex <= endIndex)
// //   {
// //     // when right child index number is smaller than left
// //     if(childIndex < endIndex && (pArray[childIndex] > pArray[childIndex + 1]))
// //     {
// //       ++childIndex;
// //     }
// //     // when parent index number is samller than child index number
// //     if(pArray[parentIndex] <= pArray[childIndex])
// //     {
// //       break;
// //     }

// //     std::swap(pArray[parentIndex], pArray[childIndex]);
// //     parentIndex = childIndex;
// //     childIndex *= 2;
// //   }

// //   return maxNumber;
// // }