#include <vector>
#include <math.h>

using namespace std;

int boardSize = 0;
int result = 0;
vector<int> v;

bool IsValid()
{
    int row = v.size() - 1;
    for( int i = 0; i < row; ++i )
    {
        if( v.at( i ) == v.at( row ) ) return false; // 수직 방향 검사.
        if( abs( v.at( i ) - v.at( row ) ) == abs( i - row ) )return false; // x값 == y값인 좌표로 대각선 방향 검사.
    }
    return true;
}

void DFS( int row )
{
    if( row == boardSize )
    {
        result++;
        return;
    }
    for( int i = 0; i < boardSize; ++i )
    {
        v.push_back( i );       // choose
        if( IsValid() )         
        {
            DFS( row + 1 );     // explore
        }
        v.pop_back();           // un-choose
    }
}

int solution( int n )
{
    boardSize = n;
    DFS( 0 );
    return result;
}
