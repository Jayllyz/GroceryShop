#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/initTab.h"

void cursorPosition(int YPos, int XPos)
 {
    printf("\033[%d;%dH",YPos,XPos);
}


int main()
{
	system("clear");


	char* emojiF[] =
    {
        "🍓",
        "🍇",
        "🍏",
        "🍎",
        "🍐",
        "🍊",
        "🍋",
        "🍌",
        "🍉",
        "🍈",
        "🍒",
        "🍑",
        "🥥",
        "🍍",
        "🥝",
    };

	float prixF[15];
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

	char* emojiL[] =
    {
        "🍅",
        "🍆",
        "🥦",
        "🌽",
        "🥒",
        "🌶",
        "🥕",
        "🥔",
        "🍠",
        "🥑",
        "🍀",
        "🥔",
        "🌱",
        "🌿",
        "🍄",
    };

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

	char* emojiV[] =
    {
        "🍗",
        "🍖",
        "🥩",
        "🥓",
        "🍘",
        "🍔",
        "🍱",
        "🦐",
        "🐚",
        "🦀",
        "🐟",
        "🐠",
        "🍤",
        "🐡",
        "🐋",
    };
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

    initPrixF(prixF);
    initPrixL(prixL);
    initPrixV(prixV);

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