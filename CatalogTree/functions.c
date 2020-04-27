#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <io.h>
#include "functions.h"


NODE* Create(char* s)
{
	NODE* root = (NODE*)malloc(sizeof(NODE));
	root->data = (char*)malloc(strlen(s) + 1);
	strcpy(root->data, s);
	root->brother = NULL;
	root->child = NULL;
	return root;
}

NODE* AddBrother(NODE* oldbrother, char* s, long int size)
{
	NODE* p = oldbrother;
	while (p && p->brother)
		p = p->brother;
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = (char*)malloc(strlen(s) + 1);
	strcpy(temp->data, s);
	temp->brother = NULL;
	temp->child = NULL;
	temp->size = size;
	if (p)
		p->brother = temp;
	else
		p = temp;
	return oldbrother;
}

NODE* AddChild(NODE* par, char* s, long int size)
{
	if (par->child)
		par->child = AddBrother(par->child, s,size);
	else
	{
		
		par->child = (NODE*)malloc(sizeof(NODE));
		par->child->data = (char*)malloc(strlen(s) + 1);
		strcpy(par->child->data, s);
		par->child->child = NULL;
		par->child->brother = NULL;
		par->child->size = size;
	}
	return par;
}
enum Flag Search(NODE* root, char* fname,enum flag flag)
{
	NODE* p = root;
	
	if (p->child)
	{
		flag = Search(p->child, fname, NO);
		if (flag == YES)
		{
			printf("%s\n", p->data);
			flag = NO;
		}
	}
	if (p->brother)
		flag=Search(p->brother, fname,flag);
	if (strcmp(p->data, fname) == 0)
	{
		flag = YES;
	}
	return flag;
	
}
int Quantity(NODE* root, int amount)
{
	NODE* p = root;
	if (p->child)
	{
		amount = Quantity(p->child, 0);
		printf("\n%s = %d\n", p->data,amount);
	}
	if (p->brother)
		amount += Quantity(p->brother, amount);
	if (p->data[strlen(p->data)-1] != '\\')amount += 1;
	return amount;
}
void More(NODE* root,long int size, char* data)
{
	NODE* p = root;
	if (p->data[strlen(p->data) - 1] == '\\')strcpy(data, p->data);
	if(p->size>size && p->data[strlen(p->data) - 1] != '\\')
		printf("%s%s\n",data,p->data);
	if (p->child)
		More(p->child,size,data);
	if (p->brother)
		More(p->brother,size,data);
}
void Print(NODE* root, int level)
{
	NODE* p = root;
	for (int i = 0; i < level; i++)
	{
		printf("   ");
	}
	if (p->data[strlen(p->data) - 1] != '\\')printf("%s=%ld byte\n", p->data, p->size);
	else printf("%s\n",p->data);
	
	if (p->child)
		Print(p->child, level + 1);
	if (p->brother)
		Print(p->brother, level);
}
NODE* Go(char* path, NODE* root)
{
	struct _finddata_t fc;
	intptr_t  hFile = _findfirst(path, &fc);
	if (!hFile)
		return root;
	_findnext(hFile, &fc);
	while (_findnext(hFile, &fc) == 0)
	{
		if (fc.attrib & _A_SUBDIR)
		{
			char fname1[1000];
			strcpy(fname1,path);
			fname1[strlen(fname1)-1] = NULL;
			strcat(fname1, fc.name);
			strcat(fname1, "\\");
			root = AddChild(root, fname1,fc.size);
			char path1[1000];
			strcpy(path1, path);
			strcpy(path1 + strlen(path1) - 1, fc.name);
			strcat(path1, "\\*");
			NODE* p = root->child;
			while (p->brother)
				p = p->brother;
			p = Go(path1, p);
		}
		else
		{
			root = AddChild(root, fc.name, fc.size);
		}
	}
	return root;
}

NODE* MakeTree(char* path, NODE* root)
{
	strcat(path, "*");
	root = Go(path, root);
	return root;
}

NODE* DelTree(NODE* root)
{
	NODE* p = root;
	if (p->brother)
		p->brother = DelTree(p->brother);
	if (p->child)
		p->child = DelTree(p->child);
	free(p->data);
	free(p);
	return NULL;
}