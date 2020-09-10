#include <string>
#include <vector>
#include <math.h>

using namespace std;

// 방문 인덱스 체크
int visited[8]={0, };
// 만들어진 숫자 중복 숫자 체크
int duplicated[10000000]={0, };

bool CheckPrime(int n)
{
    if(n == 0 || n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

void DFS(string numbers, string made, int count, int& answer)
{
    int n = 0;
    if(made != "") n = stoi(made);
    // 이 조건에서 return을 하면 첫 한자리 숫자만 검색하고 끝나버림.
    if(!duplicated[n])
    {
        duplicated[n] = 1;
        if(CheckPrime(n)) answer++;
    }
    // for문 시작 지점을 계속 0으로 해야 모든 경우의 수 찾을 수 있음.
    for(int i = 0; i < numbers.length(); i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            DFS(numbers, made + numbers[i], count + 1, answer);
            visited[i] = 0;
        }
    }
    return;
}

int solution(string numbers) {
    int answer = 0;
    DFS(numbers, "", 0, answer);
    return answer;
}