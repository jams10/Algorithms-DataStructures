#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution( vector<int> enter, vector<int> leave )
{
    vector<int> answer;

    set<int> room;

    int size = enter.size();
    int idxEnter = 0, idxLeave = 0;
    answer.resize( size );
    while( idxEnter < size )
    {
        // 입실(퇴실할 사람이 방 안에 없는 경우)
        if( room.find( leave[idxLeave] ) == room.end() )
        {
            auto iter = room.begin();
            auto iterEnd = room.end();
            int roomSize = room.size();
            // 방 안에 사람이 들어오면 이미 방 안에 있는 사람들은 그 사람을 만난 셈이 됨.
            for( iter; iter != iterEnd; ++iter )
            {
                answer[*(iter)-1]++;
            }

            room.insert( enter[idxEnter] );
            // 방 안에 처음 들어오는 사람은 방에 이미 들어가있는 사람들을 모두 만난 셈이 된다.
            answer[ enter[idxEnter] - 1 ] += roomSize;
            idxEnter++;
        }
        // 퇴실
        else
        {
            room.erase( leave[idxLeave] );
            idxLeave++;
        }
    }

    return answer;
}

/*
  풀이 방법을 참고 하였음.
  https://chaechaes-itlab.tistory.com/26?category=965808

*/
