#include "Library.h"



int main(){

    Book Books[1000];
    int nbrlAcc = stockAccount();
    int nbrlBook =stockBook(Books);
    int nbrlLoan =stockLoan();
    int idAcc;
    int choice = 1;




    while(choice){


        // Login Window

        choice = Menu();
        
        while(choice){

            if (choice==1){
                idAcc = login(nbrlAcc);

                if(idAcc==-1){
                    choice = loginVisual();
                }
                else{
                    welcomeVisual(nbrlLoan,idAcc, Books);

                    break;      
                }
            }
            if (choice==2){
                nbrlAcc = createAccount(nbrlAcc);

                choice = loginVisual();
            }
            if(choice==3){
                choice=10;

                break;
            }
        }


        // User Window

        while(choice){


            // Guest Window

            if(choice==10){
                choice = guestVisual();

                if(choice==2){
                    break;
                }
                else if(choice==1){
                    displayBooks(nbrlBook,Books);

                    if(choice==2){
                        break;
                    }
                }
                if(choice!=0){
                    choice=10;
                }
            }


            // Teacher Window

            else if(giveType(idAcc)==1){
                choice = teacherVisual();

                switch (choice)
                {
                case 1 :
                    displayBooks(nbrlBook,Books);
                    break;
                        
                case 2 :
                    nbrlLoan= loanBook(nbrlLoan,nbrlBook,idAcc,Books,1);
                    break;

                case 3 :
                    nbrlLoan= returnBook(nbrlLoan,idAcc,Books);
                    break;

                case 4 :
                    showLoan(nbrlLoan,idAcc,Books);
                    break;

                case 5 :
                    nbrlBook=addBook(nbrlBook,Books);
                    break;

                case 6 :
                    nbrlBook=delBook(nbrlBook,Books);
                    break;

                case 7 :
                    editPW(nbrlAcc,idAcc);
                }
                if (choice==8){
                    break;
                }
            }


            // Student Window

            else{
                choice = studentVisual();

                switch (choice)
                {
                case 1 :
                    displayBooks(nbrlBook,Books);
                    break;
                        
                case 2 :
                    nbrlLoan= loanBook(nbrlLoan,nbrlBook,idAcc,Books,0);
                    break;

                case 3 :
                    nbrlLoan= returnBook(nbrlLoan,idAcc,Books);
                    break;

                case 4 :
                    showLoan(nbrlLoan,idAcc,Books);
                    break;

                case 5 :
                    editPW(nbrlAcc,idAcc);
                    break;    
                }
                if (choice==6){
                    break;
                }         
            } 
        }    
    }
}






