#include <stdio.h>

#define TAILLE_MAX 100

// Variables globales simples pour la File (Queue)
int Q[TAILLE_MAX]; // Le tableau représentant la file
int n = 0;         // Le nombre d'éléments actuels dans la file

// 1. Enqueue : Ajouter un élément à la fin de la file (rear)
void enqueue(int x) {
    if (n >= TAILLE_MAX) {
        printf("Erreur : File pleine !\n");
        return;
    }
    Q[n] = x; // On ajoute l'élément à la fin
    n++;      // On incrémente la taille
}

// 2. Dequeue : Retirer et renvoyer le premier élément de la file (front)
int dequeue() {
    if (n <= 0) {
        printf("Erreur : File vide !\n");
        return -1;
    }
    
    int x = Q[0]; // 1. x <- Q[0] (on récupère le premier)
    
    // 2. Q.remove(x) : On décale tous les éléments vers la gauche
    for (int i = 0; i < n - 1; i++) {
        Q[i] = Q[i + 1];
    }
    
    n--;        // On diminue la taille
    return x;   // 3. Return x
}

// 3. Peek / Front : Consulter le premier élément sans le retirer
int peek() {
    if (n <= 0) {
        printf("Erreur : File vide !\n");
        return -1;
    }
    return Q[0];
}

// Fonction pour afficher la file
void afficher() {
    printf("File (du debut a la fin) : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

int main() {
    // Tests de la file selon le principe FIFO (First In, First Out)
    enqueue(10); // Arrive en 1er
    enqueue(20); // Arrive en 2ème
    enqueue(30); // Arrive en 3ème

    afficher(); // Affiche : 10 20 30

    printf("Premier element (Peek) : %d\n", peek()); // Affiche

    int retire = dequeue(); // Retire le premier arrivé 
    printf("Element retire (Dequeue) : %d\n", retire);

    afficher(); // Affiche 

    return 0;
}