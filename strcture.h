#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int isAvailable;
};

struct Book books[MAX_BOOKS];
int numBooks = 0;

// Sauvegarde des livres dans un fichier
void saveBooks() {
    FILE *file = fopen("books.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < numBooks; i++) {
            printf(file, "%d;%s;%s;%d\n", books[i].id, books[i].title, books[i].author, books[i].isAvailable);
        }
        fclose(file);
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}

// Chargement des livres à partir d'un fichier
void loadBooks() {
    FILE *file = fopen("books.txt", "r");
    if (file != NULL) {
        char line[200];
        while (fgets(line, sizeof(line), file) != NULL) {
            struct Book newBook;
            sscanf(line, "%d;%[^;];%[^;];%d", &newBook.id, newBook.title, newBook.author, &newBook.isAvailable);
            books[numBooks] = newBook;
            numBooks++;
        }
        fclose(file);
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}
