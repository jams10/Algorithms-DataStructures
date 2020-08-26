#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long tmp = num;
    int count = 0;
    while(tmp != 1)
    {
        if(count > 500) return -1;
        tmp = tmp % 2 == 0 ? tmp /= 2 : tmp = tmp * 3 + 1;
        count++;
    }
    return count;
}

/*
 홀수 일 때 곱하기 연산으로 int 범위가 넘어갈 수 있으므로 long long 타입으로 해결.
*/