#include <string>
#include <vector>
#include <bitset>

using namespace std;

#define BITSIZE 4 * 13

vector<long long> solution( vector<long long> numbers )
{
    vector<long long> answer;

    int nSize = numbers.size();
    for( int i = 0; i < nSize; ++i )
    {
        if( numbers[i] % 2 == 0 )
        {
            answer.push_back( numbers[i] + 1 );
        }
        else
        {
            bitset<BITSIZE> n( numbers[i] );
            long long increment = 1;
            for( int j = 0; j < BITSIZE; ++j )
            {
                if( !n[j] )
                {
                    answer.push_back( numbers[i] + increment / 2 );
                    break;
                }
                increment *= 2;
            }
        }
    }
    return answer;
}
