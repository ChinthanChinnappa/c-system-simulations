#include <stdio.h>

int main()
{
    int res, menut, status;
    float prices[4] = {80.0, 50.0, 17.0, 40.0};
    char menu[4][10] = {"Rice", "Burger", "Chappathi", "Salad"};
    
    printf("1. Restaurant A\n2. Restaurant B\n3. Restaurant C\nSelect a restaurant (1-3): ");
    scanf("%d", &res);
    if (res < 1 || res > 3) 
    {
        printf("Invalid restaurant!\n");
        return 1;
    }
    
    printf("\n1. Rice (rs 80)\n2. Burger (rs 50)\n3. Chappathi (rs 17)\n4. Salad (rs 40)\nSelect menu item (1-4): ");
    scanf("%d", &menut);
    if (menut < 1 || menut > 4) 
    {
        printf("Invalid menu choice!\n");
        return 1;
    }
    
    printf("\nYou ordered: %s. Total: rs %.2f\n", menu[menut-1], prices[menut-1]);
    printf("Enter card number to pay: ");
    char card[20];
    scanf("%s", card);
    printf("Enter 1 for successful payment notification or 0 for failure : ");
    scanf("%d", &status);
    
    if (status == 1) 
    {
        printf("Payment successful Order placed.\n");
    }
    else 
    {
        printf("Payment failed. Try again .\n");
    }
    
    return 0;
}
