#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool anagram(const string& s1, const string& s2);

int main()
{
	int q = 0, count = 0;
	string s, ss1, ss2;

	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> s;
		for (int len = 1; len < s.length(); len++)
		{
			for (int ss1_idx = 0; ss1_idx < s.length() - len; ss1_idx++)
			{
				ss1 = s.substr(ss1_idx, len);

				for (int ss2_idx = ss1_idx + 1; ss2_idx < s.length() - len + 1; ss2_idx++) // ex) len = 1 일때, ss1_idx는 0,1,2 / ss1_idx는 1,2,3
				{
					ss2 = s.substr(ss2_idx, len);
					if (anagram(ss1, ss2))
					{
						count++;
					}
				}
			}
		}
		cout << count << endl;
		count = 0;
	}
}

bool anagram(const string& s1, const string& s2)
{
	int check1[26] = { 0, };
	int check2[26] = { 0, };

	for (int i = 0; i < s1.length(); i++)
	{
		check1[s1[i] - 'a']++; // 'a' = ascii 값 97. 따라서, s1[0] = a 이면 s1[0] - 'a' = 0
		check2[s2[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (check1[i] != check2[i])
		{
			return false;
		}
	}

	return true;
}