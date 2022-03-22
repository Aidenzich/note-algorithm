#include <stdio.h>

struct weight {
    char chapter[10];
    int percent;
};

struct score {
    char chapter[10];
    int score;
};

struct report_card {
    char name[32];
    struct score record[10];
    int final;
    int max_score;
    int min_score;
};

void calculate (struct report_card[], struct weight[], int student_num, int chapter_num);

int main () {
    int student_num, chapter_num;
    struct weight chapter[10];
    struct report_card card[100];

    scanf("%d %d\n", &chapter_num, &student_num);
    for (int i = 0; i < chapter_num; ++i) {
        scanf("%d %s", &chapter[i].percent, chapter[i].chapter);
    }

    for (int i = 0; i < student_num; ++i) {
        scanf("%s", card[i].name);
        for (int j = 0; j < chapter_num; ++j) {
            scanf("%d %s", &card[i].record[j].score, card[i].record[j].chapter);
        }
    }

    calculate(card, chapter, student_num, chapter_num);

    for (int i = 0; i < student_num; ++i) {
        printf("%s %d %d %d\n", card[i].name, card[i].final, card[i].max_score, card[i].min_score);
    }
}

#include <string.h>
#include <math.h>
void calculate (struct report_card card[], struct weight chapter[], int student_num, int chapter_num) {
    for (int i=0; i<student_num; i++){
        int max = 0;
        int min = 101;
        int final = 0;
        card[i].final = 0;
        // printf("%s %d\n", card[i].name, card[i].final);
        for (int i2=0; i2<chapter_num; i2++){
            // printf("%d\n", card[i].record[i2].score);
            if (card[i].record[i2].score > max) max = card[i].record[i2].score;
            if (card[i].record[i2].score < min) min = card[i].record[i2].score;
            for (int i3=0; i3< chapter_num; i3++){
                if (strcmp(card[i].record[i2].chapter, chapter[i3].chapter) == 0){
                    final += (int)(card[i].record[i2].score * chapter[i3].percent);
                    break;
                }
            }            
        }
        card[i].final = final/100;
        card[i].max_score = max;
        card[i].min_score = min;
    }
}


// gcc weightedScore.c -o ws && ./ws < ws.in