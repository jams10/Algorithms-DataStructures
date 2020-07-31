#include<iostream>
#include<vector>
using namespace std;

long ArrayManipulation(const int &nArray, const vector<vector<int>> &queries)
{
  long tmp = 0, max = 0;

  for(int i = 0; i < queries.size(); i++)
  {
    tmp += queries[i][2];
    for(int j = 0; j < queries.size(); j++)
    {
      if(i != j)
      {
        if(queries[j][0] <= queries[i][0] && queries[j][1] <= queries[i][1]
        && queries[j][1] >= queries[i][0])
        {
          tmp += queries[j][2];
          continue;
        }
        else if(queries[j][0] > queries[i][0] && queries[j][1] > queries[i][1]
        && queries[j][0] <= queries[i][1])
        {
          tmp += queries[j][2];
          continue;
        }
        else if(queries[j][0] < queries[i][0] && queries[j][1] > queries[i][1])
        {
          tmp += queries[j][2];
          continue;
        }
        else if(queries[i][0] < queries[j][0] && queries[i][1] > queries[j][1])
        {
          tmp += queries[j][2];
          continue;
        }
      }
    }
    if(tmp > max)
    {
      max = tmp;
    }
    tmp = 0;
  }
  return max;
}

int main()
{
  int nArray = 0, nQueries = 0;
  cin >> nArray >> nQueries;

  vector<vector<int>> queries(nQueries);
  for(int i = 0; i < nQueries; i++)
  {
    queries[i].resize(3);
    for(int j = 0; j < 3; j++)
    {
      cin >> queries[i][j];
    }
  }

  printf("%ld", ArrayManipulation(nArray, queries));

  return 0;
}
