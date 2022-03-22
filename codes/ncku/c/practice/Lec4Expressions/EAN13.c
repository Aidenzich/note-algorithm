#include <stdio.h>

int main(void){
    int i1, i2, i3, sum, path, ans;
    scanf("%d%d%d", &i1, &i2, &i3);

    sum += i1;

    path = 0;
    while (i2 != 0){
        int tmp = i2 % 10;
        if (path % 2 == 0){
            sum += tmp;
        } else {
            sum += 3* tmp;
        }
        i2 = i2 / 10;
        path ++;
    }
    path = 1;
    while (i3 != 0){
        int tmp = i3 % 10;
        if (path % 2 == 0){
            sum += tmp;
        } else {
            sum += 3* tmp;
        }
        i3 = i3 / 10;
        path ++;
    }

    ans = ((((sum -1)/10) * 10) + 10) - sum;

    printf("%d", ans);
    return 0;
}