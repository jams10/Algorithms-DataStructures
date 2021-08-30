#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int length = lottos.size();
    int match = 0;
    int zeros = 0;

    int Ranking[6] = { 6,5,4,3,2,1 };

    for( int i = 0; i < length; i++ )
    {
        if( lottos[i] == 0 )
        {
            zeros++;
            continue;
        }
        for( int j = 0; j < length; j++ )
        {
            if( lottos[i] == win_nums[j] )
            {
                match++;
            }
        }
    }
    
    // 0이 없고 숫자가 다 다르면 match, zeros가 둘다 0이 됨. 여기서 -1을 하면 인덱스 에러가 일어나므로 이를 방지.
    int highest = match + zeros - 1 < 0 ? 0 : match + zeros - 1;
    int lowest = match - 1 < 0 ? 0 : match - 1;
    
    /*
        다른 사람의 풀이를 보니 아래와 같이 배열을 안쓰고 함수 만든다음 그냥 계산해 버리는 방법도 있음.
        if(num == 1 || num == 0) return 6;
        else return 7 - num;
    */

    answer.emplace_back( Ranking[highest] );
    answer.emplace_back( Ranking[lowest] );

    return answer;
}
