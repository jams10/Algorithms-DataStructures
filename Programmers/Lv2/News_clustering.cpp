#include <string>
#include <map>

using namespace std;

int Split( string& str, const int& size, map<string, int>& map );

int solution( string str1, string str2 )
{
    int answer = 0, same = 0;
    map<string, int> map1;
    map<string, int> map2;

    int mapCount1 = 0, mapCount2 = 0;

    mapCount1 = Split( str1, str1.size(), map1 );
    mapCount2 = Split( str2, str2.size(), map2 );

    for( auto m1 : map1 )
    {
        for( auto m2 : map2 )
        {
            if( m1.first == m2.first )
            {
                same += m1.second <= m2.second ? m1.second : m2.second;
            }
        }
    }

    if( mapCount1 == 0 && mapCount2 == 0 ) answer = 65536;
    else answer = static_cast<float>(65536 * same / (mapCount1 + mapCount2 - same));

    return answer;
}

int Split( string& str, const int& size, map<string, int>& map )
{
    int count = 0;
    for( int i = 0; i < size - 1; ++i )
    {
        if( isalpha( str[i] ) && isalpha( str[i + 1] ) )
        {
            if( islower( str[i] ) ) str[i] -= 32;
            if( islower( str[i + 1] ) ) str[i + 1] -= 32;
            map[string{ str[i], str[i + 1] }]++;
            count++;
        }    
    }
    return count;
}
