#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x; int y;
} Tuple;

const Tuple neighbors[] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {2, -1}, {2, 1}, {1, -2}, {1, 2}};

typedef struct {
    Tuple items[1000000];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = 0;
}

bool isEmpty(Queue* q) {
    return q->front == q->rear-1;
}

void enqueue(Queue* q, Tuple t) {
    q->items[q->rear] = t;
    q->rear++;
}

Tuple dequeue(Queue* q) {
    q->front++;
    return q->items[q->front];
}

int main(){
    int n;
    scanf("%d", &n);
    bool visited[n][n];
    int distance[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            visited[i][j] = false;
            distance[i][j] = 0;
        }
    }

    Queue q;
    initQueue(&q);

    visited[0][0] = true;
    distance[0][0] = 0;
    enqueue(&q, (Tuple){0, 0});
    while (!isEmpty(&q)) {
        Tuple current = dequeue(&q);
        int i = current.x; int j = current.y;
        for (int k=0; k<8; k++) {
            Tuple next = neighbors[k];
            int x = i+next.x; int y = j+next.y;
            if (x<0 || x>=n || y<0 || y>=n) continue;
            if (visited[x][y]) continue;
            visited[x][y] = true;
            distance[x][y] = distance[i][j]+1;
            enqueue(&q, (Tuple){x,y});
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", distance[i][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
