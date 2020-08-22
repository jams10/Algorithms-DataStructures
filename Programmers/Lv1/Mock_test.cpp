#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
  vector<int> answer;

  int one=0,two=0,three=0;

  int one_arr[5]={1,2,3,4,5};
  int two_arr[8]={2,1,2,3,2,4,2,5};
  int three_arr[10]={3,3,1,1,2,2,4,4,5,5};

  for(int i = 0; i < answers.size(); i++)
  {
    if(answers[i] == one_arr[i%5])
    {
      one++;
    }
    if(answers[i] == two_arr[i%8])
    {
      two++;
    }
    if(answers[i] == three_arr[i%10])
    {
      three++;
    }
  }

  int m = 0;
  m = max(one,two);
  m = max(m, three);

  if(one == m)
  {
    answer.push_back(1);
  }
  if(two == m)
  {
    answer.push_back(2);
  }
  if(three == m)
  {
    answer.push_back(3);
  }

  return answer;
}