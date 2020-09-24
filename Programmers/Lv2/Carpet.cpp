#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int y = sqrt(yellow); y > 0; --y)
    {
        if(yellow % y == 0)
        {
            int x = yellow / y;
            if( x*2 + y*2 + 4 == brown)
            {
                answer.emplace_back(x + 2);
                answer.emplace_back(y + 2);
                break;
            }
        }
    }
    return answer;
}