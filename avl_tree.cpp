#include <cstdlib>
#include <iostream>
#include <ctime>

#define N 25

using namespace std;

int rost;

struct vertex
{
	vertex *left;
 	vertex *right;
    int data;
    int balance;
};

void LL(vertex *&p){

	vertex *q;
	
	q = p -> left;
	p -> balance = 0;
	q -> balance = 0;
	p -> left = q -> right;
	q -> right = p;
	p = q;
}

void RR(vertex *&p){

	vertex *q;
	
	q = p -> right;
	p -> balance = 0;
	q -> balance = 0;
	p -> right = q -> left;
	q -> left = p;
	p = q;

}

void LR(vertex *&p){
	
	vertex *q, *r;

	q = p -> left;
	r = q -> right;

	if(r -> balance < 0){
		p -> balance = 1;
	}

	else{
		p -> balance = 0;
	}

	if(r -> balance > 0){
		q -> balance = -1;
	}

	else{
		q -> balance = 0;	
	}

	r -> balance = 0;
	p -> left = r -> right;
	q -> right = r -> left;
	r -> left = q;
	r -> right = p;
	p = r;

}

void RL(vertex *&p){

	vertex *q, *r;
	
	q = p -> right;
	r = q -> left;

	if(r -> balance > 0){
		p -> balance = -1;
	}
	else{
		p -> balance = 0;
	}

	if(r -> balance < 0){
		q -> balance = 1;
	}
	else{
		q -> balance = 0;
	}

	r -> balance = 0;
	p -> right = r -> left;
	q -> left = r -> right;
	r -> left = p;
	r -> right = q;
	p = r;
}

void add(vertex *&p, int data){

	if(p == NULL){
		p = new vertex;
		p -> data = data;
		p -> left = p -> right = NULL;
		p -> balance = 0;
		rost = 1;
	}
	else if(p -> data > data){
		add(p -> left, data);
		if(rost == 1){
			if(p -> balance > 0){
				p -> balance = 0;
				rost = 0;
			}
			else if(p -> balance == 0){
				p -> balance = -1;
			}
			else if(p -> left -> balance < 0){
				LL(p);
				rost = 0;
			}
			else{
				LR(p);
				rost = 0;
			}
		}
	}
	else{
		add(p -> right, data);
		if(rost == 1){
			if(p -> balance < 0){
				p -> balance = 0;
				rost = 0;
			}
			else if(p -> balance == 0){
				p -> balance = 1;
			}
			else if(p -> right -> balance > 0){
				RR(p);
				rost = 0;
			}
			else{
				RL(p);
				rost = 0;
			}
		}
	}
}



void avl(vertex *&root, int *a, int n){
     for(int i = 0; i < n; i++){
          	add(root, a[i]);
        }
}   

void obhod(vertex *p){
     if(p != NULL){
	     obhod(p->left);
	     printf("%3d ", p -> data);
	     obhod(p -> right);            
     }
}

int main(){

	srand(time(NULL));

	vertex *root = NULL;
	int array[N];

	for(int i = 0; i < N; i++){
		array[i] = rand()% 100;
	}

	avl(root, array, N);

	obhod(root);

}