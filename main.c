#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int nombreMystere=0, nombreEntre=0,compteur=0,continuePartie=1,choixNiveau=0,nombreMaximum=100;
    printf("\nChoisis le niveau : \n");
    printf("1 = entre 1 et 100 \n");
    printf("2 = entre 1 et 1000 \n");
    printf("3 = entre 1 et 10000 \n");
    scanf("%d", &choixNiveau);

    switch(choixNiveau) //choix du niveau de jeu
    {
    case 1:
        nombreMaximum=100;
        break;
    case 2:
        nombreMaximum=1000;
        break;
    case 3:
        nombreMaximum=10000;
        break;
    default:
        nombreMaximum=100;
        break;
    }

    const int MIN = 1;
    srand(time(NULL));
while(continuePartie)
{
    nombreMystere = (rand()%(nombreMaximum - MIN +1))+MIN;
    printf("%d \n",nombreMystere); //cette ligne, c'est pour eviter de jouer trop longtemps pendant les tests
    compteur=0;


    do
    {
        printf("Donnes un nombre entre 1 et %d \n",nombreMaximum);
        scanf("%d", &nombreEntre);

        compteur++;
        if (nombreEntre==nombreMystere)
        {
            printf("Tu as trouve le nombre mystere en %d coups! \n\n",compteur);
            printf("Veux tu continuer ? \n");
            printf("1 = oui \n");
            printf("0 = non \n");
            scanf("%d", &continuePartie);
        }
        else if (nombreEntre>nombreMystere)
            printf("C'est moins ! \n");
        else if(nombreEntre<nombreMystere)
            printf("C'est plus ! \n");
        else
            printf("Il y a un probleme !!! \n");//je ne suis pas arrive a gerer si on entre n'importe quoi ==> boucle infinie
    }
    while(nombreEntre!=nombreMystere);
}
printf("Au revoir \n");
    return 0;
}
