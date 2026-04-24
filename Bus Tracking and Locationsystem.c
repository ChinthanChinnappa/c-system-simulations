#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define AVG 40

int stop_distances[MAX] = {0, 2, 5, 9, 14};

int estimate_time(int current_distance, int stop_distance)
{
    int distance_left = stop_distance - current_distance;
    return (distance_left * 60) / AVG;
}

void display_bus_status(int current_stop)
{
    printf("\nBus is at Stop %d\n", current_stop);
    for (int i = current_stop; i < MAX; i++) {
        int time = estimate_time(stop_distances[current_stop], stop_distances[i]);
        printf("Time to Stop %d: %d minutes\n", i + 1, time);
    }
}

int main() 
{
    int current_stop = 1;
    display_bus_status(current_stop);

    current_stop = 2;
    display_bus_status(current_stop);

    return 0;
}
