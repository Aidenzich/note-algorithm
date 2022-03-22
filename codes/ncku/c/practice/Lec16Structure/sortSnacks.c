// gcc sortSnacks.c -o ss.c < ss.in
#include <stdio.h>
#include <string.h>

struct snack
{
    int id;
    int price;
    int weight;
    double value;
};

int cmp(const void *a, const void *b);
void sort_snacks(struct snack snacks[], int n);

int main() {
    int n;
    struct snack snacks[100];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        snacks[i].id = i+1;
        scanf("%d %d", &snacks[i].price, &snacks[i].weight);
    }
    sort_snacks(snacks, n);
    
    for(int i=0; i<n; i++) {
        printf("%d %.2f\n", snacks[i].id, snacks[i].value);
    }
    return 0;
}
int cmpSnack(const struct snack a, const struct snack b );
void sort_snacks(struct snack snacks[], int n) {
    
    for (int i=0; i<n ; ++i){
        snacks[i].value = 0.0;
        snacks[i].value = (double)snacks[i].weight / snacks[i].price;
        // printf("%d, %d, %.2f\n", snacks[i].weight, snacks[i].price ,snacks[i].value);
    }
        
    qsort (snacks, n, sizeof(struct snack), cmp);
}

int cmpSnack(const struct snack a, const struct snack b )
{
    if (a.value > b.value){
        return 0;
    }
    if (a.value == b.value){
        if (a.price < b.price){
            return 0;
        }
        if (a.price == b.price){
            if (a.id < b.id){
                return 0;
            }        
        }        
    }
    return 1;
};

int cmp(const void *a, const void *b) {    
    return cmpSnack(*(const struct snack *)a, *(const struct snack *)b);
}