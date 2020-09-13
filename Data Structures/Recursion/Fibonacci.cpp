#include <iostream>

long Memorize[100] = { 0, }; // 메모이제이션을 위한 배열.

long Fibonacci( int number );

int main()
{
	Fibonacci( 10 );
	return 0;
}

// 0부터 입력한 number 까지의 피보나치 수열을 출력하는 함수.
long Fibonacci( int number )
{
	/*
		<메모이제이션>
		재귀를 하는 과정에서 동일한 계산이 반복되어 비효율적임.
		따라서, 계산된 결과를 배열에 저장하여 재귀 과정에서 동일한 계산이면
		해당 재귀 단계에서 계산을 위해 다시 재귀적으로 호출하는 것이 아닌 
		그냥 배열에 저장된 값을 활용하여 재귀 호출 없이 계산을 하는 방법.
	*/
	if( Memorize[number] ) // 메모이제이션 활용. 동일한 계산이므로 출력문은 필요 없음.
	{
		return Memorize[number];
	}

	if( number == 0 )
	{
		std::cout << 0 << ' ';
		return Memorize[number] = 0;
	}
	if( number == 1 )
	{
		std::cout << 1 << ' ';
		return Memorize[number] = 1;
	}

	long ReturnValue = Fibonacci( number - 2 ) + Fibonacci( number - 1 );
	std::cout << ReturnValue << ' ';
	return Memorize[number] = ReturnValue;
}