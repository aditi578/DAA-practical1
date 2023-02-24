#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int arr[] = { 55,54,60,10,18 };
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, N);
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}

/*
Worst Case Complexity: O(n2)
Best Case Complexity: O(n)
average Case Complexity: O(n2)

space - O(1)
*/