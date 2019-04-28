#include <stdio.h>
#define DELAY 1000
#define MAX_VOLTAGE 5.0
#define INPUT_PIN A2

const byte pins[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
const byte pinslen = sizeof(pins)/sizeof(pins[0]);
const char * pinnames[] = { "DIG_2", "DIG_3", "DIG_4", "DIG_5" , "DIG_6", "DIG_7", "DIG_8", "DIG_9"};


void setup() {
   Serial.begin(115200);
   Serial.print("Pin under test: ");
   for(int i=0; i< pinslen; i++){
		pinMode(pins[i], OUTPUT);
   		digitalWrite(pins[i], HIGH);
   		Serial.print(pinnames[i]);
   		Serial.print(i == pinslen-1 ? "\n" : ", ");
   }
	Serial.println("Send any key to go to the next pin");
}

void loop() {
	while(1){
	  	for(int i=0; i< pinslen; i++){
	  		do{
		  		int val = analogRead(INPUT_PIN);
		  		float voltage  = val * MAX_VOLTAGE / 1024;
		  		Serial.print(pinnames[i]);;
		  		Serial.print(" value: ");
		  		Serial.println(voltage);
		  		delay(DELAY);
	  		}while(!Serial.available());
	  		// Consume the other input chars
	  		while(Serial.available()){
	  			Serial.read();
	  		}
	  	}
	}
}
