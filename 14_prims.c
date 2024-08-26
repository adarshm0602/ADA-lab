//11b) Prim’s Algo:
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
// Global Variables
int n, i, j, cost[20][20], cnt = 0, visited[20], removed[20];
int heapsize = 0;
int heapcount, graphcount, max;
// Edge structure
struct edge {
int v;
int dist;
int u;
} heap[20], ans[20];
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
if (smallest!= i) {
swap(&arr[i], &arr[smallest]);
heapify(arr, n, smallest);
}
}
void makegraph() {
printf("Enter the total number of vertices:");scanf("%d", &n);
printf("Enter the cost matrix of the Graph\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", &cost[i][j]);
if (cost[i][j] == 0)
cost[i][j] = INT_MAX;
}
}
}
void createRandomGraph(int n) {
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
cost[i][j] = rand() % 5;
if (cost[i][j] == 0)
cost[i][j] = INT_MAX;
}
}
}
edg deleteheap(edg heap[]) {
edg min = heap[1];
heap[1] = heap[heapsize];
heapsize = heapsize - 1;
heapify(heap, heapsize, 1); // Restore heap order
return min;
}
void insert(edg heap[], int start, int end, int dist){
//Start represents parent, end represents where parent is pointing to.
heapsize++;
heap[heapsize].v = start;
heap[heapsize].u = end;
heap[heapsize].dist = dist;
int index = heapsize;
while(index > 1){
int parent = index/2;
if(heap[parent].dist > heap[index].dist){
swap(&heap[parent],&heap[index]);
index = parent;
}
else break;}
}
void prim(){
//heap, ans, cost
cnt = 0;
heapsize = 0;
int visited[n];
for(int i = 0; i < n; i++) visited[i] = 0;
insert(heap,-1,0,0);
while(cnt != n){
edg temp = deleteheap(heap);
int wt = temp.dist;
int start = temp.v;
int end = temp.u;
if(visited[end]) continue;
if(end != 0){
ans[cnt].dist = wt;
ans[cnt].v = start;
ans[cnt].u = end;
}
visited[end] = 1;
for(int i = 0; i < n; i++){
graphcount++;
if(cost[end][i] != INT_MAX && !visited[i]){
insert(heap,end,i,cost[end][i]);
}
}
cnt++;
}
}
void tester() {
int sum = 0;
makegraph();
prim();
for (int i = 1; i < cnt; i++) {printf("%c --> %c == %d\n", ans[i].v + 65, ans[i].u + 65,
ans[i].dist);
sum += ans[i].dist;
}
printf("Minimum Distance is: %d\n", sum);
}
void plotter() {
FILE *f1;
f1 = fopen("primsgraph.txt", "a");
int sum = 0;
cnt = 0;
heapsize = 0;
heapcount = 0;
graphcount = 0;
max = 0;
srand(time(NULL));
for(int i = 4; i <= 8; i++){
n = i;
createRandomGraph(i);
prim();
for (int j = 1; j <= i; j++)
sum += ans[j].dist;
max = (graphcount < heapcount) ? graphcount: heapcount;
fprintf(f1, "%d\t%d\n", n, max);
}
}
void main() {
int ch;
while (1) {
printf("Enter choice 1 to run tester, 2 to run plotter, and 0 to exit\n");
scanf("%d", &ch);
switch (ch) {
case 1:
tester();
break;
case 2:
plotter();
break;
default:
exit(0);}
}
}
