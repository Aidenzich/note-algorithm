#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 1024

void convert_to_polar(int *coords, int N);

int main()
{
    int N, coords[MAX_N + 1][2];
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
        scanf("%d%d", &coords[i][0], &coords[i][1]);
    
    
    convert_to_polar((int *) coords, N);
    
    return 0;
}


void convert_to_polar(int *coords, int N)
{
    double PI = 3.14159265359;
    double DIR;
    double DIST;
    
    // for (int *i=coords; i < coords+ N*2; i+=2){
    for (int i=0; i< N*2; ++i){
        int x = *(coords+(i++));        
        int y = *(coords+i);
        // int x = i[0], y=i[1];

        DIST = sqrt(pow(x, 2) + pow(y, 2));        

        DIR = atan2(y, x)/ PI * 180 ;        
                
        if (DIR < 0 ) DIR += 360;

        printf("%.2f %.2f\n", DIR, DIST);
    }        
}
