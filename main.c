#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/initTab.h"
#include "modules/recupPrix.h"
#include "modules/payement.h"

void cursorPosition(int YPos, int XPos) //Fonction pour déplacer le curseur
 {
    printf("\033[%d;%dH",YPos,XPos);
}


int main()
{
	system("clear"); //clear le terminal avant (ca fonctionne pas rip)


	char* emojiF[] = //chaine pour stocker les emoji
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

	float prixF[15]; // tab des prix init dans le fichier initTab
    char codeF[15][4] =  //chaine pour les codes
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

    initPrixF(prixF); //initialisation des valeurs pour les tab 
    initPrixL(prixL);
    initPrixV(prixV);

    int caractereActuel = 0;
    FILE* fichier = NULL;
    fichier = fopen("vitrine.txt", "r"); //on ouvre le fichier en lecture
    do
    {
        caractereActuel = fgetc(fichier); // On lit le caractère
        printf("%c", caractereActuel);
    } while ( caractereActuel != EOF); //tant que le fichier n'est pas terminé

    cursorPosition(29,27); //on mets le curseur à l'endroit pour prendre le code
    char code[4]; // on stocke ce code dans une chaine
    scanf("%s", code);   
    printf("%s", code);
    float prix = 0;
    prix = recupPrix(code,codeF,codeL,codeV,prixF,prixL,prixV); //ensuite on recup le prix depuis la fonction
    cursorPosition(27,115); 
    printf("%.2f", prix); //et on le print à l'endroit adéquat

    cursorPosition(28,115);
    float recu = payement(prix); //même chose pour le recu
    cursorPosition(29,115);
    printf("%.2f", recu);

    
    fclose(fichier);


    return 0;
}