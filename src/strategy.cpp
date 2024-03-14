#include<iostream>
using namespace std;

// 策略接口
class SortingStrategy {
	public:
		virtual void sort(int arr[], int size) const = 0;
};

// 冒泡排序
class BubbleSortStrategy : public SortingStrategy {
	public: 
		void sort(int arr[], int size) const override {
			for (int i = 0; i < size - 1; i ++) {
				for (int j = 0; j < size - i - 1; j ++) {
					if (arr[j] > arr[j + 1]) {
						swap(arr[j], arr[j + 1]);
					}
				}
			}
		}
};

// 快速排序
class QuickSortStrategy : public SortingStrategy {
	public:
		void sort(int arr[], int size) const override {
			quickSort(arr, 0, size - 1);
		}
	private:
		void quickSort(int arr[], int low, int high) const {
			if (low < high) {
				int pivotIndex = partition(arr, low, high);
				quickSort(arr, low, pivotIndex - 1);
				quickSort(arr, pivotIndex + 1, high);
			}
		}
		int partition(int arr[], int low, int high) const {
			int pivot = arr[high];
			int i = low - 1;
			for (int j = low; j <= high - 1; j ++) {
				if (arr[j] < pivot) {
					++i;
					swap(arr[i], arr[j]);
				}
			}
			swap(arr[i + 1], arr[high]);
			return i + 1;
		}
};

class Sorter {
	private: 
		const SortingStrategy* sortingStrategy;
	public: 
		void setSortingStrategy(const SortingStrategy& strategy) {
			sortingStrategy = &strategy;
		}
		void performSort(int arr[], int size) const {
			sortingStrategy->sort(arr, size);
		}
};

int main() {
	int arr[] = {5, 2, 7, 1, 9};
	Sorter sorter;
	BubbleSortStrategy bubbleSort;
	QuickSortStrategy quickSort;
	sorter.setSortingStrategy(bubbleSort);
	sorter.performSort(arr, 5);

	cout << "冒泡排序：";
	for (int i = 0; i < 5; i ++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int arr2[] = {5, 0, 2, 4, 7, 2};
	sorter.setSortingStrategy(quickSort);
	sorter.performSort(arr2, 6);
	cout << "快速排序：";
	for (int i = 0; i < 6; i ++) {
		cout << arr2[i] << " ";
	}
	cout << endl;
	return 0;
}
