#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_VEHICLES 100

// Structure for customer information
struct Customer {
    int id;
    char name[50];
    char phone[15];
};

// Structure for vehicle information
struct Vehicle {
    int year;
    char make[20];
    char model[20];
    char license_plate[15];
    int customer_id; // Customer number who is currently renting the vehicle
};

struct Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

struct Vehicle vehicles[MAX_VEHICLES];
int num_vehicles = 0;

// Function to add a new customer
void addCustomer() {
    struct Customer new_customer;
    
    printf("Enter customer ID: ");
    scanf("%d", &new_customer.id);
    
    printf("Enter customer name: ");
    scanf("%s", new_customer.name);
    
    printf("Enter customer phone number: ");
    scanf("%s", new_customer.phone);
    
    customers[num_customers++] = new_customer;
    
    printf("Customer added successfully!\n");
}

// Function to add a new vehicle
void addVehicle() {
    struct Vehicle new_vehicle;
    
    printf("Enter vehicle model year: ");
    scanf("%d", &new_vehicle.year);
    
    printf("Enter vehicle make: ");
    scanf("%s", new_vehicle.make);
    
    printf("Enter vehicle model name: ");
    scanf("%s", new_vehicle.model);
    
    printf("Enter vehicle license plate number: ");
    scanf("%s", new_vehicle.license_plate);
    
    printf("Enter customer ID renting this vehicle: ");
    scanf("%d", &new_vehicle.customer_id);
    
    vehicles[num_vehicles++] = new_vehicle;
    
    printf("Vehicle added successfully!\n");
}

// Function to print customers' information
void printCustomers() {
    printf("\nCustomers' Information:\n");
    printf("ID\tName\tPhone\n");
    for(int i = 0; i < num_customers; i++) {
        printf("%d\t%s\t%s\n", customers[i].id, customers[i].name, customers[i].phone);
    }
}

// Function to print vehicles' information
void printVehicles() {
    printf("\nVehicles' Information:\n");
    printf("Year\tMake\tModel\tLicense Plate\tCustomer ID\n");
    for(int i = 0; i < num_vehicles; i++) {
        printf("%d\t%s\t%s\t%s\t%d\n", vehicles[i].year, vehicles[i].make, vehicles[i].model, vehicles[i].license_plate, vehicles[i].customer_id);
    }
}

int main() {
    int choice;
    
    do {
        printf("\nChoose one of the following options:\n");
        printf("1 - to add a new customer\n");
        printf("2 - to add a new vehicle\n");
        printf("3 - to print all customers' information\n");
        printf("4 - to print all vehicles' information\n");
        printf("5 - to quit\n");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                addVehicle();
                break;
            case 3:
                printCustomers();
                break;
            case 4:
                printVehicles();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}
