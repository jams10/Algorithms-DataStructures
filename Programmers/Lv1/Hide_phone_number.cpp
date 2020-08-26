#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = phone_number;
    for(int i = answer.length() - 5; i >= 0; i--)
    {
        answer[i]='*';
    }
    return answer;
}