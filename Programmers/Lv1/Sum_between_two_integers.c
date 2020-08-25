#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long aa = a;
    long long bb = b;
    return aa < bb ? (bb*(bb+1)) / 2 - (aa*(aa+1)) / 2 + aa : (aa*(aa+1)) / 2 - (bb*(bb+1)) / 2 + bb;
}

/*
  처음 제출 시, 매개변수 a,b가 int 타입이어서 큰 수가 들어가면 오버플로 되면서 올바른 계산이 이루어지지 않았음.
*/
