#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> tmp = arr;
    vector<int> answer = arr;

    sort(tmp.begin(), tmp.end());
    int min = tmp[0];
    
    for(int i = 0; i < answer.size(); i++)
    {
        if(answer[i] == min)
        {
            answer.erase(answer.begin() + i);
            i--;
        }
    }
    if(answer.size() == 0)
    {
        return vector<int>(1,-1);
    }
    return answer;
}

/*
  제일 작은 수 구할 때 algorithm 헤더 파일의 min_element 사용 가능.

  참고 : https://m.blog.naver.com/PostView.nhn?blogId=chansung0602&logNo=221116097894&proxyReferer=https:%2F%2Fwww.google.com%2F
*/