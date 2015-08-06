#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BucketSort(vector<int> &data, int dataNum, int maxNum)
{
	int bucNum = maxNum / 10;

	vector< vector<int> > vvi(bucNum + 1);
	for (int i = 0; i < dataNum; i++) //分配到每个桶中
		vvi[data[i] / 10].push_back(data[i]);

	for (int i = 0; i < bucNum; i++) //每个桶单独排序
		sort(vvi[i].begin(), vvi[i].end());

	int k = 0;
	for (int i = 0; i <= bucNum; i++)
	{
		for (vector<int>::iterator iter = vvi[i].begin(); iter != vvi[i].end(); iter++)
			data[k++] = *iter;
	}
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

	BucketSort(data, dataNum, maxNum);
	cout << "After Bucket Sort:" << endl;
	for (int i = 0; i < dataNum; i++)
		cout << data[i] << " ";
	cout << endl;

	return 0;
}