#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s = "0123456789ABCDEF";

string GetNotationNumber( int notation, int number )
{
    string result = "";

    if( number < notation ) return result += s[number];
    else
    { 
        for( ; number > 0;)
        {
            result += s[number % notation];
            number /= notation;
        }
    }
    // n진수를 구할 때 나머지의 역순으로 구성되므로 마지막에 리버스 해준다.
    reverse( result.begin(), result.end() );
    return result;
}

string solution( int n, int t, int m, int p )
{
    string answer = "";
    int tCount = 0, wholeCount = 0;
    for( int number = 0; number < t * m; ++number )
    {
        string curNumber = GetNotationNumber( n, number );
        int size = curNumber.size();

        for( int i = 0; i < size; ++i )
        {
            if( tCount == t ) break;
            if( wholeCount % m == (p - 1) )
            {
                tCount++;
                answer += curNumber[i];
            }
            ++wholeCount;
        }
        if( tCount == t ) break;
    }

    return answer;
}

/*
  n진법에 따른 숫자 구하는 코드 기억해 둘 것.
*/
