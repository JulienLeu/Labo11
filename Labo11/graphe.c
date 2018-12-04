/* Fichier : graphe.c
* Auteur   : Julien Leuenberger
* Date     : 4.12.2018
*
* But      : Fonctions permettant d'afficher en console:
*				- Un rectangle
*				- Un triangle
*				- Un sinus vertical
*				- Un sinus horizontal
*
* Remarque(s) :
*
* Modifications : Date / Auteur / Raison

* Compilateur : Visual Studio 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphe.h"

#define CENTRETRIANGLE 50
#define PREMIERESPACETRINANGLE 1
#define FONDFIGURE " "

#define PI 3.14154
#define DEUX_DOUBLE 2.0

#define POINTSINUS "*"
#define AXEHORIZONTAL "-"
#define AXEVERTICAL "|"



void aff_triangle(int hauteur)
{
	int i, j, k, z; // indices de comptage
	// Centre du triange
	int espace_avant = CENTRETRIANGLE; 
	int espace_entre = PREMIERESPACETRINANGLE;  

	printf("\t\t\t\t\tTriangle de %d de hauteur\n"
		"", hauteur);

	//	Affichage de la première ligne
	for (z = 0; z < (espace_avant+1); z++)
	{
		printf(" ");
	}
	printf(" .\n");
	// Faire chaque ligne de 1 à hauteur
	for (i = 1; i <= hauteur; i = i + 1)	
	{
		//	Espace avant
		for (j = 0; j <= espace_avant; j++)	
		{
			printf(" ");
		}
		printf("/");
		//	Espace entre
		for (k = 0; k < espace_entre; k++)	
		{
			printf(" ");
		}
		printf("\\\n");
		espace_avant = espace_avant -
			PREMIERESPACETRINANGLE;
		espace_entre = espace_entre + 
			2*PREMIERESPACETRINANGLE;
	}
	// Affichage dernière ligne
	for (j = 0; j <= (espace_avant + 1); j++)
	{
		printf(" ");
	}
	for (k = 0; k < espace_entre; k++)
	{
		printf("-");
	}
	printf("\n");
}


void aff_rectangle(int hauteur, int largeur)
{
	int i, j, k;
	int espace_gauche = 10;
	//	caractères d'affichage
	char angle_haut_gauche = 218;
	char angle_haut_droite = 191;
	char barre_verticale = 179;
	char angle_bas_gauche = 192;
	char angle_bas_droite = 217;
	char barre_horizontale = 196;

	printf("Rectangle de %d de hauteur et"
		" %d de largeur\n", hauteur, largeur);
	
	for (i = 0; i <= espace_gauche; i++)
	{
		printf(" ");
	}
	printf("%c", angle_haut_gauche);
	for (i = 0; i <= largeur; i++)
	{
		printf("%c", barre_horizontale);
		printf("%c", barre_horizontale);
	}
	printf("%c", angle_haut_droite);
	printf("\n");
	for (j = 0; j < hauteur; j++)
	{

		for (k = 0; k <= espace_gauche; k++)
		{
			printf(" ");
		}
		printf("%c", barre_verticale);
		for (k = 0; k <= largeur; k++)
		{
			printf("  ");
		}
		printf("%c\n", barre_verticale);
	}
	for (i = 0; i <= espace_gauche; i++)
	{
		printf(" ");
	}
	printf("%c", angle_bas_gauche);
	for (i = 0; i <= largeur; i++)
	{
		printf("%c", barre_horizontale);
		printf("%c", barre_horizontale);
	}
	printf("%c", angle_bas_droite);

}


void aff_sinus_vertical(int amplitude)
{
	int y, z;
	double x;
	printf("Sinus vertical d'amplitude"
		" %d\n", amplitude);
	// Pour chaque ligne
	for (y = 0; y < 2*amplitude; y++)
	{
		x = (amplitude * sin((((DEUX_DOUBLE*PI)
			/(DEUX_DOUBLE*amplitude))*y))) + amplitude;
		for (z = 0; z < x; z++)
		{
			printf(FONDFIGURE);
		}
		printf(POINTSINUS);
		printf("\n");
	}
}


void aff_sinus_horizontal(int amplitude)
{
	int indice_ligne, indice_colonne, vsin, vligne;
	printf("Sinus horizontal d'amplitude "
		"%d", amplitude);
	// Ligne par ligne
	for (indice_ligne = 0; indice_ligne <= 
		(amplitude * 2); indice_ligne++)
	{
		vligne = (amplitude - indice_ligne);
		printf(AXEVERTICAL);
		// Colonne par colonne
		for (indice_colonne = 0; indice_colonne 
			<= (amplitude * 2); indice_colonne++)
		{
			vsin = (int)(amplitude * 
				sin((((2.0*3.14159) / (2.0*amplitude))
					*indice_colonne)));
			if (vligne == vsin)
			{
				printf(POINTSINUS);
			}
			else if (indice_ligne == amplitude)
			{
				printf(AXEHORIZONTAL);
			}
			else
			{
				printf(FONDFIGURE);
			}
		}
		printf("\n");
	}
}