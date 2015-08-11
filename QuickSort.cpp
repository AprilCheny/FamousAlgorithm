#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Partition(vector<int> &data, int low, int high)
{
	int base = data[low]; //设定基准元素
	while (low < high) //一趟调整尚未完毕
	{
		while (low < high && base < data[high])
			high--;
		if (low < high) //找到小于基准的元素
		{
			data[low] = data[high];
			low++;
		}

		while (low < high && data[low] < base)
			low++;
		if (low < high) //找到大于基准的元素
		{
			data[high] = data[low];
			high--;
		}
	}

	data[low] = base; //返回基准元素的新位置

	return low;
}

void QuickSort(vector<int> &data, int low, int high)
{
	if (low < high)
	{
		int index = Partition(data, low, high); //调整数组，并返回基准元素的新位置
		QuickSort(data, low, index - 1); //基准元素左边子数组递归排序
		QuickSort(data, index + 1, high); //基准元素右边子数组递归排序
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

	QuickSort(data, 0, dataNum - 1);
	cout << "After Shell Sort:" << endl;
	for (int i = 0; i < dataNum; i++)
		cout << data[i] << " ";
	cout << endl;

	return 0;
}