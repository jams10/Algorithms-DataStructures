#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0, count = 0;
    int len = citations.size();
    sort(citations.begin(), citations.end());
    for(int i = 0; i < citations[len - 1]; i++)
    {
        for(int vectorIdx = 0; vectorIdx < len; vectorIdx++)
        {
            if( i <= citations[vectorIdx] )
            {
                count = vectorIdx;
                break;
            }
        }
        if(len - count >= i && count <= i)
        {
            answer = answer < i ? i : answer;
        }
    }
    return answer;
}