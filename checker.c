#include <stdio.h>
#include <assert.h>
void printChargeRateStatusWarning();
int batteryIsOk(float temperature, float soc, float chargeRate);
int checkTemperature(float temperature);
int checkSOC(float soc);
int checkChargeRate(float chargeRate);
void printTemperatureStatus();
void printSOCStatus();
void printChargeRateStatusWarning();

int batteryIsOk(float temperature, float soc, float chargeRate) {
  return (checkTemperature(temperature) && checkSOC(soc) \
  && checkChargeRate(chargeRate));
}

int checkTemperature(float temperature) {
  if(temperature < 0 || temperature > 45){
    printTemperatureStatus();
    return 0;
  }
  return 1;
}

int checkSOC(float soc) {
  if(soc < 20 || soc > 80) {
    printSOCStatus();
    return 0;
  }
  return 1;
}

int checkChargeRate(float chargeRate) {
  if(chargeRate > 0.8) {
    printChargeRateStatusWarning();
    return 0;
  }
  return 1;
}

void printTemperatureStatus() {
  printf("Temperature out of range!\n"); 
  
}

void printSOCStatus() {
  printf("State of Charge out of range!\n");
  
}

void printChargeRateStatusWarning() {
  printf("Charge Rate out of range!\n");  
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
