#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 15 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;


//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int afficherBibliotheque(const T_Bibliotheque  *ptrB);

void RechercherLivre(T_Bibliotheque  *ptrB);
int LivreAuteur(T_Bibliotheque *ptrB);
int SuppLivre(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);
void sauvegarde(T_Bibliotheque *ptrB);
int RendreLivre(T_Bibliotheque  *ptrB);
int emprunter(T_Bibliotheque *ptrB);

int trierAnnee(T_Bibliotheque *ptrB);
int trierTitre(T_Bibliotheque *ptrB);
int trierAuteur(T_Bibliotheque *ptrB);


#endif