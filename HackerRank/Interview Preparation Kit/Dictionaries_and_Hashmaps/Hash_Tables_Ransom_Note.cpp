// ransom : (납치유괴된 사람에 대한) 몸값

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
  int m = 0, n = 0;
  string tmp;
  //    ▼ Key ▼ Value
  map<string,int>magazine;
  map<string,int>::iterator it; 

  cin >> m >> n;
  for(int i = 0; i < m; i++)
  {
    cin>>tmp;
    magazine[tmp]++; // magazine에 해당 string key의 값을 증가 시킴. 없으면 생성.
  }

  for(int i = 0; i < n; i++)
  {
    cin>>tmp;
    if(magazine[tmp] == 0)
    {
      cout<<"No";
      return 0;
    }
    else
    {
      magazine[tmp]--;
    }
  }
  cout<<"Yes";
  return 0;
}
/*
  map<string,int>map;
  map<string,int>::iterator it;
  맵 변수 이름을 map으로 선언하고 바로 map 타입의 iterator 생성시, 다음과 같은 오류 발생.

  Hash_Tables_Ransom_Note.cpp:14:13: error: expected primary-expression before ‘,’ token
   map<string,int>::iterator it;
             ^
  Hash_Tables_Ransom_Note.cpp:14:14: error: expected primary-expression before ‘int’
   map<string,int>::iterator it;
*/

/*
  Key는 중복되지 않음.
  

  map에서 []연산자를 사용할 경우, 해당 항목이 존재하지 않으면 새로 생성함.
  이때, 디폴트 생성자를 호출하게 되고, 디폴트 생성자는 0을 리턴함.
  이를 활용해 문제를 해결.

  https://github.com/krikit/krikit.github.io/wiki/2014-07-08-map%EC%9D%98-insert-%EB%A9%94%EC%84%9C%EB%93%9C%EC%99%80-%5B%5D-%EC%97%B0%EC%82%B0%EC%9E%90

  https://www.hackerrank.com/challenges/ctci-ransom-note/forum
*/