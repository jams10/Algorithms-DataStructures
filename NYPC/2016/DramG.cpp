#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution( vector<string>& v );

int main()
{
	int N = 0;
	string input = "";
	vector<string> v;
	cin >> N;

	for( int i = 0; i < N; i++ )
	{
		cin >> input;
		v.emplace_back( input );
	}
	solution( v );

	for( const auto& e : v )
	{
		cout << e << endl;
	}
}

void solution( vector<string>& v )
{
	int count = 0, tmp = 0;

	for( int i = 0; i < v.size(); i++ )
	{
		for( int j = 0; j < v[i].length(); j++ )
		{
			if( v[i][j] == 'C' ) count++;
		}
	}

	for( int i = 0; i < v.size(); i++ )
	{
		for( int j = 0; j < v[i].length(); j++ )
		{
			if( tmp >= count * 2 ) return;
			if( v[i][j] != 'C' )
			{
				v[i][j] = 'D';
				tmp++;
			}
		}
	}
}