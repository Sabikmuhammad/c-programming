#include <stdio.h>
#include <string.h>

#define MAX_TOPICS 5
#define MAX_USERS 100

// Structure to store learning topics
struct LearningTopic {
    char topicName[50];
    int completed;
};

// Structure to store user profile information
struct User {
    char name[50];
    int age;
    char learningStyle[20];
    struct LearningTopic topics[MAX_TOPICS];
};

// Function prototypes
void registerUser(struct User *user);
void chooseLearningStyle(struct User *user);
void chooseLearningTopics(struct User *user);
void trackProgress(struct User *user);

int main() {
    struct User users[MAX_USERS];
    int userCount = 0;
    int choice;

    printf("Welcome to the Personalized Learning Platform!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Register a new user\n");
        printf("2. Choose Learning Style\n");
        printf("3. Choose Learning Topics\n");
        printf("4. Track Progress\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser(&users[userCount]);
                userCount++;
                break;
            case 2:
                chooseLearningStyle(&users[userCount-1]);
                break;
            case 3:
                chooseLearningTopics(&users[userCount-1]);
                break;
            case 4:
                trackProgress(&users[userCount-1]);
                break;
            case 5:
                printf("Exiting the program. Thank you for using the platform!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

// Function to register a new user
void registerUser(struct User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);

    // Initialize topics
    for (int i = 0; i < MAX_TOPICS; i++) {
        user->topics[i].completed = 0; // Mark all topics as incomplete
    }

    printf("User %s registered successfully!\n", user->name);
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

// Function to choose learning topics
void chooseLearningTopics(struct User *user) {
    printf("Choose your learning topics (maximum 5):\n");
    printf("1. Mathematics\n");
    printf("2. Science\n");
    printf("3. History\n");
    printf("4. Computer Science\n");
    printf("5. Arts\n");

    for (int i = 0; i < MAX_TOPICS; i++) {
        printf("Enter topic %d (1-5): ", i + 1);
        int topicChoice;
        scanf("%d", &topicChoice);

        switch (topicChoice) {
            case 1:
                strcpy(user->topics[i].topicName, "Mathematics");
                break;
            case 2:
                strcpy(user->topics[i].topicName, "Science");
                break;
            case 3:
                strcpy(user->topics[i].topicName, "History");
                break;
            case 4:
                strcpy(user->topics[i].topicName, "Computer Science");
                break;
            case 5:
                strcpy(user->topics[i].topicName, "Arts");
                break;
            default:
                printf("Invalid choice, try again.\n");
                i--; // Let the user choose again
        }
    }

    printf("Topics successfully chosen.\n");
}

// Function to track progress on learning topics
void trackProgress(struct User *user) {
    printf("Track your learning progress:\n");
    for (int i = 0; i < MAX_TOPICS; i++) {
        if (strlen(user->topics[i].topicName) > 0) {
            printf("%d. %s - %s\n", i + 1, user->topics[i].topicName,
                   user->topics[i].completed ? "Completed" : "Incomplete");
        }
    }

    int topicNumber;
    printf("Enter the topic number to mark as complete: ");
    scanf("%d", &topicNumber);

    if (topicNumber > 0 && topicNumber <= MAX_TOPICS) {
        user->topics[topicNumber - 1].completed = 1;
        printf("%s marked as completed.\n", user->topics[topicNumber - 1].topicName);
    } else {
        printf("Invalid topic number.\n");
    }
}
