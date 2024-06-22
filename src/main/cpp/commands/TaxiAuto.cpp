#include "commands/TaxiAuto.h"
#include <frc2/command/Commands.h>

TaxiAuto::TaxiAuto(Drivetrain* drivetrain){
    frc2::cmd::Run([drivetrain] {drivetrain->ArcadeDrive(0.5, 0); },
    {drivetrain})
    .WithTimeout(1.0_s)
    .AndThen(frc2::cmd::Run([drivetrain] {drivetrain->ArcadeDrive(0.0, 0.0); }, 
{drivetrain}));
}
