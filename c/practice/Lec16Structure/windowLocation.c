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
    
    temp.protocol = malloc(100);
    temp.host = malloc(1000);
    temp.hash = malloc(1000);
    temp.search = malloc(1000);
    temp.pathname = malloc(1000);
    int split1Count = 0;

    char strArr[100][100];
    
    char * split1 = strtok(url, "/");
    while (split1 != NULL ) {        
        strcpy(strArr[split1Count], split1);        
        split1 = strtok(NULL, "/");
        split1Count++;
    }
    
    char pathname[100] = {};
    int pathCount = 0;
    for (int i=0; i< split1Count; i++){
        
        if (i==0){
            // printf("proto: ");
            split1 = strtok(strArr[i], ":");
            // printf("%s\n", split1);
            strcpy(temp.protocol, split1);
        } 
        else if (i==1){            
            split1 = strtok(strArr[i], ":");
            // printf("host: %s\n", split1);
            if (split1[strlen(split1)-1] =='\n'){
                split1[strlen(split1)-1] ='\0';
            }
            
            strcpy(temp.host, split1);
            
            split1 = strtok(NULL, ":");
            if (split1 != NULL){
                temp.port = atoi(split1);
            }
            
            // printf("port: %s\n", split1);
        }  
        else if (strchr(strArr[i], '?') != NULL){
            // printf("?->%s\n", strArr[i]);
            split1 = strtok(strArr[i], "?");
            // printf("%s\n", split1);
            if (pathCount > 0){
                strcat(pathname, "/");
            }
            strcat(pathname, split1);
            split1 = strtok(NULL, "?");
            // printf("%s\n", split1);

            // #
            split1 = strtok(split1, "#");
            if (split1 != NULL){
                strcpy(temp.search, split1);
            }
            // printf("%s\n", split1);
            
            split1 = strtok(NULL, "#");
            // printf("%s\n", split1);
            if (split1 != NULL){
                strcpy(temp.hash, split1);
            }
            
        } else {
            if (pathCount > 0){
                strcat(pathname, "/");
            }            
            strcat(pathname, strArr[i]);
            pathCount++;
        }
    }

    if (pathname[strlen(pathname)-1] == '\n'){
        pathname[strlen(pathname)-1] ='\0';
    }
    
    strcpy(temp.pathname, pathname);
    // printf("path:::: %s\n", pathname);
    return &temp;
}