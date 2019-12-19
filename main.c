#include <stdio.h>
#include <stdlib.h>


int main()
{
    int caractereActuel = 0;
    FILE* fichier = NULL;
    fichier = fopen("vitrine.txt", "r");
    do
    {
        caractereActuel = fgetc(fichier); // On lit le caractère
        printf("%c", caractereActuel);
    } while ( caractereActuel != EOF);
    
    fclose(fichier);

    return 0;
}