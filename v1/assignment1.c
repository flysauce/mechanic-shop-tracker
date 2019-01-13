//author: Ryan Lubin 100 832 924
//purpose: Assignment 1 COMP 2404
//program: this program keeps a database of customers and their vehicles

#include <stdio.h>
#include <string.h>

#define MAX_STR 32
#define MAX_VEHICLES 4
#define MAX_CUSTOMERS 6

typedef struct {
	char make[MAX_STR];
	char model[MAX_STR];
	char colour[MAX_STR];
	int year;
	int mileage;
} VehicleType;

typedef struct {
	char first_name[MAX_STR];
	char last_name[MAX_STR];
	int number_vehicles;
	VehicleType vehicles[MAX_VEHICLES];
} CustomerType;

//function: print_vehicle
//in: location of VehcileType structure
//out: no output
//purpose: to print to the screen the VehicleType data
void print_vehicle(VehicleType *v) {
	printf("%d %s %s, %s, %dKM\n", v->year, v->make, v->model, v->colour, v->mileage);
}

//function: print_customer
//in: location of CustomerType structure
//out: no output
//purpose: to print to the screen the CustomerType data
void print_customer(CustomerType *c) {
    printf("%s %s, %d vehicle(s)\n", c->first_name, c->last_name, c->number_vehicles);
	if(c->number_vehicles != 0){
		for(int i = 0; i < c->number_vehicles; i++){
			print_vehicle(&c->vehicles[i]);
		}
	}
}

//function: add_vehicle
//in: location of CustomerType structure and location of VehicleType structure
//out: modify the CustomerType strcture
//purpose: to add VehiclesType structures to the data of CustomerType structure
int add_vehicle(CustomerType *customer, VehicleType *vehicle) {
	if(customer->number_vehicles < MAX_VEHICLES){
		customer->vehicles[customer->number_vehicles] = *vehicle;
		customer->number_vehicles++;
		return 0;
	}
	else{
		return -1;
	}
}

//function: create_customer
//in: location of first and last name char arrays
//out: create a CustomerType structure
//purpose: to create a CustomerType structure
CustomerType create_customer(char* fname, char* lname) {
	CustomerType temp;
	strcpy(temp.first_name, fname);
	strcpy(temp.last_name, lname);
	temp.number_vehicles = 0;
	return temp;
}

//function: create_vehicle
//in: location of the make, model, colour, year and mileage char arrays
//out: create a VehicleType structure
//purpose: to create a VehicleType structure
VehicleType create_vehicle(char* make, char* model, char* colour,
                            int year, int mileage) {
	VehicleType temp;
	strcpy(temp.make, make);
	strcpy(temp.model, model);
	strcpy(temp.colour, colour);
	temp.year = year;
	temp.mileage = mileage;
	return temp;
}

//function: main
//purpose: testing
int main() {
    CustomerType customers[MAX_CUSTOMERS];
    int number_customers = 0;
	VehicleType vehicle_temp;
	CustomerType customer_temp;
	for(int i = 0; i < MAX_CUSTOMERS; i++){
		int temp = i + 1;
		customer_temp = create_customer("First", "Last");
		customers[i] = customer_temp;
		number_customers++;
		for(int j = 0; j < temp; j++){
			vehicle_temp = create_vehicle("Make", "Model", "Colour", 2000+j, 10000+temp*j);
			add_vehicle(&customers[i], &vehicle_temp);
		}
	}
	for(int i = 0; i < number_customers; i++){
		print_customer(&customers[i]);
		printf("\n");
	}
    return 0;
}


