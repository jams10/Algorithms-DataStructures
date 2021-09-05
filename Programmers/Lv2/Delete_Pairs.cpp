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

// 처음에 단순히 string erase 써서 제출하니 시간초과.
// 서로 짝인 경우 홀수 짝수에 위치.( 이는 현재 시점에서 짝인 경우들을 제외하고 향후 짝이 될 수 있는 문자들에도 적용됨. )
// b a a b a a 
// 98 -97 +97 -98 +97 -97 = 0. 0인 경우 완벽하게 짝지어 지울 수 있음.
// 다른 풀이들을 보면 스택 자료구조로 풀었음. (같은거 들어오면 pop)
