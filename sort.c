#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

double wtime(){
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max){
	return(double)rand() / (RAND_MAX +1.0) * (max - min) + min;
}

void SortCounting(int *mas, int n){
	int masSch[1000000];
	int i, j = 0, k;

	for(i = 0; i < n; i++){
		j = mas[i];
		masSch[j]++;
	}

	k = 0;
	for(j = 0; j < 100000; j++)
		for(i = 0; i < masSch[j]; i++){
			mas[k] = j;
			k++;
		}
}

void SortInsertion(int *mas, int n){
 	int i, j, key;
 	for(i = 1; i < n; i++){
    	key = mas[i];
	    for(j = i; (j > 0) && (mas[j-1] > key); j--)
	    	mas[j] = mas[j-1];
    	mas[j] = key;
	}
}

////////////// Сортировка слиянием /////////////////
void merge(int a[], int l, int m, int r)
{
	int i, j, k;			// Счетчики
	int n1 = m - l + 1;
	int n2 =  r - m;
	int L[n1], R[n2];		// Временные массивы

	// Присвоение во временные массивы левой части
	for(i = 0; i < n1; i++)
		L[i] = a[l + i];
	// Присвоение во временные массивы правой части
	for(j = 0; j < n2; j++)
		R[j] = a[m + 1+ j];

	// Слияние временных массивов в основной
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	// Занесение остатка левого временного массива в основной
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}

	// Занесение остатка правого временного массива в основной
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(int a[], int Left, int Right){

	if (Left < Right)
	{
		int m = Left + (Right - Left) / 2; 
		MergeSort(a, Left, m);
		MergeSort(a, m + 1, Right);
		// Последнее cлияние
		merge(a, Left, m, Right);
	}


}
int main () {
	double t;
	int mas[1000000];
	int i, n, choose;

	printf("Input size array: ");
	scanf("\n%d", &n);

	for(i = 0; i < n; i++)
		mas[i] = getrand(0, 100000);

	printf("Choose sorting:\n  1 - SortCounting\n  2 - SortInsertion\n  3 - SortMerge\n");
	printf("INPUT: ");
	scanf("%d", &choose);

	int Left = 0;
	int Right = n-1;

	switch ( choose ) {
		case 1:{
			printf("\n1 - SortCounting:\n");
			t = wtime();
			SortCounting(mas, n);
			t = wtime() - t;
		  	break;
		}

		case 2:{
			printf("\n2 - SortInsertion:\n");
			t = wtime();
			SortInsertion(mas, n);
			t = wtime() - t;
			break;	
		}
		case 3:{
			printf("\n3 - SortMerge:\n");
			t = wtime();
			MergeSort(mas, Left, Right);
			t = wtime() - t;
			break;	
		}
		default:
        printf( "----Неправильный ввод!----\n" );
	}
	
	

	printf("\n" );


	for(i = 0; i < n; i++)
		printf("%d ", mas[i]);
	printf("\nElapsed time: %.6f sec.\n", t);  
	return 0;

}










