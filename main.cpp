#include <stdio.h>
#include <time.h>
#include <string.h>

extern "C" int init (int d_lev);
extern "C" int connect_to_server ( char server_addr[], int port);
extern "C" int send_to_server (char message[12]);
extern "C" int recieve_from_server (char message[12]);

extern "C" int Sleep( int sec, int usec );
extern "C" int set_motor( int motor, int speed );
extern "C" int take_picture();
extern "C" int open_screen_stream();
extern "C" char get_pixel(int row, int col, int colour);
extern "C" take_picture();

int main(){
init(1);

// NETWORK CODE START
connect_to_server("130.195.6.196", 1024);
send_to_server("Please");
char message[12];
recieve_from_server(message);
send_to_server(message);
printf("%s", message);
//Sleep(0, );                       Might not be necessary, might need to be larger, need to TEST
//return 0;                         If there is any problem opening the gate then this is where it stems from!
// NETWORK CODE END

// LINE FOLLOWING/ PHOTO ANALYSING CODE START
int rightMotorSpeed = 0;
int leftMotorSpeed = 0;
int whiteValue=0;
int i = 0;
int whiteOrBlack[15];   // White = 1, Black = 0
int startOfWhite, endOfWhite;
float centerOfWhite;

boolean reversed = false;
boolean redColorRecognised = false;        // This turning to true will signify it has reached the start of quadrant 4.

while(redColorRecognised == false){

startOfWhite = 0;
endOfWhite = 0;
reversed = false;

take_picture();

int open_screen_stream();

// FRESH CODE CHECKING FOR RED ie START OF QUAD 4
for(int i = 0; i < 16; i++){
if(get_pixel(i*20, 120, 3) == RED VALUE){             // TEST FOR RED VALUE
redColorRecognised = true;
{break;}
}
}
// END OF FRESH CODE

for(int i = 0; i < 16; i++){
whiteValue = get_pixel(i*20, 120, 3);
if(whiteValue > 127){
whiteOrBlack[i] = 1;
}

else{
whiteOrBlack[i] = 0;
}
}

for(int i=0;i<15;i++){
if( (whiteOrBlack[i]==0) && (whiteOrBlack[i+1]==1) ){
int startOfWhite = i;
}

if((whiteOrBlack[i] == 1) && (whiteOrBlack[i + 1] == 0)){ 
int endOfWhite = i;
}
}

if(startOfWhite == 0 && endOfWhite == 0){ SET THESE VALUES EQUAL TO VALUES YOU RECIEVE WHEN NO LINE IS DETECTED.
  set_motor(1, (-1*leftMotorSpeed) );
  set_motor(2, (-1*rightMotorSpeed) );
  Sleep(0, 500000);
  set_motor(1, 0);
  set_motor(2, 0);
  reversed == true;
}

CHECK IF AT QUAD 3.
if(){

if((endOfWhite - startOfWhite) > ){                 // Testing required, we need to test the value of startofwhite and endofwhite at the intersection symbolising the start of quadrant 3
  if(INTERSECTION WITH LEFT AND FORWARD, GO FORWARD){
  
  }
  
  else if(INTERSECTION WITH LEFT, TURN LEFT){           // Value inside this statement will be of an intersection.
  set_motor(1, );                                   // We need multiple if statements here asking for values of white towards the upwards direction of the intersection, the left and the right, so that we know what kind of intersection it is.
  set_motor(2, );
  }
  
  else if(INTERSCTION WITH NO LEFT AND RIGHT, TURN RIGHT){
  set_motor(1, );
  set_motor(2, );
  }
}
}

if(reversed == false){                            // If the robot has just reversed we dont want it to then go off the previous picture which must have had no white in it, therefore we want it to take another picture and try moving again
float centerofWhite = (startOfWhite + endOfWhite)/2;

float errorValue = centerOfWhite - 7.5;           // 7.5 is the center, therefore when it is equal the error value will be zero
float d = 0;                                      // We need to test this variable as different sizes in order to find a size that corrects/ prevents oscillation.

float rightMotorSpeed = 15 + errorValue + d;
float leftMotorSpeed = 15 - errorValue + d;
set_motor(1, leftMotorSpeed);
set_motor(2, rightMotorSpeed);
Sleep(0, 500000);
set_motor(1, 0);
set_motor(2, 0);
Sleep(0, 500000);
}

}
