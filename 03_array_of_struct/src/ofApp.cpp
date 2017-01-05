#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	string titles_arr []	= { "La fuga", "El comilon", "Mamma" };
	int years_arr []		= { 1992, 1999, 2003 };
	
	
	string mystr;
	int n;
	
	for (n=0; n<N_MOVIES; n++)
	{
		films[n].title	= titles_arr[n];
		films[n].year	= years_arr[n];
	}
	
	cout << "\nYou have entered these movies:\n";
	for (n=0; n<N_MOVIES; n++){
		printmovie (films[n]);
	}
}

void ofApp::printmovie(movies_t movie)
{
	cout << movie.title;
	cout << " (" << movie.year << ")\n";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}
