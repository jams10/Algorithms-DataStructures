// #include <iostream>

// class Info
// {
//   public:
//     int weight;
//     int height;
//     int rank;

//     bool operator < (Info& info)
//     {
//       return (this->weight<info.weight) && (this->height<info.height);
//     }
// };

// int main()
// {
//   int n=0;
//   std::cin>>n;
//   Info *pInfos = new Info[n];

//   for(int i=0; i<n; ++i)
//   {
//     std::cin>>pInfos[i].weight>>pInfos[i].height;
//     pInfos[i].rank=1;
//   }

//   for(int i=0; i<n; ++i)
//   {
//     for(int j=0; j<n; ++j)
//     {
//       if(i!=j && pInfos[i]<pInfos[j])
//       {
//         pInfos[i].rank++;
//       }
//     }
//   }

//   for(int i=0; i<n; ++i)
//   {
//     std::cout<<pInfos[i].rank;
//     if(i<n-1)
//     {
//       std::cout<<' ';
//     }
//   }
// }