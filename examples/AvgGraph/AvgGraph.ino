#include <ZzzMovingAvg.h>

//Keep a moving average on the last 2 values
ZzzMovingAvg <2> avg;
//Keep a moving average on the last 3 values
ZzzMovingAvg <3> avg3;
//Keep a moving average on the last 4 values
ZzzMovingAvg <4> avg4;
//Keep a moving average on the last 8 values
ZzzMovingAvg <8> avg8;
//Keep a moving average on the last 16 values
ZzzMovingAvg <16> avg16;
//Keep a moving average on the last 32 values
ZzzMovingAvg <32> avg32;

void addData(uint8_t input) {
  Serial.print(input);
  Serial.print("\t");
  Serial.print(avg.add(input));
  Serial.print("\t");
  Serial.print(avg3.add(input));
  Serial.print("\t");
  Serial.print(avg4.add(input));
  Serial.print("\t");
  Serial.print(avg8.add(input));
  Serial.print("\t");
  Serial.print(avg16.add(input));
  Serial.print("\t");
  Serial.print(avg32.add(input));
  Serial.println();
  delay(10);
}

//You can use the Arduino builtin plotter to see the differences between raw data and moving averages
void setup() {
    Serial.begin(115200);
    delay(250);

    Serial.println("\nRaw,Avg2,Avg3,Avg4,Avg8,Avg16,Avg32");

    addData(50);
}

void loop() {
  //generate random data with sudden changes
  switch(random(0,100))  {
    case 0:
      addData(50);
      break;
    case 1:
      addData(100);
      break;
    case 2: //fake peak values
      addData(150);
      break;
    default: //keep values around last values
      int lastVal=avg.getLast();
      if (lastVal>=150) //remove extreme values to create fake peak values
        lastVal=100;
      addData(lastVal+random(-3,4));
      break;
  }

  delay(50);
}
