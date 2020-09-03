#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int day = 0, idx = 0, count = 0;

    for(const auto& e : progresses) q.push(e);

    for(day=1; ;day++)
    {
        if(q.empty()) break;
        while(true)
        {
            if(!q.empty() && q.front() + speeds[idx] * day >= 100)
            {
                q.pop();
                count++;
                idx++;
            }
            else break;
        }
        if(count)
        {
            answer.emplace_back(count);
            count = 0;
        }
    }
    return answer;
}