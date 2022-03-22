#include <stdio.h>

int main () {
    char key[1000] = {'\0'}, data = '\0';
    int itr1 = 0;
    scanf("%s",key);
    getchar();
    // scanf("%c",&data);
    while(scanf("%c",&data) != EOF && data > 29)
    {
        if(key[itr1] == '\0')
            itr1 = 0;
        data ^= key[itr1];
        printf("%c",data);
        itr1++;
    }
    return 0;
}
