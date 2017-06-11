#include <stdio.h>
#include <stdlib.h>


#include "inscriptions.h"
#include "utils.h"


int main (int argc, char *argv[]){
    //input Menu
    char in;
    printf("Bienvenue dans MyKourse\n");


do {
    printf("%s", CLEAR_SCREEN);
    printf("==================\n"
                   "# -> accueil\n"
                   "#    i inscriptions\n"
                   "#    c course\n"
                   "#    a analyse\n"
                   "#    t terminaison\n");

     in = scanSel("icat");

    printf("%s", CLEAR_SCREEN);

    if (in == 'i') {
        inscr();
    }
    if (in == 'c') {
//        course();
    }
    if (in == 'a') {
//        analyse();
    }

}while(in != 't');
    printf("Fin du programme.\n");
    return EXIT_SUCCESS;


}