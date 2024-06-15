//**Sous-dossier 2 : Fonctions d'ajout et de recherche de livres**
#include <stdio.h>
#include <string.h>
// Ajout d'un livre
void addBook() {
    struct Book newBook;

    printf("Entrez l'ID du livre : \n");
    scanf("%d", &newBook.id);

    printf("Entrez le titre du livre : \n");
    scanf("%s", newBook.title);

    printf("Entrez l'auteur du livre : \n");
    scanf("%s", newBook.author);

    newBook.isAvailable = 1;

    books[numBooks] = newBook;
    numBooks++;

    saveBooks();
}
