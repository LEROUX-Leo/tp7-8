// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"

int menu()
{
	int choix;



//printf("\n Au programme du TP6 :"); 

printf("\n  1 - Ajouter un nouveau livre dans la bibliotheque "); 
printf("\n  2 - Afficher tous les livres de la bibliotheque "); 
printf("\n  3 - Rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n  4 - Rechercher et afficher tous les livres d'un auteur");
printf("\n  5 - Supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)

// au programme du TP7 :
// ajouter le champ emprunteur à votre structure T_Livre

printf("\n  6 - Emprunter un livre de la bibliotheque");
printf("\n  7 - Restituer/rendre un livre de la bibliotheque");
printf("\n  8 - Trier les livres (par titre)");
printf("\n  9 - Trier les livres (par auteur)");
printf("\n 10 - Trier les livres (par annee)");


// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc... 
printf("\n 11 - lister les livres disponibles "); 
printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
// printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ")

printf("\n  0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d[^\n]",&choix);getchar();
printf("\n");
return choix;

}


int main()
{
int reponse,chx;
//int pos;
//char *Livre;
T_Bibliotheque B; 
init( &B );


chargement(&B);

do
{
chx= menu();
switch(chx)
	{

//TP6
	case  1 : //ajouter un livre
			reponse = ajouterLivre(&B);
				if (reponse==1)
					{
						printf(" Ajout reussi !!!\n");
						sauvegarde(&B);
					}
					else
					printf("\nimpossible d ajouter (bibliotheque pleine), retour au menu\n");
			break;
			
	case 2 : // afficher tous les livres
			reponse=afficherBibliotheque(&B);
			if (reponse==0)	
				{
					printf("La bibliotheque est vide");
					sauvegarde(&B);
				}
			break;	
	
	//int RechercherLivre(T_tabloDeLivres etagere,T_Bibliotheque  nbLivres,char const Livre)
	case 3 : //rechercher un livre par son titre

			RechercherLivre(&B);
            break;
	

	case 4 : //rechercher et afficher tous les livres d'un auteur
  			reponse=LivreAuteur(&B);
            if (reponse==0)
                {printf("Le livre est introuvable\n");}
            
			
			/*printf("Saississez votre auteur : ");
			lireChaine("AUTEUR",Auteur			
			LivreAuteur(&B,Auteur);
			*/
			break;	

	case 5 : //menu :Supprimer un livre de la bibliothèque
			reponse=SuppLivre(&B);
            if (reponse==1)
                {
                    printf("La suppression a bien été effectuée!\n");
                    sauvegarde(&B);
                }
            else 
                {printf("Suppression impossible!\n");}
			break;

//TP7
	case 6 : //Emprunter un livre de la bibliothèque
			reponse=emprunter(&B);
            if (reponse==1)
                {
                    printf("L'emprunt a été effectué\n");
                    sauvegarde(&B);
                }

			break;
		

	case 7: //Restituer/rendre un livre de la bibliothèque
			reponse=RendreLivre(&B);
            if (reponse==1)
                {
                    printf("Livre bien rendu\n");
                    sauvegarde(&B);
                }
            else 
                {printf("Impossible de rendre le livre, il n'existe pas\n");}
			break;

	case 8 : //Trier les livres par titre
				reponse=trierTitre(&B);
            if (reponse!=0)
            {
                printf("Le tri a bien été effectuée!\n");
                sauvegarde(&B);
            }
            else 
                {printf("Tri impossible!\n");}
            break;


	case 9 : //Trier les livres par auteur
				reponse=trierAuteur(&B);
            if (reponse!=0)
            {
                printf("Le tri a bien été effectuée!\n");
                sauvegarde(&B);
            }
            else 
                {printf("Tri impossible!\n");}
			break;

	case 10 : //Trier les livres par année
				reponse=trierAnnee(&B);
            if (reponse!=0)
            {
                printf("Le tri a bien été effectuée!\n");
                sauvegarde(&B);
            }
            else 
                {printf("Tri impossible!\n");}
			break;

	case 11 : //Lister livres libres
				reponse=listerlivredispo(&B);
			if (reponse!=0)
			{
				printf("Livres libres : %d\n",reponse);
				sauvegarde(&B);
			}
			else 
				{printf("Livre non disponible!\n");}
			break;
	
	case 12 : //Lister les emprunts en retards

			break;
	}


}while(chx!=0);


return 0;
}
