//**Sous-dossier 1 : Fonctions de gestion de livres**
#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
#include"strcture.h"
#include"Ajoutlivre.h"
#include"recherchelivre.h"

//**Sous-dossier 3 : Fonctions d'emprunt et de retour de livres**

// Emprunt d'un livre
void borrowBook() {
    int id;
    int found = 0;

    printf("Entrez l'ID du livre a emprunter : ");
    scanf("%d", &id);

    for (int i = 0; i < numBooks; i++) {
        if (books[i].id == id && books[i].isAvailable) {
            books[i].isAvailable = 0;
            printf("Livre emprunter avec succes.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Livre non trouvé ou non disponible.\n");
    }

    saveBooks();
}

// Retour d'un livre
void returnBook() {
    int id;
    int found = 0;

    printf("Entrez l'ID du livre a rendre : ");
    scanf("%d", &id);

    for (int i = 0; i < numBooks; i++) {
        if (books[i].id == id && !books[i].isAvailable) {
            books[i].isAvailable = 1;
            printf("Livre rendu avec succes.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Livre non trouve ou deja disponible.\n");
    }

    saveBooks();
}


//**Sous-dossier 4 : Fonction d'affichage de la liste des livres**


// Affichage de la liste des livres
void displayBooks() {
    printf("Liste des livres :\n");

    for (int i = 0; i < numBooks; i++) {
        printf("ID : %d\n", books[i].id);
        printf("Titre : %s\n", books[i].title);
        printf("Auteur : %s\n", books[i].author);
        printf("Disponibilite : %s\n", books[i].isAvailable ? "Disponible" : "Non disponible");
        printf("\n");
    }
}


//**Sous-dossier 5 : Fonction principale**

int main() {
    loadBooks();

    int choice;

    while (1) {
        printf("\n\nSysteme de gestion de la bibliothèque\n\n");
        printf("1. Ajouter un livre\n");
        printf("2. Rechercher un livre par titre\n");
        printf("3. Rechercher un livre par auteur\n");
        printf("4. Emprunter un livre\n");
        printf("5. Rendre un livre\n");
        printf("6. Afficher la liste des livres\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchByTitle();
                break;
            case 3:
                searchByAuthor();
                break;
            case 4:
                borrowBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                displayBooks();
                break;
            case 7:
                printf("Au revoir !\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}
