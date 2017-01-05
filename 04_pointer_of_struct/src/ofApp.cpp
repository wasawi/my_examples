#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	pmovie = &amovie;
	
	string titles_arr []	= { "La fuga", "El comilon", "Mamma" };
	int years_arr []		= { 1992, 1999, 2003 };
	
	
	string mystr;
	int n;
	
	cout << "\nYou have entered these movies:\n";
	for (n=0; n<N_MOVIES; n++)
	{
		pmovie->title	= titles_arr[n];
		pmovie->year	= years_arr[n];
		
		printmovie (pmovie);
	}
}

void ofApp::printmovie(movies_t* movie)
{
	cout << movie->title;
	cout << " (" << movie->year << ")\n";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

