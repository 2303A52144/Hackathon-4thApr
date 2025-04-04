# Hackathon-4thApr

https://github.com/user-attachments/assets/5af2eb77-6b2c-4b64-b388-d374a83cf3a0

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char title[100];
    char category[50]; 
    char owner[50];
    char status[50];    
} Project;

Project database[MAX];
int projectCount = 0;

void addProject() {
    if (projectCount >= MAX) {
        printf("Database is full!\n");
        return;
    }
    Project p;
    p.id = projectCount + 1;
    printf("\nEnter Project Title: ");
    getchar();  
    fgets(p.title, sizeof(p.title), stdin);
    p.title[strcspn(p.title, "\n")] = '\0';
    printf("Enter Category (Research/Innovation/Startup/IPR): ");
    fgets(p.category, sizeof(p.category), stdin);
    p.category[strcspn(p.category, "\n")] = '\0';
    printf("Enter Owner Name: ");
    fgets(p.owner, sizeof(p.owner), stdin);
    p.owner[strcspn(p.owner, "\n")] = '\0';
    printf("Enter Status (Ongoing/Completed/Pending IPR/Funded): ");
    fgets(p.status, sizeof(p.status), stdin);
    p.status[strcspn(p.status, "\n")] = '\0';
    database[projectCount++] = p;
    printf("Project added successfully!\n");
}
void displayProjects() {
    if (projectCount == 0) {
        printf("\nNo projects to display.\n");
        return;
    }
    printf("\n%-5s %-30s %-15s %-20s %-15s\n", "ID", "Title", "Category", "Owner", "Status");
    printf("--------------------------------------------------------------------------------------------\n");
    int i;
    for (i = 0; i < projectCount; i++) {
        printf("%-5d %-30s %-15s %-20s %-15s\n",
            database[i].id, database[i].title, database[i].category, database[i].owner, database[i].status);
    }
}
void searchByCategory() {
    char cat[50];
    printf("\nEnter category to search (Research/Innovation/Startup/IPR): ");
    getchar(); 
    fgets(cat, sizeof(cat), stdin);
    cat[strcspn(cat, "\n")] = '\0';
    printf("\nResults for category: %s\n", cat);
    int i;
    for (i = 0; i < projectCount; i++) {
        if (strcmp(database[i].category, cat) == 0) {
            printf("ID: %d | Title: %s | Owner: %s | Status: %s\n", 
                database[i].id, database[i].title, database[i].owner, database[i].status);
        }
    }
}
int main() {
    int choice;
    do {
        printf("\n===== Gujarat Innovation Monitoring System =====\n");
        printf("1. Add Project\n");
        printf("2. Display All Projects\n");
        printf("3. Search by Category\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addProject(); break;
            case 2: displayProjects(); break;
            case 3: searchByCategory(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}
