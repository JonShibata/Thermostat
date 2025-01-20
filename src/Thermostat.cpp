
#include "Thermostat.hpp"
#include <cmath>

void Thermostat::setTarget(double T) {
  target_ = T;
}

void Thermostat::setHyst(double H) {
  hyst_ = H;
}

void Thermostat::setFilterConst(double k) {
  filterConst_ = k;
}

void Thermostat::setValvePositionOff(int counts) {
  valvePositionOff_ = counts;
}

int Thermostat::getValvePositionOff() {
  return valvePositionOff_;
}

void Thermostat::setValvePositionOn(int counts) {
  valvePositionOn_ = counts;
}

void Thermostat::setSystemEnabled(bool enabled) {
  systemEnabled_ = enabled;
}

void Thermostat::filterMeasuredTemp(double rawTemp) {
  if (std::isnan(rawTemp)) {
    // hold last value
  } else {
    // Lag filter
    filteredTemp_ = filteredTemp_ + (rawTemp - filteredTemp_) * filterConst_;
  }
}

double Thermostat::getFilteredTemp() {
  return filteredTemp_;
}

int Thermostat::getControlOutput() {
  if (systemEnabled_ == false) {
    output_ = valvePositionOff_;
  } else if (filteredTemp_ > (double)(target_ + hyst_)) {
    output_ = valvePositionOff_;
  } else if (filteredTemp_ < (double)(target_ - hyst_)) {
    output_ = valvePositionOn_;
  }
  return output_;
}