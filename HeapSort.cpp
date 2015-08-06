#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class MaxHeap
{
public:
	MaxHeap()
	{
		elemNum = 0;
		maxHeap.push_back(0); //不使用的内存，方便下标操作
	}
	MaxHeap(T elem)
	{
		elemNum = 1;
		maxHeap.push_back(0); //不使用的内存，方便下标操作
		maxHeap.push_back(elem);
	}
	MaxHeap(std::vector<T> &elem) //elem有效数据从下标1开始
	{
		elemNum = elem.size() - 1;
		if (elemNum == 0)
			return;
		else if (elemNum == 1)
		{
			maxHeap.push_back(0); //不使用的内存，方便下标操作
			maxHeap.push_back(elem[1]);
			return;
		}

		maxHeap.push_back(0); //不使用的内存，方便下标操作
		for (int i = 1; i <= elemNum; i++)
			maxHeap.push_back(elem[i]);
		for (int i = elemNum / 2; i >= 1; i--)
			MaxHeapify(maxHeap, i, elemNum);
	}

	void MaxHeapInsert(T elem)
	{
		maxHeap.push_back(elem);
		elemNum++;
		for (int i = elemNum / 2; i >= 1; i--)
			MaxHeapify(maxHeap, i, elemNum);
	}
	void MaxHeapDelete(T elem)
	{
		std::vector<T>::iterator iter = find(maxHeap.begin() + 1, maxHeap.end(), elem);
		if (iter != maxHeap.end())
		{
			*iter = maxHeap[elemNum];
			maxHeap.resize(elemNum);
			elemNum--;
			for (int i = elemNum / 2; i >= 1; i--)
				MaxHeapify(maxHeap, i, elemNum);
		}
	}
	void MaxHeapDisplay()
	{
		for (int i = 1; i <= elemNum; i++)
			std::cout << maxHeap[i] << " ";
		std::cout << std::endl;
	}
	void MaxHeapSort()
	{
		for (int i = elemNum; i > 1; i--)
		{
			swap(maxHeap[1], maxHeap[i]);
			MaxHeapify(maxHeap, 1, i - 1);
		}
	}

private:
	int elemNum;
	std::vector<T> maxHeap;

	void MaxHeapify(std::vector<T> &elem, int index, int num)
	{
		//下面的逻辑更好
		/*int left = 2 * index;
		int right = left + 1;

		int max = elem[index];
		int max_index = index;
		if (left <= num)
		{
			max = std::max(elem[index], elem[left]);
			max_index = (max == elem[left] ? left : index);
		}
		if (right <= num)
		{
			max = std::max(max, elem[right]);
			max_index = (max == elem[right] ? right : max_index);
		}

		if (max_index != index)
		{
			swap(elem[index], elem[max_index]);
			MaxHeapify(elem, max_index);
		}*/

		if (index <= num / 2)
		{
			int left = index * 2;
			int right = index * 2 + 1;
			int max_index = index;

			if (right <= num)
			{
				max_index = elem[left] < elem[right] ? right : left;
				max_index = elem[max_index] < elem[index] ? index : max_index;
			}
			else
			{
				max_index = elem[left] < elem[index] ? index : left;
			}

			if (max_index != index)
			{
				swap(elem[index], elem[max_index]);
				MaxHeapify(elem, max_index, num);
			}
		}
	}
};

int main()
{
	int dataNum;
	cout << "Please enter number of data: ";
	cin >> dataNum;
	vector<int> data(dataNum + 1, 0);
	cout << "Please enter " << dataNum << " integers:" << endl;
	for (int i = 1; i <= dataNum; i++)
		cin >> data[i];

	MaxHeap<int> maxHeap(data);
	cout << "After Build Heap:" << endl;
	maxHeap.MaxHeapDisplay();

	maxHeap.MaxHeapInsert(6);
	cout << "After Insert Heap:" << endl;
	maxHeap.MaxHeapDisplay();

	maxHeap.MaxHeapDelete(6);
	cout << "After delete Heap:" << endl;
	maxHeap.MaxHeapDisplay();

	maxHeap.MaxHeapSort();
	cout << "After Heap Sort:" << endl;
	maxHeap.MaxHeapDisplay();

	return 0;
}