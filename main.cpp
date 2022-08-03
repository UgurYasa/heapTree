#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 1000

int DIZI[N];

int kontrol(){
    int i=0;
    while(DIZI[i]){
        i++;
    }
    return i;
}

int ust(int a){
    if ((a-1)%2==0)
        return (a-1)/2;

    else if ((a-2)%2==0)
        return (a-2)/2;
}
void append(int eklenecek){
    int a=kontrol();
        DIZI[a]=eklenecek;
        while (a>0){
            int b= ust(a);
            if (DIZI[a]>DIZI[b]) {
                int result = DIZI[a];
                DIZI[a] = DIZI[b];
                DIZI[b] = result;
            }a=b;

    }
}


void heapTreeDuzenle(){
    int a=kontrol();
    int b=0;
    while(b<a){
        int c=2*b+1;
        int d=2*b+2;
        if (DIZI[c]>DIZI[b] && DIZI[d]<DIZI[c] ){
            int result = DIZI[c];
            DIZI[c] = DIZI[b];
            DIZI[b] = result;
            b=c;
        }
        else if (DIZI[d]>DIZI[b] && DIZI[d] > DIZI[c]){
            int result = DIZI[d];
            DIZI[d] = DIZI[b];
            DIZI[b] = result;
            b=d;
        }
        else
            break;

    }
}
int deletee(){
    int b = kontrol();
    b=b-1;
    int temp=DIZI[0];
    DIZI[0]=DIZI[b];
    DIZI[b]=0;
    heapTreeDuzenle();
    return temp;
}
void listele(){
    int i=0;
    printf("/////     ");
    while (DIZI[i])
        printf(" %d -",DIZI[i++]);
    printf("     \\\\\\\\\\");
    printf("\n");
}



int main() {

    append(10);
    listele();
    append(5);
    listele();
    append(12);
    listele();
    append(17);
    listele();
    append(4);
    listele();
    append(20);
    listele();
    append(25);
    listele();
    deletee();
    listele();
    deletee();
    listele();
    deletee();
    listele();
    deletee();
    listele();
    deletee();
    listele();
    deletee();
    listele();



    return 0;
}

