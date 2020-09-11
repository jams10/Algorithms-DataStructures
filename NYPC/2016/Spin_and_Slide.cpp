#include <iostream>
#include <string>
#include <vector>

using namespace std;

void SpinAndSlide( vector<string> space, const int& nSpinAndSlide );

int main()
{
	int N = 0, nSpinAndSlide = 0;
	string tmp = "";
	cin >> N >> nSpinAndSlide;
	vector<string> space;

	for( int i = 0; i < N; i++ )
	{
		cin >> tmp;
		space.emplace_back( tmp );
	}

	SpinAndSlide( space, nSpinAndSlide );
}

void SpinAndSlide( vector<string> space, const int& nSpinAndSlide )
{
	string blank = "";
	vector<string> swap = space;
	
	for( int i = 0; i < swap.size(); i++ ) blank += ".";

	if( space.size() > 1 )
	{
		for( int cnt = 0; cnt < nSpinAndSlide; cnt++ )
		{
			vector<string> tmp( swap.size(), blank );
			// Rotate
			for( int y = 0; y < swap.size(); y++ )
			{
				for( int x = 0; x < swap[0].length(); x++ )
				{
					if( swap[y][x] != '.' )
					{
						tmp[x][swap.size() - 1 - y] = swap[y][x];
					}
				}
			}
			// Slide
			for( int x = 0; x < swap[0].length(); x++ )
			{
				for( int y = swap.size() - 2; y >= 0; y-- ) // 제일 마지막이 빈칸이 아닐 경우 움직일 필요 X.
				{
					if( tmp[y][x] != '.' )
					{
						int slideY = y;
						for( slideY; slideY < swap.size() - 1; slideY++ )
						{
							if( tmp[slideY + 1][x] != '.' ) break;
						}
						tmp[slideY][x] = tmp[y][x];
						// 이동하지 않았는데도, 원래 위치를 빈칸으로 만드는 경우를 방지함.
						if(slideY != y) tmp[y][x] = '.';
					}
				}
			}
			swap = tmp;
		}
	}
	cout << endl<< "<RESULT>" << endl;
	for( const auto& e : swap )
	{
		cout << e << endl;
	}
}