#ifndef LIBRARY_H
#define LIBRARY_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



// Books structure who stock all books information

typedef struct 
{
    char name[100];
    char author[50];
    int style ;
    int date ;
} Book;



// Utilitary.c functions :

int YorN();
int scan(int min,int max);
int strDif(char *str1,char*str2);
int nbrL(FILE *file);



// Account.c functions :

void vigenereEnc(const char * text, const char * key, char * ciphertext);
int stockAccount();
int createAccount(int nbrl);
int login(int nbrl);
void editPW(int nbrl,int id);
int giveType(int id);
void welcomeVisual(int nbrl,int id,Book Books[0]);



// Books.c functions :

int stockBook(Book Books[0]);
void swapLine(int a,int b,Book Books[0]);
int showBook(int nbrl,int date,int style,char*str,Book Books[0]);
int addBook(int nbrl,Book Books[0]);
int delBook(int nbrl,Book Books[0]);
void sortAlpha(int nbrl,int check,Book Books[0]);
void sortDate(int nbrl,Book Books[0]);
int searchTitle(int nbrl,Book Books[0]);
void searchAuthor(int nbrl,Book Books[0]);
void searchDate(int nbrl,Book Books[0]);
void searchStyle(int nbrl,Book Books[0]);


// borrow.c functions :

int stockLoan();
int checkTime(int nbrl,int id,int loanLine);
int loanBook(int nbrl,int nbrlB,int id,Book Books[0],int type);
int returnBook (int nbrl,int id,Book Books[0]);
void showLoan(int nbrl,int id,Book Books[0]);



// Visual.c functions :

int loginVisual();
int Menu();
int guestVisual();
int studentVisual();
int teacherVisual();
void displayBooks(int nbrl,Book Books[0]);