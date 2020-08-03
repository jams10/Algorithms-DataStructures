#include <iostream>
#include <vector>
using namespace std;

long arrayManipulation(const int& n, const vector<vector<int>>& queries);

int main()
{
  int n = 0, m = 0;

  cin >> n >> m;

  vector<vector<int>> queries(m);
  for(int i = 0; i < m; i++)
  {
    queries[i].resize(3);
    for(int j = 0; j < 3; j++)
    {
      cin >> queries[i][j];
    }
  }

  long result = arrayManipulation(n, queries);
  cout << result;

  return 0;
}

long arrayManipulation(const int& n, const vector<vector<int>>& queries)
{
  long sum = 0, max = 0;
  int* arr = new int[n + 1](); // Initialize array by 0s.
                               // Index starts from 1.

  for(int i = 0; i < queries.size(); i++)
  {
    arr[queries[i][0]] += queries[i][2];
    if(queries[i][1] + 1 <= n)
    {
      arr[(queries[i][1]) + 1] -= queries[i][2];
    }
  }

  for(int i = 0; i < n + 1; i++)
  {
    sum += arr[i];
    if(sum > max )
    {
      max = sum;
    }
  }
  delete [] arr;
  return max;
}

/*
  <INPUT>
  4 3
  2 3 603
  1 1 286
  4 4 882

  <ARRAY> (n + 1 = 5)
            Index : 0     1     2     3      4 

  2 3 603 ->        0     0    603    0    -603
  1 1 286 ->        0    286  -286    0      0
  4 4 882 ->        0     0     0     0     882

  배열의 해당되는 범위에 포함되는 요소들에 직접 값을 더할 필요 없이
  범위의 처음과 끝에서만 더하거나 빼줌.

  범위의 시작 지점에 값을 더해주고, 범위의 끝 + 1에 값을 빼줌.
  이렇게 계산된 값들을 저장한 배열의 요소들을 모두 더해주면 최대 값이 나옴.

  참고 : https://www.hackerrank.com/challenges/crush/forum?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
*/