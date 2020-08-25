#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx = 0;

bool comp(string s1, string s2)
{
    if(s1[idx]==s2[idx])
    {
        return s1 < s2;
    }
    else
    {
        return s1[idx] < s2[idx];
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    idx = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}