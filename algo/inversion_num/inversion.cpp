#include <iostream>
using namespace std;
 
long mergeSort(long arr[], long temp[], long left, long right);
long merge(long arr[], long temp[], long left, long mid, long right);

long mergeSort(long arr[], long temp[], long left, long right)
{
    long mid, inv = 0;
    if (right > left) {

        mid = (right + left) / 2;
        inv += mergeSort(arr, temp, left, mid);
        inv += mergeSort(arr, temp, mid + 1, right);
        inv += merge(arr, temp, left, mid + 1, right);
    }
    return inv % 524287;
}
 

long merge(long arr[], long temp[], long left, long mid, long right) {
    long i, j, k;
    long inv = 0;
 
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv = inv + (mid - i);
        }
    }
 
    while (i <= mid - 1) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];
 
    return inv ;
}
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long N;
    long input;
    cin >> N;
    long arr[N];
    long temp[N];
    for (long i=0; i<N; i++){
        cin >> input;
        arr[i] = input;
    }
    
    long ans = mergeSort(arr, temp, 0, N-1);
    cout << ans;

    return 0;
}
