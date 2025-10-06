// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdio.h>




int main(void) {
	

	float variable = 0;
	int nombreE = 6;
	float nombreZ = 7;

	float *pt_variable = &variable;
	int *pt_nombreE = &nombreE;
	float *pt_nombreZ = &nombreZ;


	printf("voici les chiffres avant l'execution de la fonction : variable : %f, nombreE : %d, nombreZ : %f\n", variable, nombreE, nombreZ);
	multiplication(&pt_variable, &pt_nombreE, &pt_nombreZ);
	printf("voici les chiffres apres l'execution de la fonction : variable : %f, nombreE : %d, nombreZ : %f\n", variable, nombreE, nombreZ);

	





}
int multiplication(float **variable, int **nombreE, float **nombreZ) {
	**variable = (**nombreE) * (**nombreZ);

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
