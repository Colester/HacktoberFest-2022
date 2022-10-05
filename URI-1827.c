//1827 - Matriz Quadrada IV
#include <stdio.h>

int main()
{
    int num, i, j, k=0;
    while (scanf("%d",&num) != EOF){
    int M[num][num];

    for(i=0; i<num; i++){

        for(j=0; j<num; j++){



            M[i][j] = 0;
            M[(num-1)/2][(num-1)/2] = 4;

            if(i == j){
            M[i][j] = 2;
            }

            if(i + j == num-1){
            M[i][j] = 3;}


        }

    }

    for(i = num/3; i < num-(num/3); i++)
			for(j = num/3; j < num-(num/3); j++){
				 M[i][j] = 1;

			}
    M[(num-1)/2][(num-1)/2] = 4;



    for(i=0; i<num; i++){
        for(j=0; j<num; j++){
            printf("%d",M[i][j]);
        }
    printf("\n");
    }

printf("\n");


}
return 0;
}
