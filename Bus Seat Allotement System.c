#include <stdio.h>
#include <string.h>
#define m 10 
typedef struct {
    char name[50];
    int age;
    char contact[15];
} person;

person seats[10] = {0};

void bookSeat() 
{
    int seat;
    printf("Enter seat number (1-%d): ", m);
    scanf("%d", &seat);
    
    if (seat < 1 || seat > m || seats[seat - 1].age != 0) {
        printf("Invalid\n");
        return;
    }
    
    printf("Enter Name: ");
    scanf(" %[^\n]", seats[seat - 1].name);
    printf("Enter Age: ");
    scanf("%d", &seats[seat - 1].age);
    printf("Enter Contact: ");
    scanf("%s", seats[seat - 1].contact);
    
    printf("Seat %d booked \n", seat);
}
void cancelSeat() 
{
    int seat;
    printf("Enter seat number to cancel: ");
    scanf("%d", &seat);
    
    if (seat < 1 || seat > m || seats[seat - 1].age == 0) {
        printf("Invalid seat\n");
        return;
    }
    
    seats[seat - 1].age = 0;
    printf("Seat %d canceled!\n", seat);
}
void displaySeats() 
{
    printf("\nAllocated Seats are :\n");
    for (int i = 0; i < m; i++) {
        if (seats[i].age != 0) {
            printf("Seat %d: %s, Age: %d, Contact: %s\n", i + 1, seats[i].name, seats[i].age, seats[i].contact);
        }
    }
}
int main()
{
    int choice;
    while (1) {
        printf("\n1. Book Seat\n2. Cancel Seat\n3. Display Allocations\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) 
			bookSeat();
        else if (choice == 2) 
			cancelSeat();
        else if (choice == 3)
			displaySeats();
        else if (choice == 4) 
			break;
        else 
			printf("Invalid choice!\n");
    }
    return 0;
}
