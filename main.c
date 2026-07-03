#include <stdio.h>
#include <stdlib.h>

//Node Template
struct node {
	int data;
	struct node *next;
};

//Empty List Indicator
void emptyList() {
	printf("Head -> NULL\n\nList is empty.\n");
	return;
}

//Node Counter
void nodeCount(struct node *head) {
	int count = 0;
	if (head == NULL) {
		return;
	}
	struct node *temp = head;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}

	if (count <= 1) {
		printf("\nList Size: %d Node\n", count);
	} else {
		printf("\nList Size: %d Nodes\n", count);
	}
}

//Prints the List
void showList(struct node *head) {
	printf("\n");
	if (head == NULL) {
		emptyList();
		return;
	} else {
		struct node *temp = head;
		printf("Your List:\nHead -> ");
		while (temp != NULL) {
			printf("[%d] -> ", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

//Insertion @ Head
void insertAtHead (struct node **head, int data) {
	struct node *newNode = malloc(sizeof(*newNode));

	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

//Insertion @ Tail
void insertAtTail (struct node **head, int data) {
	if (*head == NULL) {
		insertAtHead(head, data);
	} else {
		struct node *newNode = malloc(sizeof(*newNode));
		struct node *temp = *head;

		newNode->data = data;
		newNode->next = NULL;

		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

//Deletion @ Head
void deleteAtHead(struct node **head) {
	if (*head == NULL) {
		return;
	} else {
		struct node *temp = *head;
		*head = temp->next;
		free(temp);
	}
}

//Deletion @ Tail
void deleteAtTail(struct node **head) {
	if (*head == NULL) { //Empty list
		return;
	} else if ((*head)->next == NULL) { //Only 1 node
		free(*head);
		*head = NULL;
		return;
	} else { //More than 1 node present
		struct node *temp = *head;
		struct node *prev = NULL;

		while(temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}

		prev->next = NULL;
		free(temp);
	}
}

//Deletion by Value
void deleteByValue(struct node **head, int key) {
	struct node *temp = *head;
	struct node *prev = NULL;

	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {//Empty list/value not found
		printf("\nValue not found.\n");
		return;
	} else if (prev == NULL) { //Only 1 Node
		*head = temp->next;
		free(temp);
	} else { //Deleting middle or tail
		prev->next = temp->next;
		free(temp);
	}
}

//Prints the menu
void printMenu() {
	printf("\n");
	printf("Menu\n");
	printf("----\n");
	printf("1. Insert Node at Head\n");
	printf("2. Insert Node at Tail\n");
	printf("3. Delete Node at Head\n");
	printf("4. Delete Node at Tail\n");
	printf("5. Delete by Value\n");
	printf("6. End Session\n");
}

//Invalid Input Indicator
void invalidInput() {
	printf("\nINVALID INPUT\n");
}

int main() {
	struct node *head = NULL;
	int choice;

	printf("============================\n");
	printf(" Singly Linked List Manager\n");
	printf("============================\n");

	showList(head);
	nodeCount(head);

	do {
		int input;
		printMenu();
		printf("\nChoose Action (1-6): ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("\n[Head Insertion]\nInput Value for New Node: ");
			scanf("%d", &input);
			insertAtHead(&head, input);
			break;
		case 2:
			printf("\n[Tail Insertion]\nInput Value for New Node: ");
			scanf("%d", &input);
			insertAtTail(&head, input);
			break;
		case 3:
			printf("\n[Deleting: Head]\n");
			deleteAtHead(&head);
			break;
		case 4:
			printf("\n[Deleting: Tail]\n");
			deleteAtTail(&head);
			break;
		case 5:
			printf("\nInput Target Value: ");
			scanf("%d", &input);
			printf("\n[Deleting: %d]\n", input);
			deleteByValue(&head, input);
			break;
		case 6:
			break;
		default:
			invalidInput();
			break;
		}

		if (choice >= 1 && choice <6) {
			showList(head);
			nodeCount(head);
		}

	} while (choice != 6);
	printf("\nSession Ended\n");
	showList(head);
	nodeCount(head);

	return 0;
}
