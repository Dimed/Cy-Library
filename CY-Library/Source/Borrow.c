#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Library.h"


int idAccount [1000];
int idBook [1000];
time_t timeLeft [1000];

/*
-si temps max depasé, peut plus emprunté
*/

int takeIn(){

    FILE *bor = fopen("./Data/Borrow.txt","r");
    if(bor == NULL){bor = fopen("./Data/Borrow-save.txt","r");}
    int nbrl =nbrL(bor);
    for(int i=0;i<nbrl;i++){
        fscanf(bor,"%d %d %ld",&idAccount[i],&idBook[i],&timeLeft[i]);
    }
    fclose(bor);
    return nbrl;
}

int checkT(int nbrl,int id,int prec){


    if (prec ==-1){
        for(int i=0;i<nbrl;i++){

            if(idAccount[i]==id && time(NULL)>timeLeft[id]){
    
                return 1;
            }
        }
        return 0;
    }
    else{

        if(time(NULL)>timeLeft[prec]){
    
            return 1;
        }
        return 0;
    }

}

int takeB(int nbrl,int nbrl2,int id,Book Books[0],int type){
    
    int take =0;
    int answer = 1;
    while(1){
        printf("Ecrivez le nom du livre que vous voulez emprunte\n");
        int idB = SearchN( nbrl2, Books);
        if(idB ==-1){
            printf("Aucun livre a ce nom, voulez vous emprunter un autre livre?\n");
            answer = YorN();
            if(answer==0){break;}
        }
        else{
            printf("Est-ce le livre que vous voulez emprunte (oui/non)?\n");
            answer = YorN();
            if (answer){
            
                answer=2;
            }

            if (answer==0){
                printf("Voulez vous emprunte un autre livre (oui/non)? \n");
                answer = YorN();
                if (answer==0){
                    break;
                }
            }
            else if (answer==2){

                if(checkT(nbrl,id,-1)){
                    printf("Veuillez rendre vos livre dont le temps est dépasse avant d'emprunte un autre livre");
                    return nbrl;
                }

                for(int i =0;i<nbrl;i++){
                
                    if(idB == idBook[i]){

                        printf("Livre deja emprunte,voulez vous emprunte un autre livre (oui/non)?\n");
                        answer = YorN();
                        break;
                    }
                    else if (id==idAccount[i]){
                        take++;
                        if((type == 0 && take>=3) || (type == 1 && take>=5)){
                                printf("Trop de livre déja emprunté,veuillez en rendre pour en emprunter d'autre\n");
                            return nbrl;
                        }
                    }
                }
                if(answer==0){break;}
                if (answer==2){
                    
                    FILE *bor = fopen("./Data/Borrow.txt","r+");
                    if(bor == NULL){bor = fopen("./Data/Borrow-save.txt","r+");}
                    fseek(bor,0,SEEK_END);
                    fputc('\n',bor);
                    if(type ==0){
                        fprintf(bor,"%d %d %ld",id,idB,time(NULL)+2*60);
                    }
                    else{
                        fprintf(bor,"%d %d %ld",id,idB,time(NULL)+3*60);
                    }         
                    printf("livre emprunte!\n");
                    rewind(bor);
                    fclose(bor);
                    return takeIn();
                }
            }
        }
    }
}

int backB (int nbrl,int id,Book Books[0]){


    int list[5];
    int c=0;
    for(int i=0;i<nbrl;i++){

        if(idAccount[i]==id){

            list[c]= i;
        
            printf("    %d) ",c+1);
            for(int k=0;k<30;k++){
                if(Books[idBook[i]].name[k]=='\0'){printf(" || ");break;}
                else if(Books[idBook[i]].name[k]=='-'){printf(" ");}
                else{printf("%c",Books[idBook[i]].name[k]);}
            }
            for(int m=0;m<30;m++){
                if(Books[idBook[i]].author[m]=='\0'){printf(" || ");break;}
                else if(Books[idBook[i]].author[m]=='-'){printf(" ");}
                else{printf("%c",Books[idBook[i]].author[m]);}
            }
            printf("%d\n\n",Books[idBook[i]].date);     
            c++;
        }
    }
    if(c==0){
        printf("Aucun livre emprunté!\n");
        return nbrl;
    }
    else{

        int test=1;

        rename("./Data/Borrow.txt","./Data/Borrow-save.txt");
        remove("./Data/Borrow.txt");

        printf("Quelle livre voulez vous rendre?\n");
        int num =scan(1,c)-1;

        FILE *bor = fopen("./Data/Borrow.txt","a");

        for(int j=0;j<nbrl;j++){
            if(j!=list[num]){
                if(test){

                    fprintf(bor,"%d %d %ld",idAccount[j],idBook[j],timeLeft[j]);
                }
                else{
                    fprintf(bor,"\n%d %d %ld",idAccount[j],idBook[j],timeLeft[j]);
                }
                test=0;
                
            }
        }

    remove("./Data/Borrow-save.txt");
    fclose(bor);
    printf("Livre rendu!\n");
    return takeIn();
    }
}


 
void showB(int nbrl,int id,Book Books[0]){

    time_t tleft;
    struct tm *local; 
    printf("Voici vos livres empruntee :\n\n");
    for(int i=0;i<nbrl;i++){

        if(idAccount[i]==id){

            idBook[i]= idBook[i];
        
            printf("    - ");
            for(int k=0;k<30;k++){
                if(Books[idBook[i]].name[k]=='\0'){printf(" || ");break;}
                else if(Books[idBook[i]].name[k]=='-'){printf(" ");}
                else{printf("%c",Books[idBook[i]].name[k]);}
            }
            for(int m=0;m<30;m++){
                if(Books[idBook[i]].author[m]=='\0'){printf(" || ");break;}
                else if(Books[idBook[i]].author[m]=='-'){printf(" ");}
                else{printf("%c",Books[idBook[i]].author[m]);}
            }
            printf("%d || ",Books[idBook[i]].date);
            local = localtime(&timeLeft[i]);    
            printf("a rendre le %d/%d à %dh%d et %ds\n",local->tm_mday,local->tm_mon + 1,local->tm_hour,local->tm_min,local->tm_sec);
            if(checkT(nbrl,id,i)) {
                printf("            --> ATTENTION, RETARD SUR LE RENDU. TANT QUE LE LIVRE NE SERA PAS RENDU EMPRUNTER SERA IMPOSSIBLE!!!\n\n");
            }
            else{
                printf("\n");
            }
        }
    }
}