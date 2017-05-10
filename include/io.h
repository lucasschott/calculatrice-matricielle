/**
 * \file io.h
 */

#ifndef __IO_MATRIX__
#define __IO_MATRIX__

#include <stdio.h>
#include "matrice.h"


//in
Matrix scanMatrix(void);
Matrix scanColonne(int nb_rows);
int choixMethodeInversion(void);
int choixMethodeDeterminant(void);

//out
void printMatrix(Matrix *m);
void printOpMatrix(char *op, Matrix *m1, Matrix *m2, Matrix *m3);
void printChoixMain(void);

#endif
