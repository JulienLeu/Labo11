/* Fichier : Labo11.c
 * Auteur  : Julien Leuenberger
 * Date    : 4.12.2018
 *
 * Description :	Programme qui permet d'afficher
 *						- Un rectangle
 *						- Un triangle
 *						- Un sinus vertical
 *						- Un sinus horizontal
 *
 * Remarque(s) : (Exemples: "Problèmes rencontés", Erreurs, etc.)
 *
 * Modifications : Date / Auteur / Raison
 *
 * Compilateur : Visual Studio 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include "outils_saisie.h"
#include "graphe.h"		/*Nouvelle librairie avec des fonctions
d'affichage*/

#define RECT_HAUT_MIN 1
#define RECT_HAUT_MAX 50

#define RECT_LARG_MIN 1
#define RECT_LARG_MAX 50

#define TRIAN_HAUT_MIN 1
#define TRIAN_HAUT_MAX 50

#define AMPLITUDE_MIN 1
#define AMPLITUDE_MAX 20

#define MENU_RECT 1
#define MENU_TRIAN 2
#define MENU_SINUS_VERT 3
#define MENU_SINUS_HORI 4


/* Constantes et Variables globales */
int main(void)
{
	/* Variable du programme */
	int choix_menu;
	int hauteur_triangle;
	int hauteur_rectangle;
	int largeur_rectangle;
	int amplitude;

	printf("\nProgramme permettant d'afficher"
		" plusieurs formes en console");

	do
	{
		/* Interface pour choisir le bon menu */
		printf("\n\n=========== MENU ===========");
		printf("\n1 - Rectangle");
		printf("\n2 - Triangle");
		printf("\n3 - Sinus vertical");
		printf("\n4 - Sinus horizontal");
		printf("\n0 - Quitter");

		choix_menu = saisirEntier("Choix -> ");

		switch (choix_menu)
		{
		case 0: // Quitter le programme
		{
			if (confirmer("Voulez vous vraiment quitter"
				"<O/N> : "))
			{
				printf("Vous avez choisit de quitter"
					" l'application\n");
			}
			else
			{
				choix_menu = 6;	// choix_menu doit être 
				// différent de 0 au choix
				printf("Alors on continue");
			}
			break;
		}
		case MENU_RECT: // Rectangle
		{
			hauteur_rectangle = saisirEntierBorne("Veuillez"
				" entrer la hauteur [ 1 - 50] : "
				"", RECT_HAUT_MIN, RECT_HAUT_MAX);
			largeur_rectangle = saisirEntierBorne("Veuillez"
				" entrer la largeur [ 1 - 50] : "
				"", RECT_LARG_MIN, RECT_LARG_MAX);
			aff_rectangle(hauteur_rectangle, largeur_rectangle);
			break;
		}
		case MENU_TRIAN: // Triangle
		{
			hauteur_triangle = saisirEntierBorne("Veuillez"
				" entrer la hauteur [ 1 - 50] : "
				"", TRIAN_HAUT_MIN, TRIAN_HAUT_MAX);
			aff_triangle(hauteur_triangle);
			break;
		}
		case MENU_SINUS_VERT: // Sinus Vertical
		{
			amplitude = saisirEntierBorne("Veuillez"
				" entrer l'amplitude [ 1 - 20 ] :"
				" ", AMPLITUDE_MIN, AMPLITUDE_MAX);
			aff_sinus_vertical(amplitude);
			break;
		}
		case MENU_SINUS_HORI: // Sinus Horizontal
		{
			amplitude = saisirEntierBorne("Veuillez"
				"entrer l'amplitude [ 1 - 20 ] : "
				"", AMPLITUDE_MIN, AMPLITUDE_MAX);
			aff_sinus_horizontal(amplitude);
			break;
		}
		default: // Valeur correspondant à aucun menu
		{
			printf("\nLa valeur saisie n'est pas "
				"valide.\n");
			break;
		}
		}
	} while (choix_menu != 0);
	return EXIT_SUCCESS;
}