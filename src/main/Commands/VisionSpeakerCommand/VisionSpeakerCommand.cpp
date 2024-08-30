// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "VisionSpeakerCommand.h"

VisionSpeakerCommand::VisionSpeakerCommand() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void VisionSpeakerCommand::Initialize() {
  targetWhileMoving.setTargetLocation({0.69_m, 5.56_m});
  
}

// Called repeatedly when this Command is scheduled to run
void VisionSpeakerCommand::Execute() {
  //targetWhileMoving.getMovingTarget()
}

// Called once the command ends or is interrupted.
void VisionSpeakerCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool VisionSpeakerCommand::IsFinished() {
  return false;
}
