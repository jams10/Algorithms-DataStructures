// <내 풀이>
#include <string>
#include <vector>

using namespace std;

string solution( string new_id )
{
    string tmp_id = new_id;
    string answer = "";

    int length = tmp_id.size();

    for( int i = 0; i < length; i++ )
    {
        // 1단계 : new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
        // 2단계 : new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
        if( tmp_id[i] == '-' || tmp_id[i] == '_' || tmp_id[i] == '.' ||
            (tmp_id[i] >= 'A' && tmp_id[i] <= 'Z') ||
            (tmp_id[i] >= 'a' && tmp_id[i] <= 'z') ||
            (tmp_id[i] >= '0' && tmp_id[i] <= '9') )
        {
            if( isupper( tmp_id[i] ) )
            {
                answer += tmp_id[i] + 32;
            }
            else answer += tmp_id[i];
        }
    }

    //3단계 : new_id에서 마침표( . )가 2번 이상 연속된 부분을 하나의 마침표( . )로 치환합니다.
    for( int i = 0; i < answer.size(); i++ )
    {
        int count = 0;
        if( answer[i] == '.' )
        {
            for( int j = i; answer[j] == '.'; j++ )
            {
                count++;
            }
            answer.replace( i, count, "." );
        }
    }

    // 4단계 : new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if( answer.size() > 0 && *answer.begin() == '.' )
    {
        answer.erase( answer.begin() );
    }
    if( answer.size() > 0 && *(answer.end() - 1) == '.' )
    {
        answer.erase( answer.end() - 1 );
    }

    // 5단계 : new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if( answer.size() == 0 ) answer = "a";

    // 6단계 : new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    //         만약 제거 후 마침표( . )가 new_id의 끝에 위치한다면 끝에 위치한 마침표( . ) 문자를 제거합니다.
    if( answer.size() >= 16 )
    {
        answer = answer.substr( 0, 15 );
    }
    if( *(answer.end() - 1) == '.' ) answer.erase( answer.end() - 1 );

    // 7단계 : new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    if( answer.size() <= 2 )
    {
        int count = 3 - answer.size();
        for( int i = 0; i < count; i++ )
        {
            answer += *(answer.end() - 1);
        }
    }

    return answer;
}

// <다른 사람 풀이>
#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32; // 대문자 -> 소문자로 변경. 비트 OR 연산자로 65 + 32 = 97

    string ret;
    for (char& ch: new_id) {
        if ('a' <= ch && ch <= 'z' ||     // 숫자, 알파벳, -_.만 저장
            '0' <= ch && ch <= '9' ||
            strchr("-_.", ch)) ret += ch; // strchr은 문자열에서 문자 검색해주는 함수
    }

    new_id = ret;
    ret.clear();
    for (char& ch: new_id) {               // ret 스트링은 처음에 비어있음. 
        if (!ret.empty() && ret.back() == '.' && ch == '.') continue; // ret 스트링이 비어있지 않고 && 현재 ret 스트링의 끝이 '.' 문자이고 && 현재 다음으로 들어갈 문자가 '.' 이면
        ret += ch;                                                    // continue를 통해 해당 문자를 스킵함.
    }

    if (ret.front() == '.') ret.erase(ret.begin());
    if (ret.back() == '.') ret.pop_back();

    if (ret.empty()) ret = "a";
    if (ret.size() >= 16) ret = ret.substr(0, 15);
    if (ret.back() == '.') ret.pop_back();
    while (ret.size() <= 2) ret += ret.back();

    return ret;
}
