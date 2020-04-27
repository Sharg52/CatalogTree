#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "functions.h"

int main()
{
	printf("START");
	NODE* root = NULL;
	char path[1000]= "C:\\Users\\jenya.sharunov\\Documents\\test";
	char fname[] = "something.txt";
	root = Create(path);
	root = MakeTree(path, root);
	Print(root, 0);
	Search(root, fname,0,NO);
	root = DelTree(root);
	printf("l;ol");
	return 0;
}
