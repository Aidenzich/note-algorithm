#include <iostream>
#include <cassert>
#include <stack>
#include <math.h>

using namespace std ;

int QuickSortOnce(int a[], int low, int high)
{
	int pivot = a[low];	
	int i = low, j = high;

	while (i < j)
	{
		while (a[j] >= pivot && i < j){
			j--;
		}

		a[i] = a[j];

		while (a[i] <= pivot && i < j)
		{
			i++;
		}

		a[j] = a[i];
	}
	
	a[i] = pivot;
	
	return i;
}

void QuickSort(int a[], int low, int high)
{
	if (low >= high)
	{		
		return;
	}

	int pivot = QuickSortOnce(a, low, high);
	
    
	// 對樞軸的左端進行排序。
	QuickSort(a, low, pivot - 1);

	// 對樞軸的右端進行排序。
	QuickSort(a, pivot + 1, high);
}

int EvaluateMedian(int a[], int n)
{
	QuickSort(a, 0, n - 1);

	if(n % 2 !=0){
		return a[n / 2];
	}
	else{
		return (a[n / 2] + a[n / 2 - 1]) / 2;
	}
}

int main()
{
    int num;
    cin >> num;
    
	int a[num];

    for (int i=0; i<num; ++i){
        cin >> a[i];
    }

	cout << EvaluateMedian(a, num) << "\n";

	return 0;
}