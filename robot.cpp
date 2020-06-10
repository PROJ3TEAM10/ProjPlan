// TODO: REMOVE BEFORE SUBMISSION
#include <cstdio> 
FILE _iob[] = {*stdin, *stdout, *stderr};
extern "C" FILE * __cdecl __iob_func(void){    return _iob;}

#include "robot.hpp"

//check if the current pixel is white
int doWhiteCheck(int curPix){
	if(curPix==250){
		return 1;
		}
	else{
		return 0;
		}
}

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    double vLeft = 30.0;
    double vRight = 30.0;
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    int focusRow = (cameraView.height)/2;						//-the chosen row to read the colour of the pixels from
    int centre = (cameraView.width)/2;							//the middle pixel
    int centreL = -10+(cameraView.width)/2;						//-centre L and r give me pixel values that between which the 
    int centreR = 10+(cameraView.width)/2;						//pixels should be white
    int w=0;													//-num of white pixels
    while(1){
      takePicture();	
      double shift = 0;											//-distance of middle of white line from centre
      int whitePix = 0;											//-number of white pix in the front line of the camera view
      
      setMotors(vLeft,vRight);  
      for(int i = 0; i<cameraView.width; i++){
		  
		int curPix = get_pixel(cameraView, focusRow, i, i); 	//-looks at the pixel
		w=w+doWhiteCheck(curPix);									//-adds one to the count of white pixels if the current pixel is white
		if(i>centreL&&i<centre){
			  if(doWhiteCheck(curPix)==0){vLeft=vLeft+(10-w)*0.5;}
			  }
		if(i<centreR&&i>centre){
			  if(doWhiteCheck(curPix)==0){vRight=vRight+(10-w)*0.5;};
			  }
		  
		  }
		   
      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
       usleep(10000);
       shift=0;
  } //while

} // main


