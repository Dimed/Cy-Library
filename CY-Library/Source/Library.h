#ifndef LIBRARY_H
#define LIBRARY_H
#endif


// Account.c functions :

int connect(int nbrl);
int takeInfo();
int chainDif(char *l,char*g);
int create(int nbrl);
int takeInfo();
int chainDif(char *l,char*g);
int nbrL(FILE *file);
int scan(int min,int max);
int YorN();
void editPW(int nbrl,int id);
void vigenereEnc(const char * text, const char * key, char * ciphertext);
void vigenereDec(const char * ciphertext, const char * key, char * text);


// Books.c functions :

void TriALpha(int end,int ted);
int takeInf();
int addB(int nbrl);
int supB(int nbrl);
void SearchD(int nbrl);
int showName(int nbrl,int ted,int t,char*l);
void TriDate(int nbrl);
void swapC(int a,int b);
void SearchT(int nbrl);
int SearchN(int nbrl);
void SearchA(int nbrl);


