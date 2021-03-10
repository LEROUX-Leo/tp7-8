# include "biblio.h"

void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}
return 0;
	
}


int afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre(&(ptrB->etagere[i]));
			}
		return 1;
		}
}

void sauvegarde(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i;
fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	for(i=0;i<ptrB->nbLivres;i++)
		{
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

		}
	fclose(fic);
	puts("\nSAUVEGARDE REUSSIE ..............");



	}
	else puts("ECHEC DE SAUVEGARDE  !!!!!  ");


}

void chargement(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i=0;
fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	do
		{

		fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
		i++;
		}
		while(!feof(fic));
	fclose(fic);
	ptrB->nbLivres=i-1;
	puts("CHARGEMENT  REUSSI ..............");
	}
	else puts("ECHEC DE CHARGEMENT  !!!!!  ");

}

void RechercherLivre(T_Bibliotheque  *ptrB)
{    
    int comp=0;
    int i;
    char titre[MAX_TITRE];
    
    printf("Saisir le titre: ");
    lire(titre,MAX_TITRE);


    for(i=0;i<ptrB->nbLivres;i++)
    {
        if (strcmp(ptrB->etagere[i].titre,titre)==0)
        {
            comp=comp+1;
        }
    }
    if (comp>0) printf("Il y a %d exemplaires \n",comp);
    else printf("Aucun exemplaire trouvé\n");
}


int LivreAuteur(T_Bibliotheque *ptrB)
{	
    int i=0,reponse=0;
    char AUTEUR[MAX_TITRE];
 
    printf("Saississez votre auteur : ");
	lire(AUTEUR,MAX_TITRE);

    for(i=0;i<=ptrB->nbLivres;i++)
    {
        if (strcmp(ptrB->etagere[i].auteur,AUTEUR)==0) 
        {
            printf("%s a écrit le livre : %s\n",AUTEUR,ptrB->etagere[i].titre);
            reponse=1;
        }
    }
    return reponse;
}


int SuppLivre(T_Bibliotheque *ptrB)
{
    char AUTEUR[K_MaxAut],titre[MAX_TITRE];
    int reponse=0;

    printf("Saisir le titre : ");
    lire(titre,MAX_TITRE);

    printf("Saisir l'auteur : ");
    lire(AUTEUR,K_MaxAut);
    
    for (int i=0;i<=ptrB->nbLivres;i++)
    {
        if ((strcmp(ptrB->etagere[i].titre,titre)==0) && (strcmp(ptrB->etagere[i].auteur,AUTEUR)==0))
        {
            ptrB->etagere[i]= ptrB->etagere[ptrB->nbLivres-1];
            ptrB->nbLivres=ptrB->nbLivres-1;
            reponse=1;
        }
    }  
    return reponse;  
}


int RendreLivre(T_Bibliotheque  *ptrB)
{
    char AUTEUR[K_MaxAut],titre[MAX_TITRE];
    int reponse=0;
    char *T='\0';
    printf("Saisir le titre: ");
    lire(titre,MAX_TITRE);

    printf("Saisir l'auteur : ");
    lire(AUTEUR,K_MaxAut);
    
    for (int i=0;i<=ptrB->nbLivres;i++)
    {
        if ((strcmp(ptrB->etagere[i].titre,titre)==0) && (strcmp(ptrB->etagere[i].auteur,AUTEUR)==0))
        {
            if (strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,T)==0)
            {
            strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,T);
            return 1;
            }
        }
    }  
    return reponse;  
}


int emprunter(T_Bibliotheque *ptrB)
{   
    char AUTEUR[K_MaxAut],titre[MAX_TITRE];
    int reponse=0;
    char EMPRUNTEUR[MAX];
    int aux;
    printf("Saisir le titre : ");
    lire(titre,MAX_TITRE);

    printf("Saisir l'auteur : ");
    lire(AUTEUR,K_MaxAut);
 
    for (int i=0;i<=ptrB->nbLivres;i++)
    {
        if ((strcmp(ptrB->etagere[i].titre,titre)==0) && (strcmp(ptrB->etagere[i].auteur,AUTEUR)==0))
        {
            if (*ptrB->etagere[i].emprunteur.nomemprunteur=='\0')
            {
                printf("Entrez le nom de l'emprunteur");
                lireChaine("", EMPRUNTEUR, MAX);
                strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,EMPRUNTEUR);
                printf("Quel est le jour de cet emprunt (0=lundi,1,2,3,4,5,6) : ");
                scanf("%d",&aux);
                ptrB->etagere[i].emprunteur.lejour=aux;
            
                printf("Quel est la date de cet emprunt (0,1,...,30): ");
                scanf("%d",&(ptrB->etagere[i].emprunteur.ledate));
            
                printf("Quel est le mois de cet emprunt : (0=janvier,1...,11) : ");
                scanf("%d",&aux);
                ptrB->etagere[i].emprunteur.lemois=aux;

                printf("Quel est l'annee de cet emprunt : (0-2021)");
                scanf("%d",&(ptrB->etagere[i].emprunteur.lannee));

                reponse=1;
            }

            else 
            {
                printf("Désole, il y a déjà un emprunteur");
                reponse=0;
            }       
        }
    }  
    return reponse;  
} 

int trierAnnee(T_Bibliotheque *ptrB)
{
    int i,j, reponse=0;
    if (ptrB->nbLivres!=0)
    {
        reponse=1;
        ptrB->nbLivres++;
        for(i=0;i<=ptrB->nbLivres-2;i++)
        {
            for (j=0;j<ptrB->nbLivres-2;j++)
            {
                if (ptrB->etagere[j].annee>ptrB->etagere[j+1].annee)
                {
                    ptrB->etagere[ptrB->nbLivres]=ptrB->etagere[j+1];
                    ptrB->etagere[j+1]=ptrB->etagere[j];
                    ptrB->etagere[j]=ptrB->etagere[ptrB->nbLivres];
                }
            }
        }
        ptrB->nbLivres--;
    }
    else {reponse=0;}
    return reponse;
}

int trierTitre(T_Bibliotheque *ptrB)
{
    int i,j, reponse=0;
    if (ptrB->nbLivres!=0)
    {
        reponse=1;
        ptrB->nbLivres++;
        for(i=0;i<=ptrB->nbLivres-2;i++)
        {
            for (j=0;j<ptrB->nbLivres-2;j++)
            {
                if (strcmp(ptrB->etagere[j].titre,ptrB->etagere[j+1].titre)>0)
                {
                    ptrB->etagere[ptrB->nbLivres]=ptrB->etagere[j+1];
                    ptrB->etagere[j+1]=ptrB->etagere[j];
                    ptrB->etagere[j]=ptrB->etagere[ptrB->nbLivres];
                }
            }
        }
        ptrB->nbLivres--;
    }
    else {reponse=0;}
    return reponse;
}

int trierAuteur(T_Bibliotheque *ptrB)
{
    int i,j, reponse=0;
    if (ptrB->nbLivres!=0)
    {
        reponse=1;
        ptrB->nbLivres++;
        for(i=0;i<=ptrB->nbLivres-2;i++)
        {
            for (j=0;j<ptrB->nbLivres-2;j++)
            {
                if (strcmp(ptrB->etagere[j].auteur,ptrB->etagere[j+1].auteur)>0)
                {
                    ptrB->etagere[ptrB->nbLivres]=ptrB->etagere[j+1];
                    ptrB->etagere[j+1]=ptrB->etagere[j];
                    ptrB->etagere[j]=ptrB->etagere[ptrB->nbLivres];
                }
            }
        }
        ptrB->nbLivres--;
    }
    else {reponse=0;}
    return reponse;
}

int listerlivredispo(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
                if (*ptrB->etagere[i].emprunteur.nomemprunteur=='\0'){
                    afficherLivre(&(ptrB->etagere[i]));
                }
			}
		return 1;
		}
}