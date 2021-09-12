#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<char> tmpVector;
bool Checked[20] = { false, };

void GetCases( int depth, int size, 
    const vector<char>& operators, vector<vector<char>> & cases )
{
    if( depth == size )
    {
        cases.emplace_back( tmpVector );
        return;
    }
    for( int i = 0; i < size; ++i )
    {
        if( Checked[i] ) continue;
        Checked[i] = true;
        tmpVector.emplace_back( operators[i] );
        GetCases( depth + 1, size, operators, cases );
        tmpVector.pop_back();
        Checked[i] = false;
    }
    return;
}

long long GetResult( list<string> factors, const vector<char>& operators )
{
    int count = 0;
    long long result = 0;
    while( true )
    {
        if( factors.size() < 2 )
        {
            result = stoll( *(factors.begin()) );
            break;
        }
        list<string>::iterator iter;
        list<string>::iterator iterEnd = factors.end();
        for( iter = factors.begin(); iter != iterEnd; ++iter )
        {
            if( (*iter)[0] == operators[count] )
            {
                auto beforeIter = prev( iter );
                auto afterIter = next( iter );
                long long result = 0;
                if( operators[count] == '*' )
                    result = stoll( *beforeIter ) * stoll( *afterIter );
                else if( operators[count] == '-' )
                    result = stoll( *beforeIter ) - stoll( *afterIter );
                else if( operators[count] == '+' )
                    result = stoll( *beforeIter ) + stoll( *afterIter );
                factors.erase( beforeIter );
                factors.erase( iter );
                iter = factors.erase( afterIter );
                iter = factors.insert( iter, to_string( result ) );
            }
        }
        count++;
    }

    return result;
}

long long solution( string expression )
{
    long long answer = 0;
    list<string> factors;
    vector<char> operators;
    vector<vector<char>> operatorsCases;

    int count = 0;
    int size = expression.size();
    for( int i = 0; i < size; ++i )
    {
        if( expression[i] == '*' || expression[i] == '-' || expression[i] == '+' )
        {
            factors.emplace_back( expression.substr( count, i - count ) );
            factors.emplace_back( string{ expression[i], '\0' } );
            if( find( operators.begin(), operators.end(), expression[i] ) == operators.end() )
            {
                operators.emplace_back( expression[i] );
            }
            count = i + 1;
        }
        if( i == size - 1 )
        {
            factors.emplace_back( expression.substr( count, i - count + 1 ) );
        }
    }

    GetCases( 0, operators.size(), operators, operatorsCases );
    for( auto e : operatorsCases )
    {
        long long result = GetResult( factors, e );
        answer = llabs( result ) > answer ? llabs( result ) : answer;
    }

    return answer;
}

// 맨 처음 제출 했을 때 long long 타입의 답을 int로 조작해서 실패하였음. stoi->stoll abs-> llabs로 변경해주었음.

/* 다른 사람 풀이 참고 */

/*
  연산자의 경우의 수는 최대 6개 이기 때문에 그냥 string 배열을 만들어서 모든 경우의 수를 적어놓고 사용할 수 있음. 따로 재귀 함수 짤 필요가 없음.
  계산의 경우 연산자와 피연산자 벡터를 따로 만들어서 i번째 인덱스의 피연산자와 i + 1번째 피연산자를 계산 한 뒤, 결과값을 i번째 인덱스 위치에 넣고,
  i + 1번째 인덱스의 피연산자를 지워나가는 식으로 간단한 for문을 통해 수행할 수 있다.
*/
