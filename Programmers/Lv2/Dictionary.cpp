#include <string>
#include <vector>
#include <array>
#include <math.h>
using namespace std;

#define WORD_SIZE 5

int solution( string word )
{
    int answer = 0;

    array<char, 5> cs = { 'A','E','I','O','U' };  
    int size = word.size();

    /*
     이전 column 들의 경우의 수의 합 * row + (row + 1)
     */

    for( int col = 0; col < size; ++col )
    {
        for( int row = 0; row < WORD_SIZE; ++row )
        {
            if( cs[row] == word[col] )
            {
                answer += (pow( WORD_SIZE, WORD_SIZE - col ) - 5) / 4 * row + (row + 1);
                break;
            }
        }
    }
    return answer;
}

/*
  이전 column 들의 경우의 수의 합은 등비수열 5^n의 합과 같다. 따라서 등비수열의 합 공식을 이용해 (5^(n+1) - 5) / 4 이라는 식을 도출할 수 있다.
  여기서 n은 column의 인덱스가 되고, 처음부터가 아닌 맨 끝 인덱스 부터 0으로 갈수록 증가하는 형태이기 때문에 그냥 col이 아닌 WORD_SIZE - col로 지수 값을 넣어준다.
  여기에 row 값이 증가하면(A->E->I->O->U) 해당 시점에서의 단어의 번호는 이전 row 값에서 누적된 경우의 수에 자기 자신을 포함해 1을 더해준 값이 된다.
*/
/*
  1     1     1     1     1
  782   157   32    7     2
  1563  313   63    13    3
  2344  468   94    19    4
  3125  625   125   25    5
*/
