#include <stdio.h>
#include <string.h>

#define TAILLE_TABLE 10 // Taille fixe de la table de hachage

// Structure pour stocker une paire clé-valeur
typedef struct {
    int cle;
    int valeur;
    int occupe; // 0 si la case est vide, 1 si elle contient une donnée
} Element;

// La table de hachage (tableau global simple)
Element table[TAILLE_TABLE];

// 1. La fonction de hachage (Hash Function)
// Elle prend une clé et renvoie un indice entre 0 et TAILLE_TABLE - 1
int fonction_hachage(int cle) {
    return cle % TAILLE_TABLE;
}

// 2. Insérer une paire clé-valeur (Insert)
void inserer(int cle, int valeur) {
    int index = fonction_hachage(cle);
    
    // Gestion basique des collisions (Sondage linéaire : on cherche la prochaine case libre)
    int depart = index;
    while (table[index].occupe == 1) {
        // Si la clé existe déjà, on met à jour la valeur
        if (table[index].cle == cle) {
            table[index].valeur = valeur;
            printf("Mise à jour de la clé %d avec la valeur %d à l'index %d\n", cle, valeur, index);
            return;
        }
        
        index = (index + 1) % TAILLE_TABLE; // On avance circulairement
        
        // Si on a fait tout le tour, la table est pleine
        if (index == depart) {
            printf("Erreur : Table de hachage pleine !\n");
            return;
        }
    }
    
    // Insertion dans la case libre trouvée
    table[index].cle = cle;
    table[index].valeur = valeur;
    table[index].occupe = 1;
    printf("Insertion : Clé %d -> Valeur %d à l'index %d\n", cle, valeur, index);
}

// 3. Rechercher une valeur à partir de sa clé (Search)
int rechercher(int cle) {
    int index = fonction_hachage(cle);
    int depart = index;
    
    while (table[index].occupe == 1) {
        if (table[index].cle == cle) {
            return table[index].valeur; // Trouvé !
        }
        index = (index + 1) % TAILLE_TABLE;
        if (index == depart) {
            break; // On a fait le tour
        }
    }
    
    printf("Clé %d introuvable !\n", cle);
    return -1; // Non trouvé
}

// Afficher l'état de la table de hachage
void afficher_table() {
    printf("\n--- État de la Hash Table ---\n");
    for (int i = 0; i < TAILLE_TABLE; i++) {
        if (table[i].occupe == 1) {
            printf("Index %d : [Clé: %d | Valeur: %d]\n", i, table[i].cle, table[i].valeur);
        } else {
            printf("Index %d : [Vide]\n", i);
        }
    }
    printf("-----------------------------\n\n");
}

int main() {
    // Initialisation de la table (toutes les cases sont vides)
    for (int i = 0; i < TAILLE_TABLE; i++) {
        table[i].occupe = 0;
    }

    // Insertions
    inserer(12, 100); // 12 % 10 = index 2
    inserer(22, 200); // 22 % 10 = index 2 (Collision ! Sera placé à l'index 3)
    inserer(5, 50);   // 5 % 10 = index 5

    afficher_table();

    // Recherche
    int resultat = rechercher(22);
    if (resultat != -1) {
        printf("Valeur trouvée pour la clé 22 : %d\n", resultat);
    }

    return 0;
}
