#include <string>
#include <vector>
#include <map>

using namespace std;

void GetSubstr( const string s, vector<string>& result )
{
    int idx = 0;
    int length = s.size();

    for( int i = 0; i < length; i++ )
    {
        if( s[i] == ' ' )
        {
            result.emplace_back( s.substr( idx, i - idx ) );
            idx = i + 1;
        }
    }
    result.emplace_back( s.substr( idx, length - idx ) );
}

vector<string> solution( vector<string> record )
{
    vector<string> answer;
    vector<string> commandOrder;
    map<string, string> users;

    for( string s : record )
    {
        vector<string> subStrings;
        GetSubstr( s, subStrings );

        map<string, string>::iterator iter;

        commandOrder.emplace_back( subStrings[1] );

        iter = users.find( subStrings[1] );
        // 입장
        if( subStrings[0] == "Enter" )
        {
            // 처음 들어온 경우
            if( iter == users.end() )
            {
                users.insert( { subStrings[1], subStrings[2] } );
            }
            // 다시 들어온 경우
            else
            {
                iter->second = subStrings[2];
            }
        }
        // 이름 변경
        else if( subStrings[0] == "Change" )
        {
            iter->second = subStrings[2];
        }
    }

    int size = record.size();
    for( int i = 0; i < size; i++ )
    {
        char command = record[i][0];
        if( command == 'E' )
        {
            answer.emplace_back( users.find( commandOrder[i] )->second + "님이 들어왔습니다." );
        }
        else if( command == 'L' )
        {
            answer.emplace_back( users.find( commandOrder[i] )->second + "님이 나갔습니다." );
        }
    }

    return answer;
}

/* 다른 사람의 풀이 참고 */

/*
  빈칸으로 각 string을 나누는 걸 복잡한 for문으로 하지 않고 stringstream을 써서
  
    for(string input:record)
    {
        stringstream ss(input);
        ss>>command;
        ss>>uid;
        if(command=="Enter" || command=="Change")
        {
            ss>>ID;
            m[uid]=ID;
        }
    }
    위와 같은 방식으로 한번에 입력으로 들어온 스트링을 나누고 map에 저장할 수 있음.
    위와 같은 방식으로 하면 처음 들어왔을 때와 이름을 바꾸고 들어올 때 각각 따로 처리해주지 않아도 한방에 가능함.
*/
