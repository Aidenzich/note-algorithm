#include <stdio.h>
int *report_card (int *s) ;

int main () {
    int score[1001];
    int *show;
    int count = 0;

    do {
        scanf("%d", &score[count++]);
    } while (score[count - 1] != -1);

    show = report_card(score);

    count = 0;
    while (*(show + count) != -1) {
        printf("%d ", *(show + count));
        count++;
    }
}

int *report_card (int *s) {
    int croped[1001];
    int current_idx = 0;
    
    int croped_len = 0;
    int croped_start_idx = 0;
    int croped_end_idx = 0;
    int croped_sum = 0;

    int max_croped_len = 0;
    int max_start_idx = 0;
    int max_end_idx = 0;
    int max_sum = 0;


    for (int i=0; i<1001; ++i){
        if (s[i] >= 60){
            croped_start_idx = i;
            croped_end_idx = i;
            croped_sum = s[i];
            croped_len = 0;
            while (s[++i] >= 60){
                croped_sum += s[i];
                croped_len++;
                croped_end_idx = i;
            }
            if (croped_len > max_croped_len || (croped_len == max_croped_len && croped_sum > max_sum)) {
                max_croped_len = croped_len;
                max_start_idx = croped_start_idx;
                max_end_idx = croped_end_idx;
                max_sum = croped_sum;
            }
        }

        
        if (s[i] == -1) break;
        
    }

    current_idx = 0;
    for (int i= max_start_idx; i<=max_end_idx; ++i){
        // printf("%d\n", s[i]);
        croped[current_idx] = s[i];
        current_idx++;
    }
    


    // printf("max_len:%d\n", max_croped_len);
    // printf("start_idx:%d, value:%d\n", max_start_idx, s[max_start_idx]);
    // printf("end_idx:%d value:%d\n", max_end_idx, s[max_end_idx]);
    // printf("max_sum:%d\n", max_sum);
    
    for (int i=0; i<=max_croped_len; ++i){
        // printf("%d\n", croped[i]);
        s[i] = croped[i];
    }
    s[max_croped_len + 1] = -1;

    return s;

}