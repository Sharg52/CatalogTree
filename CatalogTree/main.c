#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "functions.h"

int main()
{
	printf("START\n");
	NODE* root = NULL;
	char path[1000]= "C:\\Users\\jenya.sharunov\\Documents\\test";//êàòàëîã â êîòîðîì èùåì ÔÎÐÌÀÒ ÎÁßÇÀÒÅËÜÍÎ ÒÀÊÎÉ
	strcat(path, "\\");
	char fname[] = "something.txt";//èñêîìûé ôàéë
	root = Create(path);
	root = MakeTree(path, root);
	printf("This is what your catologist looks like\n");
	Print(root, 0);
	printf("\nAll folders where the desired file is:\n\n");
	Search(root, fname,NO);
	printf("\nThe number of files in the folder:\n");
	Quantity(root,0);
	long int fsize = 2;//êàêîé  ðàçìåð â ÊÂ
	fsize *= 1024;
	printf("\nfiles larger than the specified size:\n");
	char data[1000];
	strcpy(data, root->data);
	More(root,fsize,data);
	root = DelTree(root);
	return 0;
}
