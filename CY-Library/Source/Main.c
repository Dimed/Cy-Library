#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Library.h"


int main(){

    Book Books[1000];
    int nbrlA = takeInfo();
    int nbrlB =takeInf(Books);
    int nbrlE =takeIn();
    int idA;
    int choixM = 1;

    while(choixM){
            choixM = Menu();
            while(choixM){

                if (choixM==1){

                    idA =connect(nbrlA);
                    if(idA==-1){
                        choixM = connec();
                    }
                    else{

                        succesC(nbrlE,idA, Books);
                        break;
                        
                    }
                }

                if (choixM==2){

                    nbrlA = create(nbrlA);
                    choixM = connec();
                }
                if(choixM==3){
                    choixM=10;
                    break;
                }
            }
            while(choixM){

                if(choixM==10){
                    choixM = guest();
                    if(choixM==2){
                        break;
                    }
                    else if(choixM==1){

                        voiB(nbrlB,Books);

                        if(choixM==2){
                            break;
                        }
                    }
                    if(choixM!=0){choixM=10;}
                }
                else if(giveT(idA)==1){
                    choixM = prof();
                    switch (choixM)
                    {
                    case 1 :

                        voiB(nbrlB,Books);
                        break;
                        
                    case 2 :

                        nbrlE= takeB(nbrlE,nbrlB,idA,Books,1);
                        break;

                    case 3 :

                        nbrlE= backB(nbrlE,idA,Books);
                        break;

                    case 4 :

                        showB(nbrlE,idA,Books);
                        break;

                    case 5 :

                        nbrlB=addB(nbrlB,Books);
                        break;

                    case 6 :

                        nbrlB=supB(nbrlB,Books);
                        break;

                    case 7 :

                        editPW(nbrlA,idA);
 
                    }

                    if (choixM==8){
                        break;
                    }
                }
                else{
                    choixM = stud();
                    switch (choixM)
                    {
                    case 1 :

                        voiB(nbrlB,Books);
                        break;
                        
                    case 2 :

                        nbrlE= takeB(nbrlE,nbrlB,idA,Books,0);
                        break;

                    case 3 :

                        nbrlE= backB(nbrlE,idA,Books);
                        break;

                    case 4 :

                        showB(nbrlE,idA,Books);
                        break;

                    case 5 :

                        editPW(nbrlA,idA);
                        break;
                    
                    }
                    if (choixM==6){
                        break;
                    }
                
                }
            }
        
    }
}






