#include<vector>
#include <queue>
using namespace std;

#define MAX 10001
int MAX_Y = 0, MAX_X = 0;

typedef struct Path
{
    int x = 0, y = 0, distance = 0;
    Path operator + ( const Path& p )
    {
        Path tmp;
        tmp.x = x + p.x;
        tmp.y = y + p.y;
        return tmp;

    }
    bool operator == ( const Path& p )
    {
        return (x == p.x) && (y == p.y);
    }
};

vector<Path> dir = { Path{0,1}, Path{1,0},Path{-1,0},Path{0,-1} };

int solution( vector<vector<int> > maps )
{
    int answer = MAX;
    int distance = 0;
    MAX_Y = maps.size();
    MAX_X = maps[0].size();

    queue<Path> q;
    q.push( Path{ 0,0,1 } );
    maps[0][0] = 0;

    Path endPos{ MAX_X - 1, MAX_Y - 1 };

    while( q.size() != 0 )
    {
        Path curPos = q.front();
        q.pop();

        if( curPos == endPos )
        {
            answer = curPos.distance;
            break;
        }

        for( int i = 0; i < 4; ++i )
        {
            Path nextPos = curPos + dir[i];
            if( nextPos.x >= 0 && nextPos.x <= MAX_X - 1 &&
                nextPos.y >= 0 && nextPos.y <= MAX_Y - 1 &&
                maps[nextPos.y][nextPos.x] )
            {
                nextPos.distance = curPos.distance + 1;
                q.push( nextPos );
                maps[nextPos.y][nextPos.x] = 0;
            }
        }
    }

    if( answer == MAX ) answer = -1;

    return answer;
}

/* 다른 사람 풀이 참고 */

/*
  무작정 dfs 방식으로 문제를 제출하니, 정확성은 통과하지만 시간 초과가 생겼음.
  따라서, bfs 방식을 사용하였음. 최단거리는 dfs보다 bfs 방식을 사용하는 것이 효율적임.
*/
