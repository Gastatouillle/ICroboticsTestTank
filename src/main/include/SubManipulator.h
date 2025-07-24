// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <rev/SparkMax.h>
#include <frc2/command/CommandPtr.h> 
#include <frc2/command/Commands.h>
#include <frc/drive/DifferentialDrive.h>
#include <rev/config/SparkMaxConfig.h>

class SubManipulator : public frc2::SubsystemBase {
 public:
  SubManipulator();

  static SubManipulator &GetInstance() {
    static SubManipulator inst;
    return inst;
  }

  frc2::CommandPtr cmdSpinManipulator1(double speed);
  frc2::CommandPtr cmdSpinManipulator2(double speed);

 private:
  rev::spark::SparkMax manipulatorOne{5, rev::spark::SparkLowLevel::MotorType::kBrushless};
  rev::spark::SparkMax manipulatorTwo{6, rev::spark::SparkLowLevel::MotorType::kBrushless};
  
  rev::spark::SparkMaxConfig config1;
  rev::spark::SparkMaxConfig config2;

};
