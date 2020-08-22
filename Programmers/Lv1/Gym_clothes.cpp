#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    int answer = n - lost.size();

    for(int i = 0; i < lost.size(); i++) // 여분을 도둑 맞은 경우
    {
      for(int j = 0; j < reserve.size(); j++)
      {
        if(lost[i] == reserve[j])
        {
          reserve.erase(reserve.begin() + j ); // 인덱스 j 위치 요소 삭제
          lost.erase(lost.begin() + i); // 인덱스 i 위치 요소 삭제
          i--;
          answer++;
          break;
        }
      }
    }
    
    for(int i = 0; i < lost.size(); i++) // 도둑맞지 않고 여분이 남은 경우
    {
      for(int j = 0; j < reserve.size(); j++)
      {
        if(abs( lost[i] - reserve[j] ) == 1)
        {
          reserve.erase(reserve.begin() + j );
          answer++;
          break;
        }
      }
    }
    return answer;
}