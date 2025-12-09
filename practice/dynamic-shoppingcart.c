/*
Author: Pavel Soshenko Gnezdilov
Date: 27/11/2025
The program maintains a shopping cart for which the memory is dynamically
allocated and reallocated based on the number of incoming items
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product Product;

// function prototypes
Product *allocate();
Product *reallocate(Product *);
void storeProducts(Product *);
