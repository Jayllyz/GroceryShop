#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cursorPosition(int YPos, int XPos)
 {
    printf("\033[%d;%dH",YPos+1,XPos+1);
}


int main()
{
	system("clear");


	int emojiF[3][5];
	int prixF[15];
	
	int emojiL[3][5];
	int prixL[15];

	int emojiV[3][5];
	int prixV[15];


    int caractereActuel = 0;
    FILE* fichier = NULL;
    fichier = fopen("vitrine.txt", "r");
    do
    {
        caractereActuel = fgetc(fichier); // On lit le caractère
        printf("%c", caractereActuel);
    } while ( caractereActuel != EOF);
    
    cursorPosition(20,100);
    printf("salut");


    fclose(fichier);

    return 0;
}