#include <stdio.h>
#include <stdint.h>

int bingo (unsigned char[]);

int main () {
    unsigned char num[8];
    for (int i = 0; i < 8; ++i) {
        scanf("%hhu", &num[i]);
    }
    printf("%d\n", bingo(num));
}

int bingo(unsigned char num[])
{
    int card[8][8] = {0};
    int mask = 1, itr1 = 0, itr2 = 0, ans = 0, cross_1 = 0, cross_2 = 0;
    for(itr1 = 0; itr1 < 8; itr1++)
    {
        for(itr2 = 0; itr2 < 8; itr2++)
        {
            card[itr1][itr2] = mask & num[itr1];
            num[itr1] >>= 1;
            // printf("%d",card[itr1][itr2]);
        }
        // printf("\n");
    }
    for(itr1 = 0; itr1 < 8; itr1++)
    {
        int tmp_col = 0;
        int tmp_row = 0;
        for(itr2 = 0; itr2 < 8; itr2++)
        {
            tmp_col += card[itr2][itr1];
            tmp_row += card[itr1][itr2];
        }
        cross_1 += card[itr1][itr1];
        cross_2 += card[itr1][7 - itr1];
        if(tmp_col == 8)
            ans += 1;
        if(tmp_row == 8)
            ans += 1;
    }
    if(cross_2 == 8)
        ans += 1;
    if(cross_1 == 8)
        ans += 1;
    return ans;
}