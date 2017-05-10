/**
 * \file main.c
 * \Author Lucas SCHOTT
 */

#include "matrice.h"
#include "io.h"

/**
 * \fn int main_choixOperation(void)
 * \brief fonction qui permet de choisire l'operation a realiser
 * fonction de lecture et d'affichage
 * \return un entier representant le choix effectué
 */
int main_choixOperation(void)
{
    int choix;
    do
    {
        putchar('\n');
        printChoixMain();
        choix=getchar()-48;
        while(getchar()!='\n');
    }
    while( choix<0 || choix>8 );
    return choix;
}


/**
 * \fn void main_transpose(void)
 * \brief fonction calculant la transposé d'une matrice
 * predefinit ou a définir par l'utilisateur
 * fonction de lecture de d'affichage
 * \return void
 */
void main_transpose(void)
{
    printf("\nmatrice a transposer :\n");
    Matrix m1 = scanMatrix();
    Matrix m2;

    if(m1.valide)
    {
        //matrice no1
        printf("\ntranspose de \n");
        printMatrix(&m1);
        printf(" =\n");
        
        //transposé de m1, matrice no2
        m2 = transpose(&m1);
        printMatrix(&m2);
    }

    //free
    deleteM(&m1);
    deleteM(&m2);
    return;
}


/**
 * \fn void main_addition(void)
 * \brief fonction calculant la somme de deux matrices
 * predefinit ou a définir par l'utilisateur
 * fonction de lecture de d'affichage
 * \return void
 */
void main_addition(void)
{
    //matrice no1
    printf("\nmatrice 1 :\n");
    Matrix m1 = scanMatrix();
    //matrice no2
    putchar('\n');
    printf("matrice 2 :\n");
    Matrix m2 = scanMatrix();
    Matrix m3;
    
    if(m1.valide && m2.valide)
    {
        //resultat matrice no3
        m3 = addition(&m1, &m2);
        //affichage
        putchar('\n');
        printOpMatrix("+", &m1, &m2, &m3);
    }

    //free
    deleteM(&m1);deleteM(&m2);deleteM(&m3);
    return;
}


/**
 * \fn void main_multiplication(void)
 * \brief fonction calculant le produit de deux matrices
 * predefinit ou a définir par l'utilisateur
 * fonction de lecture de d'affichage
 * \return void
 */
void main_multiplication(void)
{
    //matrice no1
    printf("\nmatrice 1 :\n");
    Matrix m1 = scanMatrix();
    //matrice no2
    putchar('\n');
    printf("matrice 2 :\n");
    Matrix m2 = scanMatrix();
    Matrix m3;
    
    if(m1.valide && m2.valide)
    {
        //resultat matrice no3
        m3 = multiplication(&m1, &m2);
        //affichage
        putchar('\n');
        printOpMatrix("*", &m1, &m2, &m3);
    }

    //free
    deleteM(&m1);deleteM(&m2);deleteM(&m3);
    return;
}



/**
 * \fn void main_calculDeterminant(int)
 * \brief fonction calculant le determinant d'une matrice
 * predefinit ou a définir par l'utilisateur
 * avec soit le technique du pivot de gauss
 * soit le technique des cofacteurs
 * fonction de lecture de d'affichage
 * \return void
 */
void main_calculDeterminant(int methode)
{
    Elt det=0;
    //matrice
    Matrix m = scanMatrix();
    printf("\nm1 %d*%d =\n", m.nb_rows, m.nb_columns);
    printMatrix(&m);

    if(m.valide)
    {
        switch(methode)
        {
            case 1:
                if(!isSquare(&m))
                {
                    fprintf(stderr,"la matrice n'est pas carré\n");
                }
                else
                {
                    det = calcul_determinant_recursif(&m);
                    printf("\ndeterminant : %.2f\n", det);
                }
                break;
            case 2:
                if(isTriangular(&m))
                {
                    det = calcul_determinant_triangulaire(&m);
                    printf("\ndeterminant : %.2f\n", det);
                }
                else
                {
                    fprintf(stderr,"\nla matrice n'est pas triangulaire\n");
                }
                break;
            default:
                break;
        }
    }

    //free
    deleteM(&m);
    return;
}


/**
 * \fn void main_inversion(int)
 * \brief fonction calculant l'inverse d'une matrice
 * predefinit ou a définir par l'utilisateur
 * avec soit le technique du pivot de gauss
 * soit le technique des cofacteurs
 * fonction de lecture de d'affichage
 * \return void
 */
void main_inversion(int methode)
{
    //matrice
    Matrix m1 = scanMatrix();
    printf("\nm1 %d*%d =\n", m1.nb_rows, m1.nb_columns);
    printMatrix(&m1);
    Matrix m2;

    if(m1.valide)
    {
        switch(methode)
        {
            case 1: //methode de gauss
                m2 = matrice_inverse_gauss(&m1);
                printf("\nmatrice inverse: %d*%d =\n", m2.nb_rows, m2.nb_columns);
                printMatrix(&m2);
                break;
            case 2: //methode matrice des cofacteurs
                m2 = matrice_inverse_cofacteur(&m1);
                printf("\nmatrice inverse: %d*%d =\n", m2.nb_rows, m2.nb_columns);
                printMatrix(&m2);
                break;
            default:
                break;
        }
    }

    //free
    deleteM(&m1);
    deleteM(&m2);
    return;
}


/**
 * \fn void main_system(void)
 * \brief fonction resolvant un systeme lineaire
 * sous forme d'une matrice
 * predefinit ou a définir par l'utilisateur
 * fonction de lecture de d'affichage
 * \return void
 */
void main_systeme_lineaire()
{
    //matrice no1
    printf("matrice du systeme lineaire :\n");
    Matrix m1 = scanMatrix();
    printf("\nm1 %d*%d =\n", m1.nb_rows, m1.nb_columns);
    printMatrix(&m1);
    putchar('\n');
    printf("matrice colonne :\n");
    Matrix m2 = scanColonne(m1.nb_rows);

    if(m1.valide && m2.valide)
    {
        resolution_sys_lineaire(&m1,&m2);
        printf("\nsolutions :\n");
        printMatrix(&m2);
    }

    //free
    deleteM(&m1);
    deleteM(&m2);
    return;
}


/**
 * \fn void main_decompositionPLU(void)
 * \brief fonction realisant une decomposition PLU
 * d'une matrice predefinit ou a définir par l'utilisateur
 * fonction de lecture de d'affichage
 * \return void
 */
void main_decompositionPLU()
{
    //matrice no1
    Matrix m1 = scanMatrix();
    printf("\nm1 %d*%d =\n", m1.nb_rows, m1.nb_columns);
    printMatrix(&m1);
    Matrix p;
    Matrix l;
    Matrix u;

    if(m1.valide)
    {
        decomposition_plu(&m1,&p,&l,&u);
        
        printf("\nP %d*%d =\n", p.nb_rows, p.nb_columns);
        printMatrix(&p);
        printf("\nL %d*%d =\n", l.nb_rows, l.nb_columns);
        printMatrix(&l);
        printf("\nU %d*%d =\n", u.nb_rows, u.nb_columns);
        printMatrix(&u);
    }

    //free
    deleteM(&m1);
    deleteM(&p);
    deleteM(&l);
    deleteM(&u);
    return;
}


/**
 * \fn void main_valeurPropre(void)
 * \brief fonction calculant les valeurs propre
 * d'une matrice predefinit ou a définir par l'utilisateur
 * fonction de lecture de d'affichage
 * \return void
 */
void main_valeurPropre()
{
    //matrice no1
    Matrix m1 = scanMatrix();
    printf("\nm1 %d*%d =\n", m1.nb_rows, m1.nb_columns);
    printMatrix(&m1);
    int nb;
    Elt a,b;

    if(m1.valide)
    {
        valeurs_propres(&m1,&nb,&a,&b);
        printf("\nIL y a %d valeur(s) propre(s) :\n",nb);
        if(nb>0)
            printf("%.2lf\n", a);
        if(nb==2)
            printf("et %.2lf\n", b);
    }

    //free
    deleteM(&m1);
    return;
}


int main(void)
{
    while(1)
    {
        switch(main_choixOperation())
        {
            case 1:
                main_transpose();
                break;
            case 2:
                main_addition();
                break;
            case 3:
                main_multiplication();
                break;
            case 4:
                main_calculDeterminant(choixMethodeDeterminant());
                break;
            case 5:
                main_inversion(choixMethodeInversion());
                break;
            case 6:
                main_systeme_lineaire();
                break;
            case 7:
                main_decompositionPLU();
                break;
            case 8:
                main_valeurPropre();
                break;
            case 0:
                exit(EXIT_SUCCESS);
                break;
            default:
                break;
        }
    }
    return 1;
}
