/**
 * \file matrice.h
 */

#ifndef __MATRIX__
#define __MATRIX__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef double Elt;
typedef struct matrix
{
    Elt * mat;
    int nb_rows, nb_columns;
    bool valide;
} Matrix;


Matrix newMatrix(int nb_rows, int nb_columns);
Elt getElt(Matrix *m, int row, int column);
void setElt(Matrix *m, int row, int column, Elt val);
void deleteM(Matrix *m);
Matrix copier_matrice(Matrix *m);
bool isTriangular(Matrix *m);
bool isSymetric(Matrix *m);
bool isSquare(Matrix *m);
Matrix transpose(Matrix *m);
Matrix addition(Matrix *m1, Matrix *m2);
Matrix multiplication(Matrix *m1, Matrix *m2);
Matrix mult_scalar(Elt elt, Matrix *m);
Matrix comatrice(Matrix *m, int no_row, int no_column);
Elt calcul_determinant_recursif(Matrix *m);
Elt calcul_determinant_triangulaire(Matrix *m);
void soustraction_gauss_inverse(Matrix *tmp_old,Matrix * old,
        Matrix *tmp_new,Matrix *new,int ligne_pivot,int colonne_pivot,int j);
void reduire_pivot_inverse(Matrix *m,Matrix *inverse,Elt val_pivot,int ligne_pivot);
void echanger_ligne(Matrix *m,int ligne1, int ligne2);
Matrix matrice_inverse_gauss(Matrix *);
Matrix matrice_inverse_cofacteur(Matrix *);
void resolution_sys_lineaire(Matrix *m,Matrix *new);
void decomposition_plu(Matrix *m, Matrix *p, Matrix *l, Matrix *u);
void valeurs_propres(Matrix *m,int* nb, Elt *v1, Elt *v2);

#endif
