#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SwapSort(vector<int> &data, int dataNum) //注意不是选择排序
{
	for (int i = 0; i < dataNum - 1; i++)
	{
		for (int j = i + 1; j < dataNum; j++)
		{
			if (data[j] < data[i])
			swap(data[j], data[i]);
		}
	}
}

void SelectSort(vector<int> &data, int dataNum)
{
	for (int i = 0; i < dataNum - 1; i++)
	{
		int index = i;
		for (int j = i + 1; j < dataNum; j++)
		{
			if (data[j] < data[index])
				index = j;
		}

		if (index != i)
		swap(data[index], data[i]);

		/*cout << "loop: " << i << endl;
		for (int k = 0; k < dataNum; k++)
			cout << data[k] << " ";
		cout << endl;*/
	}
}

int main()
{
	int dataNum;
	cout << "Please enter number of data: ";
	cin >> dataNum;
	vector<int> data(dataNum, 0);
	cout << "Please enter " << dataNum << " integers: " << endl;
	for (int i = 0; i < dataNum; i++)
		cin >> data[i];

	SelectSort(data, dataNum);
	cout << "After select sort:" << endl;
	for (int i = 0; i < dataNum; i++)
		cout << data[i] << " ";
	cout << endl;

	return 0;
}