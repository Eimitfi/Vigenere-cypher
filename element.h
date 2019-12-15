#ifndef ELEMENT_H
#define ELEMENT_H
#define DIM 26
#define FALSE 0
#define TRUE 1
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "list.h"
#include <time.h>
#include "info.h"
void riempi_matrice(char matrice[][DIM]);
list get_testo(int * counter);
list get_chiave();
list make_chiave(int counter);
int trova_colonna(char ch, char matrice[][DIM]);
int trova_riga(char ch, char matrice[][DIM]);
list algoritmo_cifratura(list testo, list chiave);
list algoritmo_decifratura(list testo_cifrato, list chiave);
int trova_colonna_decifrare(char ch,int riga, char matrice[][DIM]);
#endif
