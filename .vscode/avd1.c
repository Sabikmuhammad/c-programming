#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOPICS 5

// Structure to store learning topics
struct LearningTopic {
    char topicName[50];
    int completed;
    struct LearningTopic *next;  // Pointer to next topic (for linked list of topics)
};

// Structure to store user profile information
struct User {
    char name[50];
    int age;
    char learningStyle[20];
    struct LearningTopic *topics;  // Head of linked list of topics
    struct User *next;  // Pointer to next user in linked list
};

// Function prototypes
void registerUser(struct User **head);
void chooseLearningStyle(struct User *user);
void chooseLearningTopics(struct User *user);
void trackProgress(struct User *user);
void saveUsersToFile(struct User *head);
void loadUsersFromFile(struct User **head);
void freeMemory(struct User *head);

int main() {
    struct User *users = NULL;  // Head of linked list of users
    int choice;

    // Load users from file at program startup
    loadUsersFromFile(&users);

    printf("Welcome to the Advanced Personalized Learning Platform!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Register a new user\n");
        printf("2. Choose Learning Style\n");
        printf("3. Choose Learning Topics\n");
        printf("4. Track Progress\n");
        printf("5. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser(&users);
                break;
            case 2:
                if (users != NULL) {
                    chooseLearningStyle(users);
                } else {
                    printf("No users registered yet!\n");
                }
                break;
            case 3:
                if (users != NULL) {
                    chooseLearningTopics(users);
                } else {
                    printf("No users registered yet!\n");
                }
                break;
            case 4:
                if (users != NULL) {
                    trackProgress(users);
                } else {
                    printf("No users registered yet!\n");
                }
                break;
            case 5:
                saveUsersToFile(users);
                freeMemory(users);
                printf("Data saved! Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

// Function to register a new user
void registerUser(struct User **head) {
    struct User *newUser = (struct User *)malloc(sizeof(struct User));
    newUser->topics = NULL;
    newUser->next = NULL;

    printf("Enter your name: ");
    scanf("%s", newUser->name);
    printf("Enter your age: ");
    scanf("%d", &newUser->age);

    // Add the new user to the linked list
    if (*head == NULL) {
        *head = newUser;
    } else {
        struct User *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newUser;
    }

    printf("User %s registered successfully!\n", newUser->name);
}

// Function to choose a learning style
void chooseLearningStyle(struct User *user) {
    int choice;
    printf("Choose your preferred learning style:\n");
    printf("1. Visual (Videos, Images)\n");
    printf("2. Auditory (Podcasts, Lectures)\n");
    printf("3. Kinesthetic (Hands-on)\n");

    printf("Enter your choice (1, 2, or 3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(user->learningStyle, "Visual");
            break;
        case 2:
            strcpy(user->learningStyle, "Auditory");
            break;
        case 3:
            strcpy(user->learningStyle, "Kinesthetic");
            break;
        default:
            printf("Invalid choice. Defaulting to Visual.\n");
            strcpy(user->learningStyle, "Visual");
    }

    printf("Learning style set to %s.\n", user->learningStyle);
}

// Function to add topics using a linked list
void chooseLearningTopics(struct User *user) {
    struct LearningTopic *temp;
    printf("Choose your learning topics (maximum 5):\n");
    printf("1. Mathematics\n");
    printf("2. Science\n");
    printf("3. History\n");
    printf("4. Computer Science\n");
    printf("5. Arts\n");

    for (int i = 0; i < MAX_TOPICS; i++) {
        struct LearningTopic *newTopic = (struct LearningTopic *)malloc(sizeof(struct LearningTopic));
        newTopic->completed = 0;
        newTopic->next = NULL;

        printf("Enter topic %d (1-5): ", i + 1);
        int topicChoice;
        scanf("%d", &topicChoice);

        switch (topicChoice) {
            case 1:
                strcpy(newTopic->topicName, "Mathematics");
                break;
            case 2:
                strcpy(newTopic->topicName, "Science");
                break;
            case 3:
                strcpy(newTopic->topicName, "History");
                break;
            case 4:
                strcpy(newTopic->topicName, "Computer Science");
                break;
            case 5:
                strcpy(newTopic->topicName, "Arts");
                break;
            default:
                printf("Invalid choice, try again.\n");
                i--;
                free(newTopic);
                continue;
        }

        if (user->topics == NULL) {
            user->topics = newTopic;
        } else {
            temp = user->topics;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newTopic;
        }
    }

    printf("Topics successfully chosen.\n");
}

// Function to track progress on learning topics
void trackProgress(struct User *user) {
    struct LearningTopic *temp = user->topics;
    int topicNumber = 1;

    printf("Track your learning progress:\n");
    while (temp != NULL) {
        printf("%d. %s - %s\n", topicNumber, temp->topicName, temp->completed ? "Completed" : "Incomplete");
        temp = temp->next;
        topicNumber++;
    }

    printf("Enter the topic number to mark as complete: ");
    scanf("%d", &topicNumber);

    temp = user->topics;
    for (int i = 1; i < topicNumber; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        temp->completed = 1;
        printf("%s marked as completed.\n", temp->topicName);
    } else {
        printf("Invalid topic number.\n");
    }
}

// Function to save user data to a file
void saveUsersToFile(struct User *head) {
    FILE *file = fopen("users_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    struct User *tempUser = head;
    while (tempUser != NULL) {
        fprintf(file, "%s %d %s\n", tempUser->name, tempUser->age, tempUser->learningStyle);
        struct LearningTopic *tempTopic = tempUser->topics;
        while (tempTopic != NULL) {
            fprintf(file, "%s %d\n", tempTopic->topicName, tempTopic->completed);
            tempTopic = tempTopic->next;
        }
        fprintf(file, "END\n");  // Marker to indicate the end of this user's topics
        tempUser = tempUser->next;
    }

    fclose(file);
    printf("User data saved successfully.\n");
}

// Function to load user data from a file
void loadUsersFromFile(struct User **head) {
    FILE *file = fopen("users_data.txt", "r");
    if (file == NULL) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }

    struct User *tempUser = NULL;
    while (!feof(file)) {
        struct User *newUser = (struct User *)malloc(sizeof(struct User));
        newUser->topics = NULL;
        newUser->next = NULL;

        if (fscanf(file, "%s %d %s", newUser->name, &newUser->age, newUser->learningStyle) != 3) {
            free(newUser);
            break;
        }

        struct LearningTopic *lastTopic = NULL;
        while (1) {
            struct LearningTopic *newTopic = (struct LearningTopic *)malloc(sizeof(struct LearningTopic));
            if (fscanf(file, "%s %d", newTopic->topicName, &newTopic->completed) != 2) {
                free(newTopic);
                break;
            }

            if (strcmp(newTopic->topicName, "END") == 0) {
                free(newTopic);
                break;
            }

            newTopic->next = NULL;
            if (newUser->topics == NULL) {
                newUser->topics = newTopic;
            } else {
                lastTopic->next = newTopic;
            }
            lastTopic = newTopic;
        }

        if (*head == NULL) {
            *head = newUser;
        } else {
            tempUser = *head;
            while (tempUser->next != NULL) {
                tempUser = tempUser->next;
            }
            tempUser->next = newUser;
        }
    }

    fclose(file);
    printf("User data loaded successfully.\n");
}

// Function to free all dynamically allocated memory
void freeMemory(struct User *head) {
    struct User *tempUser;
    while (head != NULL) {
        tempUser = head;
        head = head->next;

        struct LearningTopic *tempTopic = tempUser->topics;
        while (tempTopic != NULL) {
            struct LearningTopic *nextTopic = tempTopic->next;
            free(tempTopic);
            tempTopic = nextTopic;
        }

        free(tempUser);
    }
}
