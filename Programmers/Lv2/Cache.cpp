#include <string>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

#define HIT 1
#define MISS 5

int solution( int cacheSize, vector<string> cities )
{
    int answer = 0;

    set<string> cache;
    list<string> cacheData;

    int sSize = cities.size();
    for( int i = 0; i < sSize; ++i )
    {
        int cSize = cities[i].size();
        for( int j = 0; j < cSize; ++j )
        {
            if( islower( cities[i][j] ) ) cities[i][j] -= 32;
        }
    }

    for( string s : cities )
    {
        auto iter = cache.find( s );
        if( iter == cache.end() )
        {
            if( cacheSize > 0 )
            {
                if( cache.size() == cacheSize )
                {
                    string lru = cacheData.back();
                    cacheData.pop_back();
                    cacheData.push_front( s );
                    cache.erase( lru );
                    cache.insert( s );
                }
                else
                {
                    cacheData.push_front( s );
                    cache.insert( s );
                }
            }
            answer += MISS;
        }
        else
        {
            cacheData.remove( s );
            cacheData.push_front( s );
            answer += HIT;
        }
    }

    return answer;
}

/*
  스트링의 소문자/대문자를 모두 대문자/소문자로 바꾸려면 transform 함수를 이용하여 간단히 할 수 있다.
  transform( 바꿀 문자열의 begin iter, 바꿀 문자열의 end iter, 바꾼 문자들이 들어갈 문자열 begin iter, 어떻게 바꿀지에 대한 함수 );
  ex) transform( s.begin(), s.end(), s.begin(), ::toupper); -> 문자열 자기 자신을 모두 대문자로 변경.
*/
