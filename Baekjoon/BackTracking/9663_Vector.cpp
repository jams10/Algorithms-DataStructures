// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// int n=0;
// int result=0;
// vector<int> v;

// bool isValid()
// {
//   int row = v.size()-1;
//   for(int i=0; i<row; i++)
//   {
//     if(v.at(i)==v.at(row)) return false;
//     if(abs(v.at(i)-v.at(row)) == abs(i-row)) return false;
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
//     v.push_back(i);
//     if(isValid())
//     {
//       dfs(row+1);
//     }
//     v.pop_back();
//   }
// }

// int main()
// {
//   cin>>n;
//   dfs(0);
//   cout<<result;
// }