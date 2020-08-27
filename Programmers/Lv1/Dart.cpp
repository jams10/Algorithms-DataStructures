#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0, cur_idx = 0, next_idx = 0;
    int arr[3];
    for (int i = 0; i < 3; i++) arr[i] = 0;

    for (int i = 0; i < dartResult.length(); i++)
    {
        if (isdigit(dartResult[i]))
        {
            cur_idx = next_idx;
            if (isdigit(dartResult[i + 1]))
            {
                arr[cur_idx] = (dartResult[i] - '0') * 10;
                i++;
            }
            else arr[cur_idx] = dartResult[i]-'0';
            next_idx = cur_idx + 1;
        }

        if (dartResult[i] == 'D') arr[cur_idx] *= arr[cur_idx];
        else if (dartResult[i] == 'T') arr[cur_idx] *= arr[cur_idx] * arr[cur_idx];

        if (dartResult[i] == '*')
        {
            arr[cur_idx] *= 2;
            if (cur_idx > 0)
            {
                arr[cur_idx - 1] *= 2;
            }
        }

        if (dartResult[i] == '#')
        {
            arr[cur_idx] *= -1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        answer+=arr[i];
    }
    return answer;
}

/*
  '중첩' 일 때의 계산을 잘못 파악함.
  1S*2S3S* => 2 + 4 + 6. 처음 코드 작성 시 (1 * 2 * 2) + (2 * 2) + (3 * 2) 로 작성 하였음.
*/