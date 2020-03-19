// #include <iostream>
// #include <algorithm>
// using namespace std;

// typedef struct Info
// {
//   int age;
//   string name;
//   int order;
// }Info;

// bool Compare(const Info& info1, const Info& info2)
// {
//   if(info1.age==info2.age)
//   {
//     return info1.order<info2.order;
//   }
//   else
//   {
//     return info1.age<info2.age;
//   }
// }

// int main()
// {
//   // Cut off synchronization with stdio
//   ios_base :: sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   int n=0;
//   cin>>n;

//   Info* pInfos = new Info[n];

//   for(int i=0; i<n; ++i)
//   {
//     cin>>pInfos[i].age>>pInfos[i].name;
//     pInfos[i].order=i;
//   }

//   sort(pInfos,pInfos+n,Compare);

//   for(int i=0; i<n; ++i)
//   {
//     // Using '\n' instead of 'endl' increases the speed of I/O
//     cout<<pInfos[i].age<<' '<<pInfos[i].name<<'\n';
//   }

//   delete[] pInfos;
// }