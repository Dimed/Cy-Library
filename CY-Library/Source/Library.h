#ifndef LIBRARY_H
#define LIBRARY_H
#endif

typedef struct 
{
    char name[30];
    char author [30];
    int type ;
    int date ;
} Book;


// Account.c functions :

int connect(int nbrl);
int takeInfo();
int chainDif(char *l,char*g);
int create(int nbrl);
int nbrL(FILE *file);
int scan(int min,int max);
int YorN();
void editPW(int nbrl,int id);
void vigenereEnc(const char * text, const char * key, char * ciphertext);
int giveT(int id);
void succesC(int nbrl,int id,Book Books[0]);


// Books.c functions :


void TriALpha(int end,int ted,Book Books[0]);
int takeInf(Book Books[0]);
int addB(int nbrl,Book Books[0]);
int supB(int nbrl,Book Books[0]);
void SearchD(int nbrl,Book Books[0]);
int showName(int nbrl,int ted,int t,char*l,Book Books[0]);
void TriDate(int nbrl,Book Books[0]);
void swapC(int a,int b,Book Books[0]);
void SearchT(int nbrl,Book Books[0]);
int SearchN(int nbrl,Book Books[0]);
void SearchA(int nbrl,Book Books[0]);

// borrow.c functions :

int takeIn();
int takeB(int nbrl,int nbrl2,int id,Book Books[0],int type);
int backB (int nbrl,int id,Book Books[0]);
int checkT(int nbrl,int id,int prec);
void showB(int nbrl,int id,Book Books[0]);

// Visual.c functions :

int Menu();
int connec();
int guest();
void voiB(int nbrl,Book Books[0]);
int prof();
int stud();