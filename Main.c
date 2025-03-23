#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

void addBook();
void viewBooks();
void searchBook();

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n2. View Books\n3. Search Book\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

void addBook() {
    struct Book book;
    FILE *file = fopen("books.dat", "ab");
    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    printf("Enter Title: ");
    scanf("%s", book.title);
    printf("Enter Author: ");
    scanf("%s", book.author);
    fwrite(&book, sizeof(struct Book), 1, file);
    fclose(file);
    printf("Book added successfully!\n");
}

void viewBooks() {
    struct Book book;
    FILE *file = fopen("books.dat", "rb");
    printf("\nID | Title | Author\n");
    while (fread(&book, sizeof(struct Book), 1, file)) {
        printf("%d | %s | %s\n", book.id, book.title, book.author);
    }
    fclose(file);
}

void searchBook() {
    int id;
    struct Book book;
    FILE *file = fopen("books.dat", "rb");
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.id == id) {
            printf("Book Found: %d | %s | %s\n", book.id, book.title, book.author);
            fclose(file);
            return;
        }
    }
    printf("Book not found!\n");
    fclose(file);
}
