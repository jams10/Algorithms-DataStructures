#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(int i = 0; i < clothes.size(); i++)
    {
        if(m.find(clothes[i][1]) != m.end())
        {
            m[clothes[i][1]]++;
        }
        else
        {
            m.insert(make_pair(clothes[i][1], 1));
        }
    }
    for(auto iter : m) answer *= (iter.second + 1);
    
    return answer - 1;
}

/*
  이 문제의 핵심 규칙

  모자 : 빨간 모자, 파란 모자
  바지 : 파란 바지
  신발 : 초록 신발, 노랑 신발

  모자의 선택 경우의 수 : 하나도 선택 X, 빨간 모자, 파란 모자  = 3
  바지의 선택 경우의 수 : 하나도 선택 X, 파란 바지            = 3
  신발의 선택 경우의 수 : 하나도 선택 X, 초록 신발, 노랑 신발  = 3

  따라서, 총 경우의 수는 3*3*3 인데, 문제에서 옷은 무조건 하나라도 입는다고 조건을 제시했으므로,
  하나도 선택을 하지 않는 경우 하나를 빼주면 된다.

*/