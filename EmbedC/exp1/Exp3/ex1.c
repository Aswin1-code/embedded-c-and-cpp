#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for a Book */
struct book {
    int id;
    char title[100];
    char author[100];
    struct book *next;
};
typedef struct book Book;
/* Head pointer */
Book *head = NULL;

/* Function to create a new book node */
Book* createBook(int id, char title[], char author[]) {
    Book *newBook = (Book*)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = NULL;

    return newBook;
}

/* Add book at end */
void addBook() {
    int id;
    char title[100], author[100];

    printf("Enter Book ID: ");
    scanf("%d", &id);
    getchar(); // clear newline

    printf("Enter Title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;

    printf("Enter Author: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = 0;

    Book *newBook = createBook(id, title, author);

    if (head == NULL) {
        head = newBook;
    } else {
        Book *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    printf("Book added successfully!\n");
}

/* Display all books */
void displayBooks() {
    if (head == NULL) {
        printf("Library is empty.\n");
        return;
    }

    Book *temp = head;
    while (temp != NULL) {
        printf("\nID: %d\nTitle: %s\nAuthor: %s\n",
               temp->id, temp->title, temp->author);
        temp = temp->next;
    }
}

/* Search book by ID */
void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    Book *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nBook Found!\nID: %d\nTitle: %s\nAuthor: %s\n",
                   temp->id, temp->title, temp->author);
            return;
        }
        temp = temp->next;
    }

    printf("Book not found.\n");
}

/* Delete book by ID */
void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    Book *temp = head;
    Book *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Book deleted successfully!\n");
}

/* Free entire list before exit */
void freeLibrary() {
    Book *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5:
                freeLibrary();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
