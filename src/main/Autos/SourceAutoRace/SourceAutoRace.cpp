// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "SourceAutoRace.h"

#include <pathplanner/lib/auto/NamedCommands.h>
#include <pathplanner/lib/auto/AutoBuilder.h>

frc2::CommandPtr SourceAutoRace(Storage* storage){
    return frc2::cmd::Sequence(
        pathplanner::NamedCommands::getCommand("autoSpeaker"),
        frc2::cmd::Parallel(
            pathplanner::AutoBuilder::followPath(pathplanner::PathPlannerPath::fromPathFile("SourceAuto1")),
            pathplanner::NamedCommands::getCommand("GroundGrabLarge")
        ),
        frc2::cmd::Either(
            frc2::cmd::Sequence(
                frc2::cmd::Sequence(
                    pathplanner::AutoBuilder::followPath(pathplanner::PathPlannerPath::fromPathFile("SourceAuto2")),
                    pathplanner::NamedCommands::getCommand("VisionSpeaker")
                ),
                frc2::cmd::Parallel(
                    pathplanner::AutoBuilder::followPath(pathplanner::PathPlannerPath::fromPathFile("SourceAuto3")),
                    pathplanner::NamedCommands::getCommand("GroundGrabLargeAuto")
                )
            ),
            frc2::cmd::Parallel(
                pathplanner::AutoBuilder::followPath(pathplanner::PathPlannerPath::fromPathFile("SourceAuto-Alt-1")),
                pathplanner::NamedCommands::getCommand("GroundGrabSmall")
            ),
            [=]{return storage->isNoteOnSensor();}
        ),
        frc2::cmd::Either(
            frc2::cmd::Sequence(
                pathplanner::AutoBuilder::followPath(pathplanner::PathPlannerPath::fromPathFile("SourceAuto4")),
                pathplanner::NamedCommands::getCommand("VisionSpeaker")
            ),
            frc2::cmd::Parallel(
                pathplanner::AutoBuilder::followPath(pathplanner::PathPlannerPath::fromPathFile("SourceAuto-Alt-2")),
                pathplanner::NamedCommands::getCommand("GroundGrabSmall")
            ),
            [=]{return storage->isNoteOnSensor();}
        )
    );
}   
