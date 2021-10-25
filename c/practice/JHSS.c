#include<stdio.h>
#include <string.h>

int main () {
    int ch, so, sc;
    int app, ap, a;
    int bpp, bp, b;
    int c;
    int score, point;
    float en, ma;
    scanf("%d%f%f%d%d", &ch, &en, &ma, &so, &sc);
    if (ch >= 45){
        app++;
        score += 6;
        point += 7;
    } else if (ch >=43){
        ap++;
        score += 6;
        point += 6;
    } else if (ch >= 41) {
        a++;
        score += 6;
        point += 5;
    } else if (ch >= 36) {
        bpp++;
        score += 4;
        point += 4;
    } else if (ch >= 31) {
        bp++;
        score += 4;
        point += 3;
    } else if (ch >= 19){
        b++;
        score += 4;
        point += 2;
    } else {
        c++;
        score += 2;
        point += 1;
    }

    if (en >= 98.05){
        app++;
        score += 6;
        point += 7;
    } else if (en >= 95.15){        
        ap++;
        score += 6;
        point += 6;
    } else if (en >= 90.24) {
        a++;
        score += 6;
        point += 5;
    } else if (en >= 81.58) {
        bpp++;
        score += 4;
        point += 4;
    } else if (en >= 69.83) {
        bp++;
        score += 4;
        point += 3;
    } else if (en >= 38.75) {
        b++;
        score += 4;
        point += 2;
    } else {
        c++;
        score += 2;
        point += 1;
    }

    if (ma >= 94.23){
        app++;
        score += 6;
        point += 7;
    } else if (ma >= 90.19){        
        ap++;
        score += 6;
        point += 6;
    } else if (ma >= 81.73) {
        a++;
        score += 6;
        point += 5;
    } else if (ma >= 72.12) {
        bpp++;
        score += 4;
        point += 4;
    } else if (ma >= 63.08) {
        bp++;
        score += 4;
        point += 3;
    } else if (ma >= 40.96) {
        b++;
        score += 4;
        point += 2;
    } else {
        c++;
        score += 2;
        point += 1;
    }

    if (so >= 61){
        app++;
        score += 6;
        point += 7;
    } else if (so >= 59){
        score += 6;
        point += 6;
        ap++;
    } else if (so >= 56) {
        score += 6;
        point += 5;
        a++;
    } else if (so >= 48) {
        score += 4;
        point += 4;
        bpp++;
    } else if (so >= 39) {
        score += 4;
        point += 3;
        bp++;
    } else if (so >= 23) {
        score += 4;
        point += 2;
        b++;
    } else {
        score += 2;
        point += 1;
        c++;
    }

    if (sc >= 52){
        score += 6;
        point += 7;
        app++;
    } else if (sc >= 50){
        score += 6;
        point += 6;
        ap++;
    } else if (sc >= 46) {
        score += 6;
        point += 5;
        a++;
    } else if (sc >= 38) {
        score += 4;
        point += 4;
        bpp++;
    } else if (sc >= 31) {
        score += 4;
        point += 3;
        bp++;
    } else if (sc >= 20) {
        score += 4;
        point += 2;
        b++;
    } else {
        score += 2;
        point += 1;
        c++;
    }
    char str[100000];
    int a_num = (app + ap) + a;
    int b_num = (bpp + bp) + b;
    int c_num = (c);

    if (a_num > 0){
        char tmp[100];
        sprintf(tmp, "%d", a_num);
        strcat(str, tmp);
        strcat(str, "A");
    }
    if (b_num > 0){
        char tmp[100];
        sprintf(tmp, "%d", b_num);
        strcat(str, tmp);
        strcat(str, "B");
    }
    if (c_num > 0){
        char tmp[100];
        sprintf(tmp, "%d", c_num);
        strcat(str, tmp);
        strcat(str, "C");
    }

    printf("%d/%d(%s)", score, point, str);
    return 0;
}