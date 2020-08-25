#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    sort(arr.begin(), arr.end());
    for(const auto& element : arr)
    {
        if(element%divisor==0)
        {
            answer.push_back(element);
        }
    }
    if(answer.size()==0)
    {
        answer.push_back(-1);
        return answer;
    }
    return answer;
}