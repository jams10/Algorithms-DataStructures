#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution( vector<int> people, int limit )
{
    int answer = 0;

    sort( people.begin(), people.end(), greater<int>());

    int i = 0, j = people.size() - 1;
    while( i <= j )
    {
        if( people[i] + people[j] <= limit )
        {
            answer++;
            i++;
            j--;
        }
        else
        {
            answer++;
            i++;
        }
    }

    return answer;
}

/*
  제일 처음 제출 시, vector에 대해 매번 삭제 연산을 수행하여 시간 초과 발생.
  삭제 연산이 아닌, 단순히 인덱스 증가 감소 연산을 사용하여 제출하니 해결.
*/