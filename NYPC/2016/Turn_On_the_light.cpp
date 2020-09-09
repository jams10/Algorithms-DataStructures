#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

bool check_lighting( vector<string>space, const int& y_in, const int& x_in, const Directions& direction_in );

void solution( vector<string> space );

int main()
{
	int W = 0, H = 0;
	vector<string> space;
	string input;
	cin >> W >> H;

	for( int i = 0; i < H; i++ )
	{
		cin >> input;
		space.emplace_back( input );
	}
	solution( space );
}

bool check_lighting( vector<string>space, const int& y_in, const int& x_in, const Directions& direction_in )
{
	int y = y_in, x = x_in;
	Directions direction = direction_in;

	while( x >= 0 && x < space[0].length() && y >= 0 && y < space.size() )
	{
		if( space[y][x] == 'O' ) return true;

		if( space[y][x] != '.' )
		{
			switch( direction )
			{
			case Directions::UP:
				if( space[y][x] == '\\' ) direction = Directions::LEFT;
				else direction = Directions::RIGHT;
				break;
			case Directions::DOWN:
				if( space[y][x] == '\\' ) direction = Directions::RIGHT;
				else direction = Directions::LEFT;
				break;
			case Directions::LEFT:
				if( space[y][x] == '\\' ) direction = Directions::UP;
				else direction = Directions::DOWN;
				break;
			case Directions::RIGHT:
				if( space[y][x] == '\\' ) direction = Directions::DOWN;
				else direction = Directions::UP;
				break;
			default:
				cout << "Undefined direction" << endl;
				break;
			}
		}
		switch( direction )
		{
		case Directions::UP:
			y++;
			break;
		case Directions::DOWN:
			y--;
			break;
		case Directions::LEFT:
			x++;
			break;
		case Directions::RIGHT:
			x--;
			break;
		default:
			cout << "Undefined direction" << endl;
			break;
		}
	}

	return false;
}

void solution( vector<string> space )
{
	//UP
	for( int i = 0; i < space[0].length(); i++ )
	{
		if( check_lighting( space, 0, i, Directions::UP ) )
		{
			cout << "U " << i << endl;
			return;
		}
	}
	//DOWN
	for( int i = 0; i < space[0].length(); i++ )
	{
		if( check_lighting( space, space.size() - 1, i, Directions::DOWN ) )
		{
			cout << "D " << i << endl;
			return;
		}
	}
	//LEFT
	for( int i = 0; i < space.size(); i++ )
	{
		if( check_lighting( space, i, 0, Directions::LEFT ) )
		{
			cout << "L " << i << endl;
			return;
		}
	}
	// RIGHT
	for( int i = 0; i < space.size(); i++ )
	{
		if( check_lighting( space, i, space[0].length() - 1, Directions::RIGHT ) )
		{
			cout << "R " << i << endl;
			return;
		}
	}
}