#include "robot.hpp"
#include <vector>
void doCompletion();
void doCore();
double vLeft;
double vRight;
//void doChallenge();
int main(){
	double choice;
	std::cout<<"please select 1 for core, 2 for completion or 3 for challenge";
	std::cin>>choice;
	if(choice==1){doCore();}
	if(choice==2){doCompletion();}
	//if(choice==3){doChallenge();}
}//end of main

int doWhiteCheck(int white){
	if(white==255){return 1;}
	else{return 0;}
}
int doRedCheck(int redPix){
	if(redPix==255){return 1;}
	else{return 0;}
}
void doLeftTurn(int turnDegree){
	vLeft=-28;
	vRight=28;
	for(int i=0; i<turnDegree; i++){setMotors(vLeft,vRight);}
}//end of left turn function
void doRightTurn(int turnDegree){
	vLeft=28;
	vRight=-28;
	for(int i=0; i<turnDegree; i++){setMotors(vLeft,vRight);}
}//end of right turn function
void doCompletion(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	takePicture();
	SavePPMFile("i0.ppm",cameraView);
	bool centree;
	bool leftt;
	bool rightt;
	int centre = (cameraView.height)/2;													//the middle pixel line row
	int left = (cameraView.width)/4;													//if the line turns left, it goes throught this pixel coloumn
	int right = 3*(cameraView.width)/4;													//if the line turns right, it goes throught this pixel coloumn
	while(1){
		takePicture();
		double shift = 0; 																//-distance of middle of white line from centre
		setMotors(vLeft,vRight);
		bool centree = false;
		bool leftt  = false;
		bool rightt = false;
		// for(int i=0; i<cameraView.height/4; i++){
			//left turn check

			int whitePixLeft = get_pixel(cameraView, 3*(cameraView.height / 4), left, 3);
			if(doWhiteCheck(whitePixLeft)==1){
				leftt = true;
				doLeftTurn(2);
				std::cout << "leftTurn" << std::endl;
				}
			//if it isn't turning left do a right turn check
			if(leftt==false){
				int whitePixRight = get_pixel(cameraView, 3*(cameraView.height / 4), right, 3);
				if(doWhiteCheck(whitePixRight)==1){
					rightt = true;
					doRightTurn(2);
					std::cout << "rightTurn" << std::endl;
					}//if white pix ==1
				}//if not left
			//}//for
			//if it isn't turning drastically, check for small movement or go straight
		if(leftt==false&&rightt==false){
			for(int i = 0; i<cameraView.width; i++){
				int focusRow = (cameraView.height / 2);										//-the chosen row to read the colour of the pixels from
				int whitePix = get_pixel(cameraView, focusRow, i, 3); 						//-looks at the pixel
			
				if(doWhiteCheck(whitePix)==1) { // if pixel is white, it is part of centre line
					shift = centre - i; // the centre of view - position of white pixel = distance from centre (removed -4 sorry nat but why?)
					if (shift >=-5&&shift<=5) { // if distance from centre is close to 0
						vLeft = 30; // set motors to go straight
						vRight = 30;
					} else if (shift < 0) { //if robot is left of line
						vLeft = 30-(shift/5); // set motors to go right
						vRight = 30+(shift/5);
					} else if (shift > 0) { //if robot is right of line
						vRight = 30+(shift/5); // set motors to go left
						vLeft = 30-(shift/5);
					}
				}//if white pix = 1
			}//for
		}//if left right
		
			
			
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
	} //while

} // doCompletion

void doCore(){
		if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	double vLeft = 30.0;
	double vRight = 30.0;
	takePicture();
	SavePPMFile("i0.ppm",cameraView);
	int centre = (cameraView.height)/2;													//the middle pixel line row
	while(1){
		takePicture();
		double shift = 0;																//-distance of middle of white line from centre
		setMotors(vLeft,vRight);
		
		for(int i=0; i<cameraView.height/4; i++){
			
			for(int i = 0; i<cameraView.width; i++){
				int focusRow = cameraView.height / 2;										//-the chosen row to read the colour of the pixels from
				int whitePix = get_pixel(cameraView, focusRow, i, 3); 						//-looks at the pixel
			
				if(doWhiteCheck(whitePix)==1) { // if pixel is white, it is part of centre line
					shift = centre - i; // the centre of view - position of white pixel = distance from centre (removed -4 sorry nat but why?)
					if (shift >=-5&&shift<=5) { // if distance from centre is close to 0
						vLeft = 30; // set motors to go straight
						vRight = 30;
					} else if (shift < 0) { //if robot is left of line
						vLeft = 30-(shift/5); // set motors to go right
						vRight = 30+(shift/5);
					} else if (shift > 0) { //if robot is right of line
						vRight = 30+(shift/5); // set motors to go left
						vLeft = 30-(shift/5);
					}
				}//if white pix = 1
			}//for
		
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(1000);
	} //while
	}
	}
