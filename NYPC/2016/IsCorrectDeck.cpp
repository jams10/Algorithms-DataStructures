#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solution( const vector<string>& resource );

int main()
{
	int N = 0;
	string input = "";
	vector<string> resource;
	cin >> N;

	resource.resize( N );

	for( int i = 0; i < N; i++ )
	{
		cin >> resource[i];
	}
	solution( resource );
}

void solution( const vector<string>& resource )
{
	vector<string> types = resource;
	// unique의 경우 바로 뒤에 있는 중복된 원소에 대해 체크하므로
	// 전체에 대해 중복 원소를 걸러내기 위해 sort 함수를 사용.
	sort( types.begin(), types.end() );
	types.erase( unique( types.begin(), types.end() ), types.end() );
	//                ▲ 중복을 제외한 벡터의 끝 반환
	if( types.size() <= 3 ) cout << "valid";
	else cout << "invalid";
	return;
}