// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/Commands.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "Constants.h"
//#include "subsystems/PWMDrivetrain.h"
//#include "subsystems/PWMLauncher.h"
#include "commands/Autos.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
//#include "subsystems/Indexer.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:

  Drivetrain m_drivetrain;
  Intake m_intake;
  ShooterPID m_shooter;
  //Indexer m_indexer;
  frc::SendableChooser<frc2::Command*> m_chooser;
  frc2::CommandPtr m_testAuto = autos::a_Taxi(&m_drivetrain);
  //frc2::CommandPtr m_shootAuto = autos::a_Shoot(&m_shooter);
  
  frc2::CommandPtr m_GetToSpeedCommand = frc2::cmd::RunOnce([this]{m_shooter.Enable(); }, {&m_shooter});

  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};
  frc2::CommandXboxController m_operatorController{
      OperatorConstants::kOperatorControllerPort};    
  void ConfigureBindings();
};

