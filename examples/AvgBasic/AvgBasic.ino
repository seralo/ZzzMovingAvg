#include <ZzzMovingAvg.h>

//Keep a moving average on the last 4 int values (default template values).
ZzzMovingAvg <> avg;

//Other class configurations:
	//Keep a moving average on the last 2 int values.
	//ZzzMovingAvg <2> avg;

	//Keep a moving average on the last 8 uint8_t values (values between 0-255).
	//ZzzMovingAvg <8, uint8_t, uint16_t> avg;

	//Keep a moving average on the last 16 float values (Values could be decimal).
	//ZzzMovingAvg <16, float, float> avg;

void setup() {
	Serial.begin(115200);
	delay(250); //to ensure correctly initialized

	Serial.print("Compute moving average data size: ");
	Serial.println(avg.size());

	Serial.print("Add first value (120) avg=");
	Serial.println(avg.add(120));

	Serial.print("Add new value (130) avg=");
	Serial.println(avg.add(130));

	Serial.print("Add new value (135) avg=");
	Serial.println(avg.add(135));

	Serial.print("Add new value (130) avg=");
	Serial.println(avg.add(130));

	Serial.println("Add 4 new values (5,6,7,8)");

	avg.add(5);
	avg.add(6);
	avg.add(7);
	avg.add(8);

	Serial.print("Result: ");
	Serial.println(avg.get());

	Serial.print("Last added values: ");
	Serial.print(avg.getLast());
	for(int i=1;i<avg.size();i++) {
		Serial.print(' ');
		Serial.print(avg.getLast(i));
	}
	Serial.println();

}

void loop() {
}
