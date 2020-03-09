// #include <iostream>

// int DigitSum(int n)
// {
//   int sum=n;
//   int digits[7]={0,};
//   int div = 1000000;
//   for(int i=0; i<7; ++i)
//   {
//     if(i==6)
//     {
//       sum += n % 10;
//     }
//     else
//     {
//       sum += n / div;
//       n %= div;
//       div /= 10;
//     }
//   }
//   return sum;
// }

// int BreakdownSum(int n)
// {
//   for(int i=1; i<n; ++i)
//   {
//     if(DigitSum(i)==n)
//     {
//       return i;
//     }
//   }
//   return 0;
// }

// int main()
// {
//   int n=0;
//   std::cin>>n;
//   std::cout<<BreakdownSum(n);
// }