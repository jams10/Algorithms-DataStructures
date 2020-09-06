#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution( string s )
{
    // 압축된 문자열의 최대 길이 = 주어진 문자열의 길이
    int answer = s.length();
    
    for( int i = 1; i <= s.length() / 2; i++ )
    {
        int count = 1;
        string result = "";
        string tmp1 = s.substr( 0, i );

        for( int j = i; j < s.length(); j+=i )
        {
            string tmp2 = s.substr( j, i );

            if( tmp1 != tmp2 )
            {
                // 중복되는 것이 하나도 없을 시.
                if( count == 1 )
                {
                    result += tmp1;
                }
                // 중복되는 것이 있을시 중복 카운팅 숫자를 앞에 넣어줌.
                else
                {
                    count = 1;
                    result += to_string( count ) + tmp1;
                }
                tmp1 = tmp2;
            }
            else count++;
            
            if( j + i > s.length() - 1 )
            {
                if( count == 1 ) result += tmp2;
                else result += to_string( count ) + tmp2;
                break;
            }
        }
        answer = (answer < result.length()) ? answer : result.length();
    }

    return answer;
}