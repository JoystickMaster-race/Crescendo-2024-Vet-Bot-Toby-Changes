// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include "units/voltage.h"
#include <iostream>

using namespace DrivetrainConstants;

Drivetrain::Drivetrain()
    : m_frontLeft{kLeftFrontID},
      m_backLeft{kLeftRearID},
      m_frontRight{kRightFrontID},
      m_backRight{kRightRearID} {
      //m_testMotor{kTestID} {
  // Invert left side motors so both sides drive forward with positive output
  // values
  
  //m_frontLeft.ConfigPeakCurrentLimit(10, 10);
    
    
  m_backLeft.ConfigContinuousCurrentLimit(60, 0.1);
  m_backLeft.Follow(m_frontLeft, ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);
  m_backRight.Follow(m_frontRight, ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);
  
  //frc::DifferentialDrive m_drive{m_frontLeft, m_frontRight};
  // frc::DifferentialDrive m_drive{ [&](double output) {m_frontLeft;},
  // [&](double output) {m_frontRight;}
  // };
  
  
  // frc::DifferentialDrive m_drive{m_frontLeft, m_frontRight};
  //m_leftMotors.SetInverted(true);
  //m_rightMotors.SetInverted(false);
}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {
  std::cout << "Voltage: " << m_frontLeft.GetMotorOutputVoltage() << std::endl;
}

void Drivetrain::ArcadeDrive(double speed, double rotation) {
  m_drive.ArcadeDrive(speed, rotation);
}