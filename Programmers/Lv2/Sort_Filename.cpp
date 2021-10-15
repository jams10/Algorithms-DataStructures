#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct FILENAME
{
    string name;
    int number;
    int idx;
}FILENAME;

bool Compare( FILENAME f1, FILENAME f2 )
{
    if( f1.name != f2.name )
    {
        return f1.name < f2.name;
    }
    return f1.number < f2.number;
}

vector<string> solution( vector<string> inputFiles )
{
    vector<string> answer;

    int inputSize = inputFiles.size();
    vector<FILENAME> files( inputSize );

    for( int i = 0; i < inputSize; ++i )
    {
        int size = inputFiles[i].size();
        int stringIdx = 0;
        // name
        for( stringIdx = 0; (inputFiles[i][stringIdx] < '0' || inputFiles[i][stringIdx] > '9'); ++stringIdx )
        {
            if( islower( inputFiles[i][stringIdx] ) )
                files[i].name += (inputFiles[i][stringIdx] - 32);
            else
                files[i].name += inputFiles[i][stringIdx];
        }
        // number
        string tmp = "";
        for( stringIdx; inputFiles[i][stringIdx] >= '0' && inputFiles[i][stringIdx] <= '9'; ++stringIdx )
        {
            tmp += inputFiles[i][stringIdx];
        }
        files[i].number = stoi( tmp );
        // idx
        files[i].idx = i;
    }

    stable_sort( files.begin(), files.end(), Compare );

    for( FILENAME f : files )
    {
        answer.push_back( inputFiles[f.idx] );
    }

    return answer;
}

/*
  sort의 경우 정렬 후의 결과가 기존의 순서를 유지한다는 보장이 없음 -> unstable sort
  따라서, 해당 문제에서 같은 순위일 경우 기존의 입력으로 들어온 순서를 유지해야 한다는 조건이 있기 때문에,
  정렬 후에도 기존 순서를 보장해주는 stable sort를 사용해야 함.
*/
