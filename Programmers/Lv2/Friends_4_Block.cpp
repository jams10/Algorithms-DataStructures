#include <string>
#include <vector>
#include <set>

using namespace std;

int solution( int m, int n, vector<string> board )
{
    int answer = 0;

    vector<vector<char>> b( m );
    set<pair<int, int>> del;

    int dx[3] = { 1,0,1 };
    int dy[3] = { 0,1,1 };

    for( int i = 0; i < m; ++i )
    {
        for( int j = 0; j < n; ++j )
        {
            b[i].push_back( board[i][j] );
        }
    }

    bool isBoxInBoard = true;
    while( isBoxInBoard )
    {
        isBoxInBoard = false;
        // 블록 공통 박스 체크
        for( int i = 0; i < m - 1; ++i )
        {
            for( int j = 0; j < n - 1; ++j )
            {
                char o = b[i][j];
                if( o != 'X' )
                {
                    char r = b[i + dy[0]][j + dx[0]];
                    char l = b[i + dy[1]][j + dx[1]];
                    char d = b[i + dy[2]][j + dx[2]];
                    if( o == r && o == l && o == d )
                    {
                        del.insert( make_pair( i, j ) );
                        del.insert( make_pair( i + dy[0], j + dx[0] ) );
                        del.insert( make_pair( i + dy[1], j + dx[1] ) );
                        del.insert( make_pair( i + dy[2], j + dx[2] ) );
                        isBoxInBoard = true;
                    }
                }
            }
        }

        if( isBoxInBoard )
        {   
            // 공통 부분 X로 지우기
            auto iter = del.begin();
            auto iterEnd = del.end();
            for( iter; iter != iterEnd; ++iter )
            {
                b[iter->first][iter->second] = 'X';
                answer++;
            }

            del.clear();
            
            // 공통 박스 지운 뒤 남을 블록들을 재배열
            for( int i = m - 1; i >= 0; --i )
            {
                for( int j = 0; j < n; ++j )
                {
                    if( b[i][j] != 'X' )
                    {
                        int count = i;
                        char result = b[i][j];
                        b[i][j] = 'X';
                        for( int k = i + 1; k < m; ++k )
                        {
                            if( b[k][j] != 'X' ) break;
                            else count++;
                        }
                        b[count][j] = result;
                    }
                }
            }
        }
    }

    return answer;
}
