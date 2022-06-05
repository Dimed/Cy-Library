#include "Library.h"


// Array which stock Account.txt data

char title [1000][30];
char pwd [1000][30];
int type [1000];



// Encrypt the password
// Source of this function : https://gist.github.com/touatily/3af14ed032c407fd3e2bb2dbe3bdc154
// Take the normal password and the encryption key
// Return the crypted password in the third parameter

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



// Take data from Account.txt and stock them in idAccount, idBook, timeLeft
// Return the number of line in Account.txt (the Account number)

int stockAccount(){

    FILE *acc = fopen("./Data/Account.txt","r");
    if(acc == NULL){acc = fopen("./Data/Account-save.txt","r");}

    int nbrl =nbrL(acc);

    for(int i=0;i<nbrl;i++){

        fscanf(acc,"%s %s %d",title[i],pwd[i],&type[i]);
    }

    fclose(acc);
    return nbrl;
}



// Create a new account
// Take the account number and return the new account number

int createAccount(int nbrl){

    char username[30];
    char pw[30];
    char pwC[30];
    int typ;
    int answer=1;


    // Check if the name is already used

    while(answer){

        answer = 2;
        printf("Ecrivez votre pseudo (pas d'espace et 30 caractere max):\n");

        scanf("%30s",username);

        for (int i=0;i<nbrl;i++){

            if (strDif(username,title[i])){
                printf("Pseudo deja utilise, voulez vous reessayer ?(oui/non)\n");

                answer =YorN();
            }
        }

        if(answer==2){
            break;
        }
    }
    if (answer!=0){

        printf("Ecrivez votre mot de passe (pas d'espace et 30 caractere max):\n");
        scanf("%30s",pw);

        printf("Etes vous:\n\n1) Un eleve\n2) Un prof\n\n");
        typ = scan(1,2);


        // Save account in  Account.txt

        FILE *acc = fopen("./Data/Account.txt","r+");
        if(acc == NULL){acc = fopen("./Data/Account-save.txt","r+");}

        fseek(acc,0,SEEK_END);
        fputc('\n',acc);

        vigenereEnc(pw, "CYTECHLIBRARY", pwC);
        fprintf(acc,"%s %s %d",username,pwC,typ-1);

        printf("Compte cree !\n");

        rewind(acc);
        fclose(acc);
        return stockAccount();
    } 
}



// Login in an account 
// Take the account number and return the id account if connected, else return -1

int login(int nbrl){

    char username[30];
    char pw[30];
    char pwC[30];
    int answer = 1;

    while(answer){

        printf("Ecrivez votre pseudo:\n");

        scanf("%30s",username);

        for (int i=0;i<nbrl;i++){

            if (strDif(username,title[i])){
                while(answer){

                    printf("Ecrivez votre mot de passe:\n");

                    scanf("%30s",pw);
                    vigenereEnc(pw, "CYTECHLIBRARY", pwC);

                    if (strDif(pwC,pwd[i])){
                        printf("Connecte !\n");

                        return i;
                    }
                    else{
                        printf("Mauvais mot de passe,voulez vous reessayer(oui/non)?\n");

                        answer =YorN();     
                    }
                }

                break;
            }
        }
        if(answer){
            printf("Pseudo inconnu,voulez vous reessayer(oui/non)?\n");
        }
        else{
            printf("Voulez vous reessayer avec un autre pseudo(oui/non)?\n");
        }

        answer =YorN();
    }

    return -1;
}



// Change the password of a user
// Take the account number and the account id

void editPW(int nbrl,int id){

    char pw[30];
    char pwC[30];
    int answer = 1;

    rename("./Data/Account.txt","./Data/Account-save.txt");
    remove("./Data/Account.txt");

    while(answer){

        printf("Ecrivez votre ancien mot de passe:\n");

        scanf("%30s",pw);
        vigenereEnc(pw, "CYTECHLIBRARY", pwC);

        if (strDif(pwC,pwd[id])){
            printf("Ecrivez votre nouveaux mot de passe (pas d'espace et 30 caractere max):\n");

            scanf("%30s",pw);
            vigenereEnc(pw, "CYTECHLIBRARY", pwC);

            for(int i=0; i<30;i++){

                pwd[id][i] = pwC[i];

                if(pwC[i]=='\0'){
                    break;
                }
            }

            break;
        }
        else{
            if(answer){
                printf("Mauvais mot de passe,voulez vous reessayer(oui/non)?\n");
            }

            answer = YorN();
        }
    }


    // Save changes into Account.txt

    FILE *acc = fopen("./Data/Account.txt","a");

    for(int j=0;j<nbrl;j++){

        if(j==nbrl-1){
            fprintf(acc,"%s %s %d",title[j],pwd[j],type[j]);
        }
        else{
            fprintf(acc,"%s %s %d\n",title[j],pwd[j],type[j]);
        }
    }

    remove("./Data/Account-save.txt");
    fclose(acc);
}



// Take the account id and return the type of the account

int giveType(int id){

    return type[id];
}



// Display the welcome window when login
// Take the account number, the account id and the structure where all the books are stocked

void welcomeVisual(int nbrl,int id,Book Books[0]){

    system("clear");
    printf("\n\n  ______  __      __        __        ______  _______   _______    ______   _______  __      __\n /      \\|  \\    /  \\      |  \\      |      \\|       \\ |       \\  /      \\ |       \\|  \\    /  \\\n|  $$$$$$\\\\$$\\  /  $$      | $$       \\$$$$$$| $$$$$$$\\| $$$$$$$\\|  $$$$$$\\| $$$$$$$\\\\$$\\  /  $$\n| $$   \\$$ \\$$\\/  $$______ | $$        | $$  | $$__/ $$| $$__| $$| $$__| $$| $$__| $$ \\$$\\/  $$ \n| $$        \\$$  $$|      \\| $$        | $$  | $$    $$| $$    $$| $$    $$| $$    $$  \\$$  $$  \n| $$   __    \\$$$$  \\$$$$$$| $$        | $$  | $$$$$$$\\| $$$$$$$\\| $$$$$$$$| $$$$$$$\\   \\$$$$   \n| $$__/  \\   | $$          | $$_____  _| $$_ | $$__/ $$| $$  | $$| $$  | $$| $$  | $$   | $$    \n \\$$    $$   | $$          | $$     \\|   $$ \\| $$    $$| $$  | $$| $$  | $$| $$  | $$   | $$    \n  \\$$$$$$     \\$$           \\$$$$$$$$ \\$$$$$$ \\$$$$$$$  \\$$   \\$$ \\$$   \\$$ \\$$   \\$$    \\$$    \n\n\n");
    printf("Bienvenue %s!\n\n",title[id]);

    showLoan(nbrl,id,Books);
}