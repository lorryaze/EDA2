#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define DEBUG false
#define debugf if (DEBUG) printf
#define MOD 1000000007
#define mset(x, y) memset(&x, (y), sizeof(x));
typedef long long ll;
typedef unsigned long long ull;

#define foreach(item, array) \
    for(int keep=1, \
            count=0,\
            size=sizeof (array)/sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array)+count; keep; keep = !keep)
#define swap(x, y, T) do { T tmp = (x); (x) = (y); (y) = tmp; } while(0)
#define NEW(type, n) ( (type *) malloc(1 + (n) * sizeof(type)) )
#define Allocate(type) ( (type *) malloc(sizeof(type)) )
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))
#define max(a, b) (a > b) ? a : b
#define min(a, b) (a < b) ? a : b

// Implementation of a binary search tree (BST)

typedef struct BSTNode
{
	char info;
	int level;
	struct BSTNode *left, *right;
} bstNode;

void initialize(bstNode *root)
{
	root = NULL;
}

int isEmpty(bstNode *root)
{
	return root == NULL;
}

bstNode *search(bstNode *root, char info)
{
	if(!root) return NULL;
	if(root->info == info)
		return root;

	if(info < root->info)
		return search(root->left, info);
	else
		return search(root->right, info);
	
}

void inOrder(bstNode *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		printf("%c ", root->info);
		inOrder(root->right);
	}
}

bstNode *insert(bstNode *root, char info)
{
	if(!root)
	{
		root = Allocate(bstNode);
		root->left = root->right = NULL; root->info = info;
		root->level = 0;
	}
	else
	{
		if(info < root->info)
			root->left = insert(root->left, info);
		else
			root->right = insert(root->right, info);
	}
	return root;
}

bstNode *removeNode(bstNode *root, char info)
{
	if(!root)
		return NULL;
	else if(info < root->info)
		root->left = removeNode(root->left, info);
	else if(info > root->info)
		root->right = removeNode(root->right, info);
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if(root->left == NULL)
		{
			bstNode *tmp = root;
			root = root->right;
			free(tmp);
		}
		else if(root->right == NULL)
		{
			bstNode *tmp = root;
			root = root->left;
			free(tmp);
		}
	}
	return root;
}

int count(bstNode *root)
{
	if(!root)
		return 0;
	else
	{
		return 1 + count(root->left) + count(root->right);
	}
}

int height(bstNode *root)
{
	if(!root)
		return -1;
	int left = height(root->left);
	int right = height(root->right);

	if(left > right)
		return left + 1;
	else
		return right + 1;
}

int getLevelUtil(bstNode *root, char info, int level)
{
	if(!root) return 0;
	if(root->info == info)
		return level;
	int downlevel = getLevelUtil(root->left, info, level+1);
	if(downlevel != 0)
		return downlevel;
	downlevel = getLevelUtil(root->right, info, level+1);
	return downlevel;
}

int getLevel(bstNode *root, char info) // Calcula o level da BST
{
	return getLevelUtil(root, info, 1);
}

int subNodesLeft(bstNode *root)
{
	if(!root)
		return 0;
	return count(root->left);
}

bstNode *rotRight(bstNode *root)
{
	bstNode *x = root->left;
	root->left = x->right;
	x->right = root;
	return x;
}

bstNode *rotLeft(bstNode *root)
{
	bstNode *x = root->right;
	root->right = x->left;
	x->left = root;
	return x;
}

char selectR(bstNode *root, int k)
{
	if(!root)
		return 0;
	int t = (root->left == NULL) ? 0 : subNodesLeft(root);
	if(t > k)
		return selectR(root->left, k);
	if(t < k)
		return selectR(root->right, k-t-1);

	return root->info;
}

bstNode *partR(bstNode *root, int k)
{
	int t = (root->left == NULL) ? 0 : subNodesLeft(root);
	if(t > k)
	{
		root->left = partR(root->left, k);
		root = rotRight(root);
	}
	if(t < k)
	{
		root->right = partR(root->right, k-t-1);
		root = rotLeft(root);
	}
	return root;
}

int main()
{
	bstNode *root = NULL;
	root = insert(root, 'I');
	root = insert(root, 'H');
	root = insert(root, 'R');
	root = insert(root, 'S');
	root = insert(root, 'C');
	root = insert(root, 'E');
	root = insert(root, 'A');

	inOrder(root);
	printf("\n");
	// printf("Elementos totais da BST: %d\n", count(root));
	// printf("Altura da BST: %d\n", height(root));
	// printf("Enter a value: ");
	// char x;
	// scanf("%c", &x);
	// printf("Level of element is: %d\n", getLevel(root, x));
	// printf("Nodes in left tree: %d\n", subNodesLeft(root));
	root = partR(root, 4);
	return 0;
}

