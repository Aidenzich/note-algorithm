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
    float test;
    double temp = 0;    
    for (int i=0; i < N*2; ++i){
        int x = *(coords+(i++));        
        int y = *(coords+i);
        printf("%d %d\n", x, y);
        
        test = atan2(y, x) * 180 / 3.14159;
        if (test < 0 ) test += 360;
        printf("%.2f\n", test);
    }

    

    
    // test = atan(temp) * 180 / 3.14159;
    // printf("%d\n", N);
    // printf("%d\n", coords[0]);
    // test = atan(coords[0]);
    
}
