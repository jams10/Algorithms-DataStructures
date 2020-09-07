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