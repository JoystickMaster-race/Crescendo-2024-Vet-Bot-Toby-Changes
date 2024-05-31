#pragma once
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/PIDCommand.h>
#include "Constants.h"
#include "ctre/Phoenix.h"
#include <units/voltage.h>
#include <units/time.h>

class Shooter : public frc2::SubsystemBase {
    public:
    Shooter();

frc2::CommandPtr GetShootCommand();
frc2::CommandPtr GetReverseShootCommand();

void SetShooterMotor(units::volt_t voltage);
void Stop();
void OnUpdate(units::second_t);

 private:

 WPI_VictorSPX m_shooterTopMotor;
 WPI_VictorSPX m_shooterBottomMotor;


};