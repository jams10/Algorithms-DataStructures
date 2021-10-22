#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct
{
    int idx;
    int plays;
    string genre;
}SONG;

map<string, int> genrePlays;

bool Compare(SONG song1, SONG song2)
{
  if( song1.genre != song2.genre )
  {
    return genrePlays[song1.genre] > genrePlays[song2.genre];
  }
  else
  {
    if(song1.plays != song2.plays) return song1.plays > song2.plays;
    else return song1.idx < song2.idx;
  }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    int size = genres.size();

    vector<SONG> songs;

    for(int i = 0; i < size; ++i)
    {
        songs.push_back(SONG{i, plays[i], genres[i]});
        genrePlays[genres[i]] += plays[i];
    }

    sort(songs.begin(), songs.end(), Compare);

    map<string, int> genreCount;
    for(int i = 0; i < size; ++i)
    {
        if(genreCount[songs[i].genre] < 2)
        {
          answer.push_back(songs[i].idx);
          genreCount[songs[i].genre]++;
        }
    }

    return answer;
}

/*
    다른 사람들의 풀이를 보면 map의 map. 이중 맵을 써서 푸는 방법도 존재.
*/
