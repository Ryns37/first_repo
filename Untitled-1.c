/*
 * main.c
 *
 *  Created on: 24 Oct 2017
 *      Author: adrien
 */


#include <stdio.h>
#include <stdlib.h>

void InputGrade(int [], int);
void MeanMinMax(int [], int, float *, int *, int *);
void Display(int [], int, float, int, int);

void InputGrade(int grade[], int nb){
	for (int i = 0; i < nb; i++){
		printf("Note du %d %s élève : ", i+1, ((i+1)==1)? "ère" : "ème");
		scanf("%d", &grade[i]);
		if (grade[i] < 0)
			i--;
	}
}
void MeanMinMax(int grade[], int nb, float *moy, int *min, int *max){
	float somme = 0;
	*min=*max=grade[0];

	for (int i = 0; i < nb; i++){
		somme+=grade[i];
		*min = (*min > grade[i])? grade[i] : *min;
		*max = (*max < grade[i])? grade[i] : *max;
	}
	*moy = somme/nb;
}

void Display(int grade[], int nb, float moy, int min, int max){
	for (int i = 0; i < nb; i++)
		printf("Note %d : %d\n", i+1, grade[i]);
	printf("Le minimum est de %d\nLe maximum est de %d\nLa moyenne de la classe est de %.2f\n", min, max, moy);
}

int main(){
	int max, min, nb;
	float moy;
	int *n;

	do {
		printf("Combien d'élèves dans la classe ? ");
		scanf("%d", &nb);
	} while (nb < 0);

	n = (int *) malloc(nb * sizeof(int));
	if (!n){
		printf("Pb d'allocations !\n");
		return EXIT_FAILURE;
	}
	InputGrade(n, nb);
	MeanMinMax(n, nb, &moy, &min, &max);
	Display(n, nb, moy, min, max);

	return EXIT_SUCCESS;
}
