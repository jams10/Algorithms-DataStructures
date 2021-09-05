#include<iostream>
#include<string>
using namespace std;

int solution( string s )
{
    int length = s.length();
    int sum = 0;
    for( int i = 0; i < length; i++ )
    {
        if( i % 2 == 0 )
        {
            sum += s[i];
        }
        else sum -= s[i];
    }
    return sum == 0 ? 1 : 0;
}

// 서로 짝인 경우 홀수 짝수에 위치.( 이는 현재 시점에서 짝인 경우들을 제외하고 향후 짝이 될 수 있는 문자들에도 적용됨. )
// b a a b a a 
// 98 -97 +97 -98 +97 -97 = 0. 0인 경우 완벽하게 짝지어 지울 수 있음.
