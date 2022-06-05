#include "Library.h"



// Allows to navigate into the connexion window
// Return the choice of the user

int loginVisual(){

    printf("\n======================================================================\n\n");
    printf("1) Connecter\n2) Cree un compte\n3) Se connecter en tant qu'invite\n4) Quitter");
    printf("\n\n======================================================================\n\n");

    int choice = scan(1,4);

    if(choice == 4){
        printf("Merci d'avoir utilise CY-LIBRARY!!\n\n");
        return 0;
    }
    else{
        return choice;
    }
}



// Display the menu of the program 
// Return the choice of the user

int Menu(){

    system("clear");
    printf("\n\n  ______  __      __        __        ______  _______   _______    ______   _______  __      __\n /      \\|  \\    /  \\      |  \\      |      \\|       \\ |       \\  /      \\ |       \\|  \\    /  \\\n|  $$$$$$\\\\$$\\  /  $$      | $$       \\$$$$$$| $$$$$$$\\| $$$$$$$\\|  $$$$$$\\| $$$$$$$\\\\$$\\  /  $$\n| $$   \\$$ \\$$\\/  $$______ | $$        | $$  | $$__/ $$| $$__| $$| $$__| $$| $$__| $$ \\$$\\/  $$ \n| $$        \\$$  $$|      \\| $$        | $$  | $$    $$| $$    $$| $$    $$| $$    $$  \\$$  $$  \n| $$   __    \\$$$$  \\$$$$$$| $$        | $$  | $$$$$$$\\| $$$$$$$\\| $$$$$$$$| $$$$$$$\\   \\$$$$   \n| $$__/  \\   | $$          | $$_____  _| $$_ | $$__/ $$| $$  | $$| $$  | $$| $$  | $$   | $$    \n \\$$    $$   | $$          | $$     \\|   $$ \\| $$    $$| $$  | $$| $$  | $$| $$  | $$   | $$    \n  \\$$$$$$     \\$$           \\$$$$$$$$ \\$$$$$$ \\$$$$$$$  \\$$   \\$$ \\$$   \\$$ \\$$   \\$$    \\$$    \n\n\n");
    printf("Bienvenu sur CY-LIBRARY !!\nQue voulez vous faire ?\n\n");

    return loginVisual();
}



// Allows to navigate into the guest user window
// Return the choice of the user

int guestVisual(){

    printf("\n======================================================================\n\n");
    printf("1) Voir les livre disponibles\n2) Retour sur l'ecran d'acceuil\n3) Quitter");
    printf("\n\n======================================================================\n\n");

    int choice = scan(1,3);

    if(choice == 3){
        printf("Merci d'avoir utilise CY-LIBRARY!!\n\n");
        return 0;
    }
    else{
        return choice;
    }
}



// Allows to navigate into the student user window
// Return the choice of the user

int studentVisual(){

    printf("\n======================================================================\n\n");
    printf("1) Voir les livres disponibles\n2) Emprunter un livre\n3) Rendre un livre\n4) Voir vos emprunts \n5) Changer mdp\n6) Deconnexion\n7) Quitter");
    printf("\n\n======================================================================\n\n");

    int choice = scan(1,7);

    if(choice == 7){
        printf("Merci d'avoir utilise CY-LIBRARY!!\n\n");
        return 0;
    }
    else{
        return choice;
    }   
}



// Allows to navigate into the teacher user window
// Return the choice of the user

int teacherVisual(){

    printf("\n======================================================================\n\n");
    printf("1) Voir les livres disponibles\n2) Emprunter un livre\n3) Rendre un livre\n4) Voir vos emprunts\n5) Ajouter un livre\n6) Supprimer un livre\n7) Changer mdp\n8) Deconnexion\n9) Quitter");
    printf("\n\n======================================================================\n\n");

    int choice = scan(1,9);

    if(choice == 9){
        printf("Merci d'avoir utilise CY-LIBRARY!!\n\n");
        return 0;
    }
    else{
        return choice;
    }  
}



// Allows to choice how show the books
// Take the number of books and the structure where all the books are stocked

void displayBooks(int nbrl,Book Books[0]){

    printf("Voulez vous :\n\n1) Voir tous les livres\n2) Cherche des livres précis\n\n");

    int choice = scan(1,2);


    // Show all books by sort

    if(choice==1){
        printf("Voulez vous Triez les livres:\n\n1) Alphabetiquement\n2) Par date\n\n");
        choice = scan(1,2);

        if (choice==1){
            printf("Selon le:\n\n1) Titre\n2) Auteur\n\n");

            choice = scan(1,2);
            char voidC[1];

            if (choice ==1){
                sortAlpha(nbrl,1,Books);
                showBook(nbrl,4000,0,voidC,Books);
            }
            else{
                sortAlpha(nbrl,0,Books);
                showBook(nbrl,4000,0,voidC,Books);
            }
        }
        else{
            sortDate(nbrl,Books);
        }
    }


    // Search for a book according to a criteria

    else{
        printf("Voulez vous chercher par:\n\n1) Titre\n2) Auteur\n3) Date\n4) Style\n\n");

        choice = scan(1,4);

        switch (choice){
            case 1 :
                searchTitle(nbrl,Books);
                break;

            case 2 :
                searchAuthor(nbrl,Books);
                break;

            case 3 :
                searchDate(nbrl,Books);
                break;
                
            case 4 :
                searchStyle(nbrl,Books);
                break;
        }
    }
}

