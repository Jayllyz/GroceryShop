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
	float *prixF[15];
    char codeF[15][4] = 
    { 
        "F00",
        "F01",
        "F02",
        "F03",
        "F04",
        "F05",
        "F06",
        "F07",
        "F08",
        "F10",
        "F11",
        "F12",
        "F13",
        "F14",
    };

	int emojiL[3][5];
	float prixL[15];
    char codeL[15][4] = 
    { 
        "L00",
        "L01",
        "L02",
        "L03",
        "L04",
        "L05",
        "L06",
        "L07",
        "L08",
        "L10",
        "L11",
        "L12",
        "L13",
        "L14",
    };

	int emojiV[3][5];
	float prixV[15];
    char codeV[15][4] = 
    { 
        "V00",
        "V01",
        "V02",
        "V03",
        "V04",
        "V05",
        "V06",
        "V07",
        "V08",
        "V10",
        "V11",
        "V12",
        "V13",
        "V14",
    };


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