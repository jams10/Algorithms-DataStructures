#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution( string s )
{
    vector<int> answer;
    map<int, vector<int>> cases;

    int size = s.size();
    for( int i = 1; i < size - 1; ++i )
    {
        if( s[i] == '{' )
        {
            int j = i + 1;
            vector<int> vTmp;
            string sTmp;
            for( ; ; ++j )
            {
                if( s[j] >= '0' && s[j] <= '9' )
                    sTmp += s[j];
                if( s[j] == ',' )
                {
                    vTmp.emplace_back( stoi( sTmp ) );
                    sTmp.clear();
                }
                if( s[j] == '}' )
                {
                    vTmp.emplace_back( stoi( sTmp ) );
                    break;
                }
            }
            cases.insert( make_pair( vTmp.size(), vTmp ) );
            i = j;
        }
    }

    int count = 1;
    while( true )
    {
        auto iter = cases.find( count );
        if( iter == cases.end() )
            break;
        vector<int> v = iter->second;
        int size = v.size();
        for( int i = 0; i < size; ++i )
        {
            if( find( answer.begin(), answer.end(), v[i] ) == answer.end() )
            {
                answer.emplace_back( v[i] );
            }
        }
        count++;
    }

    return answer;
}

/* 다른 사람의 풀이 참고 */
/*
   for(char i: s)
   {
        if(i-'0' >=0 && i-'0' <=9)
        {
            tmp += i;
        }
        else
        {   // 숫자 문자는 연속되어 있음. 111, 145, 1563 등.
            // 따라서 해당 문자가 숫자 문자일 때 tmp에 넣기 시작해서 숫자가 끝나고 ',' 나 '}' 등 다른 문자를 만나면, 
            // 해당 라운드에 tmp 문자열의 길이는 이미 1 이상이므로, 아래 조건문을 수행하게 된다.
            // 이 방법을 이용하면 ',' '{' '}' 경우들을 한 번에 처리할 수 있으므로 효율적이다. 
            if(tmp.length())
                st[stoi(tmp)]++, tmp.clear();
        }
    }
    
*/
