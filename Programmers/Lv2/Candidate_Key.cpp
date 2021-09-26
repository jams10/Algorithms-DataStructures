#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution( vector<vector<string>> relation )
{
    int sizeY = relation.size();
    int sizeX = relation[0].size();
    int maxComb = 1 << sizeX;

    vector<int> v_combs;

    // 조합 경우의 수
    for( int comb = 1; comb < maxComb; ++comb )
    {
        vector<vector<string>> v_tmp;
        bool isUnique = true;

        for( int y = 0; y < sizeY; ++y )
        {
            vector<string> tmp;
            for( int i = 0; i < sizeX; ++i )
            {
                // 조합의 비트 위치에 해당하는 배열 인덱스의 문자열 넣기
                if( comb & (1 << i) )
                {
                    tmp.push_back(relation[y][i]);
                }
            }
            // 유일성 체크
            auto iter = find_if( v_tmp.begin(), v_tmp.end(), [&tmp]( const vector<string>& vs )
                {
                    // 루프를 돌면서 모든 키들이 서로 똑같은 경우가 있는지를 체크함.
                    bool isSame = true;
                    int size = vs.size();
                    for( int i = 0; i < size; ++i )
                    {
                        if( vs[i] != tmp[i] )
                        {
                            isSame = false;
                            break;
                        }
                    }
                    return isSame;
                });
            if( iter == v_tmp.end() ) v_tmp.push_back( tmp );
            else
            {
                isUnique = false;
                break;
            }
        }
        if( isUnique )
        {
            // 최소성 체크
            auto iter = find_if( v_combs.begin(), v_combs.end(), [&comb]( const int& v_comb )
                {
                    // 새로운 조합이 포함하는 기존 조합들을 체크한다. 기존 조합 & 새로운 조합 == 기존 조합
                    return (v_comb & comb) == v_comb;
                });
            // 새로운 조합이 포함하는 기존 조합들이 없는 경우.
            if( iter == v_combs.end() ) v_combs.push_back( comb );
        }
    }
    return v_combs.size();
}

/*
  처음에 dfs 방법으로 풀려고 했으나, 비트 플래그를 이용하여 나올수 있는 조합들을 계산하는 방법도 있어서 이 방법으로 풀었음.
  비트 쉬프트 연산과 & 연산의 결과를 통해 나올 수 있는 조합의 최대치와 조합들간의 포함 여부를 체크할 수 있는 방법은 다른 문제에서도 유용할 것 같다.
*/
