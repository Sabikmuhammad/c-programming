#include <stdio.h>

int main() {
    int preference;
    printf("Welcome to the Learning Preference Assessment!\n");
    printf("Please select your preferred learning style:\n");
    printf("1. Visual (Videos, Images)\n");
    printf("2. Auditory (Podcasts, Lectures)\n");
    printf("3. Kinesthetic (Hands-on Activities)\n");
    
    printf("Enter your choice (1, 2, or 3): ");
    scanf("%d", &preference);
    
    switch(preference) {
        case 1:
            printf("You prefer Visual learning. We recommend videos and diagrams for you.\n");
            break;
        case 2:
            printf("You prefer Auditory learning. We recommend podcasts and recorded lectures for you.\n");
            break;
        case 3:
            printf("You prefer Kinesthetic learning. We recommend hands-on activities and experiments for you.\n");
            break;
        default:
            printf("Invalid choice. Please run the program again and select a valid option.\n");
            break;
    }
    
    return 0;
}
