#include <frc2/command/Commands.h>
#include "commands/IntakeAuto.h"
#include "Constants.h"

IntakeAuto::IntakeAuto(Intake* intake){
    frc2::cmd::Run([intake] {intake->SetIntakeMotor(IntakeConstants::kIntakeMotorSpeed); },
    {intake})
    .WithTimeout(1.0_s)
    .AndThen(frc2::cmd::Run([intake] {intake->Stop(); }, 
{intake}));
}
