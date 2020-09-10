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

/*
  <순열과 조합>
  순열은 순서 상관 O 뽑기 / 조합은 순서 상관 X 뽑기
  따라서, 순열을 DFS 로 구현할 시 탐색하는 for문의 인덱스가 계속해서 0 부터 시작하여 
  처음부터 계속 탐색하는 반면에, 조합을 구현할 때는 인덱스를 매개변수로 넘겨주면서
  재귀에서 리턴해 돌아오면 인덱스가 증가하면서 이전 인덱스는 고려하지 않게 된다.

  
*/