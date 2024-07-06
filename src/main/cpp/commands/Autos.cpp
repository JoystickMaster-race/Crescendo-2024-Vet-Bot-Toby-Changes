#include "commands/Autos.h"
#include <iostream>
#include <frc2/command/Commands.h>
#include "Constants.h"

frc2::CommandPtr autos::a_Taxi(Drivetrain* drivetrain){
    //drivetrain::GetTalon().SetInverted(true);

    // return frc2::cmd::Run([drivetrain] {drivetrain->GetTalon().SetInverted(true); },
    // {drivetrain});
    return frc2::cmd::Run([drivetrain] {drivetrain->ArcadeDrive(0.5, 0); },
    {drivetrain})
.WithTimeout(1.0_s)
.AndThen(frc2::cmd::Run([drivetrain] {drivetrain->ArcadeDrive(0.0, 0.0); }, 
{drivetrain}));
}

frc2::CommandPtr autos::a_Shoot(ShooterPID* shooter){
    return frc2::cmd::Run([shooter] {shooter->SetShooterMotor(6_V);}, {shooter} )
.WithTimeout(2.0_s);
}
