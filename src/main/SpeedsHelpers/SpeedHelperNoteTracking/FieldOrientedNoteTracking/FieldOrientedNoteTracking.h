// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "OvertureLib/Subsystems/Swerve/SpeedsHelper/SpeedsHelper.h"
#include <frc/controller/ProfiledPIDController.h>
#include "Subsystems/Chassis/Chassis.h"
#include "photon/PhotonCamera.h"
#include "photon/PhotonUtils.h"

class FieldOrientedNoteTracking : public SpeedsHelper  {
  public:
    FieldOrientedNoteTracking(Chassis *chassis, photon::PhotonCamera *noteTrackingCamera);
      void alterSpeed(frc::ChassisSpeeds &inputSpeed) override;
      void initialize() override;

  private: 
    frc::ProfiledPIDController<units::meters> wYPIDController{
      3, 0.0, 0.0, {2.0_mps, 1_mps_sq} //Before PID 10, Before mps 4.5
    };

    frc::ProfiledPIDController<units::meters> wXPIDController{
      4, 0.0, 0.0, {2.0_mps, 1_mps_sq} //Before PID 7, Before mps 4.5
    };

    frc::ProfiledPIDController<units::radian> headingController{
    // PID constants: 
    1, 0.0, 0.0, frc::TrapezoidProfile<units::radian>::Constraints{360_deg_per_s, 540_deg_per_s / 1_s} //Constraints max velocity, max acceleration
  };

    Chassis *chassis;
    photon::PhotonCamera *noteTrackingCamera;

};