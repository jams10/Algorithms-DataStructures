#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    int *p = new int[n+1]();
    int count=0;
    
    for(int i = 2; i <= n; i++)
    {
        if(p[i] == 0)
        {
            // 해당 소수의 배수들을 모두 1로 체크
            for(int j = 2; i * j <= n; j++)
            {
                p[i*j] = 1;
            }
            count++;
        }
    }
    return count;
}