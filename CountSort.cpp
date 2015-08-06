#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void CountSort(vector<int> &data, int dataNum, int maxNum)
{
	vector<int> count(maxNum + 1, 0);
	for (int i = 0; i < dataNum; i++)
		count[data[i]]++;

	//下面使用O(maxNum)时间复杂度排好序，不是真正的计数排序
	/*
	int k = 0;
	for (int i = 0; i <= maxNum; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			cout << i << " ";
			//data[k++] = i;
		}
	}
	cout << endl;
	*/

	for (int i = 1; i <= maxNum; i++)
		count[i] += count[i - 1];

	vector<int> tmp(dataNum, 0);
	for (int i = dataNum - 1; i >= 0; i--)
	{
		tmp[count[data[i]] - 1] = data[i];
		count[data[i]]--;
	}
	for (int i = 0; i < dataNum; i++)
		data[i] = tmp[i];
}

int main()
{
	cout << "Please enter max of numbers: ";
	int maxNum;
	cin >> maxNum;
	int dataNum;
	cout << "Please enter number of data: ";
	cin >> dataNum;
	vector<int> data(dataNum, 0);
	cout << "Please enter " << dataNum << " integers:" << endl;
	for (int i = 0; i < dataNum; i++)
		cin >> data[i];

	CountSort(data, dataNum, maxNum);
	cout << "After Count Sort:" << endl;
	for (int i = 0; i < dataNum; i++)
		cout << data[i] << " ";
	cout << endl;

	return 0;
}