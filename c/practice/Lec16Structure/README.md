# CH16. Structure

## 3 way to Define/Declar and Initialize
- Basic Include and Define
    ```c
    #include <stdio.h>
    #include <strign.h>
    #define NAME_LEN 50
    ```
- First Way
    ```c
    struct address {
        char name[50];
        char street[100];
        char city[50];
        int pin;
    };

    int main(){
        struct address NCKU = {
            .name = "National Cheng Kung University",
            .street = "East District",
            .city = "Tainan City"
        };
        
        printf("%s\n", NCKU.name);
        printf("%s\n", NCKU.street);
        printf("%s\n", NCKU.city);
    }
    ```
- Second Way
    ```c
    int main(){
        struct address{
            char name[50];
            char street[100];
            char city[50];
            int pin;
        } NCKU={
            "National Cheng Kung University",
            "East District",
            "Tainan City"
        },
        MIT={
            "Massachusetts Institute of Technology",
            "77 Massachusetts Ave",
            "Cambridge"
        };

        printf("%s %s %s\n", 
            NCKU.name, 
            NCKU.street,
            NCKU.city
        );
        printf("%s %s %s", 
            MIT.name,
            MIT.street,
            MIT.city
        );
    }  
    ```
- Third Way
    ```c
    typedef struct Addresses {
        char name[NAME_LEN+1];
        char street[100];
        char city[50]; 
        int pin;
    } Address;

    int main(){
        Address NCKU;
        strcpy(NCKU.name, "National Cheng Kung University");
        strcpy(NCKU.street, "East District");
        strcpy(NCKU.city, "Tainan City");
        
        printf("%s\n", NCKU.name);
        printf("%s\n", NCKU.street);
        printf("%s\n", NCKU.city);
    }
    ```