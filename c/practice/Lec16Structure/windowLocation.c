// gcc windowLocation.c -o wl && ./wl < wl.in
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}

Location *parse_url(char *url)
{
    static Location temp;
    
    temp.protocol = malloc(5);
    temp.host = malloc(100);
    

    int split1Count = 0;
    char * split1 = strtok(url, "/");
    while (split1 != NULL ) {        
        printf("%s\n", split1);
        if (split1Count == 0){
            char *tempSplit;
            tempSplit = malloc(100);
            strcpy(tempSplit, split1);
            // printf("%s", tempSplit);
            // printf("%s\n", tempSplit);

            tempSplit = strtok(tempSplit, ":");
            strcpy(temp.protocol, tempSplit);
            
            // strrep(temp.protocol, ":", "");            
        }

        if (split1Count == 1){
            printf("%s\n", split1);
            strcpy(temp.host, split1);            
            // tempSplit = strtok(tempSplit, ":");
            if (split1Count == 0){
                // memset(split1, 0, sizeof(split1));
            }
        }

        // printf("%s\n", split1);
        split1 = strtok(NULL, "/");
        split1Count++;
    }
        
    // char * pst;
    // int pstCount = 0;
    // pst = strtok(url, "/");
    // while (pst != NULL){        
    //     printf("%d %s\n", pstCount, pst);
    //     pst = strtok(NULL, "/");
    //     pstCount++;
    // }

    char * pst2;
    int pstCount2 = 0;
    pst2 = strtok(url, "?");
    while (pst2 != NULL){
        if (pstCount2 == 1){
            // char *search = malloc(100);
            temp.search = malloc(100);                     
            strcpy(temp.search, pst2);
        }
        // printf("%d %s\n", pstCount2, pst2);
        pst2 = strtok(NULL, "?");
        pstCount2++;
    }



    // strncpy(proto, url, 4);    
    // temp->pathname = malloc(100);
    // temp->pathname = proto;
    // temp->pathname = malloc(1000);
    // strcpy(temp->pathname, proto);
    return &temp;
}