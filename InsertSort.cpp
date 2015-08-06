#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void InsertSort1(vector<int> &data, int dataNum)
{
	for (int i = 1; i < dataNum; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (data[i] < data[j])
			{
				int tmp = data[i];
				for (int k = i; k > j; k--)
					data[k] = data[k - 1];

				data[j] = tmp;
			}
		}
	}
}

void InsertSort2(vector<int> &data, int dataNum)
{
	for (int i = 1; i < dataNum; i++)
	{
		if (data[i] < data[i - 1])
		{
			int k;
			int tmp = data[i];
			for (k = i - 1; k >= 0 && data[k] > tmp; k--)
				data[k + 1] = data[k];

			data[k + 1] = tmp;
		}
	}
}

void InsertSort3(vector<int> &data, int dataNum)
{
	for (int i = 1; i < dataNum; i++)
	{
		for (int j = i - 1; j >= 0 && data[j + 1] < data[j]; j--)
			swap(data[j], data[j + 1]);
	}
}

int main()
{
	int dataNum;
	cout << "Please enter number of data: ";
	cin >> dataNum;
	vector<int> data(dataNum, 0);
	cout << "Please enter " << dataNum << " integers:" << endl;
	for (int i = 0; i < dataNum; i++)
		cin >> data[i];

	InsertSort3(data, dataNum);
	cout << "After Insert Sort:" << endl;
	for (int i = 0; i < dataNum; i++)
		cout << data[i] << " ";
	cout << endl;

	return 0;
}