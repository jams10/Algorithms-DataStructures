// #include <iostream>
// using namespace std;

// int n=0;
// int result=0;
// bool arr[15][15]={false,};

// bool isValid(int row, int col)
// {
//   for(int i=row-1; i>=0; i--)
//   {
//     if(arr[i][col])
//     {
//       return false;
//     }
//   }
//   for(int x=col-1, y=row-1; (x>=0 && y>=0); x--, y--)
//   {
//     if(arr[y][x])
//     {
//       return false;
//     }
//   }
//   for(int x=col+1, y=row-1; (x<n && y>=0); x++, y--)
//   {
//     if(arr[y][x])
//     {
//       return false;
//     }
//   }
//   return true;
// }

// void dfs(int row)
// {
//   if(row==n)
//   {
//     result++;
//     return;
//   }
//   for(int i=0; i<n; i++)
//   {
//     arr[row][i]=true;
//     if(isValid(row, i))
//     {
//       dfs(row+1);
//     }
//     arr[row][i]=false;
//   }
// }

// int main()
// {
//   cin>>n;
//   dfs(0);
//   cout<<result;
// }