#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int room_num = 0;
    scanf("%d", &room_num);
    int rooms[room_num];
    int already[500] = {-1};
    int rings_num=0;
    int rings[500][500];
    memset(rings, -1, sizeof(rings));
    for (int i=0; i<room_num; ++i){
        scanf("%d", &rooms[i]);
    }
    
    for (int i=0; i<room_num; ++i){
        if (already[i] == 1){
            continue;
        }
        // int ring[500] = {-1};
        bool end = false;
        int next = i;
        int index = 0;
        rings[rings_num][index] = i;
        
        while (!end){
            index++;
            rings[rings_num][index] = rooms[next];            
            already[rooms[next]] = 1;
            if (rooms[next] == i){
                end = true;
                rings_num++;
            } else {
                next = rooms[next];                
            }            
        }            
    }
    printf("%d rings\n", rings_num);
    // printf("%d", rings[0][2]);

    for (int i=0; i<rings_num; ++i){
        bool end =false;
        int j = 0;
        while (!end){                        
            if (rings[i][j+1] == -1){
                printf("%d\n", rings[i][j]);                    
                break;
            } else {
                printf("%d -> ", rings[i][j]);
            }            
            j++;
        }
    }
}