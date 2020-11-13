#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 다이나믹 프로그래밍 이용

int solution(vector<vector<int>> board)
{
    int answer = board[0][0]; // 사이즈 테이블 값 계산위한 공식을 위해 인덱스는 1부터 시작.
                              // 따라서, board[0][0] = 1 이고 나머지가 다 0일 경우를 위해
                              // answer의 초기 값을 이로 설정함.
    int yLen = board.size();
    int xLen = board[0].size();
    vector<vector<int>> sizeTable = board;
    
    for(int y = 1 ; y < yLen; ++y)
    {
        for(int x = 1; x < xLen; ++x)
        {
            if(board[y][x])
            {
                int across = 0, yPrev = 0, xPrev = 0, minValue = 0;
                // 대각선, 이전행, 이전열 인덱스에 위치한 요소들을 참조해 
                // 사이즈 테이블 값 계산
                // sizeT[i][j] = min(sizeT[i-1][j-1], sizeT[i][j-1], sizeT[i-1][j])  
                //                   + sizeT[i][j]
                across = sizeTable[y-1][x-1];
                yPrev = sizeTable[y-1][x];
                xPrev = sizeTable[y][x-1];
                // 최소값 찾기
                minValue = min(across, yPrev);
                minValue = min(minValue, xPrev);
                // 다음번 인덱스 값 계산시 참조하기 위해 사이즈 테이블에 값 삽입.
                // 최소값에 자기 자신을 더해서 넣어줌.
                sizeTable[y][x] = minValue + sizeTable[y][x];
            
                if(answer < sizeTable[y][x]) answer = sizeTable[y][x];
            }
        }
    }
    
    return answer * answer;
}