#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if(s.length() == 4 || s.length() == 6)
    {
        for(const auto& element : s)
        {
            if(element < 48 || element > 57)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

/*
  숫자 타입 체크는 isdigit() 함수를 통해서도 가능.
  매개변수로 들어온 char가 10진수로 변환 가능하면 true를 리턴.
*/
