// gcc e.c -o e && ./e < e.in
#include <stdio.h>
int main(){
    // int test = ({1 > 2? 1 : 2;});
    int test = ({ int a=1; int b =2; a < b ? 1 : 2; });
    printf("%d", test);

    
}
