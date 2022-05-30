#include <stdio.h>
#include <string.h>

struct Bus {
    int line;
    double price;
    int place;
};

int a = 1;
int choice;
char ok[1];


int main() {
    struct Bus bus1 = {1, 2.50, 20};
    struct Bus bus2 = {2, 10.00, 20};
    struct Bus bus3 = {3, 7.05, 20};
    struct Bus test;

    printf("%d %f %d\n", bus1.line, bus1.price, bus1.place);
    printf("%d %f %d\n", bus2.line, bus2.price, bus2.place);
    printf("%d %f %d\n", bus3.line, bus3.price, bus3.place);


    do{
        printf("Type a number: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("%d chosen\nIt will cost you %f €\n", choice, bus1.price);
                bus1.place -= 1;
                break;
            case 2:
                printf("%d chosen\nIt will cost you %f €\n", choice, bus2.price);
                bus2.place -= 1;
                break;
            case 3:
                printf("%d chosen\nIt will cost you %f €\n", choice, bus3.price);
                bus3.place -= 1;
                break;
            default:
                printf("Next time choose the right bus pls\n");
                break;
        }
        printf("%d %f %d\n", bus1.line, bus1.price, bus1.place);
        printf("%d %f %d\n", bus2.line, bus2.price, bus2.place);
        printf("%d %f %d\n", bus3.line, bus3.price, bus3.place);

        printf("Do you and an other one? y/n\n");
        scanf("%s", ok);
        if (strcmp(ok, "y") == 0) {
            a = a;
        }
        else{
            a = 0;
        };

    } while (a == 1);
    printf("Thank you bye\n");
    return 0;
}


