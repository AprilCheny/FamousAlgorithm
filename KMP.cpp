#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void LongestPrefixSuffix(const string &ps, vector<int> &lps, const int ps_len)
{
	int longest_len = 0;
	int i = 1;

	while (i < ps_len)
	{
		if (ps[i] == ps[longest_len])
		{
			longest_len++;
			lps[i] = longest_len;
			i++;
		}
		else
		{
			if (longest_len != 0)
				longest_len = lps[longest_len - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

bool KMP(const string &ts, const string &ps, int &pos)
{
	bool result = false;

	int ts_len = ts.size();
	int ps_len = ps.size();

	vector<int> lps(ps_len, 0);
	LongestPrefixSuffix(ps, lps, ps_len); //�����ǰ׺��׺

	int i = 0; //�ı���������
	int j = 0; //ģʽ��������
	while (i < ts_len)
	{
		if (j < ps_len && ps[j] == ts[i])
		{
			i++;
			j++;
		}

		if (j == ps_len) //�ҵ���ģʽ����һ��ƥ��
		{
			pos = i - j;
			j = lps[j - 1];
			result = true;
		}
		else if (i < ts_len && ps[j] != ts[i]) //��j���ַ�ƥ���ģʽ�����ı����ĵ�j+1���ַ�ʧ����
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}

	return result;
}

int main()
{
	cout << "Please enter a text string:" << endl;
	string ts;
	ts = "this is a simple example";
	//getline(cin, ts);
	cout << "Please enter a pattern string:" << endl;
	string ps;
	ps = "example";
	//getline(cin, ps);

	int pos;
	bool result = KMP(ts, ps, pos);

	if (result)
		cout << "Find pattern in text at " << pos << endl;
	else
		cout << "Did not find pattern in text" << endl;

	return 0;
}