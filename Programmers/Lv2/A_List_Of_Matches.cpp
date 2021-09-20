#include <iostream>
#include <math.h>

using namespace std;

int solution( int n, int a, int b )
{
    int answer = 0;

    while( true )
    {
        if( a == b ) return answer;
        if( a >= 2 )
        {
            if( a % 2 != 0 ) a += 1;
            a /= 2;
        }
        if( b >= 2 )
        {
            if( b % 2 != 0 ) b += 1;
            b /= 2;
        }
        answer++;
    }
}
