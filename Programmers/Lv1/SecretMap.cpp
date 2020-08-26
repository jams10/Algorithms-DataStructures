#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> getBinary(int n, int size);

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < arr1.size(); i++)
    {
        vector<int> tmp1 = getBinary(arr1[i], n);
        vector<int> tmp2 = getBinary(arr2[i], n);
        string s="";
        for(int j = 0; j < tmp1.size(); j++)
        {
            if(tmp1[j] == 0 && tmp2[j] == 0)
            {
                s+=" ";
            }
            else s+="#";
        }
        answer.emplace_back(s);
    }
    
    return answer;
}

vector<int> getBinary(int n, int size)
{
    vector<int> v;
    while(n)
    {
        v.insert(v.begin(), n % 2);
        n /= 2;
    }
    if(v.size() < size)
    {
        int len = size - v.size();
        for(int i = 0; i < len; i++)
        {
            v.insert(v.begin(),0);
        }
    }
    for(const auto& element : v)
    {
        cout<<element;
    }
    return v;
}

/*
  <다른 풀이>
  비트 연산자를 이용하면 함수를 만들지 않고 두 숫자간의 비트 비교를 할 수 있음.

  | 연산자 : 같은 위치간 비트가 모두 0일때만 0 반환.

  첫번째 벡터 요소 | 두번째 벡터 요소 = 각 벡터 요소의 비트 중 둘다 0인 비트만 0으로 바뀜.

  그 후에, 이 숫자를 % 2 연산을 통해 나머지 0일 경우 공백, 아니면 벽으로 설정해 줌.
  이진수 숫자 변환 시에 n /= 2 는 n >> 1 과 같음.

*/