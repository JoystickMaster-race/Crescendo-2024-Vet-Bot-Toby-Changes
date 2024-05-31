// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/button/JoystickButton.h>


#include "commands/Autos.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // m_chooser.SetDefaultOption("Simple Auto", &ExampleAuto);
  // m_chooser.AddOption("Complex Auto", &autos::ScoreIntakeScore);

  // Configure the button bindings
  ConfigureBindings();

  m_drivetrain.SetDefaultCommand(frc2::cmd::Run(
      [this] {
        m_drivetrain.ArcadeDrive(m_driverController.GetRightX(),
                                 m_driverController.GetLeftY());
      },
      {&m_drivetrain}));

  // m_shooter.SetDefaultCommand(frc2::cmd::Run(
  //   [this] {
  //     m_shooter.Stop();
  //   },
  //   {&m_shooter}));

  // m_intake.SetDefaultCommand(frc2::cmd::Run(
  //   [this] {
  //     m_intake.Stop();
  //   },
  //   {&m_intake}));
  }

  void RobotContainer::ConfigureBindings() {
//   frc2::JoystickButton(&m_operatorController, frc::XboxController::Button::kA)
//   .OnTrue(GetToSpeed{500_rad_per_s, &m_launcher}.WithTimeout(5_s));
  
  m_operatorController.A().WhileTrue(m_shooter.GetShootCommand());
  // m_operatorController.LeftBumper().WhileTrue(m_shooter.GetReverseShootCommand());
  // if(m_operatorController.GetLeftY() < 0.5){
  //   m_intake.GetIntakeCommand();
  // }
  // else if(m_operatorController.GetLeftY() > 0.5){
  //   m_intake.GetReverseIntakeCommand();
  // }
  
  //  if(m_operatorController.GetLeftY() < 0.5 ){  
  //   (m_intake.GetIntakeCommand());
  //  }
  //  else if(m_operatorController.GetLeftY() > 0.5){
  //   (m_intake.GetReverseIntakeCommand());
  //  }
  //  else if(m_operatorController.GetRightBumper()){
  //   (m_shooter.GetShootCommand());
  //  }
  //  else if(m_operatorController.GetLeftBumper()){
  //   (m_shooter.GetReverseShootCommand());
  //  }
  //  else {
  //   m_intake.Stop();
  //   m_shooter.Stop();
  //  }
 }
//   // Configure your trigger bindings here
  // frc2::JoystickButton(&m_launcher, frc::XboxController::Button::kA)
  // .WhileTrue(
  //   frc2::PIDCommand{
  //     frc::PIDController{0, 0, 0},

  //   [this] {return m_launcher.GetPosition(); },

  //   0,

  //   [this](double output){
  //     m_launcher.SetTopMotor(m_operatorController.GetLeftBumper(), ControlMode::PercentOutput, output);
  //   },
  //   {&m_launcher});
  //   .ToPtr());
  //   }
 

  //m_operatorController.RightBumper().WhileTrue(m_launcher.GetLaunchCommand());
  //m_operatorController.LeftBumper().WhileTrue(m_launcher.GetReverseLauncherCommand());
 

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_drivetrain);
  // return autos::AutoTIntake(&m_intake);
  
  //return autos::ScoreIntakeScore(&m_drivetrain, &m_intake, &m_shooter);
}
