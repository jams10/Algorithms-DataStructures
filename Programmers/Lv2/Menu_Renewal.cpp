#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define CUISINE_SIZE 10
#define COURSE_SIZE 10

vector<char> Tmp;
bool Selected[CUISINE_SIZE];

void DFS( int idx, int cnt, int size, string s, map<string,int>& comb )
{
    if( cnt == size )
    {
        string tmp = "";
        for( char c : Tmp )
        {
            tmp += c;
        }
        map<string, int>::iterator it = comb.find( tmp );
        if( it != comb.end() ) it->second += 1;
        else comb.insert( make_pair( tmp, 0 ) );
        return;
    }

    for( int i = idx; i < s.size(); ++i )
    {
        if( Selected[i] == true ) continue;
        Selected[i] = true;
        Tmp.emplace_back( s[i] );

        DFS( i, cnt + 1, size, s, comb );
        Tmp.pop_back();
        Selected[i] = false;
    }

    return;
}

vector<string> solution( vector<string> orders, vector<int> course )
{
    vector<string> answer;

    for( int i : course )
    {
        map<string, int> orderComb;
        for( string s : orders )
        {
            sort( s.begin(), s.end() );
            DFS( 0, 0, i, s, orderComb );
        }
        map<string, int>::iterator it;
        map<string, int>::iterator itEnd = orderComb.end();
        int max = 1;
        for( it = orderComb.begin(); it != itEnd; ++it )
        {
            if( it->second > max ) max = it->second;
        }
        for( it = orderComb.begin(); it != itEnd; ++it )
        {
            if( it->second == max ) answer.emplace_back( it->first );
        }
    }

    sort( answer.begin(), answer.end() );

    return answer;
}

/* 다른 사람 풀이 참고 */
/*
  조합 부분을 다음과 같이 축약할 수 있음.
  
  void combination(string src, string crs, int depth) {
    if (crs.size() == depth) combi[crs]++;

    else for (int i = 0; i < src.size(); i++)
        combination(src.substr(i+1), crs+src[i], depth);
  }
  
  combi[crs]++ 부분은 해당하는 crs키 값을 가진 데이터가 없으면 만들어주고, 있으면 해당 값에 ++ 해줌.
  재귀함수 호출 부분은 substr(i+1)로 처음에 ABCD가 들어왔다면 substr(1) -> BCD, substr(2) -> CD, substr(3) -> D 이런식으로 넘겨주고,
  crs+src[i]로 서브 스트링을 제외한 부분을 붙여 넣어 조합을 완성한다.
*/
