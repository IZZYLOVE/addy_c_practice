#include <stdio.h>
#include <stdlib.h>/* for screen clear etc */
#include "struct.h"
#include <string.h>
#include "myfunctions.h"

struct nodestudent *head = NULL; /* making head a global variable */

/**
 * insert_at_nth_position - processes linked list and inserts
 * a node at specified position
 * @sn: position to insert node
 * @name: name of student
 * @score: score of student
 * Return: void
 */
void insert_at_nth_position(int *sn, char *name, float *score)
{
	int i = 0;
	int c = 0;

	struct nodestudent *prev = NULL;
	struct nodestudent *current = NULL;
	struct nodestudent *next = NULL;

	current = malloc(sizeof(struct nodestudent));

	printf("size of struct nodestudent is %ld\n", sizeof(struct nodestudent));

	if (current == NULL)
	{
		if (c == 0)
		{
			/* unwanted call */
			printf("\n\nthe voluntary call\n\n ");
		}
		else
		{
			printf("\n\nmalloc error, insufficient memory\n\n ");
		}
	}
	else
	{
		strcpy(current->name, name);
		current->score = *score;
		current->next = NULL;

		/**
		* to insert data into a list, there can be two scenerios;
		* one where the list is empty
		* where the lis is not empty
		*/

		/* if the list is empty or we want to insert at the beginning */
		if (*sn <= 1 || head == NULL)
		{
			prev = NULL;
			/* first set current->next to head */
			current->next = head;
			/* the set head to current */
			head = current;
		}
		else if (*sn > 1)
		{
			prev = head;
			/**
			 * determine the link parameters
			 * the target position is (*sn - 1)
			 */

			for (i = 1; i < (*sn - 1) && prev->next != NULL; i++)
			{
				prev = prev->next;
			}
			/* first set next as prev->next */
			next = prev->next;
			/* then set prev->next as current */
			prev->next = current;
			/* then set current->next to next */
			current->next = next;
		}
	}
	free(sn);
	free(name);
	free(score);
	if (current->name == NULL)
		free(current);
}

/**
 * delete_nth_position - processes linked list and deleyes the specified
 * link from linked list
 * @n: position to delete from
 * Return: void
 */
void delete_nth_position(int *n)
{
	int i;
	struct nodestudent *next = NULL;
	struct nodestudent *current = NULL;
	struct nodestudent *prev = head;

	if (*n <= 1)
	{
		current = prev;
		head = next = prev->next;
		free(current);
		printf("Number %d Record deleted!\n", *n);
	}
	else
	{
		/* target the node before the nth node */
		for (i = 1; i < (*n - 1) && prev->next != NULL; i++)
			prev = prev->next;
		if (prev->next != NULL)
		{
			/* first set current = prev->next */
			current = prev->next;
			/* then to re-link, set prev->next = current->next */
			prev->next = current->next;
			/* then free current */
			free(current);

			printf("Number %d Record deleted!\n", *n);
		}
		else
		{
			printf("Delete failed, ");
			printf("number %d Record does not exist!\n", *n);
		}
	}
}


/**
 * print - processes structure and prints from liked list
 * Return: void
 */
void print(void)
{
	int i;
	struct nodestudent *prev = NULL;
	struct nodestudent *current = NULL;

	current = head;
	for (i = 1; current != NULL; i++)
	{
		printf("%d %s %f\n", i, current->name, current->score);
		prev = current;
		current = current->next;
	}
}


/**
 * recursive_reverse_print - prints the liked list in the reverse order
 * Return: void
 */
void recursive_reverse_print(struct nodestudent *lhead, int i)
{
	i++;
	struct nodestudent *prev = NULL;
	struct nodestudent *current = NULL;
	struct nodestudent *next = NULL;
	current = lhead;
	if (current == NULL)
		return; 
	recursive_reverse_print(current->next, i);
	printf("%d %s %f\n", i, current->name, current->score);
}


void recursive_reverse_link(struct nodestudent *lhead)
{
        struct nodestudent *prev = NULL;
        struct nodestudent *current = NULL;
        struct nodestudent *next = NULL;
        current = lhead;
        if (current->next == NULL)
	{
		head = current;
                return;
	}
        recursive_reverse_link(current->next);
       	prev = current->next;
	prev->next = current;
	current->next = NULL;

}

void itratively_reverse_link(void)
{
	int i;
	struct nodestudent *prev = NULL;
	struct nodestudent *current = NULL;
	struct nodestudent *next = NULL;

	current = head;
	for (i = 0; current != NULL; i++)
	{
		/* first set next to current->next */
		next = current->next;
		/* then set current ->next to prev */
		current->next = prev;
		/* set prev to current */
		prev = current;
		/* the set current to next */
		current = next;
	}
	head = prev;
}




/**
 * free_link - frees every node of the liked list
 * Return: void
 */
void free_link(void)
{
        int i;
        struct nodestudent *prev = NULL;
        struct nodestudent *current = NULL;
	struct nodestudent *next = NULL;

        current = head;
        for (i = 1; current != NULL; i++)
        {
                prev = current;
                next = current->next;
		free(current);
		current = next;

        }
}


/**
 * main - processes structure as node to linked list and
 * can handle any size of liked list
 * run time initialization practice of structures in c
 * this program initializes the variable for structure at run time
 * struct nodestudent: structure data type
 * Return: void
 */
void main(void)
{
	system("clear");
	printf("STUDENTS EXAM RECORDS USING SINGLY LINKED LIST\n\n");

	struct nodestudent *current;
	int *rn;
	float *score;
	char *name;
	struct nodestudent *next, *prev;

	prev = current = next = head = NULL; /* empty list */

	int *dl, i, j, d;
	char cnt = 'y';
	char g;

	for (j = 1; j >= 1 && cnt != 'n'; j++)
	{
		printf("enter name of student:");
		name = myscan_char();
		printf("enter score:");
		score = myscan_float();
		printf("enter rolenumber:");
		rn = myscan_int();

		insert_at_nth_position(rn, name, score);

		printf("\n\nPRINTING:\n");
		print();

		printf("\n\nTo delete enter d or do you want to enter another record? y/n:");
		scanf("%s", &cnt);

		if (cnt == 'd')
		{
			printf("enter record number to delete: ");
			dl = myscan_int();
			delete_nth_position(dl);
			free(dl);
			print();
			printf("To delete enter d, ");
			printf(" or do you want to enter another record? y/n:");
			scanf("%s", &cnt);
		}
		
	
		if (cnt == 'n')
		{
			printf("\n\nRECURSIVE REVERSE PRINT\n");
			recursive_reverse_print(head, 0);
			printf("\n\nDo you want to reverse link recursively? y/n:");
			scanf("%s", &g);

			if (g == 'y')
			{
			printf("\n\nRECURSIVELY REVERSED LINK\n");
			recursive_reverse_link(head);
			print();
			}
			else
			{
			printf("\n\nITRATIVELY REVERSED LINK\n");
			itratively_reverse_link();
			print();
			}
		}
	}
	free_link();
}
