#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define R 100

void rotateRight(int rotateTime);
void rotateLeft(int rotateTime);
void displayMatrix();
void flipVertical();
void flipHorizontal();
void crop(int leftEdge, int rightEdge, int upEdge, int downEdge);


int arr[R][R];
int tempArr[R][R];
int m, n, tmp;


int main(){
    
    int oper_num;
    
    scanf("%d %d", &m, &n);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    scanf("%d", &oper_num);

    char c = getchar();
    
    for (int i = 0; i<oper_num; ++i){
        
        c = getchar();
        
        // rotate
        if (c=='r'){
            
            char dir;
            int rotateTime;
            
            scanf(" %c %d", &dir, &rotateTime);
            
            rotateTime = rotateTime % 4;
            if (rotateTime < 0){
                rotateTime+=4;
            }
            if (rotateTime > 0){
                if (dir=='l') {
                    rotateLeft(rotateTime);
                }
                if (dir=='r') {                
                    rotateRight(rotateTime);
                    
                }
            }            
        }

        // vertical
        if (c=='v'){
            flipVertical();
        }

        // horizontal
        if (c=='h'){
            flipHorizontal();
        }
        if (c=='c'){
            int leftEdge, rightEdge, upEdge, downEdge;
            scanf("%d %d %d %d", &leftEdge, &rightEdge, &upEdge, &downEdge);
            crop(leftEdge, rightEdge, upEdge, downEdge);
        }
        if (c=='p'){
            displayMatrix();
        }

        c = getchar();
    }

    
    return 0;
}

void rotateRight(int rotateTime){
    for (int i=0; i<n; ++i){
        for (int j=m-1; j>=0; --j){
            tempArr[i][m-1-j] = arr[j][i];
        }
    }
    
    // update arr
    for (int i=0; i<R; ++i){
        for (int j=0; j<R; ++j){
            arr[i][j] = tempArr[i][j];
        }
    }
    // update m, n
    tmp = m;
    m = n;
    n = tmp;

    rotateTime--;
    if (rotateTime > 0) rotateRight(rotateTime);
}


void rotateLeft(int rotateTime){    
    for (int i=0; i<m; ++i){
        for (int j=0; j<n; ++j){
            tempArr[n-1-j][i] = arr[i][j];
        }
    }
    
    // update arr
    for (int i=0; i<R; ++i){
        for (int j=0; j<R; ++j){
            arr[i][j] = tempArr[i][j];
        }
    }

    // update m, n
    tmp = m;
    m = n;
    n = tmp;

    rotateTime--;
    if (rotateTime > 0) rotateLeft(rotateTime);

}

void flipVertical(){
    for (int i=0; i< m; ++i){
        for (int j=0; j<n; ++j){
            tempArr[m-1-i][j] = arr[i][j];
        }
    }
    for (int i=0; i<R; ++i){
        for (int j=0; j<R; ++j){
            arr[i][j] = tempArr[i][j];
        }
    }
}

void flipHorizontal(){
    for (int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            tempArr[i][n-1-j] = arr[i][j];
        }
    }
    for (int i=0; i<R; ++i){
        for (int j=0; j<R; ++j){
            arr[i][j] = tempArr[i][j];
        }
    }
}

void crop(int leftEdge, int rightEdge, int upEdge, int downEdge){
    for(int i=leftEdge-1, q=0; i<=rightEdge-1; i++, q++){
        for(int j=upEdge-1, p=0; j<=downEdge-1; j++, p++){
            tempArr[p][q] = arr[j][i];
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<R; j++){
            arr[i][j] = tempArr[i][j];
        }
    }

    m = downEdge - upEdge +1;
    n = rightEdge - leftEdge +1;
}



void displayMatrix(){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}