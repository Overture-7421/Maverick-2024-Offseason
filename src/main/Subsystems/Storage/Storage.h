// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "OvertureLib/MotorControllers/OverTalonFX/OverTalonFX.h"
#include "OvertureLib/MotorControllers/ControllerNeutralMode/ControllerNeutralMode.h"

class Storage : public frc2::SubsystemBase {
 public:
  Storage();

  void setVoltage(units::volt_t voltage);
  frc2::CommandPtr startStorage();
  frc2::CommandPtr stopStorage();
  frc2::CommandPtr reverseStorage();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
 OverTalonFX storagemotor{24, ControllerNeutralMode::Coast, false, "CANIvore"};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};