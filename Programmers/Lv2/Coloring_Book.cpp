#include <vector>
#include <iostream>
using namespace std;

bool checked[100][100];

void recur( const int& m, const int& n, int y, int x, int value, vector<vector<int>> picture, int& count)
{    
    if( picture[y][x] == value && !checked[y][x] )
    {
        checked[y][x] = true;
        count++;
        if( y - 1 >= 0 && picture[y - 1][x] == value) recur( m, n, y - 1, x, value, picture, count);
        if( x - 1 >= 0 && picture[y][x - 1] == value ) recur( m, n, y, x - 1, value, picture, count);
        if( y + 1 < m && picture[y + 1][x] == value ) recur( m, n, y + 1, x, value, picture, count);
        if( x + 1 < n && picture[y][x + 1] == value ) recur( m, n, y, x + 1, value, picture, count);
    }

    return;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution( int m, int n, vector<vector<int>> picture )
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int value = 0, count = 0;

    for( int i = 0; i < m; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            checked[i][j] = false;
        }
    }

    for( int y = 0; y < m; y++ )
    {
        for( int x = 0; x < n; x++ )
        {
            if( picture[y][x] && !checked[y][x] )
            {
                recur( m, n, y, x, picture[y][x], picture, count);
                if( count > max_size_of_one_area ) max_size_of_one_area = count;
                count = 0;
                number_of_area++;
            }
        }
    }

    vector<int> answer( 2 );
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

/*
  재귀 함수 내에서 재귀적으로 인덱스를 이동할 때 쓸 때 없이 바깥에 이중 for문을 넣었음.
  (이 때문에 올바른 기능 구현에 상당한 시간 소요함.)
  재귀 함수 호출 시에 재귀 조건에 걸리지 않았을 때 어떻게 동작할 것인지 설계 하는 것에 대해
  깊게 생각하는 것이 중요할 것 같음.
*/