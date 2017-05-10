/**
 * \file io.c
 * \Author Lucas SCHOTT
 */

#include "io.h"

//in
///////////////////////////////////


/**
 * \fn Matrix scanMatrix(void)
 * \brief fonction creant une matrice en demandant la taille
 * a l'utilisateur ainsi que les valeur des elements de la
 * matrice
 * \return la nouvelle matrice
 * \post creation d'un ematrice => utilisation de delete(Matrix *)
 */
Matrix scanMatrix(void)
{
    Matrix m;
    int nb_rows,nb_columns;
    printf("nb de lignes : ");
    if(scanf("%d", &nb_rows)==0)
    {
        fprintf(stderr, "caractere non reconnue\n");
        m.valide=false;
        return m;
    }
    printf("nb de colonnes : ");
    if(scanf("%d", &nb_columns)==0)
    {
        fprintf(stderr, "caractere non reconnue\n");
        m.valide=false;
        return m;
    }

    m = newMatrix(nb_rows, nb_columns);
    int i,j;
    Elt elt;
    for(i=0; i<nb_rows; i++)
    {
        for(j=0; j<nb_columns; j++)
        {
            printf("element %d*%d : ", i, j);
            if(scanf("%lf", &elt) == 0)
            {
                fprintf(stderr, "caractere non reconnue\n");
                m.valide=false;
                return m;
            }
            setElt(&m,i,j, elt);
        }
    }
    while(getchar()!='\n');
    return m;
}

/**
 * \brief scan la matrice colonne
 */
Matrix scanColonne(int nb_rows)
{
    printf("nb de lignes : %d\n", nb_rows);
    Matrix m = newMatrix(nb_rows, 1);
    int i;
    Elt elt;
    for(i=0; i<nb_rows; i++)
    {
        printf("element %d*%d : ", i, 0);
        if(scanf("%lf", &elt) == 0)
        {
            fprintf(stderr, "caractere non reconnue\n");
            m.valide=false;
            return m;
        }
        setElt(&m,i,0, elt);
    }
    while(getchar()!='\n');
    return m;
}


/**
 * \fn int choixMethodeInversion(void)
 * \brief fonction proposant à l'utilisateur le choix entre
 * la methode par pivot de gauss ou la methode par la comatrice
 * \return le choix de la methode
 * 1 : pivot de gauss
 * 2 : comatrice
 */
int choixMethodeInversion(void)
{
    int choix;
    do
    {
        printf("1 : pivot de gauss\n");
        printf("2 : comatrice\n");
        printf("choix methode : ");
        choix=getchar()-48;
        while(getchar()!='\n');
    }
    while(choix!=1 && choix!=2);
    return choix;
}


/**
 * \fn int choixMethodeDeterminant(void)
 * \brief fonction proposant à l'utilisateur le choix entre
 * la methode recursive ou par triangularisation
 * \return le choix de la methode
 * 1 : methode recursive
 * 2 : par la forme triangulaire
 */
int choixMethodeDeterminant(void)
{
    int choix;
    do
    {
        printf("1 : methode recursive\n");
        printf("2 : par la forme triangulaire\n");
        printf("choix methode : ");
        choix=getchar()-48;
        while(getchar()!='\n');
    }
    while(choix!=1 && choix!=2);
    return choix;
}


//out
///////////////////////////////////


/**
 * \fn void prinMatrix(Marix *m)
 * \brief fonction qui affiche la matrice donnée
 * \param m pointeur sur la matrice a afficher
 * \return void
 */
void printMatrix(Matrix *m)
{
    if(!m->valide)
    {
        printf("la matrice est invalide\n");
        return;
    }
    int i,j;
    for(i=0; i<m->nb_rows; i++)
    {
        for(j=0; j<m->nb_columns; j++)
        {
            printf(" %.2f ", getElt(m,i,j));
        }
        putchar('\n');
    }
    return ;
}


/**
 * \fn void printOpMatrix(char *op, Matrix *m1, Matrix *m2, Matrix *m3)
 * \brief fonction qui affiche une operation entre deux matrices
 * ainsi que le resultat, au format :
 * m1
 *  op
 * m2
 *  =
 * m3
 * \param op une chaine de caractere representant l'operation
 * typiquement "+" ou "*"
 * \param m1 pointeur sur la premiere operande
 * \param m2 pointeur sur la deuxieme operande
 * \param m3 pointeur sur la matrice resultat de l'operation
 * \return void
 */
void printOpMatrix(char *op, Matrix *m1, Matrix *m2, Matrix *m3)
{
    printMatrix(m1);
    printf(" %s\n", op);
    printMatrix(m2);
    printf(" =\n");
    printMatrix(m3);
    return ;
}


/**
 * \fn void prinChoix(void)
 * \brief fonction affichant la liste des operations disponibles
 * au debut du programme
 * \return void
 */
void printChoixMain(void)
{
    printf("0 : quitter\n");
    printf("1 : transpose d'une matrice\n");
    printf("2 : addition de deux matrices\n");
    printf("3 : multiplication de deux matrices\n");
    printf("4 : calcul du determinant\n");
    printf("5 : inversion d'une matrices\n");
    printf("6 : resolution d'un systeme lineaire carre\n");
    printf("7 : decomposition PLU\n");
    printf("8 : calcul de valeur propre\n");
    printf("choix operation : ");
    return;
}

