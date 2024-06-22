#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "subsystems/Drivetrain.h"

class TaxiAuto : public frc2::CommandHelper<frc2::SequentialCommandGroup, TaxiAuto> {
    public:

    TaxiAuto(Drivetrain* drive);
};
