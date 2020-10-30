#include <string>
#include <vector>
#include <iostream>

using namespace std;

void recur(const vector<vector<int>>& subArr, vector<int>& answer, int startY, int startX, int len)
{
    if(len == 1)
    {
        answer[subArr[startY][startX]]++;
        return;
    }
    
    int sum = 0;
    for(int y = startY; y < startY + len; ++y)
    {
        for(int x = startX; x < startX + len; ++x)
        {
            sum += subArr[y][x];
        }
    }
    if(sum == len * len)
    {
        answer[1]++;
        return;
    }
    else if(sum == 0)
    {
        answer[0]++;
        return;
    }
    else
    {
        recur(subArr, answer, startY, startX, len/2);
        recur(subArr, answer, startY, startX + len/2, len/2);
        recur(subArr, answer, startY + len/2, startX, len/2);
        recur(subArr, answer, startY + len/2, startX + len/2, len/2);
    }
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = {0,0};
    recur(arr, answer, 0, 0, arr.size());

    return answer;
}