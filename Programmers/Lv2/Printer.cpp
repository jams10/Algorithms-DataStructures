#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct element
{
    int idx;
    int value;
}element;

int solution( vector<int> priorities, int location )
{
    int answer = 1;
    vector<element> v;
    for( int i = 0; i < priorities.size(); i++ )
    {
        v.emplace_back( element{ i,priorities[i] } );
    }
    for( int i = 0; i < priorities.size(); i++ )
    {
        for( int j = i + 1; j < priorities.size(); j++ )
        {
            if( v[i].value < v[j].value )
            {
                v.emplace_back( v[i] );
                v.erase( v.begin() + i );
                i--;
                break;
            }
        }
    }
    for( const auto& e : v )
    {
        if( e.idx == location ) return answer;
        else answer++;
    }
    return answer;
}

// Queue를 이용한 풀이 - 다른 사람 풀이 참조

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct element
{
    int idx;
    int value;
}element;

int solution( vector<int> priorities, int location )
{
    int answer = 1;
    queue<int> idx;
    vector<int> v;
    
    for( int i = 0; i < priorities.size(); i++ )
    {
        idx.push( i );
    }

    while( !idx.empty() )
    {
        int cur_idx = idx.front();
        idx.pop(); // 꺼낸 뒤
        // 우선순위 확인
        if( priorities[cur_idx] == *max_element( priorities.begin(), priorities.end() ) )
        {
            v.emplace_back( cur_idx ); 
            priorities[cur_idx] = 0;
            if( cur_idx == location ) return v.size();
        }
        else
        {
            idx.push( cur_idx );
        }
    }
}