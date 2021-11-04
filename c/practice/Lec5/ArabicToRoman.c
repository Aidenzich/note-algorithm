
#include <stdio.h>
// #include <math.h>
#include <string.h>
int main(void){
    int input, thousand, hundred, ten, digits;
    char Roman[10000];
    scanf("%d", &input);
    while (input > 0) {
        if (input >= 1000){
            char tmp[10] = 'M';
            input -= 1000;
            strcat(Roman, tmp);

        } else if (input >= 900){
            char tmp[10] = 'CM';
            input -= 900;
            strcat(Roman, tmp);

        } else if (input >= 500){
            char tmp[10] = "D";
            input -= 500;
            strcat(Roman, tmp);

        } else if (input >= 400){
            char tmp[10] = "CD";
            input -= 400;
            strcat(Roman, tmp);

        } else if (input >= 100){
            char tmp[10] = "C";
            input -= 100;
            strcat(Roman, tmp);

        } else if (input >= 90){
            char tmp[10] = "XC";
            input -= 90;
            strcat(Roman, tmp);

        } else if (input >= 50){
            char tmp[10] = "L";
            input -= 50;
            strcat(Roman, tmp);

        } else if (input >= 40){
            char tmp[10] = "XL";
            input -= 40;
            strcat(Roman, tmp);

        } else if (input >= 10){
            char tmp[10] = "X";
            input -= 10;
            strcat(Roman, tmp);

        } else if (input >= 9){
            char tmp[10] = "IX";
            input -= 9;
            strcat(Roman, tmp);

        } else if (input >= 5){
            char tmp[10] = "V";
            input -= 5;
            strcat(Roman, tmp);

        } else if (input >= 4){
            char tmp[10] = "IV";
            input -= 4;
            strcat(Roman, tmp);

        } else if (input >= 1){
            char tmp[10] = "I";
            input -= 1;
            strcat(Roman, tmp);
        }
    }
    printf("%s", Roman);
    return 0;
}