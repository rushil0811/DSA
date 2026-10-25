

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int rno;
    char name[20];
    float marks;
};
void accept(struct student s[], int n);
void display(struct student s[], int n);
void linearSearch(struct student s[], int n, int key);
void binarySearch(struct student s[], int n, int key);
void binaryRecursiveSearch(struct student s[], int low, int high, int key); // Added prototype
void insertionSort(struct student s[], int n);
void selectionSort(struct student s[], int n);
void shellSort(struct student s[], int n);

void accept(struct student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].rno);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
}

void display(struct student s[], int n) {
    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    for (int i = 0; i < n; i++) {
        // Fix for the format string warning, utilizing width formatting for tabular look
        printf("%-10d %-20s %-10.2f\n", s[i].rno, s[i].name, s[i].marks);
    }
    printf("\n");
}

void linearSearch(struct student s[], int n, int key) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (s[i].rno == key) {
            printf("\n[Linear Search] Student Found at Position: %d\n", i + 1);
            printf("Name: %s, Marks: %.2f\n", s[i].name, s[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nStudent with Roll No %d not found.\n", key);
    }
}
void binarySearch(struct student s[], int n, int key) {
    int low = 0, high = n - 1, mid;
    int found = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (s[mid].rno == key) {
            printf("\n[Iterative Binary Search] Student Found at Array Index: %d\n", mid);
            printf("Name: %s, Marks: %.2f\n", s[mid].name, s[mid].marks);
            found = 1;
            break;
        } else if (s[mid].rno < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!found) {
        printf("\nStudent with Roll No %d not found.\n", key);
    }
}
void binaryRecursiveSearch(struct student s[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (s[mid].rno == key) {
            printf("\n[Recursive Binary Search] Student Found at Array Index: %d\n", mid);
            printf("Name: %s, Marks: %.2f\n", s[mid].name, s[mid].marks);
            return;
        }
        if (s[mid].rno > key) {
            return binaryRecursiveSearch(s, low, mid - 1, key);
        }
        return binaryRecursiveSearch(s, mid + 1, high, key);
    }
    printf("\nStudent with Roll No %d not found.\n", key);
}

void insertionSort(struct student s[], int n) {
    int i, j;
    struct student temp;
    for (i = 1; i < n; i++) {
        temp = s[i];
        j = i - 1;
        while (j >= 0 && s[j].rno > temp.rno) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = temp;
    }
    printf("\n--- Sorted using Insertion Sort ---\n");
}

void selectionSort(struct student s[], int n) {
    int i, j, min_idx;
    struct student temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (s[j].rno < s[min_idx].rno) {
                min_idx = j;
            }
        }
        temp = s[min_idx];
        s[min_idx] = s[i];
        s[i] = temp;
    }
    printf("\n--- Sorted using Selection Sort ---\n");
}

void shellSort(struct student s[], int n) {
    struct student temp;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            temp = s[i];
            int j;
            for (j = i; j >= gap && s[j - gap].rno > temp.rno; j -= gap) {
                s[j] = s[j - gap];
            }
            s[j] = temp;
        }
    }
    printf("\n--- Sorted using Shell Sort ---\n");
}

int main() {
    struct student s[50];
    int n, key, choice;

    printf("Enter Number of Students: ");
    scanf("%d", &n);
    accept(s, n);

    do {
        printf("\n1. Display Data\n");
        printf("2. Linear Search\n");
        printf("3. Iterative Binary Search (Requires Sorted Data)\n");
        printf("4. Recursive Binary Search (Requires Sorted Data)\n");
        printf("5. Insertion Sort (by Roll No)\n");
        printf("6. Selection Sort (by Roll No)\n");
        printf("7. Shell Sort (by Roll No)\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(s, n);
                break;
            case 2:
                printf("Enter Roll No to search: ");
                scanf("%d", &key);
                linearSearch(s, n, key);
                break;
            case 3:
                printf("Enter Roll No to search: ");
                scanf("%d", &key);
                binarySearch(s, n, key);
                break;
            case 4: 
                printf("Enter Roll No to search: ");
                scanf("%d", &key);
                binaryRecursiveSearch(s, 0, n - 1, key); 
                break;
            case 5:
                insertionSort(s, n);
                display(s, n);
                break;
            case 6:
                selectionSort(s, n);
                display(s, n);
                break;
            case 7:
                shellSort(s, n);
                display(s, n);
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
