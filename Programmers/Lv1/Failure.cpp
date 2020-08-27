#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct stage
{
    int stageN;
    double failN;
}stage;

bool comp(stage st1, stage st2)
{
    // 실패율이 같을 때는 스테이지가 작은 순으로 정렬
    // 정렬할 대상의 값들이 같은 경우 어떻게 처리할지 항상 설정해 둘 것.
    if (st1.failN == st2.failN) return st1.stageN < st2.stageN;
    else return st1.failN > st2.failN;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<stage> vStage;
    int count = 0, size = stages.size();

    for (int i = 0; i < N; i++)
    {
        stage st = { i + 1,0.0 };
        vStage.emplace_back(st);
    }

    for (int i = 1; i <= N; i++)
    {
        // 모든 플레이어가 해당 스테이지에 도착을 하지 못한 경우를 체크.
        // 해당 조건을 체크하지 않아 실패했음. 문제의 보이지 않는 조건들을 파악하는 것이 중요.
        if (stages.size() == 0)
        {
            vStage[i - 1].failN = 0;
        }
        else
        {
            for (int j = 0; j < stages.size(); j++)
            {
                if (stages[j] == i)
                {
                    vStage[i - 1].failN += 1;
                    stages.erase(stages.begin() + j);
                    count++;
                    j--;
                }
            }
            if (size == 0)
            {
                vStage[i - 1].failN = 1.0;
            }
            else vStage[i - 1].failN /= size;
            size -= count;
            count = 0;
        }
    }

    sort(vStage.begin(), vStage.end(), comp);

    for (const auto& e : vStage)
    {
        answer.emplace_back(e.stageN);
    }

    return answer;
}