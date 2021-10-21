#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution( vector<int> arr )
{
    int answer = 0, mul = 1;

    int size = arr.size();
    sort( arr.begin(), arr.end(), greater<int>() );

    while( true )
    {
        bool check = true;
        int value = arr[0] * mul;
        for( int i = 1; i < size; ++i )
        {
            if( value % arr[i] != 0 )
            {
                check = false;
                break;
            }
        }
        if( check == true )
        {
            answer = arr[0] * mul;
            break;
        }
        ++mul;
    }

    return answer;
}
