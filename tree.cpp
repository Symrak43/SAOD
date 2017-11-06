#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

using namespace std;

typedef int T;
enum nodeColor { BLACK, RED };

struct node {
	struct node *left;
	struct node *right;
	struct node *parent;
	nodeColor color;
	T data;
};


int main(){


	return 0;
}