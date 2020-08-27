#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int sum = 0, count = 0;

    for(const auto& element : d)
    {
        sum += element;
        if(sum <= budget)
        {
            count++;
        }
        else return count;
    }

    return count;
}
/*
  처음 문제 접근시 dfs로 접근하였음. -> 시간, 메모리 둘다 비효율적.
  좀 더 다양한 시각, 쉬운 방법을 생각해보는 접근 방법이 필요!
*/