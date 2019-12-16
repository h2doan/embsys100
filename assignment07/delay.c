#include "delay.h"

static uint32_t maxCount;
volatile uint32_t counterSeconds; // Count every 1 msec until maxCount.

void delay(unsigned int iteration)
{
  while (iteration > 0)
  {
    iteration--;
  }
}

void resetCounterSeconds(void) {
  counterSeconds = 0;
}

// This function is invoked every msec to count.
void incCounterSeconds(void) {
  if ((counterSeconds >= 0) && (counterSeconds < maxCount)) {
    counterSeconds++;
  }
}

void delayMsec(uint32_t delayInMilliseconds)
{
  maxCount = delayInMilliseconds;
  while (counterSeconds != maxCount) {
  }
}