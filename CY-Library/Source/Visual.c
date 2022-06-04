#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Library.h"



int connec(){

    printf("\n======================================================================\n\n");
    printf("1) Connecter\n2) Cree un compte\n3) Se connecter en tant qu'invite\n4) Quitter");
    printf("\n\n======================================================================\n\n");
    int choix = scan(1,4);
    if(choix == 4){
        printf("Merci d'avoir utilise CY-LIBRARY!!\n\n");
        return 0;
    }
    else{
        return choix;
    }
}

int Menu(){
    system("clear");
    printf("\n\n  ______  __      __        __        ______  _______   _______    ______   _______  __      __\n /      \\|  \\    /  \\      |  \\      |      \\|       \\ |       \\  /      \\ |       \\|  \\    /  \\\n|  $$$$$$\\\\$$\\  /  $$      | $$       \\$$$$$$| $$$$$$$\\| $$$$$$$\\|  $$$$$$\\| $$$$$$$\\\\$$\\  /  $$\n| $$   \\$$ \\$$\\/  $$______ | $$        | $$  | $$__/ $$| $$__| $$| $$__| $$| $$__| $$ \\$$\\/  $$ \n| $$        \\$$  $$|      \\| $$        | $$  | $$    $$| $$    $$| $$    $$| $$    $$  \\$$  $$  \n| $$   __    \\$$$$  \\$$$$$$| $$        | $$  | $$$$$$$\\| $$$$$$$\\| $$$$$$$$| $$$$$$$\\   \\$$$$   \n| $$__/  \\   | $$          | $$_____  _| $$_ | $$__/ $$| $$  | $$| $$  | $$| $$  | $$   | $$    \n \\$$    $$   | $$          | $$     \\|   $$ \\| $$    $$| $$  | $$| $$  | $$| $$  | $$   | $$    \n  \\$$$$$$     \\$$           \\$$$$$$$$ \\$$$$$$ \\$$$$$$$  \\$$   \\$$ \\$$   \\$$ \\$$   \\$$    \\$$    \n\n\n");
    printf("Bienvenu sur CY-LIBRARY !!\n    Que voulez vous faire ?\n\n");
    return connec();
}

void voiB(int nbrl,Book Books[0]){

    printf("Voulez vous :\n\n1) Voir tous les livres\n2) Cherche des livres précis\n\n");
    int choix = scan(1,2);

    if(choix==1){
        printf("Voulez vous Triez les livres:\n\n1) Alphabetiquement\n2) Par date\n\n");
        choix = scan(1,2);

        if (choix==1){
            printf("Par:\n\n1) Titre\n2) Auteur\n\n");
            choix = scan(1,2);
            char vide[1];
            if (choix ==1){
                TriALpha(nbrl,1,Books);
                showName(nbrl,4000,0,vide,Books);
            }
            else{
                TriALpha(nbrl,0,Books);
                showName(nbrl,4000,0,vide,Books);
            }
        }
        else{
            TriDate(nbrl,Books);
        }
    }
    else{
        printf("Voulez vous chercher par:\n\n1) Titre\n2) Auteur\n3) Date\n4) Style\n\n");
        choix = scan(1,4);
        if(choix==1){
            SearchN(nbrl,Books);

        }
        else if(choix==2){
            SearchA(nbrl,Books);

        }
        else if(choix==3){
            SearchD(nbrl,Books);

        }
        else{
            SearchT(nbrl,Books);
        }
    }
}


int guest(){

    printf("\n======================================================================\n\n");
    printf("1) Voir les livre disponibles\n2) Retour sur l'ecran d'acceuil\n3) Quitter");
    printf("\n\n======================================================================\n\n");
    int choix = scan(1,3);
    if(choix == 3){
        printf("Merci d'avoir utilise CY-LIBRARY!!\n\n");
        return 0;
    }
    else{
        return choix;
    }

}

int prof(){
    printf("\n======================================================================\n\n");
    printf("1) Voir les livre disponibles\n2) Emprunter un livre\n3) Rendre un livre\n4) Voir vos emprunts\n5) Ajouter un livre\n6) Supprmier un livre\n7) Changer mdp\n8) Deconnexion\n9) Quitter");
    printf("\n\n======================================================================\n\n");
    int choix = scan(1,9);
    if(choix == 9){
        printf("Merci d'avoir utilise CY-LIBRARY!!\n\n");
        return 0;
    }
    else{
        return choix;
    }
    
}

int stud(){
    printf("\n======================================================================\n\n");
    printf("1) Voir les livre disponibles\n2) Emprunter un livre\n3) Rendre un livre\n4) Voir vos emprunts \n5) Changer mdp\n6) Deconnexion\n7) Quitter");
    printf("\n\n======================================================================\n\n");
    int choix = scan(1,7);
    if(choix == 7){
        printf("Merci d'avoir utilise CY-LIBRARY!!\n\n");
        return 0;
    }
    else{
        return choix;
    }
    
}

