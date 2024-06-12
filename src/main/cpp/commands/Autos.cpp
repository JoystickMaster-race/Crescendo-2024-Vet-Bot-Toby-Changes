// // Copyright (c) FIRST and other WPILib contributors.
// // Open Source Software; you can modify and/or share it under the terms of
// // the WPILib BSD license file in the root directory of this project.

// #include "commands/Autos.h"

// #include <frc2/command/Commands.h>

// frc2::CommandPtr autos::ExampleAuto(Drivetrain* drivetrain) {
  
//   // Drive half speed reverse for 1 second and then stop.
//   return frc2::cmd::Run([drivetrain] { drivetrain->ArcadeDrive(0.5, 0); },
//                         {drivetrain})
//       .WithTimeout(1.0_s)
//       .AndThen(frc2::cmd::Run([drivetrain] { drivetrain->ArcadeDrive(0, 0); },
//                               {drivetrain}));
      
// }

// // frc2::CommandPtr autos::ScoreIntakeScore(Drivetrain* drivetrain, Intake* intake, Shooter* shooter){
// //   return frc2::cmd::Run([drivetrain] { drivetrain->ArcadeDrive(0.5, 0); },
// //                         {drivetrain})
// //       .WithTimeout(1.0_s)
// //       .AndThen(frc2::cmd::Run([drivetrain] { drivetrain->ArcadeDrive(0, 0.5); },
// //                         {drivetrain}))
// //       .AlongWith(frc2::cmd::Run([intake] {intake->SetIntakeMotor(6_V); },
// //                               {intake}))
// //       .WithTimeout(1.0_s)
// //       .AndThen(frc2::cmd::Run([intake] {intake->SetIntakeMotor(6_V); },
// //                               {intake}))
// //       .WithTimeout(1.0_s);


// // }

