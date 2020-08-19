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
				
        // ex) len = 1 일때, ss1_idx는 0,1,2 / ss1_idx는 1,2,3
				for (int ss2_idx = ss1_idx + 1; ss2_idx < s.length() - len + 1; ss2_idx++) 
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
	char c1[100];
	char c2[100];

	for (int i = 0; i < s1.length(); i++)
	{
		c1[i] = s1[i];
		c2[i] = s2[i];
	}

	sort(c1, c1 + s1.length());
	sort(c2, c2 + s1.length());

	for (int i = 0; i < s1.length(); i++)
	{
		if (c1[i] != c2[i])
		{
			return false;
		}
	}

	return true;
}