#include "robot.hpp"
	#include <vector>
	//check if the current pixel is white
	int doWhiteCheck(int white){
		if(white==255){return 1;}
		else{return 0;}
	}
	int doRedCheck(int redPix){
		if(redPix==255){return 1;}
		else{return 0;}
	}
	
	
	
	int main(){
		if (initClientRobot() !=0){
			std::cout<<" Error initializing robot"<<std::endl;
		}
		double vLeft = 30.0;
		double vRight = 30.0;
		takePicture();
		SavePPMFile("i0.ppm",cameraView);
		
		int centre = (cameraView.width)/2;							//the middle pixel
	
	
		while(1){
			takePicture();
	         int num_of_white_pix = 0;
			double shift = 0;											//-distance of middle of white line from centre
			setMotors(vLeft,vRight);
			for(int i = 0; i<cameraView.width; i++){
				int focusRow = (cameraView.height)/2;						//-the chosen row to read the colour of the pixels from
				int whitePix = get_pixel(cameraView, focusRow, i, 3); 						//-looks at the pixel
	                    if(doWhiteCheck(whitePix)==1){ num_of_white_pix++;
	shift += i;
	}
	
	
	
			}
	int white_shift=0;
	int whitePix=0;
	 for(int row=0; row<cameraView.height/2; row++){
	int white_pixel=get_pixel(cameraView,row,cameraView.width/2,3);
	  if(doWhiteCheck(whitePix)==1){num_of_white_pix ++;
	
	white_shift += row;
	}
	}
				if(num_of_white_pix>0) { // if pixel is white, it is part of centre line
					shift = centre - shift/num_of_white_pix; // the centre of view - position of white pixel = distance from centre
					if (shift == 0) { // if distance from centre is 0
						vLeft = 30; // set motors to go straight
						vRight = 30;
					} else if (shift < 0) { //if robot is left of line
						vLeft = 30-(shift/5); // set motors to go right
						vRight = 30+(shift/5);
					} else if (shift > 0) { //if robot is right of line
						vRight = 30+(shift/5); // set motors to go left
						vLeft = 30-(shift/5);
					}
	          
				} else{//line has not been found
				
	          vLeft=30;
	          vRight=-30;
	               //turning until we find the line.
	               
	               usleep(10000);
	      }
	  }
	}
