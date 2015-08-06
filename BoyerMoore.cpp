#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

/*
 *˵�����ַ���ƥ��֮Boyer-Moore�㷨
 */

void BadCharacter(const string &ps, vector<int> &bad_table, const int ps_len)
{
	for (int i = 0; i < ps_len - 1; i++) //���һ���ַ�����Ҫ����
	{
		int index = (unsigned char)ps[i];
		bad_table[index] = ps_len - i - 1; //��ʾ�ַ���ģʽ�������һ�γ��ֵ�λ�þ���ģʽ����β�ĳ���
	}
}

//���ps[0, ... , k](k= ps_len-1, ... , 0)��ps[0, ... , ps_len]�Ĺ�ͬ��׺����
void CalculateSuffixLen(const string &ps, vector<int> &suffix_len, int ps_len)
{
	//������⹲ͬ��׺
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

	//Case3: �Ѿ���good_table��ʼ����ʱ��������
	//Case2: �Ҳ����ú�׺����ȫƥ�䣬���ģʽ������ʼλ���Һú�׺����Ӵ�
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
	//Case1: �ҵ��ú�׺����ȫƥ��
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
	BadCharacter(ps, bad_table, ps_len); //�������ַ���

	vector<int> good_table(ps_len, 0);
	GoodSuffix(ps, good_table, ps_len); //�����ú�׺��

	int i = 0;
	while (i <= ts_len - ps_len)
	{
		int j = ps_len - 1;
		while (j >= 0 && ps[j] == ts[j + i]) //ģʽ�����ı�����һƥ��
			j--;
		if (j < 0) //���ı������ҵ���ģʽ��
		{
			pos = i;
			result = true;
			break;
		}

		i += max(bad_table[ts[i + j]] - (ps_len - j - 1) , good_table[j]); //��ǰ������ģʽ�����ı��Ӵ���ƥ�䣬����ת
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