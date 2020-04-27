#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Node
{
	struct Node* child;
	struct Node* brother;
	char* data;
	long int size;
}NODE;

enum Flag { YES, NO };
NODE* Create(char* s);
NODE* AddBrother(NODE* oldbrother, char* s, long int size);
int Quantity(NODE* root, int amount);
NODE* AddChild(NODE* par, char* s, long int size);
void More(NODE* root,long int size,char* data);
enum Flag Search(NODE* root, char* fname,enum flag flag);
void Print(NODE* root, int level);
NODE* MakeTree(char* path, NODE* root);
NODE* DelTree(NODE* root);


#endif 