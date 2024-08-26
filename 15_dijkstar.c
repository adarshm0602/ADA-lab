//12: Dijkstra’s Algorithm:
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n, i, j, src, heapsize = 0, cost[10][10], d[10];
int graphcount = 0, heapcount = 0, max = 0;
struct edge {
int id;
int dist;
} heap[10];
typedef struct edge edg;
void swap(struct edge *a, struct edge *b) {
struct edge temp = *a;
*a = *b;
*b = temp;
}
void heapify(struct edge arr[], int n, int i) {
int smallest = i;
int left = (2*i);
int right = ((2*i)+1);
heapcount++;
if (left <= n && arr[left].dist < arr[smallest].dist)
smallest = left;
if (right <= n && arr[right].dist < arr[smallest].dist)
smallest = right;
if (smallest != i) {
swap(&arr[i], &arr[smallest]);
heapify(arr, n, smallest);
}
}
void makegraph() {
printf("Enter the total number of vertices: ");
scanf("%d", &n);
printf("Enter the cost matrix of the Graph\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", &cost[i][j]);
if (cost[i][j] == 0)
cost[i][j] = INT_MAX;
}
}
// Initialise the source vertex distance to 0 and rest all to infinity(INT_MAX)
printf("Enter the source vertex: ");
scanf("%d", &src);
for (i = 0; i < n; i++) {
d[i] = INT_MAX;
}
d[src] = 0;
}
void createRandomGraph(int n) {
for (i = 0; i < n; i++) {for (j = 0; j < n; j++) {
cost[i][j] = rand() % 5;
if (cost[i][j] == 0)
cost[i][j] = INT_MAX;
}
}
src = 0;
for (i = 0; i < n; i++) {
d[i] = INT_MAX;
}
d[src] = 0;
}
edg deleteheap(edg heap[]) {
edg min = heap[1];
heap[1] = heap[heapsize];
heapsize = heapsize - 1;
heapify(heap, heapsize, 1); // Restore heap order
return min;
}
void insert(edg heap[], int node, int dist){
heapsize++;
heap[heapsize].id = node;
heap[heapsize].dist = dist;
int index = heapsize;
while(index > 1){
int parent = index/2;
if(heap[parent].dist > heap[index].dist){
swap(&heap[parent],&heap[index]);
index = parent;
}
else break;
}
}
void dijkstra(){
heapsize = 0;
insert(heap,src,0);
d[src] = 0;
while(heapsize != 0){
int dist = heap[1].dist;
int node = heap[1].id;
deleteheap(heap);
for(int i = 0; i < n; i++){
graphcount++;
if(cost[node][i] != INT_MAX){ //Extremely important, cuz not writing it can lead to integer overflow to negative values in dist+cost[node][i] line, thereby giving very low distances.
int newDist = dist + cost[node][i];
int newNode = i;
if(d[newNode] > newDist){
d[newNode] = newDist;
insert(heap,newNode,newDist);
}
}
}
}}
void tester() {
makegraph();
dijkstra();
printf("Shortest path from source %d is:\n", src);
for (i = 0; i < n; i++) {
if (src != i)
printf("%d -> %d = %d\n", src, i, d[i]);
}
}
void plotter() {
FILE *f1;
f1 = fopen("dijkstrasgraph.txt", "a");
srand(time(NULL));
for(int i = 4; i <= 8; i++){
createRandomGraph(i);
n = i;
max = 0;
graphcount = 0;
heapcount = 0;
heapsize = 0;
dijkstra();
max = (graphcount > heapcount) ? graphcount : heapcount;
fprintf(f1, "%d\t%d\n", n, max);
}
}
int main() {
int choice;
printf("1.Tester \n2.Plotter \n3.Exit\n ");
while (1) {
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
}
}
return 0;
}
