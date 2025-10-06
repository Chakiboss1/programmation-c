#include <windows.h>
#include <stdio.h>

HANDLE mutex;  // pour éviter les collisions d’affichage
int valeurs[3] = { 0, 0, 0 };  // valeurs de chaque thread
int fini[3] = { 0, 0, 0 };     // indique si un thread est fini

DWORD WINAPI fonction_thread(LPVOID arg) {
    int id = *(int*)arg;

    for (int i = 0; i <= 1000; i++) {
        valeurs[id - 1] = i;
        Sleep(10);
    }

    fini[id - 1] = 1;
    return 0;
}

int tous_finis() {
    return fini[0] && fini[1] && fini[2];
}

int main(void) {
    HANDLE threads[3];
    int ids[3] = { 1, 2, 3 };

    mutex = CreateMutex(NULL, FALSE, NULL);

    for (int i = 0; i < 3; i++) {
        threads[i] = CreateThread(NULL, 0, fonction_thread, &ids[i], 0, NULL);
    }

    // Boucle principale d’affichage
    while (!tous_finis()) {
        WaitForSingleObject(mutex, INFINITE);

        printf("\rThread 1: %4d | Thread 2: %4d | Thread 3: %4d",
            valeurs[0], valeurs[1], valeurs[2]);
        fflush(stdout);

        ReleaseMutex(mutex);
        Sleep(50);  // rafraîchissement
    }

    printf("\nTous les threads sont terminés.\n");
    return 0;
}
