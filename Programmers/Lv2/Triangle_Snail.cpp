#include <string>
#include <vector>

using namespace std;

int triangle[1000][1000] = { 0, };
int dx[3] = { 0, 1, -1 };
int dy[3] = { 1, 0, -1 };

vector<int> solution( int n )
{
    vector<int> answer;

    int max = n * (n + 1) / 2;
    int y = 0, x = 0, number = 0;

    while( true )
    {
        for( int i = 0; i < 3; ++i )
        {
            while( y < n && x < n && triangle[y][x] == 0 )
            {
                triangle[y][x] = ++number;
                y += dy[i];
                x += dx[i];
            }
            y -= dy[i];
            x -= dx[i];
            y += dy[(i + 1) % 3];
            x += dx[(i + 1) % 3];
        }
        if( number >= max ) break;
    }

    for( int i = 0; i < n; ++i )
    {
        for( int j = 0; j < i + 1; ++j )
        {
            answer.push_back( triangle[i][j] );
        }
    }

    return answer;
}
