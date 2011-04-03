#pragma once

#include "ofMain.h"
#include "EDSDKStringHelper.h"

namespace ofxEdsdk {
	
	/*
		Camera is currently not threaded, so
		update() blocks and isFrameNew() is true.
	*/
	
	class Camera {
	public:
		Camera();
		~Camera();
		void setup();
		void update();
		bool isFrameNew();
		
		unsigned int getWidth() const;
		unsigned int getHeight() const;
		void draw(float x, float y);
		void draw(float x, float y, float width, float height);
		
		const ofPixels& getPixelsRef() const;
		ofPixels& getPixelsRef();
		
		void setLiveViewReady(bool liveViewReady);
		
	protected:
		EdsError err;
		EdsCameraListRef cameraList;
		EdsCameraRef camera;
		
		ofPixels livePixels;
		ofTexture liveTexture;
		bool liveViewReady;
		bool frameNew;
	};
	
}