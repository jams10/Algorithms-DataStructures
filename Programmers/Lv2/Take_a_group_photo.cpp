#include <string>
#include <vector>

using namespace std;

#define MAX_COUNT 8
char g_cFriends[MAX_COUNT] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
bool g_bSelected[MAX_COUNT] = { false, };

void DFS( int count, char* arr, 
          const vector<string>& data, const int& dataSize, int& answer )
{
    if( count == MAX_COUNT )
    {
        // 조건 체크
        for( int i = 0; i < dataSize; i++ )
        {
            char f1 = data[i][0];
            char f2 = data[i][2];
            char cond = data[i][3];
            int condValue = data[i][4] - '0';

            int f1Idx = 0, f2Idx = 0;
            // 현재 스택 프레임의 arr 배열에서의 알파벳 인덱스 찾기
            for( int j = 0; j < MAX_COUNT; j++ )
            {
                if( arr[j] == f1 ) f1Idx = j;
                if( arr[j] == f2 ) f2Idx = j;
            }
            int distance = abs( f1Idx - f2Idx ) - 1;
            
            // 해당하는 조건을 모두 통과해야만 정답에 해당하는 answer 값 증가
            if( cond == '=' && distance != condValue ) return;
            else if( cond == '>' && distance <= condValue ) return;
            else if( cond == '<' && distance >= condValue ) return;
        }
        answer++;
        return;
    }
    // 순열 만들기
    for( int i = 0; i < MAX_COUNT; i++ )
    {
        if( g_bSelected[i] == true ) continue;
        g_bSelected[i] = true;
        arr[count] = g_cFriends[i];
        DFS( count + 1, arr, data, dataSize, answer );
        arr[count] = NULL;
        g_bSelected[i] = false;
    }
    return;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution( int n, vector<string> data )
{
    int answer = 0;
    int count = 0;

    char arr[MAX_COUNT] = { NULL, };

    DFS( 0, arr, data, n, answer );

    return answer;
}
