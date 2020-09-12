#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect( string s )
{
    stack<char> st;
    st.push( s[0] );
    for( int i = 1; i < s.length(); i++ )
    {
        if( !st.empty() )
        {
            if( st.top() == '(' && s[i] == ')' )
            {
                st.pop();
            }
            else st.push( s[i] );
        }
        else st.push( s[i] );
    }
    return st.empty();
}

string isBalanced( string s )
{
    if( s == "" ) return s;
    int leftCount = 0, rightCount = 0;
    string resultString = "", u = "", v = "";
    for( int i = 0; i < s.length(); i++ )
    {
        if( s[i] == '(' ) leftCount++;
        else leftCount--;
        if( leftCount == 0 )
        {
            u = s.substr( 0, i + 1 );
            v = s.substr( i + 1, s.length() - (i + 1) );
            break;
        }
    }
    if( isCorrect( u ) )
    {
        resultString = u + isBalanced( v );
        return resultString;
    }
    else
    {
        resultString = '(' + isBalanced( v ) + ')';
        for( int i = 1; i < u.length() - 1; i++ )
        {
            resultString += u[i] == '(' ? ')' : '(';
        }
        return resultString;
    }
}

string solution( string p )
{
    string answer = p;
    if( !isCorrect( p ) )
    {
        answer = isBalanced( p );
    }
    return answer;
}

/*
  <프로그래머스 풀이 참조>
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect( const string& s )
{
    int count = 0;
    for( const auto& e : s )
    {
        // 균형 체크의 경우에, 스택 사용할 필요 없이 왼쪽에서 오른쪽으로 '(' 를 체크해 주면 됨.
        // '(' 다음에 ')'가 나와 +연산이 -연산과 만나 상쇄되기 때문에 음수가 될 경우 짝이 맞지 않음을 의미함.
        if( e == '(' ) ++count;
        else --count;
        if( count < 0 ) return false;
    }
    return true;
}

string isBalanced( const string& s )
{
    if( s == "" ) return s;
    int count = 0;
    string resultString = "", u = "", v = "";
    for( int i = 0; i < s.length(); i++ )
    {
        if( s[i] == '(' ) ++count;
        else --count;
        if( count == 0 )
        {
            u = s.substr( 0, i + 1 );
            v = s.substr( i + 1, s.length() - (i + 1) );
            break;
        }
    }
    if( isCorrect( u ) )
    {
        resultString = u + isBalanced( v );
        return resultString;
    }
    else
    {
        resultString = "(" + isBalanced( v ) + ")";
        for( int i = 1; i < u.length() - 1; i++ )
        {
            resultString += u[i] == '(' ? ')' : '(';
        }
        return resultString;
    }
}

string solution( string p )
{
    string answer = p;
    if( !isCorrect( p ) && p != "" )
    {
        answer = isBalanced( p );
    }
    return answer;
}