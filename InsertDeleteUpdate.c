#include <stdio.h>

#define SIZE 5

typedef struct {
    int arr[SIZE];
    int front;
    int rear;
    int count;
} Queue;

void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(const Queue *q) {
    return q->count == 0;
}

int isFull(const Queue *q) {
    return q->count == SIZE;
}

void insertElement(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full; cannot insert %d.\n", value);
        return;
    }

    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = value;
    q->count++;

    printf("%d inserted into the queue.\n", value);
}

void deleteElement(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty; nothing to delete.\n");
        return;
    }

    printf("%d deleted from the queue.\n", q->arr[q->front]);
    q->front = (q->front + 1) % SIZE;
    q->count--;
}

void updateElement(Queue *q, int position, int newValue) {
    if (isEmpty(q)) {
        printf("Queue is empty; nothing to update.\n");
        return;
    }

    if (position < 1 || position > q->count) {
        printf("Invalid position. Enter a value from 1 to %d.\n", q->count);
        return;
    }

    int index = (q->front + position - 1) % SIZE;

    printf("Element at position %d changed from %d to %d.\n",
           position, q->arr[index], newValue);

    q->arr[index] = newValue;
}

void displayQueue(const Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (front -> rear): ");

    for (int i = 0; i < q->count; i++) {
        int index = (q->front + i) % SIZE;
        printf("%d ", q->arr[index]);
    }

    printf("\n");
}

/* Discard the rest of the current input line. */
void clearInputLine(void) {
    int character;

    while ((character = getchar()) != '\n' && character != EOF) {
        /* Keep reading until the line ends. */
    }
}

int main(void) {
    Queue q;
    int choice;
    int value;
    int position;

    initializeQueue(&q);

    do {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Update element\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputLine();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a whole number.\n");
                    clearInputLine();
                    break;
                }

                insertElement(&q, value);
                break;

            case 2:
                deleteElement(&q);
                break;

            case 3:
                printf("Enter position to update (1 = front): ");

                if (scanf("%d", &position) != 1) {
                    printf("Invalid input. Please enter a whole number.\n");
                    clearInputLine();
                    break;
                }

                printf("Enter the new value: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a whole number.\n");
                    clearInputLine();
                    break;
                }

                updateElement(&q, position, value);
                break;

            case 4:
                displayQueue(&q);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
