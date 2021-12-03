#include <stdio.h>
#define N 500
#define swap(x, y) {int tmp = x; x = y; y = tmp;}
#include <stdbool.h>
void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int size;

void quicksort(int a[], int low, int high) {
    // low -> lower_bound
    // higher -> upper_bound
    
    int p_i;

    if (low>=high) {
        return;
    }
    p_i = partition(a, low, high);

    
    for (int i=0; i<size; i++) {        
        if (i == low) {
            printf("[ ");
        }

        if (i == p_i) {
            printf("*");
        }

        printf("%d ", a[i]);

        if (i == high) {
            printf("] ");
        }        
    }
        
    printf("\n");

    // sort sub-array 1
    quicksort(a, low, p_i-1);
    // sort sub-array 2
    quicksort(a, p_i+1, high);
}

int partition(int a[], int low, int high) {    
    
    int p =a[high];
    int i = low -1;
    
    for (int j = low; j <= high - 1; j++){
        if (a[j] <= p){
            i++;
            swap(a[i], a[j]);            
        }
    }

    swap(a[i+1], a[high]);
    return (i + 1);
}


int main(void)
{
    int array[N];
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    quicksort(array, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}