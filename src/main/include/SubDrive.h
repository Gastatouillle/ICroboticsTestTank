#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

class SubDrive : public frc2::SubsystemBase {
 public:
     static SubDrive& GetInstance() {
    static SubDrive inst;
    return inst;
  }

  SubDrive();

  frc2::CommandPtr cmdDrive(frc2::CommandXboxController& controller);

 private:
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX FL{1};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX FR{2};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX BL{3};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX BR{4};

  frc::DifferentialDrive drive{FL, FR};
};
