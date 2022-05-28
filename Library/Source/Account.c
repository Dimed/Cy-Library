#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



char name [1000][15];
char pw [1000][15];
int type [1000];

int YorN(){

    char ans[4];
    while(1){
        scanf("%s",ans);

        if(ans[0]=='o' && ans[1]=='u' && ans[2]=='i'&& ans[3]=='\0'){
            return 1;
        }

        else if(ans[0]=='n' && ans[1]=='o' && ans[2]=='n' && ans[3]=='\0'){
            return 0;
        }

        printf("\nVeuillez repondre oui ou non :\n\n");
    }

}

int scan(int min,int max){

    int ask;

    while(1){
        if (scanf("%d",&ask)==0){
            printf("\nEcrivez un chiffre :\n\n");
        }
        else if(ask<min || ask>max){
            printf("\nEcrivez un chiffre entre %d et %d:\n\n",min,max);

        }
        else{
            return ask;
        }
        scanf("%*[^\n]%*1[\n]");
    }
}


// Source of this function : https://gist.github.com/touatily/3af14ed032c407fd3e2bb2dbe3bdc154

void vigenereEnc(const char * text, const char * key, char * ciphertext){
    unsigned int i, size = strlen(key);

    for(i = 0; text[i] != '\0'; i++){
        if( (text[i] >= 'a') && (text[i] <= 'z') ){
            int rang = (text[i] + key[i % size] - 2 * 'a') % 26;
            ciphertext[i] = 'a' + rang;
        }
        else if( (text[i] >= 'A') && (text[i] <= 'Z') ){
            int rang = (text[i] + key[i % size] - 'a' - 'A') % 26;
            ciphertext[i] = 'A' + rang;
        }
        else
            ciphertext[i] = text[i];
    }
    ciphertext[i] = '\0';
}

int nbrL(FILE *file){

    int i =0;
    char element;

    while ((element=getc(file))!=EOF){
		if (element=='\n'){
            i++;
        }
	}
    rewind(file);
    return i+1;
}

int chainDif(char *l,char*g){

    int i=0;
    while(1){
        if(*(l+i)=='\0' && *(g+i)=='\0'){
            return 1;
        }
        else if(*(g+i)!=*(l+i)){

            return 0;
        }
        i++;
    }
    
}

int takeInfo(){

    FILE *acc = fopen("./Data/Account.txt","r");
    if(acc == NULL){acc = fopen("./Data/Account-save.txt","r");}
    int nbrl =nbrL(acc);
    for(int i=0;i<nbrl;i++){
        fscanf(acc,"%s %s %d",name[i],pw[i],&type[i]);
    }
    fclose(acc);
    return nbrl;
}




int create(int nbrl){
    char username[15];
    char mdp[15];
    char mdp2[15];
    int typ;
    int answer=1;
    while(answer){
        answer = 2;
        printf("Pseudo:\n");
        scanf("%s",username);
        for (int i=0;i<nbrl;i++){
            if (chainDif(username,name[i])){
                printf("Pseudo deja utilise, voulez vous reesayer ?(oui/non)\n");
                answer =YorN();
                
            }
        }
        if(answer==2){break;}
    }
    if (answer!=0){
        printf("MDP:\n");
        scanf("%s",mdp);
        printf("Etes vous:\n\n1) Un eleve\n2) Un prof\n\n");
        typ = scan(1,2);
        FILE *acc = fopen("./Data/Account.txt","r+");
        if(acc == NULL){acc = fopen("./Data/Account-save.txt","r+");}
        fseek(acc,0,SEEK_END);
        fputc('\n',acc);
        vigenereEnc(mdp, "CYTECHLIBRARY", mdp2);
        fprintf(acc,"%s %s %d",username,mdp2,typ-1);
        printf("Compte crée,veuillez vous connectez maintenant:\n");
        rewind(acc);
        fclose(acc);
        return takeInfo();
    } 
    
}

int connect(int nbrl){

    char username[15];
    char mdp[15];
    char mdp2[15];
    int answer = 1;
    while(answer){
        printf("Pseudo:\n");
        scanf("%s",username);
        for (int i=0;i<nbrl;i++){
            if (chainDif(username,name[i])){
                while(answer){
                    printf("MDP:\n");
                    scanf("%s",mdp);
                    vigenereEnc(mdp, "CYTECHLIBRARY", mdp2);
                    if (chainDif(mdp2,pw[i])){
                        printf("connecte\n");
                        return i;
                    }
                    else{
                        printf("mauvais mdp,voulez vous reesayer(oui/non)?\n");
                        answer =YorN();
                        
                    }
                }
                break;
            }
        }
        if(answer){printf("pseudo inconnue,voulez vous reesayer(oui/non)?\n");}
        else{printf("voulez vous reesayer avec un autre pseudo(oui/non)?\n");}
        answer =YorN();
    }
    return -1;
}



void editPW(int nbrl,int id){

    char mdp[15];
    char mdp2[15];
    int answer = 1;
    rename("./Data/Account.txt","./Data/Account-save.txt");
    remove("./Data/Account.txt");
    FILE *acc = fopen("./Data/Account.txt","a");
    while(answer){
        printf("Ecriez votre ancien mdp:");
        scanf("%s",mdp);
        vigenereEnc(mdp, "CYTECHLIBRARY", mdp2);
        if (chainDif(mdp2,pw[id])){
            printf("Ecriez votre nvx mdp:");
            scanf("%s",mdp);
            vigenereEnc(mdp, "CYTECHLIBRARY", mdp2);
            for(int i=0; i<15;i++){
                pw[id][i] = mdp2[i];
                if(mdp2[i]=='\0'){break;}
            }
            break;
        }
        else{
            if(answer){printf("Mauvais mdp,voulez vous reesayer(oui/non)?\n");}
            answer = YorN();
        }
    }
    for(int j=0;j<nbrl;j++){
        fprintf(acc,"%s %s %d\n",name[j],pw[j],type[j]);

    }

    remove("./Data/Account-save.txt");
}



