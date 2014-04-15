#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(20);
	setupLighting();
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	ofSetLogLevel(OF_LOG_VERBOSE);
	glEnable(GL_DEPTH_TEST);
	
	// GIF
	gifEncoder.setup(ofGetWidth(), ofGetHeight(), 0.01, 255);
    ofAddListener(ofxGifEncoder::OFX_GIF_SAVE_FINISHED, this, &ofApp::onGifSaved);

	//model
	setupFiles();
	loadModel();
	
	cam.setAutoDistance(false);
	ofxLoadCamera(cam, "settings/camSettings");
	
	drawFaces = false;
	drawVerts = false;
	drawWire = true;
}
//--------------------------------------------------------------
void ofApp::setupFiles(){
	dir.listDir("models");
	currentFile=0;
}

//--------------------------------------------------------------
void ofApp::loadModel(){
	
	string filename = dir.getOriginalDirectory() + dir.getName(currentFile);
	cout <<"		loading "<< filename<< endl;

	model.loadModel(filename, true);
	model.calculateDimensions();
	model.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
	//model.setScale(10000,10000,10000);
	model.optimizeScene();
	cout << "center = "+ ofToString(model.getSceneCenter());
	
	mesh = model.getMesh(0);
	vert = mesh.getVerticesPointer();
	norm = mesh.getNormalsPointer();
	index = mesh.getIndexPointer();
	
	cout << mesh.getNumIndices()<<endl;
	cout << mesh.getNumIndices()<<endl;
	mesh.mergeDuplicateVertices();
	cout << mesh.getNumIndices()<<endl;
	cout << mesh.getNumIndices()<<endl;
	
	currentFile < dir.numFiles()-1 ? currentFile++ : currentFile=0 ;
}
//--------------------------------------------------------------
void ofApp::setupLighting(){
	
	ofVec3f center;
	center.set(ofGetWidth()*.5, ofGetHeight()*.5, 1000);

	// turn on smooth lighting //
	ofSetSmoothLighting(true);

	// Point lights emit light in all directions //
	// set the diffuse color, color reflected from the light source //
	pointLight.setDiffuseColor( ofColor(0.f, 255.f, 255.f));

	// specular color, the highlight/shininess color //
	pointLight.setSpecularColor( ofColor(0.f, 255.f, 255.f));
	pointLight.setPosition(center.x, center.y, 0);

	// shininess is a value between 0 - 128, 128 being the most shiny //
	material.setShininess( 64 );
	
	colorHue = ofRandom(0, 250);
    
    lightColor.setBrightness( 180.f );
    lightColor.setSaturation( 150.f );
    
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
}

//--------------------------------------------------------------
void ofApp::update(){

	// GIF
	gifEncoder.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
//	ofBackgroundGradient(50, 40);
	ofPushMatrix();
	cam.begin();
//	ofTranslate(ofGetWidth()/2,ofGetHeight()/2,500);
//	ofRotate(ofGetMouseX(), 0, 1, 0);
//	ofRotate(ofGetMouseY(), 1, 0, 0);
//	ofScale(20,20,20);
	ofSetColor(255);
	
	// enable lighting //
    ofEnableLighting();
    // the position of the light must be updated every frame,
    // call enable() so that it can update itself //
    pointLight.enable();
    material.begin();

	
	if(drawVerts){
		glPointSize(4);
		mesh.drawVertices();
	}
	else if(drawWire){
		mesh.drawWireframe();
	}
	else if (drawFaces){
		mesh.drawFaces();
	}
	cam.end();
	ofPopMatrix();
	
	material.end();
	// turn off lighting //
    ofDisableLighting();

}

void ofApp::swapA(){
	for(int i = 0;i<mesh.getNumVertices(); i++ ){
		//do bubble sort on vertices
		if(vert[i].length()>vert[i+1].length()){
			ofPoint v = vert[i];
			vert[i] = vert[i+1];
			vert[i+1] = v;
		}
	}
	mesh.setupIndicesAuto();
	cout <<"swapA"<<endl;
}
void ofApp::swapB(){
	for(int i = 0;i<mesh.getNumVertices(); i++ ){
		//do bubble sort on vertices
		if(vert[i].length()<vert[i-1].length()){
			ofPoint v = vert[i];
			vert[i] = vert[i-1];
			vert[i-1] = v;
		}
	}
	cout <<"swapB"<<endl;
}

void ofApp::swapC(){
	for(int i = 0;i<mesh.getNumVertices(); i++ ){
		//do bubble sort on vertices
		if(vert[i].x<vert[i+1].x){
			float t = vert[i].x;
			vert[i].x = vert[i+1].x;
			vert[i+1].x = t;
		}
		
		if(vert[i].y<vert[i+1].y){
			float u = vert[i].y;
			vert[i].y = vert[i+1].y;
			vert[i+1].y = u;
		}
		
		if(vert[i].z<vert[i+1].z){
			float v = vert[i].z;
			vert[i].z = vert[i+1].z;
			vert[i+1].z = v;
		}
	}
}

void ofApp::swapVerticesUp(){
	for(int i = 0;i<mesh.getNumVertices(); i++ ){
		//sort vertices
		ofPoint temp = vert[i];
		vert[i]= vert[i+1];
		vert[i+1] = temp;
	}
}
void ofApp::swapVerticesDown(){
	for(int i = mesh.getNumVertices();i>0; i-- ){
		//sort vertices
		ofPoint temp = vert[i];
		vert[i]= vert[i-1];
		vert[i-1] = temp;
	}
}

void ofApp::swapNormalsUp(){
	for(int i = 0;i<mesh.getNumNormals(); i++ ){
		//sort normals
		ofPoint temp = norm[i];
		norm[i]= norm[i+1];
		norm[i+1] = temp;
	}
}

void ofApp::swapNormalsDown(){
	for(int i = mesh.getNumVertices();i>0; i-- ){
		//sort normals
		ofPoint temp = norm[i];
		norm[i]= norm[i-1];
		norm[i-1] = temp;
	}
}

void ofApp::swapIndicesUp(){
	for(int i = 0;i<mesh.getNumIndices()-1; i++ ){
		//sort indices
		ofIndexType ind = index[i];
		index[i] = index[i+1];
		index[i+1] = ind;
	}
}

void ofApp::swapIndicesDown(){
	for(int i = mesh.getNumIndices()-1;i>0; i-- ){
		//sort indices
		ofIndexType ind = index[i];
		index[i] = index[i-1];
		index[i-1] = ind;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	switch(key)
    {
		case ' ':
			gifEncoder.toggleRecording();
			break;
		case 's':
			cout << "Start saving..." << endl;
			string date;
			date=ofGetTimestampString();
			gifEncoder.save(date+".gif");
			break;
	}

	
	if (key == '1') {
		drawVerts = true;
		drawWire = false;
		drawFaces = false;
	}
	if (key == '2') {
		drawVerts = false;
		drawWire = true;
		drawFaces = false;
	}
	if (key == '3') {
		drawVerts = false;
		drawWire = false;
		drawFaces = true;
	}

	if (key == 'r')	loadModel();// reset
	if (key == 'v')	swapVerticesUp();	// vertices
	if (key == 'V') swapVerticesDown();
	if (key == 'n')	swapNormalsUp();	// normals
	if (key == 'N')	swapNormalsDown();
	if (key == 'i')	swapIndicesUp();	// indices
	if (key == 'I') swapIndicesDown();
	
	if (key == 'l')	ofxLoadCamera(cam, "settings/camSettings");
	if (key == 'S')	ofxSaveCamera(cam, "settings/camSettings");
	
	if (key == 'L')	loadModel();
	if (key == 'm')	bmoveLight=true;
}

//--------------------------------------------------------------
void ofApp::onGifSaved(string &fileName) {
    cout << "gif saved as " << fileName << endl;
	gifEncoder.reset();
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'm')	bmoveLight=false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	if (bmoveLight){
	ofPoint mouse(x,y,0);
	pointLight.setPosition(cam.screenToWorld(mouse));
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::exit(){
    gifEncoder.exit();
}

