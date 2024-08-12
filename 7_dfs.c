#include <stdio.h>
#include <stdlib.h>
int graph[100][100], visited[100], path[100], isCyclic = 0;
int dfsCount = 0, count = 0, dcount = 0;
int d;
void dfs(int n, int start, int parent, int whoCalled) {
visited[start] = 1;
path[start] = 1;
count++;
if(!whoCalled) printf("--> %c ", start + 65);
for (int i = 0; i < n; i++) {
if (d == 1) {
if (i != parent && graph[start][i] && visited[i] == 1 && path[i] == 1)
isCyclic = 1;
} else {
if (i != parent && graph[start][i] && visited[i]) 
isCyclic = 1;
}
dcount++;
if (graph[start][i] && visited[i] == 0)
dfs(n, i, start, whoCalled);
}
path[start] = 0;
}
void ploter(int k) {
FILE *f1 = fopen("DFSBEST.txt", "a");
FILE *f2 = fopen("DFSWORST.txt", "a");
int v;
for (int i = 1; i <= 10; i++) {
v = i;
if (k == 0) {
for (int i = 0; i < v; i++) {
for (int j = 0; j < v; j++) {
if (i != j)
graph[i][j] = 1;
else
graph[i][j] = 0;
}
}
}
if (k == 1) {
for (int i = 0; i < v; i++) {
for (int j = 0; j < v; j++)
graph[i][j] = 0;}
for (int i = 0; i < v - 1; i++) {
graph[i][i + 1] = 1;
}
}
isCyclic = 0;
dfsCount = 0;
count = 0;
dcount = 0;
for (int j = 0; j < v; j++) {
visited[j] = 0;
path[j] = 0;
}
dfs(v, 0,-1, 1);
dfsCount++;
int start = 1;
while (count != v) {
if (visited[start] != 1) {
dfs(v, start, -1, 1);
dfsCount++;
}
start++;
}
if (k == 0)
fprintf(f2, "%d\t%d\n", v, dcount);
else
fprintf(f1, "%d\t%d\n", v, dcount);
}
fclose(f1);
fclose(f2);
}
void tester() {
int n;
printf("Enter the number of nodes in the graph:\n");
scanf("%d", &n);
printf("Enter the Adjacency Matrix:\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &graph[i][j]);
}
visited[i] = 0;
path[i] = 0;
}
printf("The Adjacency Matrix:\n");
for (int i = 0; i < n; i++) {for (int j = 0; j < n; j++) {
printf("%d ", graph[i][j]);
}
printf("\n");
}
isCyclic = 0;
count = 0;
dcount = 0;
dfsCount = 0;
printf("\nDFS traversal starting from node %c\n", 65);
dfs(n, 0,-1, 0);
dfsCount++;
if (count == n)
printf("\nThe Graph is connected\n");
else {
printf("\nThe Graph is not connected\n");
int start = 1;
while (count != n) {
if (visited[start] != 1) {
printf("\n");
dfs(n, start, -1, 0);
dfsCount++;
}
start++;
}
}
printf("\nThe number of components is %d\n", dfsCount);
if (isCyclic)
printf("\nThe graph is cyclic\n");
else
printf("\nThe graph is not cyclic\n");
}
int main() {
for (;;) {
int key;
printf("Enter the choice:\n1. To Test DFS\n2. To Plot\nAny other number to Exit\n");
scanf("%d", &key);
switch (key) {
case 1:
tester();
break;
case 2:
for (int i = 0; i < 2; i++)
ploter(i);
printf("Data entered into the files\n");
break;
default:exit(0);
}
}
return 0;
}
