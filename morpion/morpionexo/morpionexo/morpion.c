#include <stdio.h>

void initializeMorpion(char* tableau) {

	for (int i = 0; i < 9; i++) {
		tableau[i] = '1' + i;
	}

}

void afficherMorpion(char tableau[9]) {
	printf(" %c | %c | %c \n", tableau[0], tableau[1], tableau[2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", tableau[3], tableau[4], tableau[5]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", tableau[6], tableau[7], tableau[8]);
}

int verifVictoire(char tableau[9]) {
	if ((tableau[0] == tableau[1] && tableau[1] == tableau[2]) ||
		(tableau[3] == tableau[4] && tableau[4] == tableau[5]) ||
		(tableau[6] == tableau[7] && tableau[7] == tableau[8]) ||
		(tableau[0] == tableau[3] && tableau[3] == tableau[6]) ||
		(tableau[1] == tableau[4] && tableau[4] == tableau[7]) ||
		(tableau[2] == tableau[5] && tableau[5] == tableau[8]) ||
		(tableau[0] == tableau[4] && tableau[4] == tableau[8]) ||
		(tableau[2] == tableau[4] && tableau[4] == tableau[6])) {
		return 1;
	}
	return 0;
}

void isValidMove(char* tableau, int *index) {
	int isValid = 0;
	while (!isValid) {
		if (*index < 1 || *index > 9) {
			printf("Numero invalide. Veuillez entrer un numero entre 1 et 9 : ");
			scanf_s("%d", index);
		}
		else
		{
			isValid = 1;
			printf("Vous avez choisi la case: %d\n", *index);
			return;
		}
	}
	
	
}
void tabMorpion(char* tableau) {
	int player = 1;
	int index;
	int gameOver = 0;

	while (!gameOver) {
		afficherMorpion(tableau);
		printf("Joueur %d, entrez un numero de case (1-9) : ", player);
		scanf_s("%d", &index);
		isValidMove(tableau, &index);
		index = index - 1;
		

		if (tableau[index] != 'X' && tableau[index] != 'O') {
			tableau[index] = (player == 1) ? 'X' : 'O';
		}
		else {
			printf("Case deja prise, veuillez choisir une autre case.\n");
			continue;
		}


		if (verifVictoire(tableau)) {
			afficherMorpion(tableau);
			printf("Joueur %d a gagne !\n", player);
			gameOver = 1;
		}
		if (player == 1) {
			player = 2;
		}
		else {
			player = 1;
		}


		int isDraw = 1;
		for (int i = 0; i < 9; i++) {
			if (tableau[i] != 'X' && tableau[i] != 'O') {
				isDraw = 0;
				break;
			}
		}
		if (isDraw) {
			afficherMorpion(tableau);
			printf("Match nul !\n");
			gameOver = 1;
		}
	}
}

void computerMove(char* tableau) {

}