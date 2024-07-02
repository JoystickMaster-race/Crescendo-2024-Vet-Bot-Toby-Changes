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
    return frc2::cmd::Run([shooter] {shooter->UseOutput(1, ShooterConstants::kShooterTargetRPS.value()); },
    {shooter});

    //*setpoint attempts*
    //Until(shooter.m_controller->AtSetpoint())
    //.Until(std::function<bool>{shooter->AtSetpoint()});
//.Until(std::function<bool>{ shooter->AtSetpoint()} == true);

}