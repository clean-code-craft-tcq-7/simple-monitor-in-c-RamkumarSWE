#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate);
int checkTemperature(float temperature);
int checkSOC(float soc);
int checkChargeRate(float chargeRate);
void printTemperatureStatus(float temperature);
void printSOCStatus(float soc)
void printChargeRateStatus();

int batteryIsOk(float temperature, float soc, float chargeRate) {
  return (checkTemperature(temperature) && checkSOC(soc) \
  && checkChargeRate(chargeRate));
}

int checkTemperature(float temperature) {
  if(temperature < 0 || temperature > 45){
    printTemperatureStatus(temperature);
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
    printChargeRateStatus();
    return 0;
  }
  return 1;
}

void printTemperatureStatus(float temperature) {
  printf("Temperature out of range!\t");
  if (temperature < 0){
    printf("LOW\n"); 
  }else {
    printf("HIGH\n"); 
  }
  
}

void printSOCStatus(float soc) {
  printf("State of Charge out of range!\t");
  if(soc < 20){
    printf("LOW\n");
  }else {
    printf("HIGH\n");
  }
  
}

void printChargeRateStatus() {
  printf("Charge Rate out of range!\n");  
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
