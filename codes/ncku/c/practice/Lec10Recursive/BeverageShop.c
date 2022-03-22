#include <stdio.h>

int teas[5]; //black tea (L)/ White gourd (L)/Tieguanyin tea (L)/green tea (L)/milk (L)/sugar (kg)/ice (kg).
int totalNum=0, current=0, earn=0, sugar, ice, sugarLevel, iceLevel;

char c;

void useBlackTea();
void useWhiteGourd();
void useTieguanyinTea();
void useGreen();

void useIce(int iceLevel);
void useSugar(int sugarLevel);

int main() {
    
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &teas[i]);
        teas[i] = teas[i] * 1000;
    }

    scanf("%d%d", &sugar, &ice);
    sugar *= 1000;
    
    ice *= 1000;
    scanf("%d", &totalNum);
    while (current<totalNum){
        switch (c=getchar()) {
            case 'B':
                useBlackTea();
                break;
            case 'W':
                useWhiteGourd();
                break;
            case 'T':
                useTieguanyinTea(); 
                break;
            case 'G':
                useGreen();
                break;
        }
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d ",teas[i]);
    }

    printf("%d %d", sugar, ice);
    printf("\n%d", earn);

    return 0;
}

void useBlackTea(){    
    c = getchar();

    if( c =='M'){
        teas[0] -= (200);
        teas[4] -= (300);
        earn += 35;
    } else {
        teas[0]-= 500;
        earn+=20;
    }
    scanf("%d/%d", &sugarLevel, &iceLevel);
    
    useSugar(sugarLevel);
    useIce(iceLevel);
    
    ++current;
}

void useWhiteGourd(){    
    c = getchar();

    if( c =='M'){
        teas[1]-= 200;
        teas[4]-= 300;
        earn+= 30;
    } else if( c =='T'){
        teas[2]-= 350 ;
        teas[1]-= 150 ;
        earn+=40;
    } else {
        teas[1]-= 500;
        earn+=15;
    }
    scanf("%d/%d", &sugarLevel, &iceLevel);
    
    useSugar(sugarLevel);
    useIce(iceLevel);
    ++current;
}
void useTieguanyinTea(){        
    c=getchar();
    
    if(c=='M'){
        teas[2] -= 200 ;
        teas[4] -= 300;
        earn += 45;
    } else {
        teas[2] -= 500;
        earn += 30;
    }
    
    scanf("%d/%d", &sugarLevel, &iceLevel);
    
    useSugar(sugarLevel);
    useIce(iceLevel);

    ++current;
}

void useGreen(){    
    c = getchar();

    if(c == 'T'){
        teas[2] -= 250;
        teas[3] -= 250;
        earn+=45;
    } else {
        teas[3] -= 500;
        earn += 20;
    }
    scanf("%d/%d", &sugarLevel, &iceLevel);
    
    useSugar(sugarLevel);
    useIce(iceLevel);
    
    ++current;
}



void useIce(int iceLevel){
    switch (iceLevel) {
        case 1:
            break;
        case 2:
            ice -= 30; 
            break;
        case 3: 
            ice -= 50; 
            break;
        case 4: 
            ice -= 70; 
            break;
        case 5:
            ice-=100; 
            break;
    }
}

void useSugar(int sugarLevel){
    switch (sugarLevel) {
        case 1:
            break;
        case 2: 
            sugar -= 3; 
            break;
        case 3: 
            sugar -= 5; 
            break;
        case 4: 
            sugar-= 7; 
            break;
        case 5: 
            sugar-= 10; 
            break;
    }
}