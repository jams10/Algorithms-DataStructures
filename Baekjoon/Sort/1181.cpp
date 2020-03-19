// #include <iostream>
// #include <algorithm>
// #include <string>
// using namespace std;

// bool Compare(const string& s1, const string& s2)
// {
//   if(s1.length()==s2.length())
//   {
//     return s1<s2;
//   }
//   else
//   {
//     return s1.length()<s2.length();
//   }
// }

// int main()
// {
//   int n=0;
//   cin>>n;

//   string *pArr = new string[n];
  
//   for(int i=0; i<n; ++i)
//   {
//     cin>>pArr[i];
//   }

//   sort(pArr,pArr+n,Compare);

//   for(int i=0; i<n; ++i)
//   {
//     if(i>0 && pArr[i-1]==pArr[i])
//     {
//       continue;
//     }
//     cout<<pArr[i]<<endl;
//   }
//   delete[] pArr;
// }