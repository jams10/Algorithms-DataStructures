#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution( vector<string> info, vector<string> query )
{
    vector<int> answer;
    vector<int> vols[3][2][2][2];

    map<string, int> infos = {
        make_pair( "cpp",0 ), make_pair( "java", 1 ), make_pair( "python",2 ),
        make_pair( "backend", 0 ), make_pair( "frontend", 1 ),
        make_pair( "junior", 0 ), make_pair( "senior", 1 ),
        make_pair( "chicken", 0 ), make_pair( "pizza", 1 ) };

    for( string s : info )
    {
        stringstream ss( s );
        string lang, part, rank, food, score;
        ss >> lang >> part >> rank >> food >> score;
        vols[infos[lang]][infos[part]][infos[rank]][infos[food]].push_back( stoi( score ) );
    }

    for( int i = 0; i < 3; ++i )
        for( int j = 0; j < 2; ++j )
            for( int k = 0; k < 2; ++k )
                for( int l = 0; l < 2; ++l )
                    sort( vols[i][j][k][l].begin(), vols[i][j][k][l].end() );

    for( string s : query )
    {
        stringstream ss( s );
        string strings[4] = { "", };
        string tmp;
        int score = 0, matched = 0, count = 0;

        for( int i = 0; i < 7; ++i )
        {
            ss >> tmp;
            if( i % 2 == 0 )
            {
                strings[count] = tmp;
                count++;
            }
        }
        ss >> tmp;
        score = stoi( tmp );

        int im, iM, jm, jM, km, kM, lm, lM;

        if( strings[0] == "-" ) { im = 0; iM = 2; }
        else im = iM = infos[strings[0]];

        if( strings[1] == "-" ) { jm = 0; jM = 1; }
        else jm = jM = infos[strings[1]];

        if( strings[2] == "-" ) { km = 0; kM = 1; }
        else km = kM = infos[strings[2]];

        if( strings[3] == "-" ) { lm = 0; lM = 1; }
        else lm = lM = infos[strings[3]];

        for(int i = im; i <= iM; ++i )
            for(int j = jm; j <= jM; ++j )
                for(int k = km; k <= kM; ++k )
                    for( int l = lm; l <= lM; ++l )
                    {
                        int size = vols[i][j][k][l].size();
                        if( size == 0 ) continue; // 처음에 break을 사용했으나, break을 사용하면 X. 
                        // ex) 2110에 해당하는 지원자가 없고, 2111에 해당하는 지원자들이 존재하는 경우, 2110에서 l인덱스 for문이 탈출되어 2111까지 가지 못함.
                        
                        // lower_bound 함수는 이진 탐색(binary search)을 통해 들어온 값보다 작지 않은 첫번째 값을 리턴.
                        auto iter = lower_bound( vols[i][j][k][l].begin(), vols[i][j][k][l].end(), score );

                        if( iter != vols[i][j][k][l].end() )
                        {
                            matched += size - (iter - vols[i][j][k][l].begin());
                        }
                    }
        answer.push_back( matched );
    }

    return answer;
}

/* 다른 사람의 풀이 참조 */

/*
  참조 : https://yjyoon-dev.github.io/kakao/2021/01/29/kakao-ranksearch/
  
  infos의 스트링을 분할하여 저장하는 것 까지는 구현했으나, 어떤 자료 구조를 이용해 탐색할지 감이 안잡혀서 구글 검색을 통해 다른분의 풀이를 참조하여 작성하였음.
  탐색 조건들을 벡터 인덱스로 보고 각 조건의 크기를 벡터의 저장 공간 범위로 지정함. 그 후, 탐색의 주 대상이 되는 점수를 조건에 해당하는 인덱스에 차례대로 넣고,
  미리 정렬을 시킨뒤에 이진 탐색으로 탐색을 하면 효율성을 통과할 수 있음.
*/
