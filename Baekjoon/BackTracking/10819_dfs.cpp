// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// using namespace std;

// typedef struct Node
// {
//     int value;
//     bool selected=false;
// }Node;

// vector<int> tmp;
// vector<int> results;

// void dfs(int cnt, int size, Node* pArr)
// {
//     if(cnt==size)
//     {
//         int sum=0;
//         for(int i=0; i<size-1; ++i)
//         {
//             sum+=abs(tmp[i]-tmp[i+1]);
//         }
//         results.emplace_back(sum);
//         return;
//     }

//     for(int i=0; i<size; ++i)
//     {
//         if(pArr[i].selected)
//         {
//             continue;
//         }
//         pArr[i].selected = true;
//         tmp.emplace_back(pArr[i].value);

//         dfs(cnt+1,size,pArr);
//         tmp.pop_back();
//         pArr[i].selected = false;
//     }
// }


// int main()
// {
//     int n=0, sum=0;
//     cin>>n;
//     Node *pArr = new Node[n];
//     for(int i=0; i<n; ++i)
//     {
//         cin>>pArr[i].value;
//     }
    
//     dfs(0,n,pArr);

//     sort(results.begin(), results.end(), greater<int>());
    
//     cout<<results[0];
    
//     return 0;
// }