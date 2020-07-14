#include<iostream>
#include<vector>
using namespace std;

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) 
{
    int count = 0;
    {
        for(int i=q.size()-1; i>=0; i--)
        {
            if(q.at(i) - (i+1) > 2) // 두 번 이상 이동을 체크
            {
                std::cout<<"Too chaotic"<<std::endl;
                return;
            }
            for(int j=max(q.at(i)-2,0); j<i; j++) // 해당 사람의 원래 위치의 한 칸 앞부터
                                                  // 그 사람의 현재 위치 한 칸 앞까지 체크
            {
                if(q.at(j) > q.at(i))
                {
                    count++;
                }
            }
        }
    }
    std::cout<<count<<std::endl;
    return;
}

int main(int argc, char *argv[])
{
  int n = 0, limit = 0, tmp = 0;
  cin>>n;

  for(int i=0; i<n; i++)
  {
    cin>>limit;
    vector<int> v;
    for(int j=0; j<limit; j++)
    {
      cin>>tmp;
      v.push_back(tmp);
    }
    minimumBribes(v);
  }
  return 0;
}

/*
  이 문제에 제시된 조건에서, 뒷 사람은 뇌물을 통해 앞으로 한 칸씩 갈 수 있지만,
  앞사람은 뇌물을 통해 뒤로 갈 수 없음.

  두 번 이상 뇌물을 주고 앞으로 이동하면 Too chaotic

  해당 사람이 얼마나 앞으로 갔는지 체크하는 것이 아닌, 그 사람이 얼마나 많이
  뇌물(bribe)을 받았냐 체크하는 것이 더 효율적임.

  해당 사람(B)에게 뇌물을 준 사람(A)은 B의 원래 위치의 한 칸 앞 이상으로 갈 수 없음.
  (한번에 한칸씩만 이동할 수 있음.)
  이를 가지고, 해당 사람(B)의 원래 위치의 한칸 앞에 자신보다 큰 수를 가진 사람(A)이 있다면
  B는 A에게 뇌물을 받았다는 것이 되고, B가 뒷 사람으로 부터 계속해서 뇌물을 받았다면,
  뒤로 계속 밀려나게 되고 이에 대해 카운팅을 할 수 있음.
  ex) 만약 1 2 3 4 5 에서 1 2 5 3 4 가 되었다면, 5는 3에게도 뇌물을 주었다는 의미.
*/