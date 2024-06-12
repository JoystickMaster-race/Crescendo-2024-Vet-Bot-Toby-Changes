#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/PIDCommand.h>
#include "Constants.h"
#include "ctre/Phoenix.h"
#include <units/voltage.h>
#include <units/time.h>

class Intake : public frc2::SubsystemBase {
 public:
    Intake();

frc2::CommandPtr GetIntakeCommand();
frc2::CommandPtr GetReverseIntakeCommand();

//void SetIntakeMotor(double speed);
//void SetIntakeMotor(units::volt_t voltage);
void SetIntakeMotor(double output);
void Stop();
void OnUpdate(units::second_t);

 private:

// WPI_VictorSPX m_intakeMotor;
TalonSRX m_intakeMotor;
};