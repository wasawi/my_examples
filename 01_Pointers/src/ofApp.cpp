#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	cout << "this is the size of a char :" << sizeof(char)<< endl;
	cout << "this is the size of an int :" << sizeof(int)<< endl;
	cout << "this is the size of a float :" << sizeof(float)<< endl;
	cout << "this is the size of a string :" << sizeof(string)<< endl;
	cout << "this is the size of a double :" << sizeof(double)<< endl;

	age = 25;
	ages = &age;
	
	// this will return the address in memory of the variable age
	cout << "the value of ages is :" << ages << endl;

	// this will return the value stored in age
	cout << "the value of ages is :" << *ages << endl;
	
	// run our test function
	testFunction();
}

void ofApp::increase (void* data, int psize){
	// if the size of the argument = char
	if ( psize == sizeof(char) ){
		// create a pointer type of char called pchar
		char* pchar;
		// give pchar the value of data (while doing a type cast, otherwise will not build)
		pchar=(char*)data;

		// this is wrong.
		//*pchar++;
		
		// this is ok. it will increment the value of the pointer
		(*pchar)++;
	}
	// if the size of the argument = int
	else if (psize == sizeof(int) ){
		//create a pointer type of int called pint
		int* pint;
		pint=(int*)data;
		(*pint)++;
	}
}

void ofApp::testFunction(){
	char a = 'x';
	int b = 1602;
	
	//	the short way, pass a reference (pointer) to the variable
	increase (&a,sizeof(a));
	increase (&b,sizeof(b));
	cout << a << ", " << b << endl;			// this will print: y, 1603
	cout << &a << ", " << &b << endl;		// print the adress in memory
	
	//	the long way, create a pointer and pass the reference to the variable.
	char* pA;
	int* pB;
	
	pA = &a;
	pB = &b;
	
	increase (pA,sizeof(a));
	increase (pB,sizeof(b));
	cout << *pA << ", " << *pB << endl;		// print the adress in memory of a and b
	cout << pA << ", " << pB << endl;		// print: z, 1604
	cout << &pA << ", " << &pB << endl;		// print the adress in memory
											// of the pointers pA and pB
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

