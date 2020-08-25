#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        if(n%i==0)
        {
            answer+= i; 
        }
    }
    return answer;
}

/*
    범위를 n/2까지만 수행해도 충분히 구할 수 있음.
    for(int i = 1; i <= n/2; i++)
    {
        if(n%i==0)
        {
            answer+= i; 
        }
    }
    return answer + n; // 자기 자신도 약수
*/