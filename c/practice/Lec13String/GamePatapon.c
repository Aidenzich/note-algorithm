#include <string.h>
#include <stdio.h>
#include <stdbool.h>


int main(){
    int dis, health;

    scanf("%d %d", &dis, &health);
    // printf("Dis: %d Health: %d\n", dis, health);
    char PATAPON[20000];
    int i, move, available_move = 0;
    
    getchar();
    
    do {
        char ch = getchar();
        int guard = 0;
        // printf("%c",ch);    
        if (ch == '.' || ch == ',' || ch==EOF || ch=='\n'){
            if (health == 0) break;
            move++;
            // printf("==========%s==========\n", PATAPON);
            if (strcmp(PATAPON, "PATA PATA PATA PON") == 0){
                available_move++;
                dis--;                
                // printf("Move %d: 前進一步 [距離%d 怪獸血量%d] \n", move, dis, health);                
            } 
            else if (strcmp(PATAPON, "PON PON PATA PON") == 0){
                available_move++;
                if (dis <= 3){
                    health--;
                    // printf("Move %d: 原地攻擊怪物，扣除怪獸一滴血. [距離%d 怪獸血量%d] \n", move, dis, health);
                } else {
                    // printf("Move %d: 原地攻擊怪物，太遠打不到. [距離%d 怪獸血量%d] \n", move, dis, health);                
                }                                
            }
            else if (strcmp(PATAPON, "CHAKA CHAKA PATA PON") == 0){                
                available_move++;
                // if (move%10==0){
                    dis++;
                    guard = 1;
                    // printf("Move %d: 後退一步並防禦怪物攻擊. [距離%d 怪獸血量%d] \n", move, dis, health);
                // } else {
                    // printf("Move %d: 未觸發防禦. [距離%d 怪獸血量%d] \n", move, dis, health);
                // }                                    
            } else {
                // printf("Move %d: 無效操作\n ", move);
            }
            
            if (move%10 == 0 && guard == 0 && health != 0){
                // printf("GG 被打死了");
                printf("NO %d", health);
                return 0;
            }

            i=0;
            memset(PATAPON, 0, sizeof(PATAPON));
            
        } else {
            PATAPON[i] = ch;
            i++;
            // break;            
        }

        if (ch == '\n' || ch==EOF){
            break;
        }
        
    }while(true);

    if (health <= 0){
        printf("YES %d", available_move);
    } else {
        printf("NO %d", health);
    }

    if (move > 30 && health > 0){
        printf("NO %d", health);
    }
    
 
}