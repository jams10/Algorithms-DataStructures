using namespace std;

long long solution( int w, int h )
{
    long long answer = 0;
    for( long long int i = 1; i < w; i++ )
    {
        answer += (h * i / w); // 기울기 이용
    }

    return answer * 2;
}