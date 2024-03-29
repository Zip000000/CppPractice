#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000

typedef struct Queue {
    int *data;
    int head, tail, length;
} Queue;

void init_queue(Queue *q, int length_input) {
    q->data = (int *)malloc(sizeof(int) * length_input);
    q->length = length_input;
    q->head = 0;
    q->tail = -1;
}

void push(Queue *q, int element) {
    if (q->tail + 1 < q->length) {
        q->tail++;
        q->data[q->tail] = element;
    }
}

int front(Queue *q) {
        return q->data[q->head];
}

void pop(Queue *q) {
        q->head++;
}

int empty(Queue *q) {
    if (q->head > q->tail) {
        return 1;
    } else {
        return 0;
    }
}

void clear_queue(Queue *q) {
    free(q->data);
    free(q);
}

typedef struct Node {
    int vertex;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert_node(LinkedList head, int index) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->vertex = index;
    node->next = head;
    head = node;
    return head;
}

typedef struct Graph {
    LinkedList edges[MAX_N];
    int visited[MAX_N];
    int n;
}Graph;

void init_graph(Graph *g, int n) {
    g->n = n;
    memset(g->visited, 0, sizeof(g->visited));
    for (int i = 0; i < g->n; ++i) {
        g->edges[i] = NULL;
    }
}

void insert(Graph *g, int x, int y) {
    if (x < 0 || x >= g->n || y < 0 || y >= g->n) {
        return ;
    }
    g->edges[x] = insert_node(g->edges[x], y);
    g->edges[y] = insert_node(g->edges[y], x);
}

void clear_graph(Graph *g) {
    for (int i = 0; i < g->n; ++i) {
        Node *head = g->edges[i];
        while (head != NULL) {
            Node *delete_node = head;
            head = head->next;
            free(delete_node);
        }
    }
    free(g);
}

void bfs(Graph *g, int id) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q, MAX_N);
    push(q, id);
    g->visited[id] = 1;
    while(!empty(q)) {
        int now_data = front(q);
	    printf("%d\n", now_data);
        Node *cnode = g->edges[now_data];
        while(cnode) {
            if(g->visited[cnode->vertex] != 1) {
                g->visited[cnode->vertex] = 1;
                push(q, cnode->vertex);
            }
            cnode = cnode->next;
        }
        pop(q);
    }
    clear_queue(q);
    
}

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    init_graph(graph, n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        insert(graph, x, y);
    }
    scanf("%d", &k);
    bfs(graph, k);
    clear_graph(graph);
    return 0;
}