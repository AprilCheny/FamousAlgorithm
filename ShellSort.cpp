#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ShellSort(vector<int> &data, int dataNum)
{
	int step = dataNum / 2;
	while (step > 0)
	{
		for (int i = step; i < dataNum; i++)
		{
			for (int j = i - step; j >= 0; j -= step)
			{
				if (data[j] > data[j + step])
					swap(data[j], data[j + step]);
			}
		}
		cout << "step: " << step << endl;
		for (int i = 0; i < dataNum; i++)
			cout << data[i] << " ";
		cout << endl;

		step = step  / 2;
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

	ShellSort(data, dataNum);
	cout << "After Shell Sort:" << endl;
	for (int i = 0; i < dataNum; i++)
		cout << data[i] << " ";
	cout << endl;

	return 0;
}