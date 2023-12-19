#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*** Function Prototypes  ***/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/*** Utilities ***/
int _writeline(char *str);
int _is_digits(char *x);
int _isdigit(char x);
int _atoi(char *str);
int _isspace(char c);
int _strlen(char *string);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
int _putstring(char *str);
void _print_ints(int arr[], unsigned int size);
void _print_int(int n);
void _print_ints_n_txt(int arr[], unsigned int size, char *txt);
void printArray(int arr[], int size);

int partition(int array[], int start, int end, size_t size);
void quicksrt(int A[], int first, int last, size_t size);
void swap(int *x, int *y);
void mergesrt(int A[], int left, int right);
void merge(int A[], int left, int mid, int right);
int get_max(int *array, int size);
int *array_from_boundary(int A[], int left, int end);
void quicksort_fn_hoare(int A[], int low, int high, size_t size);
int hoare_lf_pvt(int A[], int left, int right, size_t size);
int hoare_rt_pvt(int A[], int left, int right, size_t size);

void printArray(int arr[], int size);
void heap_sort(int *array, size_t size);

#endif
