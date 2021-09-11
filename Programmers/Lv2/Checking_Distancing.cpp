#include <string>
#include <vector>

using namespace std;

#define ROW_NUMBER 5
#define COL_NUMBER 5

int Distance( int depth, int x, int y, vector<string>& places )
{
    int detected = 0;

    if( x < 0 || y < 0 || x >= ROW_NUMBER || y >= COL_NUMBER ) return 0;
    if( depth > 2 || places[y][x] == 'X' ) return 0;
    if( places[y][x] == 'P' && depth > 0 )
    {
        return 1;
    }

    if( places[y][x] != 'X' )
    {
        if( places[y][x] == 'P' ) places[y][x] = 'X';
        // left
        detected += Distance( depth + 1, x - 1, y, places );
        // right
        detected += Distance( depth + 1, x + 1, y, places );
        // up
        detected += Distance( depth + 1, x, y - 1, places );
        // down
        detected += Distance( depth + 1, x, y + 1, places );
    }

    return detected;
}

vector<int> solution( vector<vector<string>> places )
{
    vector<int> answer;

    for( vector<string> s : places )
    {
        int n = 0;
        for( int y = 0; y < ROW_NUMBER; ++y )
        {
            for( int x = 0; x < COL_NUMBER; ++x )
            {
                if( s[y][x] == 'P' )
                {
                    n += Distance( 0, x, y, s );
                }
            }
        }
        if(n > 0) answer.emplace_back(0);
        else answer.emplace_back(1);
    }

    return answer;
}

/* 다른 사람 풀이 참고 */
/*
  상하좌우 확인할 때 dx{1,-1,0,0}, dy{0,0,1,-1} 배열을 이용하여 0부터 3까지의 인덱스를 돌면서
  dx와 dy 원소를 다음 위치에 더해주면 더 간결한 코드 작성 가능.
*/
