#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int limit_time = 0;
    int tmp_hour = 0;
    int tmp_min = 0;
    int t = 0;
    scanf("%d:%d", &tmp_hour, &tmp_min);
    scanf("%d", &t);


    limit_time = 60*tmp_hour + tmp_min;
    // printf("%d:%d\n", tmp_hour, tmp_min);
    // printf("%d", limit_time);
    int ans_id;
    int min = 1e9;
    for (int i=0; i< t; i++){
        int tmp_start = 0;
        int tmp_id = 0;
        int tmp_take = 0;
        
        scanf("%d %d:%d %d", &tmp_id, &tmp_hour, &tmp_min, & tmp_take);
        tmp_start = 60*tmp_hour + tmp_min;
        if (tmp_start < limit_time){
            // printf("can't drive\n");
            continue;
        }
        int arrive_time = tmp_start + tmp_take;
        

        if (min > arrive_time){
            min = arrive_time;
            ans_id = tmp_id;
        }
    }
    printf("%d", ans_id);
}