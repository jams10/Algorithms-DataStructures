#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution( string s )
{
    int answer = 0;
    int size = s.length();

    for( int i = 0; i < size; ++i )
    {
        stack<char> brackets;
        char bracket = ' ';
        for( int j = 0; j < size; ++j )
        {
            if( !brackets.empty( ) ) bracket = brackets.top();
            if( bracket == '[' && s[(i + j) % size] == ']' )
            {
                brackets.pop();
            }
            else if( bracket == '(' && s[(i + j) % size] == ')' )
            {
                brackets.pop();
            }
            else if( bracket == '{' && s[(i + j) % size] == '}' )
            {
                brackets.pop();
            }
            else brackets.push( s[(i + j) % size] );
        }
        if( brackets.size() == 0 ) ++answer;
    }

    return answer;
}
/*
  괄호를 왼쪽으로 하나씩 미는 부분을 직접 문자열을 하나씩 미는 방식보다 원본을 그대로 두고, 접근하는 인덱스를 변화시켜서
  문자열을 미는 연산을 하지 않고 바로 인덱스로 접근해 푸는 방식으로 구현하였음.
*/
