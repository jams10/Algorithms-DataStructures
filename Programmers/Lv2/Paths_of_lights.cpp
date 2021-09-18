#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Vec2
{
    int x, y;
    Vec2( const int& _x, const int& _y ) : x( _x ), y( _y ) {}
    bool operator == ( const Vec2& v )
    {
        return (x == v.x) && (y == v.y);
    }
};

typedef struct Spot
{
    bool passed[4] = { false, };
};

vector<int> solution( vector<string> grid )
{
    vector<int> answer;

    Vec2 directions[4] = { Vec2( 0,-1 ), Vec2( 0,1 ), Vec2( -1,0 ), Vec2( 1,0 ) };

    vector<vector<Spot>> spots;

    int ySize = grid.size();
    spots.resize( ySize );
    for( int y = 0; y < ySize; ++y )
    {
        spots[y].resize( grid[y].size() );
    }

    ySize = grid.size();
    for( int y = 0; y < ySize; ++y )
    {
        int xSize = grid[y].size();
        for( int x = 0; x < xSize; ++x )
        {
            for( int i = 0; i < 4; ++i )
            {
                if( spots[y][x].passed[i] == false )
                {
                    spots[y][x].passed[i] = true;
                    Vec2 dir = directions[i];
                    int distance = 0;
                    bool loopState = true;
                    while( loopState )
                    {
                        distance++;
                        x += dir.x;
                        y += dir.y;

                        if( x < 0 ) x = xSize - 1;
                        if( y < 0 ) y = ySize - 1;
                        if( x >= xSize ) x = 0;
                        if( y >= ySize ) y = 0;

                        if( grid[y][x] == 'L' ) dir = Vec2( dir.y, -dir.x );
                        else if( grid[y][x] == 'R' ) dir = Vec2( -dir.y, dir.x );

                        for( int i = 0; i < 4; ++i )
                        {
                            // 빛은 반사되어 내부에서 순환됨. 따라서 제일 처음 사이클이 하나 완성되면, 해당 사이클에서 사용된 경로로 다른 사이클을 만들 수 없음.
                            // 또 다른 사이클들은 사용되지 않은 경로로만 만들어질 수 있음.
                            if( directions[i] == dir )
                            {
                                if( spots[y][x].passed[i] == true )
                                {
                                    answer.push_back( distance );
                                    loopState = false;
                                }
                                else
                                {
                                    spots[y][x].passed[i] = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    sort( answer.begin(), answer.end() );
    return answer;
}
