#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0, idx = 0;
    for(int i = 0; i < skill_trees.size(); i++)
    {
        string tmp = "";
        for(int j = 0; j < skill_trees[i].length(); j++)
        {
            for(int k = 0; k < skill.length(); k++)
            {
                if(skill_trees[i][j] == skill[k])
                {
                    tmp += skill[k];
                    break;
                }
            }
        }

        for(int j = 0; j < tmp.length(); j++)
        {
            if(tmp[j] != skill[j]) break;
            if(j == tmp.length() - 1 && tmp[j] == skill[j]) answer++;
        }
        // none exists
        if(tmp.length() == 0) answer++;
    }
    return answer;
}

/*
  skill 매개변수에 해당하는 글자가 하나도 없는 경우에도 가능한 스킬트리로 체크해 주어야 함.
*/