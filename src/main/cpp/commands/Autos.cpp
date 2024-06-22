#include "commands/Autos.h"

#include <frc2/command/Commands.h>

frc2::CommandPtr autos::a_Test(Drivetrain* drivetrain){
    return frc2::cmd::Run([drivetrain] {drivetrain->ArcadeDrive(0.5, 0); },
    {drivetrain})
.WithTimeout(1.0_s)
.AndThen(frc2::cmd::Run([drivetrain] {drivetrain->ArcadeDrive(0.0, 0.0); }, 
{drivetrain}));
}