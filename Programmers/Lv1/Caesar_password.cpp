#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i = 0; i < s.length(); i++)
    {
        if(isupper(s[i]))
        {
            if(s[i] + n > 90)
            {
                s[i] = (s[i] + n) % 90 + 64;
            }
            else
            {
                s[i] += n;
            }
        }
        else if(islower(s[i]))
        {
            if(s[i] + n > 122)
            {
                s[i] = (s[i] + n) % 122 + 96;
            }
            else
            {
                s[i] += n;
            }
        }
    }
    return s;
}

/*
  <다른 풀이 방법>
  알파벳 개수 26개임을 이용,
  소문자의 경우 : s[i] = 97 + (s[i] - 97 + n) % 26;
                      ▲소문자 'a' 아스키 값
*/