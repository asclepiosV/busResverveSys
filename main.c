#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Bus {
    int line;
    double price;
    int place;
};

struct User {
    char username[50];
    char password[50];
};

int a = 1;
int choice;
char ok[1];
char agree[1];

bool login();
double priceCalculator();

int main() {
    bool log = false;
    struct Bus bus1 = {1, 2.50, 20};
    struct Bus bus2 = {2, 10.00, 20};
    struct Bus bus3 = {3, 7.05, 20};

    printf("Bus line: %d, Price: %f, Number of tickets: %d\n", bus1.line, bus1.price, bus1.place);
    printf("Bus line: %d, Price: %f, Number of tickets: %d\n", bus2.line, bus2.price, bus2.place);
    printf("Bus line: %d, Price: %f, Number of tickets: %d\n", bus3.line, bus3.price, bus3.place);

    log = login(log);

    if (log == true) {

        do {
            printf("\nType a bus number: \n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    bus1.price = priceCalculator(bus1.line, bus1.place, bus1.price);
                    printf("%d chosen\nIt will cost you %f €\n", choice, bus1.price);
                    printf("Do you want to buy it? y/n\n");
                    scanf("%s", agree);
                    if (strcmp(agree, "y") == 0) {
                        bus1.place -= 1;
                    } else {
                        printf("Ok, you can choose another bus\n");
                    }
                    break;
                case 2:
                    bus2.price = priceCalculator(bus2.line, bus2.price, bus2.place);
                    printf("%d chosen\nIt will cost you %f €\n", choice, bus2.price);
                    bus2.place -= 1;
                    printf("Do you want to buy it? y/n\n");
                    scanf("%s", agree);
                    if (strcmp(agree, "y") == 0) {
                        bus2.place -= 1;
                    } else {
                        printf("Ok, you can choose another bus\n");
                    }
                    break;
                case 3:
                    bus3.price = priceCalculator(bus3.line, bus3.price, bus3.place);
                    printf("%d chosen\nIt will cost you %f €\n", choice, bus3.price);
                    printf("Do you want to buy it? y/n\n");
                    scanf("%s", agree);
                    if (strcmp(agree, "y") == 0) {
                        bus3.place -= 1;
                    } else {
                        printf("Ok, you can choose another bus\n");
                    }
                    break;
                default:
                    printf("Next time choose the right bus pls\n");
                    break;
            }
            printf("Bus line: %d, Number of tickets: %d\n", bus1.line, bus1.place);
            printf("Bus line: %d, Number of tickets: %d\n", bus2.line, bus2.place);
            printf("Bus line: %d, Number of tickets: %d\n", bus3.line, bus3.place);

            printf("Do you and an other one? y/n\n");
            scanf("%s", ok);
            if (strcmp(ok, "y") == 0) {
                a = a;
            } else {
                a = 0;
            }
        } while (a == 1);
    }
    else printf("Please log in\n");
    printf("Thank you bye\n");
    return 0;
}


bool login(log){
    char id[8], p[6];
    int n=1, x, y;
    struct User u1 = {"admin", "admin"};

    do{
        printf("\nUsername:");
        scanf("%s", &id);

        printf("\nPassword:");
        scanf("%s", &p);

        x=strcmp(id, u1.username);
        y=strcmp(p, u1.password);

        if(x==0 && y==0){
            printf("\nSucessfully Logged In");
            log = true;
        }else {
            printf("\nWrong Password, try again", 5-n);
            n++;}

        if(n>5){
            printf("\nAccess Denied");
        }

    }while (log != true && n<=5);
    return log;
}

double priceCalculator(int bus, double price, int place){
    switch (bus) {
        case 1:
            price = 100.00/place;
            break;
        case 2:
            price = 60.00/place ;
            break;
        case 3:
            price = 50.00/place;
            break;
        default: price = price;
    }
    return price;
}