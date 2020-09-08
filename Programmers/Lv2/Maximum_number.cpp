#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp( string s1, string s2 )
{
    // 조건이 true인 경우로 정렬을 시행함.
    // ex) a < b 인 경우 오름차순(a < b 인 경우에 true 이므로)
    //     a > b 인 경우 내림차순(a > b 인 경우에 true 이므로)
    // s1 = "10", s2 = "101" 인 경우에 s1+s2 = "10101", s2+s1 = "10110"
    // "10101" > "10110" = false
    // s1 = "101", s2 = "10" 인 경우에 비로소 true가 되므로 이 순서대로 정렬.
    return s1 + s2 > s2 + s1;
}

string solution( vector<int> numbers )
{
    string answer = "";

    vector<string> v;
    for( const auto& e : numbers ) v.emplace_back( to_string( e ) );

    sort( v.begin(), v.end(), comp);

    for( const auto& e : v )
    {
        answer += e;
    }
    // 0만으로 구성된 수는 0
    if(atoi( answer.c_str() )==0) answer = "0";
    return answer;
}

/*
  <invalid comparator 에러>

  sort 함수의 비교 함수는 a > b 와 b > a 가 동시에 true를 리턴할 수 없다는
  strick-weark-order를 만족해야 함.

  따라서 comp(a,b) 가 true 일 때, comp(b,a) 도 true 일 수 없음.
  또한 a==b 일 때 a > b 가 false 이면 

*/