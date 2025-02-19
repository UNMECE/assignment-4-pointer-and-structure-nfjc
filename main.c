// #including all the needed libraries and my item.h file for my program to run smoothly.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
//Implicitly delcaring my functions because gcc gets mad otherwise and wont compile.
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);
 
int main(int argc, char *argv[]){
//If no argument is found it yells at the user and doesn't run.
if(argc != 2) {
	printf("Incorrect Arguments!");
	return 1;
}
//Declaring size, the searched for SKU number, and the array used to store all of the items.
int size = 5;
char *search_sku = argv[1];
Item *item_list = malloc(size * sizeof(Item));
//Declaring a fun grocery list for my program.
add_item(item_list, 7.99, "37138", "Dairy", "Milk", 0);
add_item(item_list, 0.99, "48191", "Produce", "Apple", 1);
add_item(item_list, 2.99, "91038", "Pastry", "Pop Tarts", 2);
add_item(item_list, 5.99, "31235", "Meat", "Bacon", 3);
add_item(item_list, 8.99, "39103", "Snacks", "Doritos: Cool Ranch", 4);
//How my function counts and searches for the sku. If the sku is found before the end of size it prints out the associated item.
int ct = 0;
while(ct < size && strcmp(item_list[ct].sku, search_sku) !=0){
	ct++;
}
//Throws item not found if it doesn't find the sku.
if(ct < size){
	print_items(&item_list[ct], 1);
} else {
	printf("Item not found.\n");
}
//Calling free_items and passing the whole struct and size.
free_items(item_list, size);

return 0;
}

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index){
//Didn't dynamically allocate memory for price because it's already a double and that takes a certain amount of data already.
item_list[index].price = price;
//Mallocating data + 1 so it doesn't overflow.
item_list[index].sku = malloc(strlen(sku) + 1);
item_list[index].category = malloc(strlen(category + 1));
item_list[index].name = malloc(strlen(name + 1));
//THe actual storing of the variables in item_list.
strcpy(item_list[index].sku, sku);
strcpy(item_list[index].category, category);
strcpy(item_list[index].name, name);


}
void free_items(Item *item_list, int size){
//Pretty simple, just frees all the memory that I used up throughout this preogram.
	for(int i = 0; i < size; i++) {
		free(item_list[i].sku);
		free(item_list[i].category);
		free(item_list[i].name);
	}
	free(item_list);		
}
double average_price(Item *item_list, int size){
//Takes the averages of all the prices and divides it by size which is passed.
	double sum = 0.0;
	for(int i = 0; i < size; i++){
		sum += item_list[i].price;
	}	
	return sum / size;
}
void print_items(Item *item_list, int size){
//Didn't change the print function much after having it print everything. I just pass size of 1 to pass 1 index of struct.
	for(int i = 0; i < size; i++){
		printf("Item Name: %s", item_list[i].name);
		printf("SKU: %s\n", item_list[i].sku);
		printf("Category: %s\n", item_list[i].category);
		printf("Price: $%.2f\n", item_list[i].price);	
	}
}

