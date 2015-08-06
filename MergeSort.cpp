#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MergeData(vector<int> &dataIn, vector<int> &dataOut, int low, int index, int high)
{
	int i = low;
	int j = index + 1;
	int k = low;

	while (i <= index && j <= high)
	{
		if (dataIn[i] <= dataIn[j])
			dataOut[k++] = dataIn[i++];
		else
			dataOut[k++] = dataIn[j++];
	}

	while (i <= index) //[index+1, high]还有元素未合并
		dataOut[k++] = dataIn[i++];
	while (j <= high) //[low, index]还有元素未合并
		dataOut[k++] = dataIn[j++];

	for (int m = low; m <= high; m++)
		dataIn[m] = dataOut[m];
}

void MergeSort(vector<int> &dataIn, vector<int> &dataOut, int low, int high)
{
	if (high == low)
	{
		dataOut[low] = dataIn[low];
		return;
	}

	int index = (low + high) / 2;
	MergeSort(dataIn, dataOut, low, index);
	MergeSort(dataIn, dataOut, index + 1, high);
	MergeData(dataIn, dataOut, low, index, high);
}

int main()
{
	int dataNum;
	cout << "Please enter number of data: ";
	cin >> dataNum;
	vector<int> dataIn(dataNum, 0);
	cout << "Please enter " << dataNum << " integers:" << endl;
	for (int i = 0; i < dataNum; i++)
		cin >> dataIn[i];
	vector<int> dataOut(dataNum, 0);

	MergeSort(dataIn, dataOut, 0, dataNum - 1);
	cout << "After Merge Sort:" << endl;
	for (int i = 0; i < dataNum; i++)
		cout << dataIn[i] << " ";
	cout << endl;

	return 0;
}

#if 0
void func(int price[], int psize, int low, int &sum)
{
	if (low == psize - 1)
		return;

	int high = low + 1;
	if (price[low] < price[high])
		sum += price[high] - price[low];

	func(price, psize, high, sum);
}

int main()
{
	int price[] = { 3, 3, 3, 3 };

	int sum = 0;

	func(price, 4, 0, sum);

	cout << sum << endl;

	int a = 1999, b = 2299;
	int m = a ^ b;

	int count = 0;
	while (m > 0)
	{
		count++;
		m = m & (m - 1);
	}
	cout << count << endl;

	return 0;
}
#endif