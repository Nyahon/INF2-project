//
// Created by nyahon on 11.06.17.
//

#include "course.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void course(){

    int res;
    int pectoral;
    struct tm start;
    struct tm arrival;
    char name[80];
    do {
        printf("Entrez prénom, nom et catégorie:\n");
        res = scanf("%80s", name);
        //1234; 13/04/2014 10:01:03; 13/04/2014 11:31:22
        scanf("%d%*s %d/%d/%d %d:%d:%d%*s %d/%d/%d %d:%d:%d %*s",
               &pectoral, &start.tm_mday, &start.tm_mon, &start.tm_yday, &start.tm_hour, &start.tm_min, &start.tm_sec,
              &arrival.tm_mday, &arrival.tm_mon, &arrival.tm_yday, &arrival.tm_hour, &arrival.tm_min, &arrival.tm_sec);
        char buffer[26];
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", &start);
        puts(buffer);
    }while(true);

}