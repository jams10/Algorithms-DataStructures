#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    int a = n, b = m;
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return vector<int>{a , m * n / a };
}
/*
  최대 공약수(Greatest Common Measure) = G
  최소 공배수(Least Common Multiple) = L

  G | A B
    ------
      a b
  
  최대 공약수 = G
  최소 공배수 = L = G * a * b
  A * B = L * G

  <유클리드 호제법 이용>
  1071은 1029로 나누어떨어지지 않기 때문에, 1071을 1029로 나눈 나머지를 구한다. => 42
  1029는 42로 나누어떨어지지 않기 때문에, 1029를 42로 나눈 나머지를 구한다. => 21
  42는 21로 나누어떨어진다.

  참고 : http://lonpeach.com/2017/11/12/Euclidean-algorithm/
*/