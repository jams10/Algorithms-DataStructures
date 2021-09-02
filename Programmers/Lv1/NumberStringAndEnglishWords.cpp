#include <string>
#include <vector>

using namespace std;

int solution( string s )
{
    int answer = 0;

    string sArr[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    int input_string_length = s.size();

    for( int i = 0; i < input_string_length; i++ )
    {
        if( s[i] >= '0' && s[i] <= '9' )
        {
            answer = answer * 10 + (s[i] - '0');
        }
        else
        {
            for( int j = 0; j < 10; j++ )
            {
                if( s[i] == sArr[j][0] && s[i + 1] == sArr[j][1] )
                {
                    answer = answer * 10 + j;

                    i += (sArr[j].size() - 1);

                    break;
                }
            }
        }
    }

    return answer;
}
