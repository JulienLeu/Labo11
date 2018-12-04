/* Fichier : graphe.h
* Auteur   : Julien Leuenberger
* Date     : 4.12.2018
*
* But      : Prototypes des fonctions permettant d'afficher en console:
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

#ifndef __OUTIL_SAISIE_H_
#define __OUTIL_SAISIE_H_
//-----------------------------------------------------------------------------
// Cette fonction affiche un triangle d'une hauteur paramétrable
void aff_triangle(int hauteur);

//-----------------------------------------------------------------------------
// Cette fonction affiche un rectagle d'hauteur et largeur paramétrable
void aff_rectangle(int hauteur, int largeur);

//-----------------------------------------------------------------------------
// Cette fonction affiche un sinus vertical d'amplitude paramétrable
void aff_sinus_vertical(int amplitude);

//-----------------------------------------------------------------------------
// Cette fonction affiche un sinus horizontal d'amplitude paramétrable
void aff_sinus_horizontal(int amplitude);


#endif