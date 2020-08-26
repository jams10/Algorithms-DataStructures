#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void set(int& pos, const int& value, string& answer, const string& s)
{
    pos = value;
    answer += s;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lPos=10, rPos=12;
    int nextN = 0;
    for(const auto& element : numbers)
    {
        if(element%3 == 1) set(lPos, element, answer, "L");

        else if(element%3 == 0 && element != 0) set(rPos, element, answer, "R");

        else
        {
            int lDis = 0, rDis = 0;
            if(element == 0) nextN = 11;
            else nextN = element;
            
            // 다음 누를 버튼 위치 , 현재 위치 2,5,8,0 자리에 위치할 경우 아래 위로 한 칸씩
            // 이동 하는 것은 숫자의 순서에 따라 3만큼 증가 감소하는 것과 같음.
            if(lPos % 3 != 1) lDis = abs(nextN - lPos) / 3; 
            // 현재 위치가 1,4,7 등의 왼쪽 버튼인 경우에 위 아래 이동 계산을 위해 
            // 다음 누를 버튼 - 1 을 하여 가운데 숫자를 1,4,7 열 숫자로 만들어 계산. 
            // 가로 움직임의 경우 가운데-> 왼쪽 한 번 이므로 + 1
            else lDis = abs(nextN - 1 - lPos) / 3 + 1;
            
            if(rPos % 3 != 0) rDis = abs(nextN - rPos) / 3;
            else rDis = abs(nextN + 1 - rPos) / 3 + 1;
            
            if(lDis == rDis)
            {
                if(hand == "left") set(lPos, nextN, answer, "L");

                else set(rPos, nextN, answer, "R");
 
            }
            else if(lDis < rDis) set(lPos, nextN, answer, "L");

            else set(rPos, nextN, answer, "R");
        }
    }
    
    return answer;
}