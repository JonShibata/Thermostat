

#ifdef UNIT_TEST

#include <gtest/gtest.h>
#include "../src/Thermostat.hpp"

TEST (ThermostatMain, MethodTests) {
  Thermostat thermostat;

  thermostat.setValvePositionOff(37);

  EXPECT_EQ(thermostat.getValvePositionOff(), 37);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif