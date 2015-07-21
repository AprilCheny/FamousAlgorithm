#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

/*
 *说明：字符串匹配的Sunday算法
 */

bool Find(const string &ts, const string &ps, int &pos, const vector<int> &dis_table)
{
	int ts_size = ts.size();
	int ps_size = ps.size();
	int limit = ts_size - ps_size + 1;

	bool result = false;

	for (int i = 0; i < limit;)
	{
		if (ts[i] == ps[0])
		{
			int j = 1;
			while (j < ps_size)
			{
				if (ts[i + j] != ps[j])
					break;

				j++;
			}

			if (j == ps_size)
			{
				result = true;
				pos = i + j - ps_size;
				break;
			}
		}

		i += dis_table[ts[i + ps_size]];
	}

	return result;
}

bool SundayAlgorithm(const string &ts, const string &ps, int &pos)
{
	int ts_size = ts.size();
	int ps_size = ps.size();
	if (ts_size <= 0 || ps_size <= 0)
		return false;

	vector<int> dis_table(256, ps_size + 1);
	for (int i = 0; i < ps_size; i++)
	{
		int index = (unsigned char)ps[i];
		dis_table[index] = ps_size - i;
	}

	bool result = Find(ts, ps, pos, dis_table);

	return result;
}

int main()
{
	cout << "Please enter a text string:" << endl;
	string ts;
	//ts = "this is a simple example";
	getline(cin, ts);
	cout << "Please enter a pattern string:" << endl;
	string ps;
	//ps = "example";
	getline(cin, ps);

	int pos;
	bool result = SundayAlgorithm(ts, ps, pos);

	if (result)
		cout << "Find pattern in text at " << pos << endl;
	else
		cout << "Did not find pattern in text" << endl;

	return 0;
}