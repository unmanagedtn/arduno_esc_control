
//Gavin Groce unmanaged@gmail.com 
// Code adapted from the following sites
//https://www.instructables.com/ESC-Programming-on-Arduino-Hobbyking-ESC/
//https://www.best-microcontroller-projects.com/arduino-string.html
//Commands: "r" attaches the servo pin to allow esc startup, sets throttle to lowest posit.
//          "t" sets full throttle 
//          "b" sets lowest thottle
//          "d" detaches servo pin to prevent esc startup
#include <Servo.h>
String sdata="";  // Initialised to nothing.
byte full_up,full_down,attach_run,detach_stop;
//int value = 0; // set values you need to zero
Servo firstESC;
void setup (void) {
  // firstESC.attach(9);    // attached to pin 9 I just do this with 1 Servo
   Serial.begin(9600);
   Serial.println("Hobbywing Skywalker Control \r\n Commands: \r\n r sets the servo pin to allow esc startup run a power-on, trottle down...\r\n t sets full throttle...\r\n b sets lowest thottle... \r\n d detaches servo pin to prevent esc startup");
}

void loop(void ) {
byte ch;
String valStr;
int val;

   if (Serial.available()) {
      ch = Serial.read();

      sdata += (char)ch;

      if (ch=='\r') {  // Command received and ready.
         sdata.trim();

         // Process command in sdata.
         switch( sdata.charAt(0) ) {
         case 'r':
            attach_run = 1;
            firstESC.attach(9);
            Serial.println("Pin Enabled");
            firstESC.writeMicroseconds(1000);
            break;
         case 't':
            full_up = 1;
            Serial.println("Send 2000");
            firstESC.writeMicroseconds(2000);
            break;
         case 'b':
            full_down = 1 ;
            Serial.println("Set to 1000");
            firstESC.writeMicroseconds(1000);
            break;
            case 'd':
            detach_stop = 1;
            Serial.println("Pin Disabled");
            firstESC.detach();
            break;
            switch( sdata.charAt(0) ) {
         default: 
         firstESC.detach();
         } // switch
         }

         sdata = ""; // Clear the string ready for the next command.
    
      } // if \r
   }  // available
   }
