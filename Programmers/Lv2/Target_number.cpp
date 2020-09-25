#include <string>
#include <vector>

int count = 0;

using namespace std;

void dfs(vector<int> numbers, int sum, int target, int idx)
{
    if(idx == numbers.size())
    {
        if(sum == target) count++;
        return;
    }
    dfs(numbers, sum + numbers[idx], target, idx + 1);
    dfs(numbers, sum - numbers[idx], target, idx + 1);
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, 0, target, 0);
    return count;
}

/*
  처음 재출 시, 재귀 호출 부분에 쓸 데 없이 for문을 집어넣어 틀렸음.
*/