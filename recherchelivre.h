#include <stdio.h>
#include <string.h>

// Recherche de livres par titre
void searchByTitle() {
    char title[100];
    int found = 0;

    printf("Entrez le titre du livre a rechercher : ");
    scanf("%s", title);

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Livre trouver :\n");
            printf("ID : %d\n", books[i].id);
            printf("Titre : %s\n", books[i].title);
            printf("Auteur : %s\n", books[i].author);
            printf("Disponibilité : %s\n", books[i].isAvailable ? "Disponible" : "Non disponible");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Livre non trouve.\n");
    }
}

// Recherche de livres par auteur

void searchByAuthor() {
    char author[100];
    int found = 0;

    printf("Entrez l'auteur du livre a rechercher : ");
    scanf("%s", author);

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printf("Livre trouver :\n");
            printf("ID : %d\n", books[i].id);
            printf("Titre : %s\n", books[i].title);
            printf("Auteur : %s\n", books[i].author);
            printf("Disponibilité : %s\n", books[i].isAvailable ? "Disponible" : "Non disponible");
            found = 1;
        }
    }

    if (!found) {
        printf("Livre non trouver.\n");
    }
}
