//
// Created by nyahon on 10.06.17.
//
#include "inscriptions.h"
#include "utils.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define str(x) #x
#define xstr(s) str(s)
#define NAME_LEN_MAX 80
#define SNME_LEN_MAX 80
#define CATE_LEN_MAX 10
#define INPUT_LEN NAME_LEN_MAX+SNME_LEN_MAX+CATE_LEN_MAX

void inscr(){
    char in;
    printf("==================\n"
                   "# -> Inscriptions\n"
                   "#  n nouvel element\n"
                   "#  t terminaison\n");
    do{

        in = scanSel("nt");
        if(in == 'n'){

            char name[NAME_LEN_MAX+1];
            char surname[SNME_LEN_MAX+1];
            char category[CATE_LEN_MAX+1];
          //  int res =  scanf(" %4[^;]s %4[^;]s %4[^\n]s " , name, surname, category);
            //TODO WORK WITH ;

            inscrMenu(name, surname, category);
            if(!addParticipant(name, surname, category)){
                printf("Une erreur est apparue lors de l'ajout du participant.");
                return;
            }

        }else{
            printf("Commande incorrecte. Tapez n ou t\n");
        }


    }while(in != 't');
    printf("retour au menu principal..\n");

}
bool inscrMenu(char* name, char* surname, char* category){
    int res;

    do {
        printf("Entrez prénom, nom et catégorie:\n");
        res = scanf("%" xstr(NAME_LEN_MAX) "s %" xstr(SNME_LEN_MAX) "s %" xstr(CATE_LEN_MAX) "s",
                    name,                     surname,                 category);
#if DEBUG
        printf("\nValues scanned: %d |First input: %s\n", res, name);
#endif
    }while(!checkInscriptionData(name, surname, category));
    sanitize(name, ';');
    sanitize(surname, ';');
    sanitize(category, ';');


}


bool checkInscriptionData(const char *name, const char *surname, const char *category){
    const char* c[] ={name, surname};

    for(size_t i = 0;i<size(c);i++){
            const char* cl = c[i];
            while(*cl != '\0'){
                if(!isalpha(*cl))
                    return false;
#if DEBUG
                printf("%c", *cl);
                printf("\n");
#endif
                cl++;
            }
    }

    for(size_t i = 0;i<size(CATEGORY);++i){
        if(!strcmp(category,CATEGORY[i]))
            return true;
    }
    return false;
}

bool addParticipant(const char* name, const char* surname, const char* category){
    FILE* fp;
    fp = fopen(FILE_PARTICIPANTS, "a+");
    if(!isFileOpen(fp, FILE_PARTICIPANTS))
        return EXIT_FAILURE;
    size_t PECT_CURRENT_MAX;
    if(!countLines(FILE_PARTICIPANTS, &PECT_CURRENT_MAX))
        return false;
    size_t pectNumber = PECT_CURRENT_MAX+1;
    fprintf(fp, "%s;%s;%s;%d\n", name, surname,category, pectNumber);
    printf( "%s %s: pectoral %04d\n", name, surname, pectNumber);
    fclose(fp);
    return true;
}