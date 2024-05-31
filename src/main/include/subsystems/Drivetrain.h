// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include "rev/CANSparkMax.h"
#include <ctre/Phoenix.h>
//#include <ctre/phoenix/motorcontrol/can/BaseMotorController.h>

#include "Constants.h"

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void ArcadeDrive(double speed, double rotation);

  TalonSRX GetTalon();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  // The motor controllers
  TalonSRX m_frontLeft{3};
  TalonSRX m_backLeft{1};
  TalonSRX m_frontRight{4};
  TalonSRX m_backRight{2};
  //WPI_VictorSPX m_testMotor{99};

  

  // The motors on the left side of the drive
  //frc::MotorControllerGroup m_leftMotors{m_frontLeft, m_backLeft};


  // The motors on the right side of the drive
  //frc::MotorControllerGroup m_rightMotors{m_frontRight, m_backRight};

  // The robot's drive
  //frc::DifferentialDrive m_drive{m_frontLeft, m_frontRight};
  frc::DifferentialDrive m_drive{ 
  [&](double output) {m_frontLeft.Set(ControlMode::PercentOutput, output); },
  [&](double output) {m_frontRight.Set(ControlMode::PercentOutput, output); }};
};
