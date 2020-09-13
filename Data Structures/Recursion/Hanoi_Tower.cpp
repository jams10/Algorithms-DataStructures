#include <iostream>

int HanoiTower( int NumberOfPlates, char From, char Tmp, char To );

int main()
{
	std::cout << "총 옮긴 횟수 : " << HanoiTower( 4, 'A', 'B', 'C' );
	return 0;
}

int HanoiTower( int NumberOfPlates, char From, char Tmp, char To )
{
	// 총 옮긴 횟수
	int Count = 0;
	if( NumberOfPlates == 1 )
	{
		Count++;
		std::cout << "1 번째 원판을 " << From << " 에서 " << To << " 로 옮긴다." << std::endl;
		return Count;
	}
	else
	{
		// n - 1 개의 원판을 To를 이용, From -> Tmp 로 옮김.
		Count += HanoiTower( NumberOfPlates - 1, From, To, Tmp ); 
		// n 번째 원판을 From -> To 로 옮김.
		std::cout << NumberOfPlates << " 번째 원판을 " << From << " 에서 " << To << " 로 옮긴다." << std::endl;
		Count++;
		// n - 1 개의 원판을 From을 이용, Tmp -> To 로 옮김.
		Count += HanoiTower( NumberOfPlates - 1, Tmp, From, To );
	}
	return Count;
}