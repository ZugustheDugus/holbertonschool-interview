#include "lists.h"

/**
 * get_listint_size - returns the number of elements in a linked listint_t list
 * @head: pointer to the head of the list
 * Return: number of elements in a linked listint_t list
*/
int get_listint_size(listint_t *head)
{
	int i = 0;

	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * listint_to_array - converts a linked list to an array
 * @head: pointer to the head of the linked list
 * @array: pointer to the array
 * Return: pointer to the array
*/

int listint_to_array(listint_t *head, int *array)
{
	int i = 0;

	while (head != NULL)
	{
		array[i] = head->n;
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * check_palindrome - checks if an array is a palindrome
 * @array: pointer to the array
 * @size: size of the array
 * Return: 1 if the array is a palindrome, 0 otherwise
*/
int check_palindrome(int *array, int size)
{
	int i = 0;
	int j = size - 1;

	while (i < j)
	{
		if (array[i] != array[j])
			return (0);
		i++;
		j--;
	}
	return (1);
}


/**
 * is_paindrome - determines if linked list is palindrome
 * @head: linked list
 * Return: 1 if true else 0
*/
int is_palindrome(listint_t **head)
{
	listint_t *temp;
	int len, isPal, *arr;

	if (head == NULL || *head == NULL)
		return (1);
	temp = *head;
	len = get_listint_size(*head);
	arr = malloc(sizeof(int) * len);
	if (arr == NULL)
		return (0);
	temp = *head;
	listint_to_array(temp, arr);
	isPal = check_palindrome(arr, len);
	free(arr);
	return (isPal);
}
