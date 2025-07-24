#include "SubDrive.h"
SubDrive::SubDrive(){
  BR.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
  BL.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
  FR.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
  FL.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

  BR.Follow(FR);
  BL.Follow(FL);
}


frc2::CommandPtr SubDrive::cmdDrive(frc2::CommandXboxController& controller) {
  return Run([this, &controller] {
    drive.ArcadeDrive(-controller.GetLeftY(), -controller.GetLeftX() * 0.8);
  });
}
