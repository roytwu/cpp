/* *********************************************************
File name:   main.cpp (_inheritance)
Author:      Roy Wu
Description: 2018       - Demo about inheritance
             03/04/2020 - shared ponters implementation
********************************************************* */
#include <iostream>
#include <memory>
#include "animal.h"
#include "cat.h"
#include "tiger.h"
//using std::cout;
//using std::endl;

// //Return objects from functions
// Cat *createCat(){
// 	Cat *op_Cat = new Cat();
// 	op_Cat->makeAngry();
// 	return op_Cat;
// }

int main(){
	//cout << "----- Super class 'Animal' -----\n";
	//Animal o_am(99);
	//o_am.speak();
	//o_am.info();
	////o_am.jump(); //* error!! Animal can't access its child class


	//cout << "\n\n----- Sub class 'Cat' -----\n";
	//Cat *op_tom = new Cat(); 
	//op_tom->m_happy = true;
	//op_tom->speak();          //*Cat can do what Animal can do
	//op_tom->jump();
	//delete op_tom;

	//cout << endl;
	//Cat *op_kitty = new Cat(108);
	//op_kitty->info();
	//delete op_kitty;


	cout << "\n\n----- Sub-sub class 'Tiger' -----\n";
	std::shared_ptr<Tiger> o_bengal(new Tiger);
	o_bengal->info();
	o_bengal->speak();          //* Tiger can do what Animal can do
	o_bengal->attackAntelope();
	//delete op_bengal;         //* no need to "delete" the shared pointer

	//* ---using make_shared() to construct a shared pointer
	std::shared_ptr<Tiger> o_siberian = std::make_shared<Tiger>();
	cout << "\n Tiger obhject #2\n";
	cout << "\tSiberian pointer count... " << o_siberian.use_count() << endl;
	o_siberian->info();
	o_siberian->jump();         //* Tiger can do what Cat can do
	
	//* ---share ownership of resource
	std::shared_ptr<Tiger> oSib2(o_siberian);
	cout << "\tSiberian pointer count... " << o_siberian.use_count() << endl;
	oSib2->info();

	cout << "\n\n===== ===== Polymorphism ===== =====\n";
	Animal *op_animal = new Cat;  //* old-school approach
	op_animal->speak();           //* function overriding
	delete op_animal;

	cout << "\n\n----- Polymorphism (shared-pointer) -----\n";
	std::shared_ptr<Animal> oAni = std::make_shared<Cat>(88);  
	oAni->speak();               //* function overriding
	oAni->info();


    cout << "\nEnding porgram..." << endl;
	return 0;
}


/*
  ---------------------------------
  super-calss      Animal  
  ---------------------------------               
  sub-class          |--> Cat
  ---------------------------------
  sub-sub-class        |--> Tiger
  ---------------------------------

*/