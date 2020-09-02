#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution( int bridge_length, int weight, vector<int> truck_weights )
{
    int whole_time = 0, weight_sum = 0;
    queue<int> on_bridge, start_time;
    
    // 전체 시간 계속 증가
    for( whole_time = 1; ; whole_time++ )
    {
        // 현재 다리에 올라간 트럭이 있는 경우
        if( !on_bridge.empty() )
        {
            // 트럭은 1초에 한번씩 이동하므로, 도착했을 때 해당 트럭은 다리 길이만큼의 시간 동안 이동함.
            if( whole_time - start_time.front() == bridge_length )
            {
                weight_sum -= on_bridge.front();
                on_bridge.pop();
                start_time.pop();
            }
        }
        // 위의 !empty 조건 체크에 들어가서 연산을 통해 on_bridge가 empty 상태가 될 수 있으므로,
        // 이를 대기 트럭 empty 여부와 함께 체크해주어야 함.
        if( on_bridge.empty() && truck_weights.empty() ) return whole_time;

        while( true )
        {
            if( !truck_weights.empty() && weight_sum + truck_weights.front() <= weight )
            {
              on_bridge.push( truck_weights.front() );
              start_time.push( whole_time );
              weight_sum += truck_weights.front();
              truck_weights.erase( truck_weights.begin() );
            }
            break;
        }
    }
}