#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0, count2 = 0;
void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}
void heapify(int *heap, int n, int root) {
int largest = root;
int left = 2 * root + 1;
int right = 2 * root + 2;
if (left < n) {
count++;
if (heap[left] > heap[largest]) {
largest = left;
}
}
if (right < n) {
count++;
if (heap[right] > heap[largest]) {
largest = right;
}
}
if (largest != root) {
swap(&heap[root], &heap[largest]);
heapify(heap, n, largest);
}
}
void heapSort(int *heap, int n) {
for (int i = (n / 2) - 1; i >= 0; i--) {
heapify(heap, n, i);
}
count2 = count;
count = 0;
for (int i = n - 1; i >= 0; i--) {
swap(&heap[0], &heap[i]);
heapify(heap, i, 0);
}
}int max(int a, int b) {
return (a > b) ? a : b;
}
void tester(){
int *arr, n;
printf("ENTER THE NUMBER OF ELEMENTS\n");
scanf("%d", &n);
arr = (int *)malloc(sizeof(int) * n);
printf("ENTER THE ELEMENTS OF THE ARRAY\n");
for (int i = 0; i < n; i++)
scanf("%d", &arr[i]);
printf("THE ELEMENTS OF THE ARRAY BEFORE SORTING\n");
for (int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
heapSort(arr, n);
printf("THE ELEMENTS OF THE ARRAY AFTER SORTING\n");
for (int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
free(arr);
}
void plotter() {
int *arr, n;
srand(time(NULL));
FILE *f1 = fopen("HEAPSORTBEST.txt", "a");
FILE *f2 = fopen("HEAPSORTWORST.txt", "a");
FILE *f3 = fopen("HEAPSORTAVG.txt", "a");
n = 100;
while (n <= 1000) {
arr = (int *)malloc(sizeof(int) * n);
// Best case: descending order
for (int i = 0; i < n; i++)
arr[i] = n - i;
count = 0;
heapSort(arr, n);
count = max(count, count2);
fprintf(f1, "%d\t%d\n", n, count);// Worst case: ascending order
for (int i = 0; i < n; i++)
arr[i] = i + 1;
count = 0;
heapSort(arr, n);
count = max(count, count2);
fprintf(f2, "%d\t%d\n", n, count);
// Average case: random order
for (int i = 0; i < n; i++)
arr[i] = rand() % n;
count = 0;
heapSort(arr, n);
count = max(count, count2);
fprintf(f3, "%d\t%d\n", n, count);
n += 100;
free(arr);
}
fclose(f1);
fclose(f2);
fclose(f3);
}
int main() {
int choice;
while (1) {
printf("ENTER 1. TO TEST HEAP SORT\n2. TO PLOT HEAP SORT\n3. TO EXIT\n");
scanf("%d", &choice);
switch (choice) {
case 1:
tester();
break;
case 2:
plotter();
break;
case 3:
exit(0);
default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}
