/*!
\file main.c
\author Charrier Simon
\version 1
\date 12 novembre 2023
\brief TP6
*/

// Importations
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// Définition
#define TAILLE 5
#define ERROR -1

/*!
\fn void afftab(int tableau[TAILLE])
\author Charrier Simon
\version 1
\date 7 novembre 2023
\brief Affiche un tableau
\param int tableau[TAILLE] : tableau d'entiers
*/
void afftab(int tableau[TAILLE])
{
	// Déclarations
	int i;

	// Affichage
	printf("|");
	for (i = 0 ; i < TAILLE ; i++)
	{
		printf("%d|",tableau[i]);
	}
}

/*!
\fn void inversion (int tableau[TAILLE])
\author Charrier Simon
\version 1
\date 7 novembre 2023
\brief Inverse les cases d'un tableau d'entiers
\param int tableau[TAILLE] : tableau d'entiers
*/
void inversion (int tableau[TAILLE])
{
	// Définition des variables
	int i;
	int temp;

	// Procédure
	for (i = 0 ; i < TAILLE/2 ; i++)
	{
		temp = tableau[i];
		tableau[i] = tableau[TAILLE -1 - i];
		tableau[TAILLE -1 -i] = temp;
	}
	
	// Affichage du tableau
	afftab(tableau);
}

/*!
\fn void somme (int tableau1[TAILLE], int tableau2[TAILLE])
\author Charrier Simon
\version 1
\date 7 novembre 2023
\brief additionne 2 tableaux
\param int tableau[TAILLE] : tableau d'entiers
*/
void somme(int tableau1[TAILLE], int tableau2[TAILLE])
{
	// Déclarations
	int tabfin[TAILLE];
	int i;

	// Procédure
	for (i = 0 ; i < TAILLE ; i++)
	{
		tabfin[i] = tableau1[i] + tableau2[i];
	}
	afftab(tabfin);
}

/*!
\fn bool tableauTraversable (int tableau[Taille])
\author Charrier Simon
\version 1
\date 9 novembre 2023
\brief Annonce si un tableau est traversable ou non, et return true ou false
\return true : si le tableau est traversable, false sinon
\param int tableau[TAILLE] : tableau d'entiers
*/
bool tableauTraversable (int tableau[TAILLE])
{	
	int i = 0;

	while (i <= TAILLE)
	{
		if (i == TAILLE - 1)
		{
			printf("Le tableau est traversable.\n");
			return true;
		}
		else
		{
			i = i + tableau[i];
		}
	}
	printf("Le tableau n'est pas traversable.\n");
	return false;
}

/*!
\fn void afftext(char tableau[TAILLE])
\author Charrier Simon
\version 1
\date 9 novembre 2023
\brief Affiche un tableau de charactères
\param char tableau[TAILLE] : tableau de charactères
*/
void afftext(char tableau[TAILLE])
{
	// Déclarations
	int i;

	// Affichage
	for (i = 0 ; i < TAILLE ; i++)
	{
		printf("%c",tableau[i]);
	}
	printf("\n");
}

/*!
\fn int palindrome(char texte[TAILLE])
\author Charrier Simon
\version 1
\date 9 novembre 2023
\brief Vérifie qu'un mot soit un palindrome
\return 1 si le mot est un palindrome, 0 sinon
\param char t
*/
int palindrome(char texte[TAILLE])
{
	char inverse[TAILLE];
	int i;

	for (i = 0 ; i < TAILLE ; i++)
	{
		inverse[TAILLE -1 - i] = texte[i];
	}
	afftext(inverse);

	// Ici, on utilise "*()" pour indiquer à C de ne pas utiliser le pointeur mais bien le contenu du texte comme moyen de comparaison
	if (*(inverse) == *(texte))
	{
		printf("C'est un palindrome.\n");
		return 1;
	}
	else
	{
		printf("Ce n'est pas un palindrome.\n");
		return 0;
	}
}

// Partie fonctions servant pour le puissance 4 !

/*!
\fn void init (int plateau[5][5])
\author Charrier Simon
\version 1
\date 9 novembre 2023
\brief Initialisation du puissance 4
\param int plateau[5][5] : un tableau d'entier 5/5
*/
void init (int plateau[5][5])
{	
	int x,y;

	system("clear");
	for (y = 0 ; y <= 4 ; y++)
	{
		for (x = 0 ; x <= 4 ; x++)
		{
			plateau[x][y] = -1;
		}
	}
}

/*!
\fn void affichage (int plateau[5][5])
\author Charrier Simon
\version 1
\date 10 novembre 2023
\brief Affichage du plateau
\param int plateau[5][5] : un tableau d'entier 5/5
*/
/*!
\fn void affichage (int plateau[5][5])
\author Charrier Simon
\version 1
\date 10 novembre 2023
\brief Affichage du plateau
\param int plateau[5][5] : un tableau d'entier 5/5
*/
void affichage (int plateau[5][5])
{
	int x,y;

	system("clear");
	// Affichage du tableau
	// Lignes centrales + Première ligne
	for (y = 0 ; y <= 4 ; y++)
	{	
		printf("+");
		for (x = 0 ; x <= 4 ; x++)
		{
			printf("-------+");
		}
		printf("\n");
		printf("|");
		for (x = 0 ; x <= 4 ; x++)
		{
			printf("       |");
		}
		printf("\n");
		printf("|");
		for (x = 0 ; x <= 4 ; x++)
		{
			if (plateau[x][y] == 1)
			{
				printf("   X   |");
			}
			else if (plateau[x][y] == 2)
			{
				printf("   O   |");
			}
			else
			{
				printf("       |");
			}
		}
		printf("\n");
		printf("|");
		for (x = 0 ; x <= 4 ; x++)
		{
			printf("       |");
		}
		printf("\n");
	}

	// Dernière ligne
	printf("+");
	for (x = 0 ; x <= 4 ; x++)
	{
		printf("-------+");
	}
	printf("\n");
}

/*!
\fn int jouer (int plateau[5][5], int joueur, int pos)
\author Charrier Simon
\version 1
\date 10 novembre 2023
\brief Mise à jour du plateau selon les entrées utilisateurs
\return 1 si tout s'est bien passé, 0 sinon
\param int plateau[5][5] : le tableau d'entier représentant le puissance 4
\param int joueur : joueur 1 ou 2
\param int pos : position dans laquelle mettre la pièce
*/
int jouer (int plateau[5][5], int joueur, int pos)
{	
	// Déclaration des variables
	int vide;
	int verif;
	
	// Vérification de pos :
	if (pos >= 5 || pos <= -1)
	{
		return 0;
	}

	// Vérification de la ligne où on peut mettre une pièce
	verif = 0;

	// Verif passe à 1 si on trouve une case vide
	while (verif == 0)
	{
		vide = 4;

		// Si on trouve une case vide (donc =-1) ou que vide passe à -1, on sort du While
		while (plateau[pos][vide] != -1 && vide >= 0)
		{
			vide = vide - 1;
		}

		if (vide == -1)
		{
			printf("La colonne est pleine, choisissez-en une autre !\n");
			return 0;
		}
		else 
		{
			verif = 1;
		}
	}
	
	// Selon le joueur, on place le bon symbole dans la case trouvée plus haut
	if (joueur == 1)
	{
		plateau[pos][vide] = 1;
		return 1;
	}
	if (joueur == 2)
	{
		plateau[pos][vide] = 2;
		return 1;
	}
	return 0;
}

/*!
\fn int aGagne (int plateau[5][5])
\author Charrier Simon
\version 1
\date 11 novembre 2023
\brief Verification des conditions de fin de partie
\return 1 si le joueur 1 gagne, 2 si c'est le joueur 2, 0 en cas d'égalité et -1 si la partie n'est pas finie
\param int plateau[5][5] : le tableau d'entier représentant le puissance 4
*/
/*!
\fn int aGagne (int plateau[5][5])
\author Charrier Simon
\version 1
\date 11 novembre 2023
\brief Verification des conditions de fin de partie
\return 1 si le joueur 1 gagne, 2 si c'est le joueur 2, 0 en cas d'égalité et -1 si la partie n'est pas finie
\param int plateau[5][5] : le tableau d'entier représentant le puissance 4
*/
int aGagne (int plateau[5][5])
{
	// Déclaration des variables
	// x lignes du plateau, y colonnes du plateau
	int x,y;
	// Points des joueurs
	int pointJ1,pointJ2;
	// Compteur de pièces (pour vérifier si le plateau est plein)
	int pieces=0;

	// Vérification des colonnes
	for (y = 0 ; y <= 4 ; y++)
	{
		for (x = 0 ; x <= 4 ; x++)
		{

			// Si sur une même colonne, 2 mêmes symboles se suivent, on incrémente la variable correspondante
			if (plateau[y][x] == 1 && plateau[y][x+1] == 1)
			{
				pointJ1=pointJ1+1;
				pointJ2=0;
			}
			else if (plateau[y][x] == 2 && plateau[y][x+1] == 2)
			{
				pointJ2=pointJ2+1;
				pointJ1=0;
			}
			// Sinon on repasse à 0
			else
			{
				pointJ1=0;
				pointJ2=0;
			}

			// Si un des 2 joueurs gagne, on arrete la vérification (impossible de faire gagner les 2 joueurs le même tour)
			if (pointJ1 >= 3)
			{
				printf("Le joueur 1 à gagné !\n");
				return 1;
			} 

			else if (pointJ2 >= 3)
			{
				printf("Le joueur 2 à gagné !\n");
				return 2;
			}
		}
	}

	// Vérification des lignes
	for (x = 0 ; x <= 4 ; x++)
	{
		for (y = 0 ; y <= 4 ; y++)
		{

			// Si sur une même colonne, 2 mêmes symboles se suivent, on incrémente la variable correspondante
			if (plateau[y][x] == 1 && plateau[y+1][x] == 1)
			{
				pointJ1=pointJ1+1;
				pointJ2=0;
			}
			else if (plateau[y][x] == 2 && plateau[y+1][x] == 2)
			{
				pointJ2=pointJ2+1;
				pointJ1=0;
			}
			// Sinon on repasse à 0
			else
			{
				pointJ1=0;
				pointJ2=0;
			}

			// Si un des 2 joueurs gagne, on arrete la vérification (impossible de faire gagner les 2 joueurs le même tour)
			if (pointJ1 >= 3)
			{
				printf("Le joueur 1 à gagné !\n");
				return 1;
			} 

			else if (pointJ2 >= 3)
			{
				printf("Le joueur 2 à gagné !\n");
				return 2;
			}
		}
	}

	// Vérification des diagonales
	// Seules certaines diagonales sont possibles (Diagonales (/) en 0,0 impossible) car on veut 4 pièces d'affilées
	
	// Diagonales "/" (3,0 - 0,3)
	// On initialise les variables (hors for)
	y=0;
	pointJ1=0;
	pointJ2=0;
	for (x = 3 ; x >= 0 ; x--)
	{
		if (plateau[y][x] == 1 && plateau[y+1][x-1] == 1)
		{
			pointJ1=pointJ1+1;
			pointJ2=0;
		}
		else if (plateau[y][x] == 2 && plateau[y+1][x-1] == 2)
		{
			pointJ2=pointJ2+1;
			pointJ1=0;
		}
		else
		{
			pointJ1=0;
			pointJ2=0;
		}
		if (pointJ1 >= 3)
		{
			printf("Le joueur 1 à gagné !\n");
			return 1;
		}
		else if (pointJ2 >= 3)
		{
			printf("Le joueur 2 à gagné !\n");
			return 2;
		}
		y=y+1;	
	}

	// Diagonales "/" (4,0 - 0,4)
	// On initialise les variables (hors for)
	y=0;
	pointJ1=0;
	pointJ2=0;
	for (x = 4 ; x >= 0 ; x--)
	{
		if (plateau[y][x] == 1 && plateau[y+1][x-1] == 1)
		{
			pointJ1=pointJ1+1;
			pointJ2=0;
		}
		else if (plateau[y][x] == 2 && plateau[y+1][x-1] == 2)
		{
			pointJ2=pointJ2+1;
			pointJ1=0;
		}
		else
		{
			pointJ1=0;
			pointJ2=0;
		}
		if (pointJ1 >= 3)
		{
			printf("Le joueur 1 à gagné !\n");
			return 1;
		}
		else if (pointJ2 >= 3)
		{
			printf("Le joueur 2 à gagné !\n");
			return 2;
		}
		y=y+1;	
	}

	// Diagonales "/" (4,1 - 1,4)
	// On initialise les variables (hors for)
	y=1;
	pointJ1=0;
	pointJ2=0;
	for (x = 4 ; x >= 0 ; x--)
	{
		if (plateau[y][x] == 1 && plateau[y+1][x-1] == 1)
		{
			pointJ1=pointJ1+1;
			pointJ2=0;
		}
		else if (plateau[y][x] == 2 && plateau[y+1][x-1] == 2)
		{
			pointJ2=pointJ2+1;
			pointJ1=0;
		}
		else
		{
			pointJ1=0;
			pointJ2=0;
		}
		if (pointJ1 >= 3)
		{
			printf("Le joueur 1 à gagné !\n");
			return 1;
		}
		else if (pointJ2 >= 3)
		{
			printf("Le joueur 2 à gagné !\n");
			return 2;
		}
		y=y+1;	
	}

	// Diagonales "\" (1,0 - 4,3)
	// On initialise les variables (hors for)
	y=0;
	pointJ1=0;
	pointJ2=0;
	for (x = 1 ; x <=4 ; x++)
	{
		if (plateau[y][x] == 1 && plateau[y+1][x+1] == 1)
		{
			pointJ1=pointJ1+1;
			pointJ2=0;
		}
		else if (plateau[y][x] == 2 && plateau[y+1][x+1] == 2)
		{
			pointJ2=pointJ2+1;
			pointJ1=0;
		}
		else
		{
			pointJ1=0;
			pointJ2=0;
		}
		if (pointJ1 >= 3)
		{
			printf("Le joueur 1 à gagné !\n");
			return 1;
		}
		else if (pointJ2 >= 3)
		{
			printf("Le joueur 2 à gagné !\n");
			return 2;
		}
		y=y+1;	
	}

	// Diagonales "\" (0,0 - 4,4)
	// On initialise les variables (hors for)
	y=0;
	pointJ1=0;
	pointJ2=0;
	for (x = 0 ; x <=4 ; x++)
	{
		if (plateau[y][x] == 1 && plateau[y+1][x+1] == 1)
		{
			pointJ1=pointJ1+1;
			pointJ2=0;
		}
		else if (plateau[y][x] == 2 && plateau[y+1][x+1] == 2)
		{
			pointJ2=pointJ2+1;
			pointJ1=0;
		}
		else
		{
			pointJ1=0;
			pointJ2=0;
		}
		if (pointJ1 >= 3)
		{
			printf("Le joueur 1 à gagné !\n");
			return 1;
		}
		else if (pointJ2 >= 3)
		{
			printf("Le joueur 2 à gagné !\n");
			return 2;
		}
		y=y+1;	
	}

	// Diagonales "\" (0,1 - 3,4)
	// On initialise les variables (hors for)
	y=1;
	pointJ1=0;
	pointJ2=0;
	for (x = 0 ; x <=3 ; x++)
	{
		if (plateau[y][x] == 1 && plateau[y+1][x+1] == 1)
		{
			pointJ1=pointJ1+1;
			pointJ2=0;
		}
		else if (plateau[y][x] == 2 && plateau[y+1][x+1] == 2)
		{
			pointJ2=pointJ2+1;
			pointJ1=0;
		}
		else
		{
			pointJ1=0;
			pointJ2=0;
		}
		if (pointJ1 >= 3)
		{
			printf("Le joueur 1 à gagné !\n");
			return 1;
		}
		else if (pointJ2 >= 3)
		{
			printf("Le joueur 2 à gagné !\n");
			return 2;
		}
		y=y+1;	
	}

	// Gestion de l'égalité (Plateau plein)
	pieces = 0;
	for (y = 0 ; y <= 4 ; y++)
	{
		for (x = 0 ; x <= 4 ; x++)
		{
			if (plateau[y][x] != -1)
			{
				pieces = pieces+1;
			}
		}
	}

	if (pieces == 25)
	{
		printf("Le plateau est plein, égalité !\n");
		return 0;
	}
	return -1;
}

/*!
\fn void tourDeJeu (int plateau[5][5])
\author Charrier Simon
\version 1
\date 12 novembre 2023
\brief Partie de puissance 4 en utilisant les autres fonctions
\param int plateau[5][5] : le tableau d'entier représentant le puissance 4
*/
void tourDeJeu(int plateau[5][5]) {
  // Déclaration des variables
  // Partie finie ?
  int finie = -1;
  // Joueur du tour
  int joueur = 0;
  // Position fournie par le joueur
  int pos;
  // verification de l'entrée du joueur
  int verif;

  // initialisation du plateau
  init(plateau);
  // Affichage du plateau pour la première fois
  affichage(plateau);

  // Tant que la partie n'est pas finie
  while (finie == -1) {
    // Joueur du tour ?
    // Si joueur = 1, on passe au joueur 2, si joueur = 2, joueur > 1 donc
    // joueur = 1.
    if (joueur <= 1) 
	{
      joueur = joueur + 1;
    } 
	else 
	{
      joueur = 1;
    }
    printf("\nC'est au joueur %d de jouer !\n", joueur);

    // On demande une colonne au joueur du tour
    // Pour faciliter la compréhension de l'utilisateur, on lui demande un
    // numéro de colonne "décalé" par rapport au fonctionnement de C. On
    // rectifie la faute plus tard.
    printf(
        "Entrez une colonne (entre 1 et 5) dans laquelle mettre la pièce :\n");
    scanf("%d", &pos);

    // On vérifie que l'entrée soit bien un entier entre 1 et 5
    while (pos <= 0 || pos >= 6) {
      affichage(plateau);
      printf("Veuillez entrer un numéro de colonne valide !\n");
      scanf("%d", &pos);
    }

    // Maintenant qu'on a une valeurs acceptable pour la fonction jouer, on peut
    // l'utiliser et verifier que la colonne ne soit pas pleine Si jouer renvoie
    // autre chose que 1 (erreur) on doit recommencer toutes les vérifications
    verif = jouer(plateau, joueur, pos - 1);
    while (verif != 1) {
      scanf("%d", &pos);

      while (pos <= 0 || pos >= 6) {
        affichage(plateau);
        printf("Veuillez entrer un numéro de colonne valide !\n");
        scanf("%d", &pos);
      }

      verif = jouer(plateau, joueur, pos - 1);
    }

    // On affiche le plateau pour montrer la progression du jeu une fois la
    // colonne entrée valide
    affichage(plateau);

    // on vérifie tout de suite si l'action donne lieu à une victoire
    // Si finie = -1 (ce que renvoie aGagner quand la partie continue), on reste
    // dans le while, sinon la partie est finie et aGagner à déjà afficher le
    // vainqueur.
    finie = aGagne(plateau);
  }
}

// Fin des fonction gérants le puissance 4

/*!
\fn int main (int argc, char** argv)
\author Charrier Simon
\version 1
\date 12 novembre 2023
\brief Menu
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
*/
int main(int argc, char ** argv) 
{

	// Définition
	int verif;
	int choix;
	int i;
	int tableau[TAILLE];
	int tableau2[TAILLE];	
	int plateau[5][5];	
	char texte[TAILLE];	

	// Menu
	printf("----------------------------------\n");
	printf("---------------Menu---------------\n");
	printf("----------------------------------\n");
	printf("----Quelle fonction utiliser ?----\n");
	printf("----------------------------------\n");
	printf("- 1. Inversion                   -\n");
	printf("- 2. Somme                       -\n");
	printf("- 3. Tableau traversable         -\n");
	printf("- 4. Palindrome                  -\n");
	printf("- 5. Puissance 4                 -\n");
	printf("----------------------------------\n");
	printf("----------------------------------\n");

	verif = scanf("%d",&choix);

	if (verif!=1)
	{
		printf("Veuillez entrer une option valide\n");
		exit(ERROR);
	}
	else
	{
		switch (choix)
		{
			case 1 :

				printf("Inversion : \n");

				// Initialisation du tableau
				for (i = 0 ; i < TAILLE ; i++)
				{
					printf("Entrez l'élément %d du tableau d'entiers\n",i+1);
					verif = scanf("%d",&tableau[i]);
					if (verif != 1)
					{
						printf("Veuillez entrer un tableau valide\n");
						exit(ERROR);
					}
				}
				inversion(tableau);
				break;

			case 2 :

				printf("Somme : \n");

				// Initialisation des tableaux
				for (i = 0 ; i < TAILLE ; i++)
				{
					printf("Entrez l'élément %d du premier tableau d'entiers\n",i+1);
					verif = scanf("%d",&tableau[i]);
					if (verif != 1)
					{
						printf("Veuillez entrer un tableau valide\n");
						exit(ERROR);
					}
				}
				for (i = 0 ; i < TAILLE ; i++)
				{
					printf("Entrez l'élément %d du second tableau d'entiers\n",i+1);
					verif = scanf("%d",&tableau2[i]);
					if (verif != 1)
					{
						printf("Veuillez entrer un tableau valide\n");
						exit(ERROR);
					}
				}
				somme(tableau,tableau2);
				break;
			
			case 3 :

				printf("Tableau traversable : \n");
				for (i = 0 ; i < TAILLE ; i++)
				{
					printf("Entrez l'élément %d du tableau d'entiers\n",i+1);
					verif = scanf("%d",&tableau[i]);
					if (verif != 1)
					{
						printf("Veuillez entrer un tableau valide\n");
						exit(ERROR);
					}
				}
				tableauTraversable(tableau);
				break;
			
			case 4 :

				printf("Palindrome : \n");
				printf("Entrez le mot de %d lettres à tester : \n",TAILLE);
				scanf("%s",texte);	
				if (strlen(texte) == TAILLE)
				{
					palindrome(texte);
					break;
				}
				else
				{
					printf("Veuillez entrer le bon nombre de charactères.\n");
					exit(ERROR);
				}
			
			case 5 :

				printf("Puissance 4 :\n");
				tourDeJeu(plateau);
				break;


		}
	}
	return (0);
}
