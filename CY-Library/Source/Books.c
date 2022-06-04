#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Library.h"
char vide[2]="aa";


int addB(int nbrl,Book Books[0]){
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
        printf("En quelle année est sortie le livre ? :\n");
        dat = scan(-2023,2023);
        printf("Quelle style de livre:\n\n1) Policier\n2) Romantique\n3) Poeme\n4) Fantastique\n5) Historique\n6) Educatif\n7) Scientifique\n8) Bande dessinee\n9) Erotique\n10) Thriller\n11) Science Fiction\n12) autobiographique\n\n");
        style = scan(1,12);
        FILE *boo = fopen("./Data/Books.txt","r+");
        if(boo == NULL){boo = fopen("./Data/Books-save.txt","r+");}
        fseek(boo,0,SEEK_END);
        fputc('\n',boo);
        fprintf(boo,"%s %s %d %d",title,auth,dat,style);
        printf("livre crée!\n");
        rewind(boo);
        fclose(boo);
        return takeInf(Books);
    } 
    
}





void swapC(int a,int b,Book Books[0]){
    char temp[30];
    

    strcpy(&temp[0] , &Books[a].name[0]);

    strcpy(&Books[a].name[0] , &Books[b].name[0]);
    
    strcpy(&Books[b].name[0] , &temp[0]);
    

    strcpy(&temp[0] , &Books[a].author[0]);
    
    strcpy(&Books[a].author[0] ,&Books[b].author[0]);
    
    strcpy(&Books[b].author[0] , &temp[0]);
    

    int temp2 = Books[a].date ;
    Books[a].date = Books[b].date;
    Books[b].date = temp2 ;

    temp2 = Books[a].type ;
    Books[a].type = Books[b].type;
    Books[b].type = temp2 ;
    
}
int takeInf(Book Books[0]){

    FILE *boo = fopen("./Data/Books.txt","r");
    if(boo == NULL){boo = fopen("./Data/Books-save.txt","r");}
    int nbrl =nbrL(boo);
    for(int i=0;i<nbrl;i++){
        fscanf(boo,"%s %s %d %d",Books[i].name,Books[i].author,&Books[i].date,&Books[i].type);
    }
    fclose(boo);
    return nbrl;
    
}


int showName(int nbrl,int ted,int type,char*l,Book Books[0] ){
    int cont = 0;
    printf("\n\n");
    if(ted==3000){

        for(int k=0;k<nbrl;k++){

            cont=1;
            printf("    %d) ",k+1);
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

        else if(ted==4000){

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

    if(cont==0){
        printf("0 resultat trouve!\n");
        return -1;    
    }
}


void TriALpha(int end,int ted,Book Books[0]){

    
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
        swapC(tri,i,Books);

    }
}


void TriDate(int nbrl,Book Books[0]){

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
        swapC(tri,i,Books);
    }
    showName(nbrl,4000,0,vide,Books);
}


void SearchD(int nbrl,Book Books[0]){

    TriALpha(nbrl,1,Books);
    printf("Choissisez la date:\n");
    showName(nbrl,scan(-10000,2023),0,vide,Books);
}


int supB(int nbrl,Book Books[0]){
    int test=1;

    rename("./Data/Books.txt","./Data/Books-save.txt");
    remove("./Data/Books.txt");

    printf("Choissisez le livre a suprimmer:\n");
    showName(nbrl,3000,0,vide,Books);
    
    int num =scan(1,nbrl)-1;

    FILE *boo = fopen("./Data/Books.txt","a");
    for(int j=0;j<nbrl;j++){
        if(j!=num){
            if(test){

                fprintf(boo,"%s %s %d %d",Books[j].name,Books[j].author,Books[j].date,Books[j].type);
            }
            else{
                fprintf(boo,"\n%s %s %d %d",Books[j].name,Books[j].author,Books[j].date,Books[j].type);
            }
            test=0;
            
        }

    }

    remove("./Data/Books-save.txt");
    fclose(boo);
    return takeInf(Books);
}

void SearchT(int nbrl,Book Books[0]){

    printf("Quelle style de livre:\n\n1) Policier\n2) Romantique\n3) Poeme\n4) Fantastique\n5) Historique\n6) Educatif\n7) Scientifique\n8) Bande dessinee\n9) Erotique\n10) Thriller\n11) Science Fiction\n12) autobiographique\n\n");
    int choice =scan(1,12);
    TriALpha(nbrl,1,Books);
    showName(nbrl,5000,choice,vide,Books);
}


int SearchN(int nbrl,Book Books[0]){
    
    char title[30];
    printf("Titre:\n");
    scanf("%s",title);
    return showName(nbrl,6000,0,title,Books);
}


void SearchA(int nbrl,Book Books[0]){

    char auth[30];
    TriALpha(nbrl,1,Books);
    printf("Auteur:\n");
    scanf("%s",auth);
    showName(nbrl,7000,0,auth,Books);
}


