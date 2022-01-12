# 2021 Final Exam Code Book
# Sort
## qsort
```c
struct tempStruct
{
    /* data */
};

int cmpTempStruct(const struct tempStruct a, const struct tempStruct b){
    /* condition */
}

int cmp(const void* a, const void* b) {               
    return cmpTempStruct(*(const struct tempStruct *)a, *(const struct tempStruct *)b);
}

struct tempStruct temps[100];
qsort (temps, n, sizeof(struct snack), cmp);
```

## for loop use for sort array
```c
for (int i=0; i<count; i++){
    for (int j=i; j<count; j++){
        /* data */
    }
}
```

## Swap
```c
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
```

## int cmp(const void * a, const void * b) with struct
```c
struct tempStruct {
    /* data */
}

int cmp(const void *a, const void *b){
    return cmpRule(*(const struct tempStruct *)a, *(const struct tempStruct *)b);
}

int cmpRule(const struct tempStruct a, cosnt struct tempStruct b){
    /* data */
}

```

# String
## Compare String
- *strcmp*
    - usecase
        ```c
        char PATAPON = "PATA PATA PATA PON";    
        strcmp(PATAPON, "PATA PATA PATA PON") == 0; // True
        ```
    - Return value
      - return `0` : if strings are equal.
      - return `>0` : if the first non-matching character in str1 is greater(in ASCII) than that in str2.
      - return `<0` : if the first non-matching character in str1 is smaller than that in str2.
## Capture String
- *strncpy*
    - usecase
        ```c
            char src[] = "12345678";
            char temp[10] = {0};
            printf("%s", strncpy(temp, src, 3)); // 123
        ```
## String Pointer with Memory locate
```c
char *temp = malloc(7);
strcpy(temp, "HELLO!");
printf("%s", temp);
```
- to use `malloc`, don't forget to:
    ```c
    #include <stdlib.h>
    ```
- wrong case that without malloc.
    ```c
    \\ -------------wrong--------------
    char *temp;
    strcpy(temp, "HELLO!");
    \\ cause `bus error`
    ```

