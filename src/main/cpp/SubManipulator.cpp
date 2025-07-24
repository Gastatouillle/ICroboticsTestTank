#include "SubManipulator.h"
  
SubManipulator::SubManipulator(){
  config1.SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kBrake);
  config2.SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kBrake);

  manipulatorOne.Configure(config1, rev::spark::SparkBase::ResetMode::kNoResetSafeParameters,
                            rev::spark::SparkBase::PersistMode::kPersistParameters);

  manipulatorTwo.Configure(config2, rev::spark::SparkBase::ResetMode::kNoResetSafeParameters,
                            rev::spark::SparkBase::PersistMode::kPersistParameters);
}


frc2::CommandPtr SubManipulator::cmdSpinManipulator1(double speed){
    return frc2::cmd::Run([this,speed]{
        manipulatorOne.Set(speed);
    });
}

frc2::CommandPtr SubManipulator::cmdSpinManipulator2(double speed){
    return frc2::cmd::Run([this,speed]{
        manipulatorTwo.Set(speed);
    });
}
