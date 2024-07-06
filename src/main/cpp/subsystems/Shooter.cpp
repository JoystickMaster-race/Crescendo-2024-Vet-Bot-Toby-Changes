#include "subsystems/Shooter.h"

#include <frc/controller/PIDController.h>

#include "Constants.h"


 ShooterPID::ShooterPID()
     : PIDSubsystem{frc::PIDController{ShooterConstants::kP, ShooterConstants::kI, ShooterConstants::kD,}},
     m_shooterTopMotor{ShooterConstants::kShooterTopID},
    m_shooterBottomMotor{ShooterConstants::kShooterBottomID},
    m_shooterEncoder{0, 1},
    m_shooterFeedforward(ShooterConstants::kS, ShooterConstants::kV) {
        m_controller.SetTolerance(ShooterConstants::kShooterToleranceRPS.value());
        SetSetpoint(ShooterConstants::kShooterTargetRPS.value());
    }

frc2::CommandPtr ShooterPID::GetRawControlCommand() {
    return StartEnd(

        [this] {
            SetShooterMotor(ShooterConstants::kShooterVoltage);
        },

        [this] { Stop(); });
    
}

void ShooterPID::UseOutput(double output, double setpoint) {
    m_shooterTopMotor.SetVoltage(units::volt_t{output} + m_shooterFeedforward.Calculate(ShooterConstants::kShooterTargetRPS));

}

double ShooterPID::GetMeasurement() {
    return m_shooterEncoder.GetRate();
}

bool ShooterPID::AtSetpoint() {
    return m_controller.AtSetpoint();
}

void ShooterPID::SetShooterMotor(units::volt_t voltage){
    m_shooterTopMotor.SetVoltage(voltage);
}

void ShooterPID::Stop(){
    m_shooterTopMotor.SetVoltage(0_V);
}

void ShooterPID::OnUpdate(units::second_t dt){
   _table->GetEntry("Setpoint").SetDouble(ShooterConstants::kShooterTargetRPS.value());
   _table->GetEntry("Output").SetDouble(ShooterPID::m_shooterEncoder.GetRate());
}