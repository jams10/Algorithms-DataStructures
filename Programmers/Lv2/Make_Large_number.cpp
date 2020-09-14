#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution( string number, int k )
{
    string answer = "";
    int len = number.length();
    int count = 0, start = 0;
    while( count < len - k )
    {
        int max = -1, tmp = 0;
        for( int i = start; i < len; i++ )
        {
            if( len - i < len - k - count ) break;
            if( max <= number[i] )
            {
                max = number[i];
                tmp = i;
            }
        }
        answer += max;
        start = tmp + 1;
        count++;
    }
    return answer;
}