// // // Copyright (c) FIRST and other WPILib contributors.
// // // Open Source Software; you can modify and/or share it under the terms of
// // // the WPILib BSD license file in the root directory of this project.
#pragma once
#include <frc2/command/CommandPtr.h>
#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SendableChooser.h>


namespace autos {
    frc2::CommandPtr a_Taxi(Drivetrain* drivetrain);
    frc2::CommandPtr a_Shoot(ShooterPID* shooter);
    
    //frc2::CommandPtr a_2Note(Drivetrain*, drivetrain, Intake* intake, ShooterPID* shooter);
    //frc2::CommandPtr a_Shoot(ShooterPID* shooter);
}