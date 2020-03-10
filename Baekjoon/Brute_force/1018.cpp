#include <iostream>
#include <vector>

int CheckBoard(const std::vector< std::vector<char> >& board, int row, int col)
{
  int paintingNumber=0;
  for(; row<=row+7; ++row)
  {
    for(; col<=col+7; ++col)
    {
      // check slope. 2 cases first W or B
    }
  }
}

int main()
{
  int n=0,m=0;
  char tmp;
  std::vector<int> cases;
  std::vector< std::vector<char> > chessBoard;
  std::cin>>n>>m;

  // 2D Vector
  for(int row=0; row<n; ++row)
  {
    chessBoard.push_back(std::vector<char>());
    for(int col=0; col<m; ++col)
    {
      std::cin>>tmp;
      chessBoard.at(row).push_back(tmp);
    }
  }

  // Check the board
  for(int row=0; row<n; ++row)
  {
    for(int col=0; col<m; ++col)
    {
      if(row+7<n && col+7<m)
      {

      }
    }
  }
}