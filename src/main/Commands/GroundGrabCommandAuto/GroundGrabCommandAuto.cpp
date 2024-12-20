// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "GroundGrabCommandAuto.h"

frc2::CommandPtr GroundGrabCommandAuto(Intake* intake, Storage* storage, SuperStructure* superStructure, Gamepad* gamepad){
    return frc2::cmd::Sequence(
        superStructure->setAngle(-31_deg, 68_deg),
        frc2::cmd::WaitUntil([superStructure]{
            return superStructure->getTargetPosition(-31_deg, 68_deg);
        }),
        frc2::cmd::Parallel(
            intake->startIntakeAuto(),
            storage->startStorageAuto()
        ),
        

        frc2::cmd::WaitUntil([storage]{
            return storage->isNoteOnSensor();
            
        })
    
    ).FinallyDo([=]() {
        intake->setVoltage(0_V);
        storage->setVoltage(0_V);
    });
}