# ZzzMovingAvg
Simple Arduino / C++ library to compute moving average


The library consist of a single header file (ZzzMovingAvg.h) containing a template class.

The template has 3 parameters
 * N     is the number of values to smooth the data (default=4). Could be a power of 2 (2,4,8,16,32...) to optimize computation at compile time.
 * T     is the type of data (default=int). Could be uint8_t, int8_t, uint16_t, int, float...
 * TSUM  is the type of the sum (default=long). Should be able to contain N*data without overflowing. if N is 8 and values could go up to 100, then T could be uint8_t (max=255) and TSUM should at least be uint16_t (max=65535).


### Constructor

```cpp

ZzzMovingAvg <> avg; //Constructor with default template parameters 4, int, long

ZzzMovingAvg <4, uint8_t> avg; //Constructor with 4 values, and uint8_t as data type.

ZzzMovingAvg <16, float, float> avg; //Constructor with 16 values, and float as data type

```

### Functions

```cpp
T add()                // Add a new value to the moving average
T get()                // Get the current moving average value (same as the last add return value)
T last(size_t back=0)  // Get raw value added previously. No param will get the last added value. 1 will get the previous added value... up to size()-1.
size_t size()          // Return the number of values used for the moving average, or the number of value it could get using last()
void reset()                // Reset the average values
void fill()                 // Fill the buffer with all identical values
```

### Included examples

- `AvgBasic/AvgBasic.ino` - Show basic usage with static data
- `AvgGraph/AvgGraph.ino` - Demonstrates smoothing of moving average algorithms depending on number of data.


### Simple code example for 4 int values

```cpp
#include <ZzzMovingAvg.h>

ZzzMovingAvg <4> avg;

void setup()
{
    ...
}

void loop()
{
    ...

    int avgSensorValue = avg.add(mySensorValue);

    ...
}
```

### Simple code example for 16 float values

```cpp
#include <ZzzMovingAvg.h>

ZzzMovingAvg <16, float, float> avg;

void setup()
{
    ...
}

void loop()
{
    ...

    float avgSensorValue = avg.add(mySensorValue);

    ...
}
```
