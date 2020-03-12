// #include <iostream>
// #include <vector>

// int CheckBoard(const std::vector< std::vector<char> >& board, int row, int col)
// {
//   int paintWB=0, paintBW=0;

//   for(int r=row; r<=row+7; ++r)
//   {
//     for(int c=col; c<=col+7; ++c)
//     {
//       if((r+c)%2==0)
//       {
//         if(board[r][c]=='W')  paintWB++;
//         else paintBW++;
//       }
//       else
//       {
//         if(board[r][c]=='B')  paintWB++;
//         else paintBW++;
//       }
//     }
//   }
//   return paintWB<paintBW? paintWB : paintBW;
// }

// int main()
// {
//   int n=0,m=0;
//   char tmp;
//   int min=0, result=2501;
//   std::vector< std::vector<char> > chessBoard;
//   std::cin>>n>>m;

//   // 2D Vector
//   for(int row=0; row<n; ++row)
//   {
//     chessBoard.push_back(std::vector<char>());
//     for(int col=0; col<m; ++col)
//     {
//       std::cin>>tmp;
//       chessBoard.at(row).push_back(tmp);
//     }
//   }

//   // Check the board
//   for(int row=0; row<n; ++row)
//   {
//     for(int col=0; col<m; ++col)
//     {
//       if(row+7<n && col+7<m)
//       {
//         min=CheckBoard(chessBoard, row, col);
//         if(min<result)
//         {
//           result=min;
//         }
//       }
//     }
//   }
//   std::cout<<result;
// }