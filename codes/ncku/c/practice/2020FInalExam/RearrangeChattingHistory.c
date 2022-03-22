#include <stdio.h>
#include <stdlib.h>
#define MESSAGE_LENGTH 64
#define NAME_LENGTH 10

struct timestamp {
    int hour, minute;
};

struct message_info {
    struct timestamp time;
    char name[NAME_LENGTH];
    char message[MESSAGE_LENGTH];
};

int cmp(const void *a, const void *b);
void sort_message(struct message_info *m, int *total);
int cmpMessage(const struct message_info a, const struct message_info b);

int main(void) {
    struct message_info m[100];
    int total;
    scanf("%d", &total);
    for(int i = 0; i < total; i++)
        scanf("%d:%d %s %[^\n]", &m[i].time.hour, &m[i].time.minute, m[i].name, m[i].message);

    sort_message(m, &total);

    for(int i = 0; i < total; i++)
        printf("%02d:%02d %s %s\n", m[i].time.hour, m[i].time.minute, m[i].name, m[i].message);
    
    return 0;
}

int cmpMessage(const struct message_info a, const struct message_info b){
    int totalMinA = a.time.hour * 60 + a.time.minute;
    int totalMinB = b.time.hour * 60 + b.time.minute;
    // printf("compare %s and %s\n", a.name, b.name);
    if (totalMinA > totalMinB){
        return 1;
    }
    return 0;
}

int cmp(const void* a, const void* b) {
            
    // printf("%s\n", *(const message *)&a); // printf const point                
    return cmpMessage(*(const struct message_info *)a, *(const struct message_info *)b);
}

void swap(struct message_info *a, struct message_info *b){
    struct message_info temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void sort_message(struct message_info *m, int *total) {
    for (int i=0; i<=*total; i++){            
        for (int j=i; j<*total; j++){
            if (cmp(&m[i], &m[j]) == 1){
                swap(&m[i], &m[j]);
            }            
        }
    }
}

// gcc RearrangeChattingHistory.c -o c && ./c < c.in