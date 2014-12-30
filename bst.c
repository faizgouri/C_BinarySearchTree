#include "bst.h"
#include "data.h"
#include "queue.h"
#include "stack.h"
#include <unistd.h>

void printDepthFirstSearch(struct tree *t)
{
	// if Tree is Empty, return
	if(t->root == NULL)
	{
		printf("Tree is Empty !!\n");
		return;
	}

	//otherwise, create a new stack and push root into stack 
	struct stack *s = createStack();
        pushStack(s, t->root);
	// iterate until stack is not empty
	while(!isEmptyStack(s))
        {
		// print Top element of stack, pop it and push its left and right if they are not NULL
                struct leaf *current = topStack(s);
                printData(current->dta);
		popStack(s);
		if(current->right != NULL)
		{
			pushStack(s, current->right);
		}
		if(current->left != NULL)
		{
			pushStack(s, current->left);
		}
	}
	// clean stack
        cleanStack(s);
}

int isCompleteBst(struct tree *tr)
{
	// if tree is empty, return 0
        if(tr->root == NULL)
	{
		printf("Tree is empty !!\n");
		return 0;
	}
	// otherwise call recursive function to check whether tree is Complete BST
	return (isCompleteBst_r(tr->root));
}

int isCompleteBst_r(struct leaf* lf)
{
	// if it is a leaf node, return 1
	if(lf->left == NULL && lf->right == NULL)
	{
		return 1;
	}
	// otherwise check whether current node's left subTree an right subTree are Complete or not
	if((lf->left != NULL && lf->right != NULL))
	{
		// if height of leftSubTree and right subTree is not equal, it is not Complete BST, hence then return 0
		if(getBstHeight_r(lf->left) != getBstHeight_r(lf->right))
		{
			return 0;
		}
		// otherwise call recursive function to check whether left and right subTrees are Complete BST
		else
		{
			return (isCompleteBst_r(lf->left) && (isCompleteBst_r(lf->right)));
		}
	}
	return 1;
}

void printBreadthFirstSearch(struct tree *t)
{
	// if tree is empty, return
	if(t->root == NULL)
	{
		printf("Tree is Empty !!\n");
		return;
	}
	// otherwise, create a Queue and push root node into Queue
	struct queue *q = createQueue();
	pushQueue(q, t->root);
	//iterate until Q is not empty
	while(!isEmptyQueue(q))
	{
		// Take top element of Q, pop it from Queue, print it and then push its left and right subTrees if exist
		struct leaf *current = topQueue(q);
		printData(current->dta);
		popQueue(q);
		if(current->left != NULL)
		{
			pushQueue(q, current->left);
		}
		if(current->right != NULL)
		{
			pushQueue(q, current->right);
		}
	}
	cleanQueue(q);
}

void cleanBST(struct tree *t)
{
	// if Tree is empty, just free Tree and return
	if(t->root == NULL)
	{
		free(t);
		return;
	}
	// otherwise,free memory occupied by all the nodes and then free Tree
	cleanBST_r(t->root);
	free(t);
}

void cleanBST_r(struct leaf *lf)
{
	// if node is a Leaf node, free data and leaf pointer
	if(lf->left == NULL && lf->right == NULL)
	{
		free(lf->dta);
		free(lf);
		return;
	}
	// otherwise call recursive clean function for its left and/or right subtrees
	if(lf->left != NULL)
	{
		cleanBST_r(lf->left);
	}
	if(lf->right != NULL)
	{
		cleanBST_r(lf->right);
	}
	// free node's data and leaf pointer
	free(lf->dta);
	free(lf);
}

float sumLeaves(struct tree *t)
{
	if(t->root == NULL)
	{
		return 0;
	}
	return (sumLeaves_r(t->root));
}

float sumLeaves_r(struct leaf *lf)
{
	if(lf == NULL)
	{
		return 0;
	}
	// if leaf node, return sumData
	if(lf->left == NULL && lf->right == NULL)
	{
		return (sumData(lf->dta));
	}
	// otherwise return sum of leftSubtree and right subTree's leaves data
	return (sumLeaves_r(lf->left) + sumLeaves_r(lf->right));
}

void reverseBST(struct tree *t)
{
	if(t->root == NULL)
	{
		return;
	}
	else
	{
		reverseBST_r(t->root);
	}
}

void reverseBST_r(struct leaf *lf)
{
	if(lf == NULL)
	{
		return;
	}
	reverseBST_r(lf->left);
	reverseBST_r(lf->right);
	struct leaf *temp = lf->left;
        lf->left = lf->right;
        lf->right = temp;
}

int isFullBst(struct tree *tr)
{
	if(tr->root == NULL)
	{
		return 1;
	}
	else
	{
		return (isFullBst_r(tr->root));
	}

}
int isFullBst_r(struct leaf *lf)
{
	if((lf->left == NULL && lf->right != NULL) || (lf->left != NULL && lf->right == NULL))
	{
		return 0;
	}
	else if(lf->left == NULL && lf->right == NULL)
	{
		return 1;
	}
	return (isFullBst_r(lf->left) && isFullBst_r(lf->right));
}

void printInRange(struct tree *tr, float begin, float end)
{
	if(tr->root == NULL)
	{
		printf("Empty Tree \n");
		return;
	}
	printInRange_r(tr->root, begin, end);
}

void printInRange_r(struct leaf* lf, float begin,float end)
{
	if(lf == NULL)
	{
		return;
	}
	printInRange_r(lf->left, begin, end);
	if(sumData(lf->dta) > begin && sumData(lf->dta) < end)
	{
		printData(lf->dta);
	}
	printInRange_r(lf->right, begin, end);
}

int getBstHeight(struct tree *tr)
{
	if(tr->root == NULL)
	{
		return 0;
	}
	else
	{
		return getBstHeight_r(tr->root);
	}
}
int getBstHeight_r(struct leaf* lf)
{
	if(lf->left == NULL && lf->right == NULL)
	{
		return 1;
	}
	int lh = 0;
	int rh = 0;
	if(lf->left != NULL)
	{
		lh = getBstHeight_r(lf->left);
	}
	if(lf->right != NULL)
	{
		rh = getBstHeight_r(lf->right);
	}
	if(lh > rh)
	{
		return (1 + lh);
	}
	else
	{
		return (1 + rh);
	}
}

struct data* getMimData(struct tree *tr)
{
	if(tr->root == NULL)
	{
		return NULL;
	}
	else
	{
		return (getMimData_r(tr->root));
	}
}

struct data* getMimData_r(struct leaf* lf)
{
	if(lf->left == NULL)
	{
		return lf->dta;
	}
	if(sumData(lf->dta) == sumData(lf->left->dta))
	{
		struct data *temp = getMimData_r(lf->left);
		if(sumData(lf->dta) == sumData(temp))
		{
			return lf->dta;
		}
	}
	return getMimData_r(lf->left);
}

struct data* getMaxData(struct tree *tr)
{
	if(tr->root == NULL)
	{
		return NULL;
	}
	else
	{
		return (getMaxData_r(tr->root));
	}
}

struct data* getMaxData_r(struct leaf* lf)
{
	if(lf->right == NULL)
	{
		return lf->dta;
	}
	else
	{
		return (getMaxData_r(lf->right));
	}
}

void preOrderBst(struct tree *t)
{
	if(t->root == NULL)
        {
                printf("Empty Tree\n");
        }
        else
        {
                preOrderBst_r(t->root);
        }
}

void preOrderBst_r(struct leaf *lf)
{
	if(lf == NULL)
        {
                return;
        }
        else
        {
                printData(lf->dta);
		preOrderBst_r(lf->left);
                preOrderBst_r(lf->right);
        }
}

void postOrderBst(struct tree *t)
{
	if(t->root == NULL)
        {
                printf("Empty Tree\n");
        }
        else
        {
                postOrderBst_r(t->root);
        }
}

void postOrderBst_r(struct leaf *lf)
{
	if(lf == NULL)
        {
                return;
        }
        else
        {
                inOrderBst_r(lf->left);
                inOrderBst_r(lf->right);
		printData(lf->dta);
        }
}

struct leaf* createLeaf(struct data *d)
{
  struct leaf* maple = malloc(sizeof(struct leaf));
  maple->right = NULL;
  maple->left = NULL;
  maple->dta = d;
  return maple;
}

struct tree* createTree()
{
  struct tree* oak = malloc(sizeof(struct tree));
  oak->root = NULL;
  return oak;
}

void insertBst(struct tree *t,struct data *d)
{
	struct leaf *l = createLeaf(d);
	if(t->root == NULL)
	{
		t->root = l;
	}
	else
	{
		insertBst_r(t->root, l);
	}
}

void insertBst_r(struct leaf* current,struct leaf* newLeaf)
{
	if(sumData(newLeaf->dta) > sumData(current->dta))
	{
		if(current->right == NULL)
		{
			current->right = newLeaf;
		}
		else
		{
			insertBst_r(current->right, newLeaf);
		}
	}
	else
	{
		if(current->left == NULL)
		{
			current->left = newLeaf;
		}
		else
		{
			insertBst_r(current->left, newLeaf);
		}
	}
}
void inOrderBst(struct tree *t)
{
	if(t->root == NULL)
        {
                printf("Empty Tree\n");
        }
        else
        {
                inOrderBst_r(t->root);
        }

}
void inOrderBst_r(struct leaf *current)
{
	if(current == NULL)
	{
		return;
	}
	else
	{
		inOrderBst_r(current->left);
		printData(current->dta);
		inOrderBst_r(current->right);
	}
}
float totalSum(struct tree *t)
{
	return totalSum_r(t->root);

}

float totalSum_r(struct leaf* current)
{
	float sum = 0;
        if(current == NULL)
        {
                return 0;
        }
        else
        {
                sum = sum + sumData(current->dta) + totalSum_r(current->left) + totalSum_r(current->right);
        }
	return sum;
}

int isBST(struct tree *t)
{

	return((isBST_r(t->root) > isBST_r(t->root->left)) && (isBST_r(t->root) <= isBST_r(t->root->right)));
}

float isBST_r(struct leaf *n)
{

	if(n == NULL)
	{
		return 1;
	}
	else if(sumData(n->left->dta) <= sumData(n->dta) && sumData(n->dta) <= sumData(n->right->dta))
        {
		return sumData(n->dta);
	}
	else
	{
		return (isBST_r(n->left) && isBST_r(n->right));
	}
}
