// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "SubDrive.h"
#include "SubManipulator.h"

#include <frc2/command/Commands.h>

RobotContainer::RobotContainer() {
  SubDrive::GetInstance();
  SubManipulator::GetInstance();
  ConfigureBindings();

  SubDrive::GetInstance().SetDefaultCommand(SubDrive::GetInstance().cmdDrive(DriverController));
}


void RobotContainer::ConfigureBindings() {
  DriverController.LeftBumper().WhileTrue(SubManipulator::GetInstance().cmdSpinManipulator1(0.5))
    .OnFalse(SubManipulator::GetInstance().cmdSpinManipulator1(0));
  DriverController.LeftTrigger().WhileTrue(SubManipulator::GetInstance()
    .cmdSpinManipulator2(0.5)).OnFalse(SubManipulator::GetInstance().cmdSpinManipulator2(0));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}
