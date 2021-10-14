#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution( string msg )
{
    vector<int> answer;

    map<string, int> m;

    for( char c = 'A'; c <= 'Z'; ++c )
    {
        string alphabet = "";
        m.insert( make_pair( alphabet + c, c - 'A' + 1 ) );
    }

    int number = m.size();
    int size = msg.size();
    map<string, int>::iterator findIter;
    map<string, int>::iterator endIter = m.end();
    for( int i = 0; i < size; ++i)
    {
        string word = "";
        for( int j = 0; j < size; ++j )
        {
            findIter = m.find( word + msg[i + j] );
            if( findIter == endIter )
            {
                findIter = m.find( word );
                answer.push_back( findIter->second );
                m.insert( make_pair( word + msg[i + j], ++number ) );
                i += j - 1;
                break;
            }
            else
            {
                word += msg[i + j];
                // 더 이상의 긴 단어가 없으면 그냥 답에 넣기
                if( j == size - 1 )
                {
                    findIter = m.find( word );
                    answer.push_back( findIter->second );
                }
            }
        }
    }

    return answer;
}

/*
  기존 코드가 입력이 "A" 일 경우를 처리하지 못했음.
  
  테스트 시에 입력이 가장 짧은 경우에 대해서도 생각할 것.
*/
