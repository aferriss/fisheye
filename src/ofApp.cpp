#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    w = 800;
    h = 1000;
    
    ofSetWindowShape(w, h);
    ofDisableArbTex();
    fbo.allocate(w, h, GL_RGB);
    shader.load("base");
    img.load("house.jpg");
    img.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);
    fbo.begin();
    ofClear(0,255);
    fbo.end();
    
    save = false;
    
    gui.setup();
    
    gui.add(ring.set("ring", 70, 0.01,200.0));
    gui.add(ringDiv.set("ringDiv", 70, 0.01,200.0));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(save){
        ofPixels savePix;
        fbo.readToPixels(savePix);
        ofSaveImage(savePix, "saved/" + ofGetTimestampString() + ".png");
        save = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
        shader.begin();
        shader.setUniformTexture("tex0", img.getTexture(), 0);
        shader.setUniform1f("ring", ring);
        shader.setUniform1f("ringDiv", ringDiv);
        shader.setUniform2f("mouse", ofMap(ofGetMouseX(), 0, w, 0, 1),ofMap(ofGetMouseY(), 0, h, 0, 1));
            img.draw(0,0);
        shader.end();
    fbo.end();
    
    fbo.draw(0,0);
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        save = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
