#include <stdio.h>

#define TAILLE_MAX 100

// Variables globales simples pour la pile (comme dans le pseudo-code du cours)
int S[TAILLE_MAX]; // Tableau représentant la pile
int n = 0;         // Taille courante (curr size n)
int N = TAILLE_MAX; // Taille maximale (max size N)

// 1. Fonction PUSH (Ajouter un élément au sommet)
// Pseudo-code : S[n-1] <- x puis n <- n + 1
// (Attention en C, on utilise l'index 'n' avant d'incrémenter)
void push(int x) {
    if (n >= N) {
        printf("Erreur : Pile pleine (Stack Overflow) !\n");
        return;
    }
    S[n] = x;
    n = n + 1;
}

// 2. Fonction POP (Retirer l'élément du sommet)
// Pseudo-code : x <- S[n-1], n <- n - 1, Return x
int pop() {
    if (n <= 0) {
        printf("Erreur : Pile vide (Stack Underflow) !\n");
        return -1;
    }
    n = n - 1;
    int x = S[n];
    return x;
}

// 3. Fonction PEEK (Consulter le sommet sans le retirer)
// Pseudo-code : Return S[n-1]
int peek() {
    if (n <= 0) {
        printf("Erreur : Pile vide !\n");
        return -1;
    }
    return S[n - 1];
}

// Fonction pour afficher la pile
void afficher() {
    printf("Pile (du bas vers le sommet) : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", S[i]);
    }
    printf("\n");
}

int main() {
    // Tests de la pile selon le principe LIFO (Last In First Out)
    push(10); // Ajoute 10
    push(20); // Ajoute 20
    push(30); // Ajoute 30 -> Sommet = 30

    afficher(); // Affiche : 10 20 30

    printf("Sommet (Peek) : %d\n", peek()); // Affiche 30

    int retire = pop(); // Retire le 30
    printf("Element retire (Pop) : %d\n", retire);

    afficher(); // Affiche : 10 20

    return 0;
}
