#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    int len = phone_book.size();
    for(int i = 0; i < len; i++)
    {
        string prefix = phone_book[i];
        for(int j = 0; j < len; j++)
        {
            string tmp = phone_book[j].substr(0, prefix.length());
            if(i!=j && tmp == prefix) return false;
        }
    }
    return true;
}