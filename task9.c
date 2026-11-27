#include <stdio.h>
#include "myarrfunc.h"
#define SIZE_STR 20
#define SIZE_STOL 20

int main(void){
    int mat[SIZE_STR][SIZE_STOL]={0};
    int str,stol =0;
    char vib;
    do{
        printf("\n----------------------------\n");
        printf("a   Задать размер массива\n");
        printf("b   Заполнить массив\n");
        printf("c   Представление массива (значение, адреса)\n");
        printf("d   Индексы элементов,которые больше K\n");
        printf("e   Индексы чисел между МАХ и МIН\n");
        printf("f   Сумма чисел если,которые больше К\n");
        printf("g   Выход\n");
        printf("Введите пункт:");
        if (scanf(" %c",&vib)==EOF){
            break;
        }
        switch(vib){
            case 'a':
            case 'A':
                printf("Введите размер ма до %dX%d:",SIZE_STR,SIZE_STOL);
                int res = scanf("%d %d",&str,&stol);
                if (res == EOF){
                    return 0;
                }
                if (res != 2){
                    printf("Введено некоретно\n");
                    int c;
                    while ((c = getchar())!='\n' && c != EOF)
                    break;
                }
                if (str<0 || str> SIZE_STR || stol<0 || stol> SIZE_STOL){
                    printf("НЕВЕРНО ВВЕДЕН РАЗМЕР");
                    str=0;
                    stol=0;
                }
                else{
                    printf("Размер установелен:%dX%d",str,stol);
                }
                break;
            case 'b':
            case 'B':
                if (str==0 || stol ==0){
                    printf("Введи сначало размер");
                    break;
                }
                else{
                    printf("Введи %dX%d элементов: ",str,stol);
                    for (int i = 0; i<str; i++){
                        for (int j=0;j<stol;j++){
                            printf("Элемент:строка[%d]столбец[%d]",i,j);
                            int res = scanf("%d",(mat[0]+i*stol+j));
                            if (res == EOF){
                                return 0;
                            }
                            if (res != 1){
                                printf("Введено некоретно!\n");
                                i--;
                                int c;
                                while ((c = getchar())!='\n' && c != EOF)
                                break;
                            }
                        }
                    }
                }
                break;
            case 'c':
            case 'C':
                if (str==0||stol==0){
                    printf("Массив пустой\n");
                }
                else{
                    printf("Представление массива\n");
                    for (int i=0;i<str;i++){
                        for(int j=0; j<stol;j++){
                            printf("Индекс: [%d,%d] | Значение: %d | Адрес: %p\n",i,j,*(mat[0]+i*stol+j),(mat[0]+i*stol+j));
                        }
                    }
                }
                break;
            case 'd':
            case 'D':
                if (str==0||stol==0){
                     printf("Массив пустой\n");
                }
                else{
                    poisk_index_min(&mat[0][0],str,stol);
                }
                break;
            case 'e':
            case 'E': 
                if (str==0||stol==0){
                     printf("Массив пустой\n");
                }
                else{
                    int k;
                    printf("Введите К:");
                    int prov;
                    prov=scanf("%d",&k);
                    if (prov==EOF){
                        break;
                    }
                    if (prov!=1){
                        int c;
                        printf("Введено некоретно\n");
                        while ((c=getchar())!='\n' && c!=EOF);
                        break;
                    }
                    int res=sum_bol_k(&mat[0][0],str,stol,k);
                    printf("Сумма:%d",res);
                }
                break;
            case 'f':
            case 'F': 
                if (str==0||stol==0){
                     printf("Массив пустой\n");
                }
                else{
                    poisk_index_poslpol(&mat[0][0],str,stol);
                }
                break;
            case 'g':
            case 'G': 
                printf("Exit");
                break;
            default:
                printf("невверная команда!\n");
                int c;
                while ((c = getchar())!='\n');
                break;
        }
    }while (vib != 'g' && vib != 'G');
    return 0;
}