#include <string>
#include <vector>
#include <iostream>

using namespace std;

int right( const int& cur_idx, const string& name, int& next_idx)
{
    int count = 0;
    int i = cur_idx;
    while( name[i] == 'A' )
    {
        if( count > name.length() || i + 1 >= name.length() )
        {
            return -1;
        }
        i++;
        count++;
    }
    next_idx = i;
    return count;
}

int left( const int& cur_idx, const string& name, int& next_idx )
{
    int count = 0;
    int i = cur_idx;
    while( name[i] == 'A' )
    {
        if( count > name.length() ) break;
        if( i - 1 < 0 )
        {
            i = name.length();
        }
        i--;
        count++;
    }
    next_idx = i;
    return count;
}

int solution( string name )
{
    int answer = 0;
    int idx = 0, next_right = 0, next_left = 0;
    while( true )
    {
        // string이 모두 A인지 체크
        for( int i = 0; i < name.length(); i++ )
        {
            if( name[i] != 'A' ) break;
            if( i == name.length() - 1 ) return answer;
        }

        int right_count = right( idx, name, next_right );
        int left_count = left( idx, name, next_left );

        if( right_count != -1 && right_count <= left_count )
        {
            idx = next_right;
            answer += right_count;
        }
        else
        {
            idx = next_left;
            answer += left_count;
        }
        answer += name[idx] - 'A' < 'Z' - name[idx] + 1 ? name[idx] - 'A' : 'Z' - name[idx] + 1;
        name[idx] = 'A';
    }
    cout << name << endl;
    return answer;
}

// 프로그래머스 답안 LUT 사용 참고 & 코드 수 줄이기

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution( string name )
{
    // A에서 특정 알파벳으로 바꿀 때 몇번이 걸리는지 미리 저장해둔 테이블
    int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 }; 
    int answer = 0;
    // 미리 알파벳들을 변환했을 때의 수를 답에 저장.
    for( const auto e : name ) answer += LUT[e - 'A'];
    
    int len = name.length();
    int idx = 0;
    string finish( name.length(), 'A' );
    
    while( true )
    {
        for( int i = 0; i < len; i++ )
        {
            // 오른쪽으로 진행 string 인덱스 초과시 오류 발생 => mod 연산 사용하여 길이만큼 나눔.
            if( name[(idx + i) % len] != 'A' )
            {
                answer += i;
                name[(idx + i) % len] = 'A';
                idx = (idx + i) % len;
                break;
            }
            // 왼쪽으로 진행
            else if( name[(len + idx - i) % len] != 'A' )
            {
                answer += i;
                name[(len + idx - i) % len] = 'A';
                idx = (len + idx - i) % len;
                break;
            }
        }
        if( finish == name ) break;
    }
    return answer;
}