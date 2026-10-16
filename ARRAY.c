#include <stdio.h>

#define TAILLE_MAX 100

// Variables globales simples pour gérer le tableau
int tableau[TAILLE_MAX];
int nb_elements = 0; // Nombre d'éléments actuellement dans le tableau

// 1. Afficher le tableau
void afficher() {
    printf("Tableau : ");
    for (int i = 0; i < nb_elements; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

// 2. Insérer un élément à une position donnée
void inserer(int position, int valeur) {
    if (nb_elements >= TAILLE_MAX) {
        printf("Erreur : le tableau est plein !\n");
        return;
    }
    if (position < 0 || position > nb_elements) {
        printf("Erreur : position invalide !\n");
        return;
    }

    // Décaler les éléments vers la droite
    for (int i = nb_elements; i > position; i--) {
        tableau[i] = tableau[i - 1];
    }

    // Insérer la valeur et augmenter la taille
    tableau[position] = valeur;
    nb_elements++;
}

// 3. Supprimer un élément à une position donnée
void supprimer(int position) {
    if (nb_elements <= 0) {
        printf("Erreur : le tableau est vide !\n");
        return;
    }
    if (position < 0 || position >= nb_elements) {
        printf("Erreur : position invalide !\n");
        return;
    }

    // Décaler les éléments vers la gauche
    for (int i = position; i < nb_elements - 1; i++) {
        tableau[i] = tableau[i + 1];
    }

    // Réduire la taille
    nb_elements--;
}

int main() {
    // Test des fonctions simples
    inserer(0, 10); 
    inserer(1, 20); 
    inserer(1, 15); 
    inserer(2,56);
    afficher(); 

    supprimer(1); // Supprime l'élément à la position 1 
    
    afficher(); // Affiche 

    return 0;
}