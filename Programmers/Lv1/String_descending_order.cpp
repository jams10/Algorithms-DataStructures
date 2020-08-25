#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const int& c1, const int& c2)
{
    return c1 > c2;
}

string solution(string s) 
{
    vector<char> v;
    for(int i = 0; i < s.length(); i++)
    {
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < s.length(); i++)
    {
        s[i]=v[i];
    }
    return s;
}

// 다른 방법
// string에 대해 직접 sort

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) 
{
    sort(s.begin(), s.end(), greater<char>());
    return s;
}