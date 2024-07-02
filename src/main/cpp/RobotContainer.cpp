// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/Autos.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"


RobotContainer::RobotContainer() {
 // Initialize all of your commands and subsystems here
  //inline style
  m_chooser.AddOption("Taxi Auto", m_testAuto.get());
  m_chooser.AddOption("8 note auto red alliance", m_shootAuto.get());

  frc::SmartDashboard::PutData(&m_chooser);
  frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser);
 // Configure the button bindings
  ConfigureBindings();

  m_drivetrain.SetDefaultCommand(frc2::cmd::Run(
      [this] {
        m_drivetrain.ArcadeDrive(m_driverController.GetRightX(),
                                 m_driverController.GetLeftY());
      },
      {&m_drivetrain}));

   }

  void RobotContainer::ConfigureBindings() {
    if(m_operatorController.GetLeftY() < 0.05){
      m_intake.GetIntakeCommand();
    } else if(m_operatorController.GetLeftY() > 0.05){
      m_intake.GetReverseIntakeCommand();
    } 


  //  m_operatorController.RightBumper().WhileTrue(m_indexer.GetIndexCommand());
  //  m_operatorController.LeftBumper().WhileTrue(m_indexer.GetReverseIndexCommand());

   m_operatorController.A().WhileTrue(m_GetToSpeedCommand.get());
  }

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  //return autos::a_Taxi(&m_drivetrain);
 return m_chooser.GetSelected();
}
