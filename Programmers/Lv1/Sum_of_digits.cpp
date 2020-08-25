#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    long long int div1 = 10;
    long long int div2 = 1;
    while( div1 <= n *10 )
    {
        answer += (n % div1) / div2;
        div1*=10;
        div2*=10;
    }
    return answer;
}