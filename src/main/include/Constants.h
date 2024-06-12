// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <units/time.h>
#include <units/voltage.h>
#include <units/angle.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants {
    //Port numbers for driver and operator gamepads. These correspond with the numbers on the USB tab of the DriverStation
    constexpr int kDriverControllerPort = 0;
    constexpr int kOperatorControllerPort = 1;
}  // namespace OperatorConstants

namespace DrivetrainConstants {
   // PWM ports/CAN IDs for motor controllers
    constexpr int kLeftRearID = 2;
    constexpr int kLeftFrontID = 1;
    constexpr int kRightRearID = 4;
    constexpr int kRightFrontID = 3;
    constexpr int kTestID = 99;

   // Current limit for drivetrain motors
    constexpr int kCurrentLimit = 60;
}  // namespace DrivetrainConstants

 namespace IndexerConstants {
    constexpr int kIndexID = 99;
    constexpr units::volt_t kIndexVoltage = 2_V;
    constexpr units::volt_t kReverseIndexVoltage = -2_V;


 }
 namespace IntakeConstants {

    constexpr int kIntakeID = 99;
    constexpr double kIntakeMotorSpeed = 0.5;
    constexpr double kReverseIntakeMotorSpeed = -0.5;
    constexpr units::volt_t kIntakeVoltage = 6_V;
    constexpr units::volt_t kReverseIntakeVoltage = -6_V;
 }

 namespace ShooterConstants {
    constexpr int kShooterTopID = 99;
    constexpr int kShooterBottomID = 99;
    constexpr double kShooterMotorSpeed = 1;
    constexpr units::volt_t kShooterVoltage = 8_V;
    constexpr units::volt_t kReverseShooterVoltage = -8_V;

    inline constexpr auto kShooterFreeRPS = 5300_tr / 1_s;
    inline constexpr auto kShooterTargetRPS = 4000_tr / 1_s;
    inline constexpr auto kShooterToleranceRPS = 50_tr / 1_s;
    inline constexpr int kEncoderCPR = 1024;
    inline constexpr double kEncoderDistancePerPulse = 1.0 / static_cast<double>(kEncoderCPR);

    inline constexpr double kP = 0;
    inline constexpr double kI = 0;
    inline constexpr double kD = 0;

    inline constexpr auto kS = 0.05_V;
    inline constexpr auto kV = 12_V / kShooterFreeRPS;
 }
