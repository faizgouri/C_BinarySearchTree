#include <stdio.h>

#include "structures.h"
#include "bst.h"

int main(int argc,char* argv[])
{
	struct tree *t = createTree();
	insertBst(t, createData(11,2));
/*	insertBst(t, createData(12,11));
	insertBst(t, createData(8,1));
	insertBst(t, createData(9, 3));
	insertBst(t, createData(1, 1));
	insertBst(t, createData(11, 22));
	insertBst(t, createData(12, 36));
	inOrderBst(t);

	printf("sum = %f\n", totalSum(t));
	printf("PreOrder\n");
	preOrderBst(t);
	printf("PostOrder\n");
	postOrderBst(t);
	struct data *max = getMaxData(t);
	printf("max is ");
	printData(max);
	struct data *min = getMimData(t);
	printf("Min is ");
	printData(min);
	printf("height = %d\n", getBstHeight(t));
	printInRange(t, 1, 24);
	printf("isFullBst = %d\n", isFullBst(t));
	printf("Reverse\n");
	reverseBST(t);
	preOrderBst(t);
	printf("sumLeaves = %f\n", sumLeaves(t));
	printf("BFS Search\n");
	printBreadthFirstSearch(t);
	printf("DFS \n");
	printDepthFirstSearch(t);
	printf("isCompleteBst = %d\n", isCompleteBst(t));
	*/
	printf("isBST = %d\n",isBST(t));
	cleanBST(t);
	return 0;

}
