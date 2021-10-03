#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution( int n, vector<string> words )
{
    vector<int> answer;
    set<string> exist;

    int people = 1;
    string before = words[0];
    exist.insert( before );

    int size = words.size();
    for( int i = 1; i < size; ++i )
    {
        auto iter = exist.find( words[i] );
        bool isUsed = (iter != exist.end());
        if( before.back() != words[i].front() || isUsed )
        {
            cout << i << endl;
            answer.push_back( i % n + 1 );
            answer.push_back( i / n + 1 );
            break;
        }
        exist.insert( words[i] );
        before = words[i];
    }

    if( answer.size() == 0 ) answer = vector<int>{ 0,0 };
    return answer;
}
