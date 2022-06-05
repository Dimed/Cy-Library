#include "Library.h"



// Array which stock Borrow.txt data

int idAccount [1000];
int idBook [1000];
time_t timeLeft [1000];



// Take data from Borrow.txt and stock them in idAccount, idBook, timeLeft
// Return the number of line in Borrow.txt (the loan number)

int stockLoan(){

    FILE *bor = fopen("./Data/Borrow.txt","r");
    if(bor == NULL){bor = fopen("./Data/Borrow-save.txt","r");}

    int nbrl = nbrL(bor);

    for(int i=0;i<nbrl;i++){
        fscanf(bor,"%d %d %ld",&idAccount[i],&idBook[i],&timeLeft[i]);
    }

    fclose(bor);
    return nbrl;
}



// Check if the maximum borrowing time is exceeded
// Take the loan number, the account id and the borrow book we want check (-1 for check for all borrow book)
// Return 1 if the time is expired and 0 if not

int checkTime(int nbrl,int id,int loanLine){

    if (loanLine ==-1){
        for(int i=0;i<nbrl;i++){

            if(idAccount[i]==id && time(NULL)>timeLeft[i]){
                return 1;
            }
        }
        return 0;
    }
    else{

        if(time(NULL)>timeLeft[loanLine]){
            return 1;
        }
        return 0;
    }
}



// Choice a Book and loan it
// Take the loan number,the books number, the account id, the structure where all the books are stocked and the typee of account (teacher or student)
// Return the new loan number

int loanBook(int nbrl,int nbrlB,int id,Book Books[0],int type){
    
    int nbrLoan =0;
    int answer = 1;

    while(1){

        int idB = searchTitle(nbrlB, Books);

        if(idB ==-1){
            printf("Aucun livre a ce nom, voulez vous emprunter un autre livre (oui/non)?\n");

            answer = YorN();

            if(answer==0){
                break;
            }
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


                // Check if one of the account borrow book is expired

                if(checkTime(nbrl,id,-1)){
                    printf("Veuillez rendre vos emprunts expire avant de reesayer d'emprunter.");

                    return nbrl;
                }
                for(int i =0;i<nbrl;i++){


                    // Check if the book is already borrow
                
                    if(idB == idBook[i]){
                        printf("Livre deja emprunte,voulez vous emprunte un autre livre (oui/non)?\n");

                        answer = YorN();
                        break;
                    }


                    // Check if the user have borrow too much book

                    else if (id==idAccount[i]){
                        nbrLoan++;

                        if((type == 0 && nbrLoan>=3) || (type == 1 && nbrLoan>=5)){
                            printf("Trop de livre deja emprunte,veuillez en rendre pour en emprunter d'autre\n");

                            return nbrl;
                        }
                    }
                }
                if(answer==0){
                    break;
                }


                // Save the loan in the file 

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
                    return stockLoan();
                }
            }
        }
    }
}



// Choice a borrow book and return it
// Take the loan number,the books number, the account id and the structure where all the books are stocked 
// Return the new loan number

int returnBook (int nbrl,int id,Book Books[0]){


    int listLoan[5];
    int c=0;

    rename("./Data/Borrow.txt","./Data/Borrow-save.txt");
    remove("./Data/Borrow.txt");


    // Display the books borrow

    for(int i=0;i<nbrl;i++){

        if(idAccount[i]==id){
            listLoan[c]= i;
        
            printf("    %d) ",c+1);

            for(int k=0;k<100;k++){

                if(Books[idBook[i]].name[k]=='\0'){
                    printf(" || ");
                    break;
                }
                else if(Books[idBook[i]].name[k]=='-'){
                    printf(" ");
                }
                else{
                    printf("%c",Books[idBook[i]].name[k]);
                }
            }
            for(int m=0;m<50;m++){

                if(Books[idBook[i]].author[m]=='\0'){
                    printf(" || ");
                    break;
                }
                else if(Books[idBook[i]].author[m]=='-'){
                    printf(" ");
                }
                else{
                    printf("%c",Books[idBook[i]].author[m]);
                }
            }

            printf("%d\n\n",Books[idBook[i]].date);     
            c++;
        }
    }
    if(c==0){
        printf("Aucun livre emprunte!\n");

        return nbrl;
    }
    else{
        int check=1;

        printf("Quelle livre voulez vous rendre :\n");

        int choice =scan(1,c)-1;


        // Remove the loan from the file 

        FILE *bor = fopen("./Data/Borrow.txt","a");

        for(int j=0;j<nbrl;j++){

            if(j!=listLoan[choice]){
                if(check){
                    fprintf(bor,"%d %d %ld",idAccount[j],idBook[j],timeLeft[j]);

                    check=0;
                }
                else{
                    fprintf(bor,"\n%d %d %ld",idAccount[j],idBook[j],timeLeft[j]);
                }
            }
        }

    printf("Livre rendu!\n");

    remove("./Data/Borrow-save.txt");
    fclose(bor);
    return stockLoan();
    }
}



// Display all borrow books
// Take the loan number,the books number, the account id and the structure where all the books are stocked 

void showLoan(int nbrl,int id,Book Books[0]){

    time_t tleft;
    struct tm *tnow; 
    int check =1;
    int maxLoan = 3;
    
    for(int i=0;i<nbrl;i++){

        if(idAccount[i]==id){
            idBook[i]= idBook[i];

            if (check){

                if(giveType(id)==1){
                    maxLoan =5;
                }
                printf("Vous pouvez emprunte au maximum %d livres ! \n",maxLoan);
                printf("Voici vos livres empruntes :\n\n");

                check=0;
            }

            printf("    - ");

            for(int k=0;k<100;k++){

                if(Books[idBook[i]].name[k]=='\0'){
                    printf(" || ");break;
                }
                else if(Books[idBook[i]].name[k]=='-'){
                    printf(" ");
                }
                else{
                    printf("%c",Books[idBook[i]].name[k]);
                }
            }

            for(int m=0;m<50;m++){

                if(Books[idBook[i]].author[m]=='\0'){
                    printf(" || ");break;
                }
                else if(Books[idBook[i]].author[m]=='-'){
                    printf(" ");
                }
                else{
                    printf("%c",Books[idBook[i]].author[m]);
                }
            }

            printf("%d || ",Books[idBook[i]].date);


            // Show the maximum return date

            tnow = localtime(&timeLeft[i]);    
            printf("a rendre le %d/%d à %dh%d et %ds\n",tnow->tm_mday,tnow->tm_mon + 1,tnow->tm_hour,tnow->tm_min,tnow->tm_sec);

            if(checkTime(nbrl,id,i)) {
                printf("            --> ATTENTION, RETARD SUR LE RENDU. TANT QUE LE LIVRE NE SERA PAS RENDU EMPRUNTER SERA IMPOSSIBLE!!!\n\n");
            }
            else{
                printf("\n");
            }
        }
    }

    if(check){
        printf("Aucun livre emprunte!\n");
    }
}