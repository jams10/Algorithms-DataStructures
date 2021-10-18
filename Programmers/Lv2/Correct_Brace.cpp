#include<string>
#include<iostream>
#include<stack>

using namespace std;

bool solution( string s )
{
    bool answer = true;
    stack<char> st;

    for( char c : s )
    {
        if( c == ')' )
        {
            if( st.size() > 0 && st.top() == '(' )
                st.pop();
            else st.push( c );
        }
        else st.push( c );
    }

    return st.size() == 0;
}
