
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>



typedef struct pessoa{
  char nome[20];
  char eventos[200];


}CONGRESSISTA;



typedef struct oficina{
  char professor[20];
  char tema[20];
  int dia;
  int codigo;
  int capacidade;
  int hora;
  int sala;

}OFICINA;


typedef struct palestra{
  char  palestrante[20];
  char tema[20];
  int dia;
  int capacidade;
  int codigo;
  int hora;
  int sala;

}PALESTRA;

typedef struct grupos{

 char  membros [6][20];
  char tema[20];
  int dia;
  int capacidade;
  int codigo;
  int hora;
  int sala;
}GRUPO;

typedef struct curso{

 char  professor[20];
  char tema[20];
  int dia;
  int capacidade;
  int codigo;
  int hora;
  int sala;
}CURSO;

// VARIAVEIS GLOBAIS
PALESTRA palestra;
OFICINA oficina;
CONGRESSISTA congressista;
GRUPO grupo;
CURSO curso;
char separador[50]={"--------------------------------------\n"};
char espaco[]={"\t\t\t\t\t\t\t"};



void HEAD(){
//CABEÇALHO DO PROGRAMA
system("cls");
printf("\t\t\t\t\t ______   _   _    _____   ______    _____ \n\t\t\t\t \t|  ____| | \\ | |  / ____| |  ____|  / ____|\n\t\t \t\t\t| |__    |  \\| | | |      | |__    | |     \n\t\t\t\t \t|  __|   | . ` | | |      |  __|   | |     \n\t\t\t\t \t| |____  | |\\  | | |____  | |____  | |____ \n\t\t\t\t \t|______| |_| \\_|  \\_____| |______|  \\_____|\n\n\n\n");



}





/////////FUNÇÕES DE CRIAÇÃO.
void CriarCongressistas(){

  system("cls");
  HEAD();
 FILE* arquivoCongressista;
  int opcao;
  int codigo;
  int j;
  char continuar;
  char *string;
arquivoCongressista= fopen("arquivoCongressista.txt","ab");

 if (arquivoCongressista == NULL){
  printf("Falha Ao Abrir");
   }
 else{
  fflush(stdin);
  printf("Digite o Nome do Participante: ");
  gets(congressista.nome);

  fflush(stdin);
while(1){
    system("cls");

  printf("Digite os eventos que irá comparecer:\n\n");

  printf("1 -> Participar de uma palestra\n\n");
  printf("2 -> Participar de uma Oficina\n\n");
  printf("3 -> Participar de um Grupo de Discussão\n\n");
  printf("4 -> participar de um Curso\n\n");
  printf("opção: ");

  scanf("%d",&opcao);

  switch(opcao){

    case 1:
      mostrar_Palestras();
    break;
    case 2:
      mostrar_oficina();
      break;
    case 3:
      mostrar_Grupo();
      break;
    case 4:
      mostrar_Curso();
      break;
  }
  printf("DIGITE O CÓDIGO DO EVENTO QUE DESEJA PARTICIPAR: ");
  scanf("%d",&codigo);

  if (codigo>=100&&codigo<200){///////////////////


      FILE* arquivoPalestra;
       j=0;
     codigo= codigo-99;

      arquivoPalestra = fopen("arquivoPalestra.txt","rb");

     {
      while (fread(&palestra,sizeof(PALESTRA),1,arquivoPalestra) == 1){


       j++;
      if (j==codigo){



      strcpy(congressista.eventos,palestra.tema);
        break;

      }



      }

  }

fclose(arquivoPalestra);

  }

 else if (codigo>=200&&codigo<300){
      FILE* arquivoOficina;
       j=0;
      codigo = codigo-199;

      arquivoOficina = fopen("arquivoOficina.txt","rb");

     {
      while (fread(&oficina,sizeof(OFICINA),1,arquivoOficina) == 1){
      j++;
      if (j==codigo){



      strcpy(congressista.eventos, oficina.tema);
        break;
}



      }

  }

fclose(arquivoOficina);


 system("pause");


  }

else if (codigo>=300&&codigo<400){//////////////////////////////
      FILE* arquivoGrupos;
       j=0;
      codigo = codigo-299;

      arquivoGrupos = fopen("arquivoGrupos.txt","rb");

     {
      while (fread(&grupo,sizeof(GRUPO),1,arquivoGrupos) == 1){
     j++;
      if (j==codigo){



        strcpy(congressista.eventos,grupo.tema);
        break;}





      }

  }

fclose(arquivoGrupos);


 system("pause");


  }

else if (codigo>=400&&codigo<500){

   FILE* arquivoCurso;
       j=0;
      codigo = codigo-399;

      arquivoCurso = fopen("arquivoCurso.txt","rb");

     {
      while (fread(&curso,sizeof(CURSO),1,arquivoCurso) == 1){
       j++;
      if (j==codigo){
        break;



      strcpy(congressista.eventos  ,curso.tema);
      }


      }

  }

fclose(arquivoCurso);


 system("pause");

}



    fwrite(&congressista,sizeof(CONGRESSISTA),1,arquivoCongressista);


    fclose(arquivoCongressista);


fflush(stdin);

 system("cls");
  break;
  }
 }

}





void CriarCurso(){
 FILE* arquivoCurso;
  HEAD();
arquivoCurso= fopen("arquivoCurso.txt","ab");

 if (arquivoCurso == NULL){
  printf("Falha Ao Abrir");
   }
 else{
  fflush(stdin);
  printf("Digite o Nome do Professor: ");
  gets(curso.professor);

 fflush(stdin);
    printf("Digite o tema: ");
    gets(curso.tema);


printf("Digite a capacidade máxima do curso (até 20 pessoas) \n");
scanf("%d",&curso.capacidade);

printf("DIGITE EM QUAL DIA A ATIVIDADE SERÁ REALIZADA:\n");
scanf("%d",&curso.dia);

    printf("Digite a Hora do palestra\n");
    scanf("%d",&curso.hora);

    printf("Digite em qual sala vai se passar o curso\n");
    scanf("%d",&curso.sala);

    fwrite(&curso,sizeof(CURSO),1,arquivoCurso);
    centralize(separador);
printf("\n");
centralize("CURSO CADASTRADO COM SUCESSO!\n");
centralize(separador);
Sleep(3000);

    fclose(arquivoCurso);

   }


}










void CriarPalestra(){
  FILE* arquivoPalestra;
  HEAD();
  arquivoPalestra = fopen("arquivoPalestra.txt","ab");

  if (arquivoPalestra==NULL){
      printf("falha ao abrir");
}
else{


    fflush(stdin);
    printf("DIGITE O PALESTRANTE: ");
    gets(palestra.palestrante);

    fflush(stdin);
    printf("DIGITE O TEMA: ");
    gets(palestra.tema);

    printf("INSIRA LOTAÇÃO MÁXIMA(50-150) : \n");
    scanf("%d",&palestra.capacidade);

    printf("DIGITE EM QUAL DIA A ATIVIDADE SERÁ REALIZADA:\n");
    scanf("%d",&palestra.dia);


    printf("DIGITE A HORA DA PALAESTRA APENAS MANHÃ DISPONÍVEL!\n");
    scanf("%d",&palestra.hora);

    printf("DIGITE O NUMERO DO AUDITÓRIO EM QUE VAI SE PASSAR A PALESTRA:\n");
    printf("AUDITÓRIO 1 | AUDITÓRIO 2 | AUDITÓRIO 3\n");
    scanf("%d",&palestra.sala);

    fwrite(&palestra,sizeof(PALESTRA),1,arquivoPalestra);


    fclose(arquivoPalestra);

}

centralize(separador);
printf("\n\n");
centralize("PALESTRA CADASTRADA COM SUCESSO!\n");
centralize(separador);
Sleep(3000);
  return;
}





void CriarGrupos(){
  FILE* arquivoGrupos;
  int i;
  HEAD();
  arquivoGrupos = fopen("arquivoGrupos.txt","ab");

  if (arquivoGrupos==NULL){
      printf("falha ao abrir");
}
else{


    fflush(stdin);
    printf("DIGITE O NOME DOS MEMBROS:\n ");

    for (i=1;i<=5;i++){
      printf("\t\t\tDIGITE O MEMBRO %d: ",i);
       fflush(stdin);
       gets(grupo.membros[i]);
    }

    fflush(stdin);
    printf("Digite o tema: ");
    gets(grupo.tema);

    printf("INSIRA A LOTAÇÃO MÁXIMA(30-50) : \n");
    scanf("%d",&grupo.capacidade);

    printf("DIGITE EM QUAL DIA A ATIVIDADE SERÁ REALIZADA:\n");
    scanf("%d",&grupo.dia);

    printf("DIGITE A HORA DA ATIVIDADE\n");

    scanf("%d",&grupo.hora);

    printf("DIGITE QUAL A SALA 4->SALA 1/ 5->SALA 2 / 6-> SALA 3:");
    scanf("%d",&grupo.sala);

    fwrite(&grupo,sizeof(GRUPO),1,arquivoGrupos);


    fclose(arquivoGrupos);

}
centralize(separador);
printf("\n");
centralize("GRUPO DE DISCUSSÃO CADASTRADA COM SUCESSO!\n");
centralize(separador);
Sleep(3000);
  return;
}




void Criar_Oficina(){

 FILE* arquivoOficina;


  arquivoOficina = fopen("arquivoOficina.txt","ab");

  system("cls");
  HEAD();
  if (arquivoOficina==NULL){
      printf("falha ao abrir");
}
else{

    fflush(stdin);
    printf("DIGITE O NOME DO PROFESSOR QUE IRÁ MANEGAR A OFICINA: ");
    gets(oficina.professor);

    fflush(stdin);
    printf("DIGITE O TEMA:: ");
    gets(oficina.tema);

    printf("INSIRA A QUANTIDADE DE ALUNOS: (até 20):");
    scanf("%d",&oficina.capacidade);

    printf("DIGITE EM QUAL DIA A ATIVIDADE SERÁ REALIZADA:\n");
    scanf("%d",&oficina.dia);


    printf("DIGITE A HORA\n");
    scanf("%d",&oficina.hora);


    printf("INSIRA A SALA DA OFICINA 7->LAB1 / 8->LAB2\n");
    scanf("%d",&oficina.sala);

    fwrite(&oficina,sizeof(OFICINA),1,arquivoOficina);


    fclose(arquivoOficina);

}
centralize(separador);
printf("\n");
centralize("OFICINA CADASTRADA COM SUCESSO!\n");
centralize(separador);
Sleep(3000);
  return;

}

//EXIBIÇÕES


void mostrar_congressistas(){

FILE* arquivoCongressista;
  int i=100;


  HEAD();
  arquivoCongressista = fopen("arquivoCongressista.txt","rb");



  if (arquivoCongressista==NULL){
    printf("falha ao abrir");
  }else{
      while (fread(&congressista,sizeof(CONGRESSISTA),1,arquivoCongressista) == 1){
       printf("%s",separador);
      printf("[%d]",i);
      printf("NOME: %s \n",congressista.nome);
      printf("ATIVIDADES: %s \n ",congressista.eventos);


      i++;
      putchar('\n');
      }

  }

  fclose(arquivoCongressista);
  system("pause");
}




void mostrar_Palestras(){
  FILE* arquivoPalestra;
  int i=100;


  HEAD();
  arquivoPalestra = fopen("arquivoPalestra.txt","rb");



  if (arquivoPalestra==NULL){
    printf("falha ao abrir");
  }else{
      while (fread(&palestra,sizeof(PALESTRA),1,arquivoPalestra) == 1){
       printf("%s",separador);
      printf("[%d]",i);

      printf("  %s\n",palestra.palestrante);

      printf("TEMA: %s\n",palestra.tema);
      printf("CAPACIDADE %d/150\n",palestra.capacidade);
      printf("DIA %d\n",palestra.dia);
      printf("HORA: %d:00\n",palestra.hora);

      sala(palestra.sala);
      printf("%s",separador);
      i++;
      putchar('\n');
      }

  }

  fclose(arquivoPalestra);
  system("pause");
}


//FUNÇÃO A OFICINA


void mostrar_oficina(){
  FILE* arquivoOficina;
  int i=200;


  HEAD();
  arquivoOficina = fopen("arquivoOficina.txt","rb");



  if (arquivoOficina==NULL){
    printf("falha ao abrir");
  }else{
      while (fread(&oficina,sizeof(OFICINA),1,arquivoOficina) == 1){
       printf("%s",separador);
       printf("[%d]",i);
      printf("  %s\n",oficina.professor);
      printf("CAPACIDADE : %d\n",oficina.capacidade);
      printf("TEMA: %s\n",oficina.tema);
      printf("DIA %d\n",oficina.dia);
      printf("HORA: %d:00\n",oficina.hora);
      sala(oficina.sala);
      printf("%s",separador);

      putchar('\n');
      i++;
      }

  }

  fclose(arquivoOficina);
  system("pause");
}



void mostrar_Grupo(){
  FILE* arquivoGrupos;
  int i=300;
  int j;
  system("cls");
  HEAD();
  arquivoGrupos = fopen("arquivoGrupos.txt","rb");



  if (arquivoGrupos==NULL){
    printf("falha ao abrir");
  }else{
      while (fread(&grupo,sizeof(GRUPO),1,arquivoGrupos) == 1){
       printf("%s",separador);

      printf("[%d]\n",i);
      printf("PROFESSORES: ");
      for (j=0;j<=5;j++)
      printf("  %s",grupo.membros[j]);
      putchar('\n');
      printf("CAPACIDADE:%d",grupo.capacidade);

      printf("\nTEMA: %s\n",grupo.tema);
      printf("DIA %d\n",grupo.dia);
      printf("HORA: %d:00\n",grupo.hora);
      sala(grupo.sala);
      printf("%s",separador);
      i++;
      putchar('\n');
      }

  }

  fclose(arquivoGrupos);
  system("pause");
}

void mostrar_Curso(){
  FILE* arquivoCurso;
  int i=400;
  int j;
  system("cls");
  HEAD();
  arquivoCurso = fopen("arquivoCurso.txt","rb");



  if (arquivoCurso==NULL){
    printf("falha ao abrir");
  }else{
      while (fread(&curso,sizeof(CURSO),1,arquivoCurso) == 1){
       printf("%s",separador);
      printf("[%d]\n",i);
      printf("PROFESSORES: ");

      printf("  %s",curso.professor);
      printf("\nTEMA: %s\n",curso.tema);
      printf("DIA %d\n",curso.dia);
      printf("HORA: %d :00\n",curso.hora);
      sala(grupo.sala);
      printf("%s",separador);
      i++;
      putchar('\n');
      }

  }

  fclose(arquivoCurso);
  system("pause");

  }
//MENU QUE MOSTRA OS EVENTOS.



void mostrar_evento(){

int select;
      system("cls");
      HEAD();
      centralize("Qual atividade deseja verificar?\n\n");
      centralize("1 -> Palestra\n");
      centralize("2 -> Oficina\n");
      centralize("3 -> Grupos de Discussão\n");
      centralize("4 -> Cursos\n");
      scanf("%d",&select);

      switch(select){
        case 1:
          mostrar_Palestras();
          break;

        case 2:
          mostrar_oficina();
          break;

        case 3:
          mostrar_Grupo();
          break;

        case 4:
          mostrar_Curso();
          break;

}

return;

}


//PALESTRA
void editarPalestra(){
    PALESTRA palestra;
    char string[20];
    int i;
    FILE *arq=fopen("arquivoPalestra.txt","r+b");
    FILE *arq1=fopen("auxiliar.txt","a+b");

    mostrar_Palestras();
    printf("\n\nDIGITE O TEMA DA PALESTRA QUE IRÁ EDITAR:");
    fflush(stdin);
    gets(string);
    while(fread(&palestra,sizeof(PALESTRA),1,arq)==1){
        if(strcmp(string,palestra.tema)==0){
            printf("\n\n NOVOS DADOS DO PALESTRA ");
            printf("\n\n");
            printf("DIGITE O NOME:");
            fflush(stdin);
            gets(palestra.palestrante);
            printf("\n");
            printf("DIGITE A CAPACIDADE:");
            scanf(" %d",&palestra.capacidade);
            printf("\n");
            printf("DIGITE O TEMA:");
            fflush(stdin);
            gets(palestra.tema);
            printf("\n");
            printf("DIGITE O DIA EM QUE SERÁ REALIZADO(1 OU 2)\n");
            scanf("%d",&palestra.dia);
            printf("DIGITE A HORA:");
            scanf("%d",&palestra.hora);
            printf("\n");

            printf("DIGITE QUAL A SALA:");
            scanf("%d",&palestra.sala);
            printf("\nPALESTRA EDITADO COM SUCESSO!!!\n\n\n");

            system("pause");;
            fwrite(&palestra, sizeof(PALESTRA),1,arq1);
            printf("\n");
            system("cls");

    }
     else
        {

    fwrite(&palestra, sizeof(PALESTRA), 1,  arq1);
        }

        }

fclose(arq1);
fclose(arq);
system("del arquivoPalestra.txt");
system("ren auxiliar.txt arquivoPalestra.txt");
}

//OFICINA
void editarOficina(){
    OFICINA oficina;
    char string[20];
    int i;
    FILE *arq=fopen("arquivoOficina.txt","r+b");
    FILE *arq1=fopen("auxiliar2.txt","a+b");
    HEAD();
    mostrar_oficina();
    printf("\n\nDIGITE O TEMA DA OFICINA QUE IRÁ EDITAR :");
    fflush(stdin);
    gets(string);
    while(fread(&oficina,sizeof(OFICINA),1,arq)==1){
        if(strcmp(string,oficina.tema)==0){
            printf("\n\nNOVOS DADOS DA OFICINA ");
            printf("\n\n");
            printf("DIGITE O NOME:");
            fflush(stdin);
            gets(oficina.professor);
            printf("\n");
            printf("DIGITE A CAPACIDADE:");
            scanf(" %d",&oficina.capacidade);
            printf("\n");
            printf("DIGITE O TEMA:");
            fflush(stdin);
            gets(oficina.tema);
            printf("\n");
            printf("DIGITE O DIA EM QUE SERÁ REALIZADO(1 OU 2)\n");
            scanf("%d",&oficina.dia);
            printf("DIGITE A HORA:");
            scanf("%d",&oficina.hora);
            printf("\n");

            printf("DIGITE QUAL LABORATÓRIO 7-> LAB1 / 8->LAB 2:");
            scanf("%d",&oficina.sala);
            printf("\nOFICINA EDITADA COM SUCESSO!!!\n\n\n");

            system("pause");;
            fwrite(&oficina, sizeof(OFICINA),1,arq1);
            printf("\n");
            system("cls");

    }
     else
        {

    fwrite(&oficina, sizeof(OFICINA), 1,  arq1);
        }

        }

fclose(arq1);
fclose(arq);
system("del arquivoOficina.txt");
system("ren auxiliar2.txt arquivoOficina.txt");
}

//GRUPOS
void editarGrupo(){
    GRUPO grupo;
    char string[20];
    int i;
    FILE *arq=fopen("arquivoGrupos.txt","r+b");
    FILE *arq1=fopen("auxiliar3.txt","a+b");
     HEAD();
    mostrar_Grupo();

    printf("\n\nDIGITE O TEMA DO GRUPO DE DISCUSSÃO:");
    fflush(stdin);
    gets(string);
    while(fread(&grupo,sizeof(GRUPO),1,arq)==1){
        if(strcmp(string,grupo.tema)==0){
            system("pause");
            printf("\n\n INSIRA NOVOS DADOS DO GRUPO DE DISCUSSÃO ");
            printf("\n\n");
           for (i=1;i<=5;i++){
          printf("\nDigite o membro %d:\n",i);
          fflush(stdin);
            gets(grupo.membros[i]);
          }

            printf("\n");
            printf("DIGITE A CAPACIDADE:");
            scanf(" %d",&grupo.capacidade);
            printf("\n");
            printf("DIGITE O TEMA:");
            fflush(stdin);
            gets(grupo.tema);
            printf("\n");
            printf("DIGITE O DIA EM QUE SERÁ REALIZADO(1 OU 2)\n");
            scanf("%d",&grupo.dia);
            printf("DIGITE A HORA:");
            scanf("%d",&grupo.hora);
            printf("\n");

            printf("DIGITE QUAL A SALA 4->SALA 1/ 5->SALA 2 / 6-> SALA 3:");
            scanf("%d",&grupo.sala);
            printf("\nGRUPO EDITADO COM SUCESSO!!!\n\n\n");

            system("pause");;
            fwrite(&grupo, sizeof(GRUPO),1,arq1);
            printf("\n");
            system("cls");

    }
     else
        {

    fwrite(&grupo, sizeof(GRUPO), 1,  arq1);
        }

        }

fclose(arq1);
fclose(arq);
system("del arquivoGrupos.txt");
system("ren auxiliar3.txt arquivoGrupos.txt");
}
//curso
void editarCurso(){
    CURSO curso;
    char string[20];
    int i;
    FILE *arq=fopen("arquivoCurso.txt","r+b");
    FILE *arq1=fopen("auxiliar4.txt","a+b");
    mostrar_Curso();
    HEAD();
    printf("\n\nDIGITE O TEMA DO CURSO:");
    fflush(stdin);
    gets(string);
    while(fread(&curso,sizeof(CURSO),1,arq)==1){
        if(strcmp(string,curso.tema)==0){
            printf("\n\nINSIRA OS DADOS ALTERADOS DO CURSO ");
            printf("\n\n");
            printf("DIGITE O NOME:");
            fflush(stdin);
            gets(curso.professor);
            printf("\n");
            printf("DIGITE A CAPACIDADE:");
            scanf(" %d",&curso.capacidade);
            printf("\n");
            printf("DIGITE O TEMA:");
            fflush(stdin);
            gets(curso.tema);
            printf("\n");
            printf("DIGITE O DIA EM QUE SERÁ REALIZADO(1 OU 2)\n");
            scanf("%d",&curso.dia);
            printf("DIGITE A HORA:");
            scanf("%d",&curso.hora);
            printf("\n");

            printf("DIGITE QUAL A SALA:");
            scanf("%d",&curso.sala);
            printf("\nCURSO EDITADO COM SUCESSO!!!\n\n\n");

            system("pause");;
            fwrite(&curso, sizeof(CURSO),1,arq1);
            printf("\n");
            system("cls");

    }
     else
        {

    fwrite(&curso, sizeof(CURSO), 1,  arq1);
        }

        }

fclose(arq1);
fclose(arq);
system("del arquivoCurso.txt");
system("ren auxiliar4.txt arquivoPalestra.txt");
}
///REMOVEDORES///////////////////
void removerpalestra(){
      char string[20];
      PALESTRA palestra;

    FILE *arq=fopen("arquivoPalestra.txt","r+b");
    FILE *arq1=fopen("auxiliar5.txt","a+b");
    printf("REMOVENDO PALESTRA\n");
    mostrar_Palestras();
    printf("\n\nDIGITE O TEMA DA PALESTRA QUE SERÁ REMOVIDA:");
    fflush(stdin);
    gets(string);
    rewind(arq);
    while(fread(&palestra,sizeof(PALESTRA),1,arq)==1){
        if(strcmp(string,palestra.tema)!=0){
            fwrite(&palestra,sizeof(PALESTRA),1,arq1);
        }
    }
printf("\n\nPALESTRA REMOVIDA COM SUCESSO!!!\n\n\n");

system("pause");
fclose(arq1);
fclose(arq);
system("del arquivoPalestra.txt");
system("ren auxiliar5.txt arquivoPalestra.txt");

}

void removerOficina(){
      char string[20];
      OFICINA oficina;

    FILE *arq=fopen("arquivoOficina.txt","r+b");
    FILE *arq1=fopen("auxiliar6.txt","a+b");
    printf(" REMOVENDO OFICINA n");
    mostrar_oficina();
    printf("\n\nDIGITE O TEMA DA OFICINA QUE SERÁ REMOVIDA:");
    fflush(stdin);
    gets(string);
    rewind(arq);
    while(fread(&oficina,sizeof(OFICINA),1,arq)==1){
        if(strcmp(string,oficina.tema)!=0){
            fwrite(&oficina,sizeof(OFICINA),1,arq1);
        }
    }
printf("\n\nOFICINA REMOVIDA COM SUCESSO!!!\n\n\n");

system("pause");
fclose(arq1);
fclose(arq);
system("del arquivoOficina.txt");
system("ren auxiliar6.txt arquivoOficina.txt");

}
void removerGrupos(){
      char string[20];
      GRUPO grupo;

    FILE *arq=fopen("arquivoGrupos.txt","r+b");
    FILE *arq1=fopen("auxiliar7.txt","a+b");
    printf(" REMOVENDO GRUPOS ");
    mostrar_Grupo();
    printf("\n\nDIGITE O TEMA DO GRUPO DE DISCUSSÃO QUE SERÁ REMOVIDA:");
    fflush(stdin);
    gets(string);
    rewind(arq);
    while(fread(&grupo,sizeof(GRUPO),1,arq)==1){
        if(strcmp(string,grupo.tema)!=0){
            fwrite(&grupo,sizeof(GRUPO),1,arq1);
        }
    }
printf("\n\nGRUPO DE DISCUSSÃO REMOVIDO COM SUCESSO!!!\n\n\n");

system("pause");
fclose(arq1);
fclose(arq);
system("del arquivoGrupos.txt");
system("ren auxiliar7.txt arquivoGrupos.txt");

}
void removerCursos(){
      char string[20];
      CURSO curso;

    FILE *arq=fopen("arquivoCurso.txt","r+b");
    FILE *arq1=fopen("auxiliar8.txt","a+b");
    printf(" REMOVENDO CURSO \n");
    mostrar_Curso();
    printf("\n\nDIGITE O TEMA DO CURSO QUE SERÁ REMOVIDO:");
    fflush(stdin);
    gets(string);
    rewind(arq);
    while(fread(&curso,sizeof(CURSO),1,arq)==1){
        if(strcmp(string,curso.tema)!=0){
            fwrite(&curso,sizeof(CURSO),1,arq1);
        }
    }
printf("\n\nCURSO REMOVIDO COM SUCESSO!!!\n\n\n");

system("pause");
fclose(arq1);
fclose(arq);
system("del arquivoCurso.txt");
system("ren auxiliar8.txt arquivoCurso.txt");

}


void removerCongressista(){
      char string[20];
      CONGRESSISTA congressista;

    FILE *arq=fopen("arquivoCongressista.txt","r+b");
    FILE *arq1=fopen("auxiliar9.txt","a+b");
    printf("REMOVENDO CONGRESSISTA \n");
    mostrar_congressistas();
    printf("\n\nDIGITE O NOME DO CONGRESSSISTA  QUE SERÁ REMOVIDO:");
    fflush(stdin);
    gets(string);
    rewind(arq);
    while(fread(&congressista,sizeof(CONGRESSISTA),1,arq)==1){
        if(strcmp(string,congressista.nome)!=0){
            fwrite(&congressista,sizeof(CONGRESSISTA),1,arq1);
        }
    }
printf("\n\nCONGRESSISTA REMOVIDO COM SUCESSO!!!\n\n\n");

system("pause");
fclose(arq1);
fclose(arq);
system("del arquivoCongressista.txt");
system("ren auxiliar9.txt arquivoCongressista.txt");

}

int contar_congressistas(){

FILE* arquivoCongressista;
  int i=0;


  HEAD();
  arquivoCongressista = fopen("arquivoCongressista.txt","rb");



  if (arquivoCongressista==NULL){
    printf("falha ao abrir");
  }else{
      while (fread(&congressista,sizeof(CONGRESSISTA),1,arquivoCongressista) == 1){
        i++;

      }

  }

  fclose(arquivoCongressista);
  system("pause");
  return i;
}

void menu_Remover(){
int selecao;
system("cls");
centralize("QUAL ATIVIDADE DESEJA REMOVER?");
putchar('\n');
centralize("1 -> PALESTRAS");
putchar('\n');
centralize("2 -> OFICINAS");
putchar('\n');
centralize("3 -> GRUPOS DE DISCUSSÃO");
putchar('\n');
centralize("4 -> CURSOS");
putchar('\n');
printf("OPÇÃO:");
scanf("%d",&selecao);
switch(selecao){
case 1:
  removerpalestra();
  break;
case 2:
  removerOficina();
  break;
case 3:
  removerGrupos();
  break;
case 4:
  removerCursos();
  break;


}

}


void menu_eventos(){

  int selecao;
  system("cls");

  centralize("Selecione a atividade\n\n");

  centralize("1 -> Palestras\n");
  centralize("2 -> Grupos de Discussão\n");
  centralize("3 -> Oficinas\n");
  centralize("4 -> Cursos\n");

  scanf("%d",&selecao);

  switch(selecao){

  case 1:
    CriarPalestra();


    break;


  case 2:
    CriarGrupos();
    break;



  case 3:
    Criar_Oficina();

    break;

  case 4:
    CriarCurso();

    break;


  }

}


void menu_edicao(){

system("cls");
int selection;
printf("O QUE VOCÊ DESEJA ALTERAR NO PROGRAMA:\n");

printf("1 -> alterar Palestras\n");
printf("2 -> alterar Oficinas\n");
printf("3 -> alterar Grupos de Discussão\n");
printf("4 -> alterar Cursos \n");
scanf("%d",&selection);
switch(selection){
  case 1:
    editarPalestra();
    break;
  case 2:
    editarOficina();
    break;
  case 3:
    editarGrupo();
    break;
  case 4:
    editarCurso();
    break;
  default:
    printf("OPÇÃOO NÃO VÁLIDA.\n");
}


}

void menuCongressista(){
  int selecao;
  system("cls");
  printf("SELECIONE SUA AÇÃO:\n");
  printf("1 -> CADASTRAR CONGRESSISTA\n");
  printf("2 -> LISTAR CONGRESSISTA\n" );
  printf("3 -> REMOVER CONGRESSISTA\n");
  printf("OPÇÃO: ");
  scanf("%d",&selecao);
  switch(selecao){

case 1:
  if (contar_congressistas()>300){ //NAO DEIXA O EVENTO PASSAR DO LIMITE DE LOTAÇÃO
    printf("EVENTO LOTADO,LAMENTAMOS!\n");
    system("pause");
  }
  else
  CriarCongressistas();
  break;

case 2:
  mostrar_congressistas();
  break;
case 3:
  removerCongressista();
  break;
  }
}




void load(){//CARREGAMENTO DO PROGRAMA
centralize("Bem vindo ao programa\n\n");
int i;

centralize("CARREGANDO...\n\n");
printf("       \t\t\t\t\t\t");
for (i=0;i<3;i++){
 Sleep(1000);
  printf("%c",176);

}
for (i=0;i<3;i++){
  Sleep(1000);
  printf("%c",177);

}
for (i=0;i<3;i++){
  Sleep(1000);
  printf("%c",178);

}
for (i=0;i<3;i++){
  Sleep(1000);
  printf("%c",219);

}
Sleep(2000);

}


void sala(int num){

switch(num){
system("cls");
HEAD();
case 1:
  printf("AUDITÓRIO 1\n");
  break;
case 2:
  printf("AUDITORIO 2\n");
  break;
case 3:
  printf("AUDITÓRIO 3\n");
  break;
  case 4:
  printf("SALA 1\n");
  break;
  case 5:
  printf("SALA 2\n");
  break;
  case 6:
  printf("SALA 3\n");
  break;
  case 7:
  printf("LABORATORIO 1\n");
  break;
  case 8:
  printf("LABORATORIO 2\n");
  break;
}



}


void centralize (char string[30]){//FUNÇÃO QUE PERMITE QUE EU IMPRIMA COISAS NO MEIO DA TELA, SEM NECESSIDADE DE USAR GOTO
  int a,b,i;

  a=strlen(string);
  b = (120-a)/2;

  for(i=0;i<b;i++){
    printf(" ");
  }



    printf("%s",string);
  }









int main(void){
int p;
load();
system("Color 1F");
setlocale(LC_ALL,"portuguese");
system("mode con:cols=120 lines=30");


  int selecao;



  while(1){

system("cls");



HEAD();


centralize("-----------------------------------------------------------------");

    centralize("\n\n\n\n\n\n\t\t\t\t\t\tESCOLHA A OPÇÃO ABAIXO: \n\n");

    printf("\t\t\t\t1 para CONGRESSISTAS\t");


    printf("\t 2 PARA CADASTRAR ATIVIDADES.\n\n");
    printf("\t\t\t\t3 PARA VER ATIVIDADES\t\t ");
    printf("4 PARA EDITAR\n\n");
    printf("\t\t\t\t5 PARA REMOÇÃO\n\n");
    centralize(" 6 PARA SAIR\n\n\n");

centralize("-----------------------------------------------------------------\n");


    scanf("%d",&selecao);


    if (selecao==1){
     menuCongressista();
      }


    if(selecao==2){
      menu_eventos();

    }



    if (selecao==3){
       mostrar_evento();

      }


    if (selecao==4){
    menu_edicao();
    }

    if (selecao==5){
      menu_Remover();
    }

    if (selecao==6){
      printf("Obrigado por usar o programa!\n");

      break;


        }

  }


return 0;

}

