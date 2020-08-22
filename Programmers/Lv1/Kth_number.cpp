#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;

    for(int i = 0; i < commands.size(); i++)
    {
      tmp = arr;
      sort(tmp.begin() + commands[i][0] - 1, tmp.begin() + commands[i][1]);
      answer.push_back(tmp[commands[i][0] + commands[i][2] - 2]);
    }
    return answer;
}