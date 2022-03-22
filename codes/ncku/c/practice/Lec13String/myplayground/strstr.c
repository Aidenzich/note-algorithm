#include <stdio.h>
#include <string.h>


int main () {
    const char haystack[45] = "TutorialsPoint  ss Point";
    const char needle[10] = "Point";
    char *ret;

    ret = strstr(haystack, needle);
    int pos = ret - haystack;
    int need_len = strlen(needle);

    int need_end = pos + strlen(needle);



    int sub_len = strlen(haystack) - pos;
    
    char remain[45];
    memcpy(remain, &haystack[need_end], sub_len);
    remain[sub_len] = '\0';



    printf("The substring is: %s\n", remain);
    
    return(0);
}


