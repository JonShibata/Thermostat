
#ifndef THERMOSTAT_HPP
#define THERMOSTAT_HPP

class Thermostat {
  public:
  void setTarget(double T);
  void setHyst(double T);
  void setFilterConst(double k);
  void setValvePositionOff(int counts);
  void setValvePositionOn(int counts);
  void setSystemEnabled(bool enabled);
  void filterMeasuredTemp(double rawTemp);

  int getValvePositionOff();
  double getFilteredTemp();
  int getControlOutput();

  private:
  double target_ = 80.0;
  double hyst_ = 3.0;
  double filterConst_ = 0.5;
  double filteredTemp_ = 0.0;
  int valvePositionOff_ = 0;
  int valvePositionOn_ = 180;
  int output_ = valvePositionOff_;
  bool systemEnabled_ = false;
};

#endif
