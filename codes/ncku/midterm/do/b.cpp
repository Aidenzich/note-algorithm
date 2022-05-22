#include <bits/stdc++.h>
using namespace std;
 
const int N = 100001;
int answer[N];
 
void merge(pair<int, int> a[], int start, int mid, int end) {
    pair<int, int> f[mid - start + 1],
                   s[end - mid];
                    
    int n = mid - start + 1;
    int m = end - mid;
     
    for(int i = start; i <= mid; i++)
        f[i - start] = a[i];
    for(int i = mid + 1; i <= end; i++)
        s[i - mid - 1] = a[i];
         
    int i = 0, j = 0, k = start;
    int cnt = 0;
 
    while(i < n && j < m) {
        if (f[i].second <= s[j].second) {
            answer[f[i].first] += cnt;
            a[k++] = f[i++];
        } else {
            cnt++;
            a[k++] = s[j++];
        }
    }
 
    
    while(i < n) {
        answer[f[i].first] += cnt;
        a[k++] = f[i++];
    }
     
    while(j < m) {
        a[k++] = s[j++];
    }
}
 
void ms(pair<int, int> item[], int low, int high) {
    if (low >= high)
        return;
         
    int mid = (low + high) / 2;
    ms(item, low, mid);
    ms(item, mid + 1, high);
    merge(item, low, mid, high);
}
 

void printAll(int arr[], int n)
{
    for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}
 
int main()
{
    int n;
    cin >> n;
    int arr[n] = {0};
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    

    pair<int, int> pairA[n];
    memset(answer, 0, sizeof(answer));
     
    for(int i = 0; i < n; i++)
    {
        pairA[i].second = arr[i];
        pairA[i].first = i;
    }
     
    ms(pairA, 0, n - 1);
    printAll(answer, n);
     
    return 0;
}