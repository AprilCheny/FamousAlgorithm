#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���һ�����ֵ�ĳһλ
void GetDigits(vector<int> &initVec, vector<int> &afterVec, int count)
{
	int index = 0;
	for (vector<int>::iterator iter = initVec.begin(); iter != initVec.end(); iter++)
	{
		int tmp = *iter;
		for (int i = 0; i < count; i++)
			tmp = tmp / 10;
		tmp = tmp % 10;
		afterVec[index] = tmp;
		index++;
	}
}

int main()
{
	int dataNum;
	cout << "Please enter the number of data: ";
	cin >> dataNum;
	vector<int> data(dataNum);
	cout << "Please enter " << dataNum << " numbers(bigger than 0): " << endl;
	for (int i = 0; i < dataNum; i++)
		cin >> data[i];

	int maxDigits = 1; //������ݵ�λ��
	vector<int>::iterator iter = max_element(data.begin(), data.end());
	int maxData = *iter;
	while (maxData / 10 != 0)
	{
		maxDigits++;
		maxData = maxData / 10;
	}

	vector<int> digits(dataNum, 0);
	for (int i = 0; i < maxDigits; i++)
	{
		vector< vector<int> > dataSet(10);
		//���䵽��ӦͰ��
		GetDigits(data, digits, i);
		for (int j = 0; j < dataNum; j++)
		{
			int digit = digits[j];
			dataSet[digit].push_back(data[j]);
		}

		//��������ʹ��������
		int index = 0;
		for (int k = 0; k < 10; k++)
		{
			for (vector<int>::iterator iter = dataSet[k].begin(); iter != dataSet[k].end(); iter++)
			{
				data[index] = *iter;
				index++;
			}
		}
	}

	cout << "After Radix Sort:" << endl;
	for (int i = 0; i < dataNum; i++)
		cout << data[i] << " ";
	cout << endl;

	return 0;
}
