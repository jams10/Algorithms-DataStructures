#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string s="";
    for(int i = 1; i <= n; i++)
    {
        i%2!=0 ? s.append("수") : s.append("박");
    }
    return s;
}

/*
 append 함수 대신 += 연산자 이용 가능
*/