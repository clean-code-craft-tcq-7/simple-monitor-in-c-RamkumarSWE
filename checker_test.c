#include <assert.h>
#include "checker.h"

int main() {

  //Battery Check
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0.8));
  assert(!batteryIsOk(25, -12, 0.7));
  assert(!batteryIsOk(-110, 80, 0.7));

  //Battery Temperature Check
  assert(checkTemperature(33.0));
  assert(!checkTemperature(-52.0));
  assert(!checkTemperature(150.0));
  
  //Battery SOC Check
  assert(checkSOC(23.0));
  assert(!checkSOC(-32.0));
  assert(!checkSOC(350.0));

  //Battery charge rate check
  assert(checkChargeRate(0.7));
  assert(!checkChargeRate(122.0));
}
