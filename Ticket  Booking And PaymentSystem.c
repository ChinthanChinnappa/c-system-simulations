#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char name[],contact[],date[],bus_type[]; 
int age;
float price;
void book_ticket()
{
    printf("\nEnter Name: ");
    scanf("%s", name);
	printf("Enter Age: ");
    scanf("%d", age);
	printf("Enter Contact Number: ");
    scanf("%s", contact);
	printf("Enter Travel Date: ");
    scanf("%s", date);
	printf("Enter Bus Type (AC/Non-AC): ");
    scanf("%s", bus_type);
	char bus_type;
	printf("Enter Bus Type (A for AC, N for Non-AC): ");
	scanf(" %c", &bus_type);
	if (bus_type == 'A' || bus_type == 'a')
	{
		price = 50000;
	}
	else
	{
    price = 3000.0;
	}
	printf("\n Booked Ticket Price: %.2f\n", *price);
}
void make_payment()
{
    char method[20], transaction_id[20];
    float amount;

    printf("\nEnter Payment Method: ");
    scanf("%s", method);

    printf("Enter Amount: ");
    scanf("%f", &amount);

    if (amount < price) {
        printf("\nPayment Failed! Insufficient Amount.\n");
        return;
    }

    printf("Enter Transaction ID: ");
    scanf("%s", transaction_id);

    printf("\nPayment Successful! Transaction ID: %s\n", transaction_id);
}

void cancel_ticket(float price) {
    char choice;
    printf("\nDo you want to cancel your ticket? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("\nTicket Cancelled! Refund Amount: %.2f\n", price * 0.9);
    } else {
        printf("\nTicket Not Cancelled.\n");
    }
}

int main() {
    char name[50], contact[15], date[15], bus_type[10];
    int age;
    float price;

    book_ticket(name, age, contact, date, bus_type, price);
    make_payment(price);
    cancel_ticket(price);

    return 0;
}
