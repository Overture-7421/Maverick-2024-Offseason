// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "AlignToNote.h"

AlignToNote::AlignToNote(Chassis *chassis, photon::PhotonCamera *noteTrackingCamera) : noteTracking(chassis, noteTrackingCamera) {
  // Use addRequirements() here to declare subsystem dependencies.
  this->chassis = chassis;
  this->camera = noteTrackingCamera;
  
}

// Called when the command is initially scheduled.
void AlignToNote::Initialize() {
  chassis->enableSpeedHelper(&noteTracking);
}

// Called repeatedly when this Command is scheduled to run   
void AlignToNote::Execute() {}

// Called once the command ends or is interrupted.
void AlignToNote::End(bool interrupted) {
  chassis->disableSpeedHelper();
}

// Returns true when the command should end.
bool AlignToNote::IsFinished() {
  return false;
}
