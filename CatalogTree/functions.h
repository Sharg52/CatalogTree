#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Node
{
	struct Node* child;
	struct Node* brother;
	char* data;
}NODE;

enum Flag { YES, NO };
NODE* Create(char* s);
NODE* AddBrother(NODE* oldbrother, char* s);
NODE* AddChild(NODE* par, char* s);
enum Flag Search(NODE* root, char* fname, int level);
void Print(NODE* root, int level);
NODE* MakeTree(char* path, NODE* root);
NODE* DelTree(NODE* root);


#endif 