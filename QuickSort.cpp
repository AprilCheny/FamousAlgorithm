#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Partition(vector<int> &data, int low, int high)
{
	int base = data[low]; //�趨��׼Ԫ��
	while (low < high) //һ�˵�����δ���
	{
		while (low < high && base < data[high])
			high--;
		if (low < high) //�ҵ�С�ڻ�׼��Ԫ��
		{
			data[low] = data[high];
			low++;
		}

		while (low < high && data[low] < base)
			low++;
		if (low < high) //�ҵ����ڻ�׼��Ԫ��
		{
			data[high] = data[low];
			high--;
		}
	}

	data[low] = base; //���ػ�׼Ԫ�ص���λ��

	return low;
}

void QuickSort(vector<int> &data, int low, int high)
{
	if (low < high)
	{
		int index = Partition(data, low, high); //�������飬�����ػ�׼Ԫ�ص���λ��
		QuickSort(data, low, index - 1); //��׼Ԫ�����������ݹ�����
		QuickSort(data, index + 1, high); //��׼Ԫ���ұ�������ݹ�����
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