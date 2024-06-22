#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "subsystems/Intake.h"

class IntakeAuto : public frc2::CommandHelper<frc2::SequentialCommandGroup, IntakeAuto> {
    public:

    IntakeAuto(Intake* intake);
};