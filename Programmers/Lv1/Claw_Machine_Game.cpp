#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> basket;

    for(const auto& element : moves)
    {
      for(int i = 0; i < board[0].size(); i++)
      {
        if( board[i][element-1] != 0 )
        {
          basket.push_back( board[i][element-1] );
          board[i][element-1] = 0;
          break;
        }
      }
      if(basket[basket.size() - 1] == basket[basket.size() - 2])
      {
        answer++;
        basket.erase(basket.end() - 1);
        basket.erase(basket.end() - 1);
      }
    }
    return answer*2;
}