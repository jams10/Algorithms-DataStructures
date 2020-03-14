// // Couldn't solve 2751 by using QuickSort...
// // Worst case O(n^2)

// #include <iostream>
// #include <stdio.h>

// int partition(int *pArray, int left, int right)
// {
//   int pivot = left;
//   int i = left + 1;
//   int j = right - 1;

//   // Iterate until indices cross each other
//   while(i <= j)
//   {
//     // left side numbers should be smaller than pivot number
//     while(pArray[i]<=pArray[pivot] && i < right)
//     {
//       i++;
//     }
//     // left side numbers should be greater than pivot number
//     while(pArray[j]>=pArray[pivot] && j > left)
//     {
//       j--;
//     }
//     // if left side number greater than pivot number
//     // and right side number smaller than pivot number
//     // and indices don't cross each other swap left, right side number
//     if(i <= j)
//     {
//       // SWAP by using XOR bit operation (only for Integer)
//       pArray[i]^=pArray[j];
//       pArray[j]^=pArray[i];
//       pArray[i]^=pArray[j];
//     }
//   }
//   // if indices crossed each other, swap right side number and pivot number
//   // cause, when indices crossed each other, 
//   // the numbers of left side of 'j' index are smaller than pivot
//   // SWAP by using function
//   std::swap(pArray[pivot], pArray[j]);
//   return j;
// }


// void quickSort(int *pArray, int left, int right)
// {
//   if(left < right)
//   {
//     int pivot = partition(pArray, left, right); // Conquer
//     // because the sort of pivot index number is finished, do sort except it.
//     quickSort(pArray, left, pivot); // Divide
//     quickSort(pArray, pivot + 1, right); // Divide
//   }
// }

// int main()
// {
//   int n=0;
//   std::cin>>n;
  
//   int *pArray = new int[n];
  
//   for(int i=0; i<n; ++i)
//   {
//     scanf("%d", &pArray[i]);
//   }

//   quickSort(pArray, 0, n);

//   for(int i=0; i<n; ++i)
//   {
//     printf("%d\n",pArray[i]);
//   }
//
//   delete[] pArray;
// }