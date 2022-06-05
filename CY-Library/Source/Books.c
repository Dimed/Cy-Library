#include "Library.h"
 
char voidC[1];



// Take data from Books.txt and stock them in Books
// Return the number of line in Books.txt (the books number)


int stockBook(Book Books[0]){

    FILE *boo = fopen("./Data/Books.txt","r");
    if(boo == NULL){boo = fopen("./Data/Books-save.txt","r");}

    int nbrl = nbrL(boo);

    for(int i=0;i<nbrl;i++){
        fscanf(boo,"%s %s %d %d",Books[i].name,Books[i].author,&Books[i].date,&Books[i].style);
    }

    fclose(boo);
    return nbrl;
    
}



// Swap lane in the structure where all the books are stocked
// Take the 2 lane which need to be swap and the structure where all the books are stocked

void swapLine(int a,int b,Book Books[0]){

    char temp[100];

    strcpy(&temp[0] , &Books[a].name[0]);

    strcpy(&Books[a].name[0] , &Books[b].name[0]);
    
    strcpy(&Books[b].name[0] , &temp[0]);
    

    strcpy(&temp[0] , &Books[a].author[0]);
    
    strcpy(&Books[a].author[0] ,&Books[b].author[0]);
    
    strcpy(&Books[b].author[0] , &temp[0]);
    

    int temp2 = Books[a].date ;
    Books[a].date = Books[b].date;
    Books[b].date = temp2 ;


    temp2 = Books[a].style ;
    Books[a].style = Books[b].style;
    Books[b].style = temp2 ;
    
}



// Display books by some criteria
// Take the books nuber, the date (if wanted), the style (if wanted), the author/title (if wanted) and the structure where all the books are stocked

int showBook(int nbrl,int date,int style,char*str,Book Books[0]){

    int check = 0;
    printf("\n\n");


    // Show all books in list ( 1) 2) 3) ...)

    if(date==3000){
        for(int k=0;k<nbrl;k++){

            check=1;

            printf("    %d) ",k+1);

            for(int i=0;i<100;i++){

                if(Books[k].name[i]=='\0'){
                    printf(" || ");break;
                }
                else if(Books[k].name[i]=='-'){
                    printf(" ");
                }
                else{
                    printf("%c",Books[k].name[i]);
                }
            }
            for(int j=0;j<50;j++){

                if(Books[k].author[j]=='\0'){
                    printf(" || ");break;
                }
                else if(Books[k].author[j]=='-'){
                    printf(" ");
                }
                else{
                    printf("%c",Books[k].author[j]);
                }
            }

            printf("%d\n\n",Books[k].date);
        }
    } 


    // Show all books 

    else if(date==4000){
        for(int k=0;k<nbrl;k++){

            check=1;

            printf("    - ");

            for(int i=0;i<100;i++){

                if(Books[k].name[i]=='\0'){
                    printf(" || ");
                    break;
                }
                else if(Books[k].name[i]=='-'){
                    printf(" ");
                }
                else{
                    printf("%c",Books[k].name[i]);
                }
            }
            for(int j=0;j<50;j++){

                if(Books[k].author[j]=='\0'){
                    printf(" || ");break;
                }
                    else if(Books[k].author[j]=='-'){
                    printf(" ");
                }
                else{
                    printf("%c",Books[k].author[j]);
                }
            }

            printf("%d\n\n",Books[k].date);
        }
    }


    // Show books by style

    else if(date==5000){
        for(int k=0;k<nbrl;k++){
            
            if(Books[k].style==style){
                check=1;

                printf("    - ");

                for(int i=0;i<100;i++){

                    if(Books[k].name[i]=='\0'){
                        printf(" || ");
                        break;
                    }
                    else if(Books[k].name[i]=='-'){
                        printf(" ");
                    }
                    else{
                        printf("%c",Books[k].name[i]);
                    }
                }
                for(int j=0;j<50;j++){

                    if(Books[k].author[j]=='\0'){
                        printf(" || ");
                        break;
                    }
                    else if(Books[k].author[j]=='-'){
                        printf(" ");
                    }
                    else{
                        printf("%c",Books[k].author[j]);
                    }
                }
                
                printf("%d\n\n",Books[k].date);
            }
        }
    }


    // Show books by title

    else if(date==6000){
        for(int k=0;k<nbrl;k++){
            
            if(strDif(Books[k].name,str)){
                check=1;

                printf("    - ");

                for(int i=0;i<100;i++){

                    if(Books[k].name[i]=='\0'){
                        printf(" || ");
                        break;
                    }
                    else if(Books[k].name[i]=='-'){
                        printf(" ");
                    }
                    else{
                        printf("%c",Books[k].name[i]);
                    }
                }
                for(int j=0;j<50;j++){

                    if(Books[k].author[j]=='\0'){
                        printf(" || ");
                        break;
                        }
                    else if(Books[k].author[j]=='-'){
                        printf(" ");
                    }
                    else{
                        printf("%c",Books[k].author[j]);
                    }
                }

                printf("%d\n\n",Books[k].date);

                return k;
            }
        }
    }


    // Show books by author

    else if(date==7000){
        for(int k=0;k<nbrl;k++){
            
            if(strDif(Books[k].author,str)){
                check=1;

                printf("    - ");

                for(int i=0;i<100;i++){

                    if(Books[k].name[i]=='\0'){
                        printf(" || ");
                        break;
                    }
                    else if(Books[k].name[i]=='-'){
                        printf(" ");
                    }
                    else{
                        printf("%c",Books[k].name[i]);
                    }
                }
                for(int j=0;j<50;j++){

                    if(Books[k].author[j]=='\0'){
                        printf(" || ");
                        break;
                    }
                    else if(Books[k].author[j]=='-'){
                        printf(" ");
                    }
                    else{
                        printf("%c",Books[k].author[j]);
                    }
                }

                printf("%d\n\n",Books[k].date);
            }
        }
    }


    // Show books by date
          
    else if(date<2500){
            
        for(int k=0;k<nbrl;k++){

            if(Books[k].date==date){
                check=1;

                printf("    - ");

                for(int i=0;i<100;i++){

                    if(Books[k].name[i]=='\0'){
                        printf(" || ");
                        break;
                    }
                    else if(Books[k].name[i]=='-'){
                        printf(" ");
                    }
                    else{
                        printf("%c",Books[k].name[i]);
                    }
                }
                for(int j=0;j<50;j++){

                    if(Books[k].author[j]=='\0'){
                        printf(" || ");
                        break;
                        }
                    else if(Books[k].author[j]=='-'){
                        printf(" ");
                    }
                    else{
                        printf("%c",Books[k].author[j]);
                    }
                }

                printf("%d\n\n",Books[k].date);
            }
        }
    }
    if(check==0){
        printf("0 resultat trouve!\n");

        return -1;
    }
}



// Add a book if you are a teacher
// Take books number and the structure where all the books are stocked
// Return the new books number

int addBook(int nbrl,Book Books[0]){

    char title[100];
    char author[50];
    int date;
    int style;
    int answer=1;


    // Check if the title is already used

    while(answer){

        answer = 2;

        printf("Ecrivez le titre du livre (mettez des - a la place des expaces et 100 caractere max):\n");
        scanf("%100s",title);

        for (int i=0;i<nbrl;i++){

            if (strDif(title,Books[i].name)){
                printf("Titre deja utilise, voulez vous reessayer ?(oui/non)\n");

                answer =YorN();    
            }
        }

        if(answer==2){
            break;
        }
    }
    if (answer!=0){

        printf("Ecrivez l'auteur du livre (mettez des - a la place des expaces et 100 caractere max):\n");
        scanf("%50s",author);

        printf("En quelle annee est sorti le livre ? :\n");
        date = scan(-2023,2023);

        printf("Quel est le style de livre:\n\n1) Policier\n2) Romantique\n3) Poeme\n4) Fantastique\n5) Historique\n6) Educatif\n7) Scientifique\n8) Bande dessinee\n9) Erotique\n10) Thriller\n11) Science Fiction\n12) Biographique\n\n");
        style = scan(1,12);


        // Save the book in the file 

        FILE *boo = fopen("./Data/Books.txt","r+");
        if(boo == NULL){boo = fopen("./Data/Books-save.txt","r+");}

        fseek(boo,0,SEEK_END);
        fputc('\n',boo);

        fprintf(boo,"%s %s %d %d",title,author,date,style);

        printf("livre crée !\n");

        rewind(boo);
        fclose(boo);
        return stockBook(Books);
    }    
}



// Delete a book if you are a teacher
// Take books number and the structure where all the books are stocked
// Return the new books number

int delBook(int nbrl,Book Books[0]){

    int check=1;

    rename("./Data/Books.txt","./Data/Books-save.txt");
    remove("./Data/Books.txt");

    printf("Choisissez le livre a supprimer:\n");
    showBook(nbrl,3000,0,voidC,Books);
    
    int num =scan(1,nbrl)-1;


    // Remove the book from the file 

    FILE *boo = fopen("./Data/Books.txt","a");

    for(int j=0;j<nbrl;j++){

        if(j!=num){
            if(check){
                fprintf(boo,"%s %s %d %d",Books[j].name,Books[j].author,Books[j].date,Books[j].style);
            }
            else{
                fprintf(boo,"\n%s %s %d %d",Books[j].name,Books[j].author,Books[j].date,Books[j].style);
            }
            
            check=0;  
        }
    }

    remove("./Data/Books-save.txt");
    fclose(boo);
    return stockBook(Books);
}



// Sort books in alphabetical order 
// Take the books number, a int (1 for sort title and 0 for author) and the structure where all the books are stocked

void sortAlpha(int nbrl,int check,Book Books[0]){

    int sort ;

    for(int i=0;i<nbrl;i++){

        sort = i ;

        if(check){
            for(int j=1+i;j<nbrl;j++){

                if(strcmp(Books[sort].name,Books[j].name)>0){
                    sort = j;
                }
            }
        }
        else{
            for(int j=1+i;j<nbrl;j++){

                if(strcmp(Books[sort].author,Books[j].author)>0){
                    sort = j;
                }
            }
        }

        swapLine(sort,i,Books);
    }
}



// Sort books in date order 
// Take the books number and the structure where all the books are stocked

void sortDate(int nbrl,Book Books[0]){

    int sort;

    sortAlpha(nbrl,1,Books);

    printf("Voulez vous triez les dates de facon :\n\n1) Croissant\n2) Decroissant\n");
    int answer = scan(1,2);

    for(int i=0;i<nbrl;i++){

        sort = i;

        if(answer == 1){
            for(int j=1+i;j<nbrl;j++){

                if(Books[sort].date>Books[j].date){
                    sort = j;
                }
            }
        }
        else{
            for(int j=1+i;j<nbrl;j++){

                if(Books[sort].date<Books[j].date){
                    sort = j;
                }
            }   
        } 

        swapLine(sort,i,Books);
    }

    showBook(nbrl,4000,0,voidC,Books);
}



// Search for a book by title
// Take the books number and the structure where all the books are stocked and return the book id

int searchTitle(int nbrl,Book Books[0]){
    
    char title[100];

    printf("Quelle est le titre du livre que vous cherchez (mettez des - a la place des expaces svp):\n");
    scanf("%s",title);

    return showBook(nbrl,6000,0,title,Books);
}



// Search for a book by author
// Take the books number and the structure where all the books are stocked

void searchAuthor(int nbrl,Book Books[0]){

    char author[50];

    sortAlpha(nbrl,1,Books);

    printf("Quelle auteur cherchez vous (mettez des - a la place des expaces svp):\n");
    scanf("%50s",author);

    showBook(nbrl,7000,0,author,Books);
}



// Search for a book by date
// Take the books number and the structure where all the books are stocked

void searchDate(int nbrl,Book Books[0]){

    sortAlpha(nbrl,1,Books);

    printf("Choisissez la date:\n");
    showBook(nbrl,scan(-10000,2023),0,voidC,Books);
}



// Search for a book by style
// Take the books number and the structure where all the books are stocked

void searchStyle(int nbrl,Book Books[0]){

    printf("Quel style de livre voulez vous:\n\n1) Policier\n2) Romantique\n3) Poeme\n4) Fantastique\n5) Historique\n6) Educatif\n7) Scientifique\n8) Bande dessinee\n9) Erotique\n10) Thriller\n11) Science Fiction\n12) Biographique\n\n");
    int choice =scan(1,12);

    sortAlpha(nbrl,1,Books);

    showBook(nbrl,5000,choice,voidC,Books);
}