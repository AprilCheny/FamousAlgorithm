#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

/*
 *说明：字符串匹配之Boyer-Moore算法
 */

void BadCharacter(const string &ps, vector<int> &bad_table, const int ps_len)
{
	for (int i = 0; i < ps_len - 1; i++) //最后一个字符不需要计算
	{
		int index = (unsigned char)ps[i];
		bad_table[index] = ps_len - i - 1; //表示字符在模式串中最后一次出现的位置距离模式串串尾的长度
	}
}

//求解ps[0, ... , k](k= ps_len-1, ... , 0)和ps[0, ... , ps_len]的共同后缀长度
void CalculateSuffixLen(const string &ps, vector<int> &suffix_len, int ps_len)
{
	//暴力求解共同后缀
	suffix_len[ps_len - 1] = ps_len;
	for (int i = ps_len - 2; i >= 0; i--)
	{
		int j = i;
		while (j >= 0 && ps[j] == ps[j + ps_len - i - 1])
			j--;

		suffix_len[i] = i - j;
	}
}

void GoodSuffix(const string &ps, vector<int> &good_table, const int ps_len)
{
	vector<int> suffix_len(ps_len, 0);
	CalculateSuffixLen(ps, suffix_len, ps_len);

	//Case3: 已经在good_table初始化的时候做好了
	//Case2: 找不到好后缀的完全匹配，则从模式串的起始位置找好后缀的最长子串
	for (int i = ps_len - 1; i >= 0; i--)
	{
		if (suffix_len[i] == i + 1)
		{
			for (int j = 0; j < ps_len - i - 1; j++)
			{
				if (good_table[j] == ps_len)
					good_table[j] = ps_len - i - 1;
			}
		}
	}
	//Case1: 找到好后缀的完全匹配
	for (int i = 0; i < ps_len - 1; i++)
		good_table[ps_len - suffix_len[i] - 1] = ps_len - i - 1;
}

bool BoyerMoore(const string &ts, const string &ps, int &pos)
{
	bool result = false;

	int ts_len = ts.size();
	int ps_len = ps.size();
	if (ts_len <= 0 || ps_len <= 0)
		return false;

	vector<int> bad_table(256, ps_len);
	BadCharacter(ps, bad_table, ps_len); //创建坏字符表

	vector<int> good_table(ps_len, 0);
	GoodSuffix(ps, good_table, ps_len); //创建好后缀表

	int i = 0;
	while (i <= ts_len - ps_len)
	{
		int j = ps_len - 1;
		while (j >= 0 && ps[j] == ts[j + i]) //模式串与文本串逐一匹配
			j--;
		if (j < 0) //在文本串中找到了模式串
		{
			pos = i;
			result = true;
			break;
		}

		i += max(bad_table[ts[i + j]] - (ps_len - j - 1) , good_table[j]); //当前对齐下模式串与文本子串不匹配，则跳转
	}

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
	bool result = BoyerMoore(ts, ps, pos);

	if (result)
		cout << "Find pattern in text at " << pos << endl;
	else
		cout << "Did not find pattern in text" << endl;

	return 0;
}