#include <windows.h>
#include <stdio.h>

DWORD WINAPI fonction_thread(LPVOID arg) {
    int id = *(int*)arg;

    for (int i = 0; i <= 1000; i++) {
        printf("Thread %d : %d\n", id, i);
        Sleep(1); // ralentit un peu pour voir le mélange des threads
    }

    return 0;
}

int main(void) {
    HANDLE threads[3];
    int ids[3] = { 1, 2, 3 };

    // Création de 3 threads
    for (int i = 0; i < 3; i++) {
        threads[i] = CreateThread(
            NULL,                // sécurité par défaut
            0,                   // taille de pile par défaut
            fonction_thread,     // fonction exécutée par le thread
            &ids[i],             // paramètre passé (ici l'id)
            0,                   // démarrer immédiatement
            NULL                 // on ne récupère pas l’ID du thread
        );

        if (threads[i] == NULL) {
            printf("Erreur création du thread %d\n", i + 1);
            return 1;
        }
    }

    // Attendre que tous les threads se terminent
    WaitForMultipleObjects(3, threads, TRUE, INFINITE);

    printf("\nTous les threads ont terminé.\n");
    return 0;
}
