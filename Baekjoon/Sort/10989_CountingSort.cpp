// // This problem has limited memory capacity.
// // So if the input numbers are saved in array, that will exceed capacity.

// #include <iostream>
// #include <stdio.h>
// #define MAX 10001

// int main()
// {
//   int n=0, input=0;
//   int counts[MAX]={0,};
//   scanf("%d",&n);

//   // Count numbers
//   for(int i=0; i<n; ++i)
//   {
//     scanf("%d",&input);
//     counts[input]++;
//   }

//   // Print number as much as its counts
//   for(int number=1; number<10001; ++number)
//   {
//     for(int count=0; count<counts[number]; ++count)
//     {
//       printf("%d\n",number);
//     }
//   }
// }