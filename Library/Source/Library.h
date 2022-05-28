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

