#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Library.h"

int main(){
    int nbrl = takeInfo();

    nbrl = create(nbrl);

    int id =connect(nbrl);
    editPW(nbrl,id);
    int a = 2113531;
    //test
}   
