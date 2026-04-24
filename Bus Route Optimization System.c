#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 9999
typedef enum 
{add = 1, find, update, exits} menu;
typedef enum menu m;
typedef struct 
{
    int time[MAX][MAX];
    char stops[MAX][20];
    int no_stops;
} bus;
bus b;
int dist[MAX], p[MAX], spath[MAX], path[MAX];
int min, v, i, j, w, x, u;
int src, dest, trtime;

void addR(int src, int dst, int trtime)
{
    b.time[src][dst] = trtime;
    b.time[dst][src] = trtime;
}

int minm()
{
    min = INF;
    w = -1;
    for (v = 0; v < b.no_stops; v++) 
    {
        if (dist[v] < min && p[v] == -1)
        {
            min = dist[v];
            w = v;
        }
    }
    return w;
}

void s(int src)
{
    for (i = 0; i < b.no_stops; i++) 
    {
        dist[i] = INF;
        spath[i] = 0;
        p[i] = -1;
    }
    dist[src] = 0;
    for (j = 0; j < b.no_stops - 1; j++) 
    {
        u = minm();
        spath[u] = 1;
        for (int v = 0; v < b.no_stops; v++) 
        {
            if (!spath[v] && b.time[u][v] != INF && dist[u] != INF && dist[u] + b.time[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + b.time[u][v];
                p[v] = u;
            }
        }
    }
}

void dispRoute(int dest) 
{
    if (p[dest] == -1) 
    {
        printf("No route available \n");
        return;
    }
    printf("New route is: \n");
    x = 0;
    while (dest != -1) 
    {
        path[x] = dest;
        dest = p[dest];
        x++;
    }
    for (i = x - 1; i >= 0; i--) 
    {
        printf("%s ", b.stops[path[i]]);
        if (i > 0) printf("-> ");
    }
    printf("\n");
}

int main() 
{
    b.no_stops = 5;

    printf("Enter names of bus stops:\n");
    for (int i = 0; i < b.no_stops; i++) {
        printf("Enter name for stop %d: ", i + 1);
        scanf("%s", b.stops[i]);
    }

    int choice;
    while (choice != exits) 
    {
        printf("\nMenu:\n");
        printf("1. Add Route\n2. Find Route\n3. Update Route\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == add) 
        {
            printf("Enter source stop (0 to %d): ", b.no_stops - 1);
            scanf("%d", &src);
            printf("Enter destination stop (0 to %d): ", b.no_stops - 1);
            scanf("%d", &dest);
            if (src < 0 || src >= b.no_stops || dest < 0 || dest >= b.no_stops) {
                printf("Invalid bus stop numbers.\n");
                continue;
            }
            printf("Enter travel time: ");
            scanf("%d", &trtime);
            addR(src, dest, trtime);
            printf("Route added.\n");
        }

        else if (choice == find) 
        {
            printf("Enter source stop no: ");
            scanf("%d", &src);
            printf("Enter destination stop no: ");
            scanf("%d", &dest);
            if (src < 0 || src >= b.no_stops || dest < 0 || dest >= b.no_stops) {
                printf("Invalid bus stop numbers.\n");
                continue;
            }
            s(src);
            printf("Shortest travel time from %s to %s: %d\n", b.stops[src], b.stops[dest], dist[dest]);
            dispRoute(dest);
        }

        else if (choice == update) 
        {
            printf("Enter source stop: ");
            scanf("%d", &src);
            printf("Enter destination stop: ");
            scanf("%d", &dest);
            if (src < 0 || src >= b.no_stops || dest < 0 || dest >= b.no_stops) {
                printf("Invalid bus stop numbers.\n");
                continue;
            }
            printf("Enter new travel time: ");
            scanf("%d", &trtime);
            addR(src, dest, trtime);
            printf("Route updated.\n");
        }

        else if (choice == exits)
        {
            printf("Exiting program.\n");
        } 
        else 
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
