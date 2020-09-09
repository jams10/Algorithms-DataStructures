#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, tmp = 0;

    priority_queue< int, vector<int>, greater<int> > pq; // Min heap의 우선 순위 큐
    for(const auto& e : scoville) pq.push(e);

    while(pq.top() < K)
    {
        if( pq.size() < 2 ) return - 1;
        tmp = pq.top();
        pq.pop();
        tmp += pq.top() * 2;
        pq.pop();
        pq.push(tmp);
        answer++;
    }

    return answer;
}
/*
  <우선 순위 큐>
  힙으로 구현된 큐.

  <힙>
  최대, 최소 값을 빨리 찾기 위해 만들어진 완전 이진 트리
  각 부모 노드가 MAX Heap 일 경우 자식 노드 보다 크고, MIN Heap의 경우 자식 노드 보다 작음.
  힙 정렬 시간복잡도 : 힙 생성 (logN) * 전체 원소의 수(N) = NlogN
*/