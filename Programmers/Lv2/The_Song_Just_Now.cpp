#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution( string m, vector<string> musicinfos )
{
    string answer = "";
    int answerSongLength = 0;
    int mSize = m.size();

    vector<int> inputNotes;
    for( int i = 0; i < mSize; ++i )
    {
        if( m[i] == '#' )
            inputNotes[inputNotes.size() - 1] *= -1;
        else
            inputNotes.push_back( m[i] );
    }

    for( string s : musicinfos )
    {
        istringstream mainInput( s );
        vector<string> infos( 4 );
        string currentSong = "";

        for( int i = 0; i < 4; ++i )
        {
            getline( mainInput, infos[i], ',' );
        }

        string startHour = "", startMinute = "";
        string endHour = "", endMinute = "";

        istringstream startTime( infos[0] );
        getline( startTime, startHour, ':' );
        getline( startTime, startMinute, ':' );

        istringstream endTime( infos[1] );
        getline( endTime, endHour, ':' );
        getline( endTime, endMinute, ':' );

        // calculate the length of the current song
        int length = (stoi( endHour ) * 60 + stoi( endMinute )) - (stoi( startHour ) * 60 + stoi( startMinute ));

        // modify notes
        int noteSize = infos[3].size();
        vector<int> infoNotes;
        for( int i = 0; i < noteSize; ++i )
        {
            if( infos[3][i] == '#' )
                infoNotes[infoNotes.size() - 1] *= -1;
            else
                infoNotes.push_back( infos[3][i] );
        }

        int infoNoteSize = infoNotes.size();
        int inputNoteSize = inputNotes.size();

        for( int i = 0; i < length; ++i )
        {
            if( i + inputNoteSize > length ) break;
            for( int j = 0; j < inputNoteSize; ++j )
            {
                if( inputNotes[j] != infoNotes[(i + j) % infoNoteSize] )
                {
                    currentSong = "";
                    break;
                }
                else
                {
                    currentSong = infos[2];
                }
            }
            // 정답이 여러개 일 경우 곡의 길이가 가장 긴 곡으로 정답을 처리.
            if( currentSong != "" )
            {
                if( answerSongLength < length )
                {
                    answer = currentSong;
                    answerSongLength = length;
                }
                break;
            }
        }
    }
    // 해당되는 곡이 없으면 (None)을 리턴함.
    if( answer != "" ) return answer;
    else return "(None)";
}
