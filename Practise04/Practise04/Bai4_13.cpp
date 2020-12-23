#include <bits/stdc++.h>

using namespace std;
//
bool checkBinary(string s) {
	bool ss = true;
	int zero0 = 0, one1 = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0') zero0++;
		if (s[i] == '1') one1++;
	}
	if (zero0 == one1) return true;
	else return false;
}
//
void subString(string s)
{
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {

		for (int len = 1; len <= s.length() - i; len++) {
			if (checkBinary(s.substr(i, len)) == true)
				sum++;
		}
	}
	cout << sum << endl;
}

int main()
{
	string ss;
	cin >> ss;
	subString(ss);
	return 0;
}