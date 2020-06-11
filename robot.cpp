// TODO: REMOVE BEFORE SUBMISSION

#include "robot.hpp"
#include <vector>
//check if the current pixel is white
int doWhiteCheck(int curPix){
	if(curPix==255){
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
	int focusRow = (cameraView.height)/1.5;						//-the chosen row to read the colour of the pixels from
	int centre = (cameraView.width)/2;							//the middle pixel

	while(1){
		takePicture();
		double shift = 0;											//-distance of middle of white line from centre
		setMotors(vLeft,vRight);
		for(int i = 0; i<cameraView.width; i++){
			int curPix = get_pixel(cameraView, focusRow, i, 3); 						//-looks at the pixel
			if(doWhiteCheck(curPix)==1) { // if pixel is white, it is part of centre line
				shift = centre - i-4; // the centre of view - position of white pixel = distance from centre
				if (shift == 0) { // if distance from centre is 0
					vLeft = 30; // set motors to go straight
					vRight = 30;
				} else if (shift < 0) { //if robot is left of line
					vLeft = 35; // set motors to go right
					vRight = 25;
				} else if (shift > 0) { //if robot is right of line
					vRight = 35; // set motors to go left
					vLeft = 25;
				}
			}
		}
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
	} //while

} // main


