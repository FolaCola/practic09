#include "myarrfunc.h"
#include <stdio.h>

void poisk_index_min(int *mat,int str,int stol){
    if (stol<=0 || str<=0){
        printf("Неправильный формат!");
        return;
    }
    int otv=*(mat+0);
    int minstr=0;
    int minstol=0;
    for (int i=0; i<str; i++){
        for (int j=0;j<stol;j++){
            int tek=*(mat + (i*stol + j));  
            if (tek<otv){
                otv=tek;
                minstol=j;
                minstr=i;
            }
        }
    }
    printf("Мин.элемент:%d (Строка:%d)(Столб:%d).",otv,minstr,minstol);
}

int sum_bol_k(int *mat, int str,int stol, int k){
    int sum=0;
    for(int i=0;i<str;i++){
        for(int j=0; j<stol; j++){    //         0 0, 0,1 0,2 1,0 1.1 1.2 2.0 2.1 2.2 
            int otv=*(mat+(i*stol+j));//       1 2 3    
            if (otv>k){              //        4 5 6
                sum+=otv;            //        7 8 9    0*3+0=0
            }
        }
    }
    return sum;
}

void poisk_index_poslpol(int *mat, int str,int stol){
    if( str<0 || str<0 ){
        printf("Неверный формат!\n");
        return;
    }
    int strposl=-1;
    int stolposl=-1;
    int otv=0;

    for (int i=0; i<str;i++){
        for(int j=0;j<stol;j++){
            int tek=*(mat+(i*stol+j));
            if (tek>=0){
                otv = tek;
                strposl=i;
                stolposl=j;
            }
        }
    }
    if (strposl != 1){
        printf("Послдедние положительное:%d.Индексы:(Строка:%d),(Столбец:%d)\n",otv1 , strposl,stolposl);
    }
    else{
        printf("Нету положительных!\n");
    }
}