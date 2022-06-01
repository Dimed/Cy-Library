#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Library.h"
int YorN();
int nbrL(FILE *file);
int chainDif(char *l,char*g);
char vide[2]="aa";

typedef struct 
{
    char name[30];
    char author [30];
    int type ;
    int date ;
} Book;

Book Books[1000];




int addB(int nbrl){
    char title[30];
    char auth[30];
    int dat;
    int style;
    int answer=1;
    while(answer){
        answer = 2;
        printf("titre (- a la place des espaces):\n");
        scanf("%s",title);
        for (int i=0;i<nbrl;i++){
            if (chainDif(title,Books[i].name)){
                printf("Titre deja utilise, voulez vous reesayer ?(oui/non)\n");
                answer =YorN();
                
            }
        }
        if(answer==2){break;}
    }
    if (answer!=0){
        printf("auteur:\n");
        scanf("%s",auth);
        printf("En quelle anée est sortie le livre ? :\n");
        dat = scan(0,2023);
        printf("Quelle style de livre:\n\n1) Policier\n2) Romantique\n3) Poeme\n4) Fantastique\n5) Historique\n6) Documentaire\n7) Scientifique\n8) Bande dessinee\n9) Erotique\n10) Thriller\n11) Science Fiction\n12) autobiographique\n\n");
        style = scan(1,12);
        FILE *boo = fopen("./Data/Books.txt","r+");
        if(boo == NULL){boo = fopen("./Data/Books-save.txt","r+");}
        fseek(boo,0,SEEK_END);
        fputc('\n',boo);
        fprintf(boo,"%s %s %d %d",title,auth,dat,style);
        printf("livre crée!\n");
        rewind(boo);
        fclose(boo);
        return takeInf();
    } 
    
}





void swapC(int a,int b){
    char temp[30];
    for(int i =0;i<30;i++){
        strcpy(&temp[i] , &Books[a].name[i]);
    }
    for(int j =0;j<30;j++){
        strcpy(&Books[a].name[j] , &Books[b].name[j]);
    }
    for(int k =0;k<30;k++){
        strcpy(&Books[b].name[k] , &temp[k]);
    }

    for(int l =0;l<30;l++){
        strcpy(&temp[l] , &Books[a].author[l]);
    }
    for(int m =0;m<30;m++){
        strcpy(&Books[a].author[m] ,&Books[b].author[m]);
    }
    for(int n =0;n<30;n++){
        strcpy(&Books[b].author[n] , &temp[n]);
    }

    int temp2 = Books[a].date ;
    Books[a].date = Books[b].date;
    Books[b].date = temp2 ;

    temp2 = Books[a].type ;
    Books[a].type = Books[b].type;
    Books[b].type = temp2 ;
    
}
int takeInf(){

    FILE *boo = fopen("./Data/Books.txt","r");
    if(boo == NULL){boo = fopen("./Data/Books-save.txt","r");}
    int nbrl =nbrL(boo);
    for(int i=0;i<nbrl;i++){
        fscanf(boo,"%s %s %d %d",Books[i].name,Books[i].author,&Books[i].date,&Books[i].type);
    }
    fclose(boo);
    return nbrl;
    
}


int showName(int nbrl,int ted,int type,char*l ){
    int cont = 0;
    printf("\n\n");

        if(ted==4000){

            for(int k=0;k<nbrl;k++){

                cont=1;
                printf("    - ");
                for(int i=0;i<30;i++){
                    if(Books[k].name[i]=='\0'){printf(" || ");break;}
                    else if(Books[k].name[i]=='-'){printf(" ");}
                    else{printf("%c",Books[k].name[i]);}
                }
                for(int j=0;j<30;j++){
                    if(Books[k].author[j]=='\0'){printf(" || ");break;}
                    else if(Books[k].author[j]=='-'){printf(" ");}
                    else{printf("%c",Books[k].author[j]);}
                }
                printf("%d\n\n",Books[k].date);
            }
        }   
        else if(ted==5000){

            for(int k=0;k<nbrl;k++){
            
                if(Books[k].type==type){

                    cont=1;
                    printf("    - ");
                    for(int i=0;i<30;i++){
                        if(Books[k].name[i]=='\0'){printf(" || ");break;}
                        else if(Books[k].name[i]=='-'){printf(" ");}
                        else{printf("%c",Books[k].name[i]);}
                    }
                    for(int j=0;j<30;j++){
                        if(Books[k].author[j]=='\0'){printf(" || ");break;}
                        else if(Books[k].author[j]=='-'){printf(" ");}
                        else{printf("%c",Books[k].author[j]);}
                    }
                    printf("%d\n\n",Books[k].date);
                }
            }
        }
        else if(ted==6000){

            for(int k=0;k<nbrl;k++){
            
                if(chainDif(Books[k].name,l)){

                    cont=1;
                    printf("    - ");
                    for(int i=0;i<30;i++){
                        if(Books[k].name[i]=='\0'){printf(" || ");break;}
                        else if(Books[k].name[i]=='-'){printf(" ");}
                        else{printf("%c",Books[k].name[i]);}
                    }
                    for(int j=0;j<30;j++){
                        if(Books[k].author[j]=='\0'){printf(" || ");break;}
                        else if(Books[k].author[j]=='-'){printf(" ");}
                        else{printf("%c",Books[k].author[j]);}
                    }
                    printf("%d\n\n",Books[k].date);
                    return k;
                }
            }
        }
        else if(ted==7000){

            for(int k=0;k<nbrl;k++){
            
                if(chainDif(Books[k].author,l)){

                    cont=1;
                    printf("    - ");
                    for(int i=0;i<30;i++){
                        if(Books[k].name[i]=='\0'){printf(" || ");break;}
                        else if(Books[k].name[i]=='-'){printf(" ");}
                        else{printf("%c",Books[k].name[i]);}
                    }
                    for(int j=0;j<30;j++){
                        if(Books[k].author[j]=='\0'){printf(" || ");break;}
                        else if(Books[k].author[j]=='-'){printf(" ");}
                        else{printf("%c",Books[k].author[j]);}
                    }
                    printf("%d\n\n",Books[k].date);
                }
            }
        }
          
        else if(ted<2500){
            
            for(int k=0;k<nbrl;k++){

                if(Books[k].date==ted){

                    cont=1;
                    printf("    - ");
                    for(int i=0;i<30;i++){
                        if(Books[k].name[i]=='\0'){printf(" || ");break;}
                        else if(Books[k].name[i]=='-'){printf(" ");}
                        else{printf("%c",Books[k].name[i]);}
                    }
                    for(int j=0;j<30;j++){
                        if(Books[k].author[j]=='\0'){printf(" || ");break;}
                        else if(Books[k].author[j]=='-'){printf(" ");}
                        else{printf("%c",Books[k].author[j]);}
                    }
                    printf("%d\n\n",Books[k].date);
                }
            }
        }

    if(cont==0){printf("0 resultat trouve!\n");}
}


void TriALpha(int end,int ted){

    
    for(int i=0;i<end;i++){
        int tri = i ;
        if(ted){
            for(int j=1+i;j<end;j++){
                if(strcmp(Books[tri].name,Books[j].name)>0){
                    tri = j;
                }
            }
        }
        else{

            for(int j=1+i;j<end;j++){
                if(strcmp(Books[tri].author,Books[j].author)>0){
                    tri = j;
                }
            }
        }
        swapC(tri,i);

    }
}


void TriDate(int nbrl){

    printf("Un tri :\n\n1) Croissant\n2) Décroissant\n");
    int answer = scan(1,2);

    for(int i=0;i<nbrl;i++){
        int tri = i;

        if(answer == 1){
    
            for(int j=1+i;j<nbrl;j++){
                if(Books[tri].date>Books[j].date){
                    tri = j;
                }
            }
        }
        else{

            for(int j=1+i;j<nbrl;j++){
                if(Books[tri].date<Books[j].date){
                    tri = j;
                }
            }   
        }  
        swapC(tri,i);
    }
    showName(nbrl,4000,0,vide);
}


void SearchD(int nbrl){

    TriALpha(nbrl,1);
    printf("Choissisez la date:\n");
    showName(nbrl,scan(-10000,2023),0,vide);
}


int supB(int nbrl){

    rename("./Data/Books.txt","./Data/Books-save.txt");
    remove("./Data/Books.txt");

    printf("Choissisez le livre a suprimmer:\n");
    for(int k=0;k<nbrl;k++){

        showName(k,4000,0,vide);
    }
    int num =scan(1,nbrl)-1;

    FILE *boo = fopen("./Data/Books.txt","a");
    for(int j=0;j<nbrl;j++){
        if(j!=num){
            if(j==nbrl-1){
                fprintf(boo,"%s %s %d %d",Books[j].name,Books[j].author,Books[j].date,Books[j].type);
            }
            else{
                fprintf(boo,"%s %s %d %d\n",Books[j].name,Books[j].author,Books[j].date,Books[j].type);
            }
        }

    }

    remove("./Data/Books-save.txt");
    fclose(boo);
    return takeInf();
}

void SearchT(int nbrl){

    printf("Quelle style de livre:\n\n1) Policier\n2) Romantique\n3) Poeme\n4) Fantastique\n5) Historique\n6) Documentaire\n7) Scientifique\n8) Bande dessinee\n9) Erotique\n10) Thriller\n11) Science Fiction\n12) autobiographique\n\n");
    int choice =scan(1,12);
    TriALpha(nbrl,1);
    showName(nbrl,5000,choice,vide);
}


int SearchN(int nbrl){
    
    char title[30];
    printf("Titre:\n");
    scanf("%s",title);
    return showName(nbrl,6000,0,title);
}


void SearchA(int nbrl){

    char auth[30];
    printf("Auteur:\n");
    scanf("%s",auth);
    showName(nbrl,7000,0,auth);
}


