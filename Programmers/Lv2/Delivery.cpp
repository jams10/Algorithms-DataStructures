#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 500001

int solution( int N, vector<vector<int> > road, int K )
{
    int answer = 0;

    vector<vector<pair<int, int>>> dist( N );
    vector<int> minDist( N );
    for( int i = 0; i < N; ++i )
    {
        minDist[i] = INF;
    }

    for( vector<int> v : road )
    {
        dist[v[0] - 1].push_back( make_pair( v[1] - 1, v[2] ) );
        dist[v[1] - 1].push_back( make_pair( v[0] - 1, v[2] ) );
    }

    minDist[0] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push( make_pair( 0, 0 ) );

    while( !pq.empty() )
    {
        int cur = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        if( minDist[cur] < distance ) continue;
        int size = dist[cur].size();
        for( int i = 0; i < size; ++i )
        {
            int next = dist[cur][i].first;
            int nextDist = distance + dist[cur][i].second;

            if( nextDist < minDist[next] )
            {
                minDist[next] = nextDist;
                pq.push( make_pair( next, -nextDist ) );
            }
        }
    }

    for( int n : minDist )
    {
        if( n <= K ) answer++;
    }

    return answer;
}

/* 다익스트라 알고리즘 활용 */
