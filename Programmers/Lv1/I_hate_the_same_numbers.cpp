#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int tmp = -1;

    for (const auto& element : arr)
    {
        if (element != tmp)
        {
            answer.push_back(element);
            tmp = element;
        }
    }

    return answer;
}

/*
<다른 풀이>

unique 함수를 이용하는 방법.

1 1 1 2 3 4 5 6 7 7 -> '1 2 3 4 5 6 7' '6 7 7'
                        ▲변경되는 부분   ▲유지되는 부분

벡터의 초기 길이에서 중복된 값을 제외한 길이 만큼의 범위가 바뀜.
나머지 범위는 초기 벡터 값과 동일함.

unique 함수의 리턴 값은 바뀌지 않는 부분의 첫 부분(중복제거된 벡터의 끝 위치)
따라서 이를 통해 erase를 사용하여 제거하면 중복 제거된 벡터를 얻을 수 있음.

ex) v.erase(unique(v.begin(), v.end()), v.end());

참고 : https://dpdpwl.tistory.com/39
       https://m.blog.naver.com/PostView.nhn?blogId=withham1&logNo=221102099316&proxyReferer=https:%2F%2Fwww.google.com%2F
*/
