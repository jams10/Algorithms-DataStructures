#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution( int n )
{
    long long tmp = 0;
    long long count = 1;
    string answer = "";
    long long arr[3] = { 1, 2, 4 };
    while( n != 0 )
    {
        tmp += (arr[--n % 3] * count);
        n /= 3;
        count *= 10;
    }

    return to_string( tmp );
}