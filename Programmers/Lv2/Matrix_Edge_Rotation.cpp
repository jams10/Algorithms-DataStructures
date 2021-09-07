#include <string>
#include <vector>

using namespace std;

int Rotate( vector<vector<int>>& v, int top, int left, int bottom, int right );

vector<int> solution( int rows, int columns, vector<vector<int>> queries )
{
    vector<int> answer;
    vector<vector<int>> v( rows, vector<int>( columns, 0 ) );

    for( int i = 0; i < rows; ++i )
    {
        for( int j = 0; j < columns; ++j ) v[i][j] = i * columns + (j + 1); // 이 부분을 row를 곱해서 실수.
                                                                            // 정사각행렬이면 오류 안나지만, 그 외의 경우 오류 발생.
    }

    int size = queries.size();

    for( int i = 0; i < size; i++ )
    {
        answer.push_back(
            Rotate( v, queries[i][0] - 1, queries[i][1] - 1, queries[i][2] - 1, queries[i][3] - 1 ) 
        );
    }

    return answer;
}

int Rotate( vector<vector<int>>& v, int top, int left, int bottom, int right )
{
    int topLeft = v[top + 1][left];
    int topRight = v[top][right - 1];
    int bottomLeft = v[bottom][left + 1];
    int bottomRight = v[bottom - 1][right];
    int min = v[top][left];

    for( int x = right - 1; x > left; --x )
    {
        v[top][x] = v[top][x - 1];
        if( v[top][x] < min ) min = v[top][x];
    }
    for( int y = bottom - 1; y > top; --y )
    {
        v[y][right] = v[y - 1][right];
        if( v[y][right] < min ) min = v[y][right];
    }
    for( int x = left + 1; x < right; ++x )
    {
        v[bottom][x] = v[bottom][x + 1];
        if( v[bottom][x] < min ) min = v[bottom][x];
    }
    for( int y = top; y < bottom; ++y )
    {
        v[y][left] = v[y + 1][left];
        if( v[y][left] < min ) min = v[y][left];
    }

    if( min > topLeft ) min = topLeft;
    if( min > topRight ) min = topRight;
    if( min > bottomLeft ) min = bottomLeft;
    if( min > bottomRight ) min = bottomRight;

    v[top][left] = topLeft;
    v[top][right] = topRight;
    v[bottom][left] = bottomLeft;
    v[bottom][right] = bottomRight;

    return min;
}
