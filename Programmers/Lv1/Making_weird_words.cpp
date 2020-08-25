#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int count = 1;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i]==' ')
        {
            count = 1;
            continue;
        }
        if(count % 2 == 0)
        {
            s[i] = tolower(s[i]);
        }
        else
        {
            s[i] = toupper(s[i]);
        }
        count++;
    }
    return s;
}