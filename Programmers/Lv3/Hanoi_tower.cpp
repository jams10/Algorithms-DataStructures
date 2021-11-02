#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi( int from, int by, int to, int n )
{
    if( n == 1 ) // 재귀 탈출
    {
        answer.push_back( vector<int>{from, to} );
    }
    else
    {
        hanoi( from, to, by, n - 1 ); // n-1개를 to를 이용 from 에서 by 로 이동
        answer.push_back( vector<int>{from, to} ); // 마지막 한개를 이동
        hanoi( by, from, to, n - 1 ); // n-1개를 from을 이용, by에서 to 로 이동
    }
}

vector<vector<int>> solution( int n )
{
    hanoi( 1, 2, 3, n );
    return answer;
}
