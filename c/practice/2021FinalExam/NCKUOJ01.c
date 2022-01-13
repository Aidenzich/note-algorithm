#include<stdio.h>
#include<string.h>
#include<memory.h>

int main()
{
    char command[100][10];
    const char *split = ",";
    const char *attack = "PON PON PATA PON";
    const char *forward = "PATA PATA PATA PON";
    const char *backward_and_defend = "CHAKA CHAKA PATA PON";

    char *token = '\0';
    char tmp[10] = {'\0'};

    int distance = 0;
    int blood = 0;
    int counter = 0;
    int valid = 0;
    int input_counter = 0;

    scanf("%d %d", &distance, &blood);

    while (scanf("%s",tmp) != EOF && input_counter<30)
    {
        strcpy(command[input_counter],tmp);
        printf("%s",tmp);
        input_counter += 1;
        printf("%s\n", command[input_counter]);
    }

    while (token != NULL && counter<30)
    {
        token = (NULL, split);
        counter += 1;
        if(strcmp(token, attack) == 0)
        {
            valid += 1;
            if(distance <= 3)
                blood -= 1;
            if (blood == 0)
            {
                printf("YES %d\n", valid);
            }
            if(counter == 10)
            {
                printf("NO %d\n", blood);
            }
        }
        else if(strcmp(token, forward) == 0)
        {
            valid += 1;
            distance -= 1;
            if(distance == 0 || counter == 10)
            {
                printf("NO %d\n", blood);
            }
        }
        else if((strcmp(token, backward_and_defend) == 0))
        {
            valid += 1;
            distance += 1;
        }
        printf("%s\n",token);
        token = (NULL, split);
        counter += 1;
    }
    printf("NO %d\n", blood);
    return 0;
}