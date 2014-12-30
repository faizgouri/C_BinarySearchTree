
#ifndef BST_H_
#define BST_H_

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "data.h"
#include "stack.h"
#include "queue.h"

// create a new leaf and return it
struct leaf* createLeaf(struct data *d);

// create a new Tree
struct tree* createTree();

// Insert a new node into tree
void insertBst(struct tree *t,struct data *d);
void insertBst_r(struct leaf* current,struct leaf* newLeaf);

// Print all the node of Tree in InOrder sequence
void inOrderBst(struct tree *t);
void inOrderBst_r(struct leaf *current);

// Find out sum of all the nodes in tree
float totalSum(struct tree *t);
float totalSum_r(struct leaf* current);

//
void breathFirstBst(struct tree *t); 

// Print all the nodes of tree in PreOrder sequence
void preOrderBst(struct tree *t);
void preOrderBst_r(struct leaf *lf);

// Print all the nodes of Tree in PostOrder sequence
void postOrderBst(struct tree *t);
void postOrderBst_r(struct leaf *lf);

// recursively find out the node with largest value and return it
struct data* getMaxData(struct tree *tr);
struct data* getMaxData_r(struct leaf* lf);

// recursively find out the node with smallest value and return it
struct data* getMimData(struct tree *tr);
struct data* getMimData_r(struct leaf* lf);

// return height of BST
int getBstHeight(struct tree *tr);
int getBstHeight_r(struct leaf* lf);

// Print out all of the elements whose sum is greater than begin and less than end in inOrde sequence 
void printInRange(struct tree *tr, float begin, float end);
void printInRange_r(struct leaf* lf, float begin,float end);

// Check whether BST is a complete BST (all of the leaves terminate at the same level)
int isCompleteBst(struct tree *tr);
int isCompleteBst_r(struct leaf* lf);

// Check Whether BST is a Full BST (every node has 2 children except for the leaves)
int isFullBst(struct tree *tr);
int isFullBst_r(struct leaf *lf);

// Create a mirror image of BST
void reverseBST(struct tree *t);
void reverseBST_r(struct leaf *lf);

// return sum of all the leaves of BST
float sumLeaves(struct tree *t);
float sumLeaves_r(struct leaf *lf);

// Print BST in Breadth First Order
void printBreadthFirstSearch(struct tree *t);

// Print BST in Depth First Order
void printDepthFirstSearch(struct tree *t);

// Free all the memory allocated by tree
void cleanBST(struct tree *t);
void cleanBST_r(struct leaf *lf);

int isBST(struct tree *t);
float isBST_r(struct leaf *n);

#endif
