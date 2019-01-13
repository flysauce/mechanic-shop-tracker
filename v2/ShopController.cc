#include "ShopController.h"

ShopController::ShopController() {

    initCustomers();

}

void ShopController::launch() {

    int choice;

    while (1) {
        choice = -1;
        view.mainMenu(choice);
        
        if (choice == 1) {
            view.printCustomers(mechanicShop.getCustomers());
            view.pause();
        } /*else if (choice == 2) {

        } else if (choice == 3) {

        } else if (choice == 4) {
      
        } ... */
        
        else {
            break;
        }
    }
}

void ShopController::initCustomers() {
	int count = 1;
	for(int i = 0; i < 6; i++){
    	Customer *customer = new Customer("Lelouche", "vi Britannia", "123 Zero Street", "(613) 123-4567");
    	for(int j = 0; j < count; j++){
    		Vehicle *vehicle = new Vehicle("Honda", "Civic", "Racing Yellow", 2018, 100000);
    		(*customer).addVehicle(vehicle);
    	}
    	mechanicShop.addCustomer(customer);
    	count++;
    }
}
