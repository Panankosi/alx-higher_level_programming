#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_t - singly linked list
 * @data: Integer stored in the node
 * @next: Pointer to the next node
 */
{
	int data;
	struct listint_t *next;
} listint_t;

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head: Pointer to a pointer to the head of the list
 * @number: The number to insert
 *
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	return (NULL);

	new_node->data = number;
	new_node->next = NULL;

	if (*head == NULL || number < (*head)->data)
	{
	new_node->next = *head;
	*head = new_node;
	return (new_node);
	}

	listint_t *current = *head;

	while (current->next != NULL && current->next->data < number)
	{
	current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}

int main(void)
{
	listint_t *head = NULL;

	insert_node(&head, 5);
	insert_node(&head, 10);
	insert_node(&head, 2);

	listint_t *current = head;

	while (current != NULL)
	{
	printf("%d\t->\t", current->data);
	current = current->next;
	}

	printf("NULL\n");

	while (head != NULL)
	
	{
	listint_t *temp = head;
	head = head->next;
	free(temp);
	}

	return (0);
}

