#include "subsystems/Shooter.h"
#include <iostream>

Shooter::Shooter()
    : m_shooterTopMotor{ShooterConstants::kShooterTopID},
    m_shooterBottomMotor{ShooterConstants::kShooterBottomID} {

    m_shooterBottomMotor.Follow(m_shooterTopMotor, ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);

    }
frc2::CommandPtr Shooter::GetShootCommand() {
    return StartEnd(

        [this] {
            SetShooterMotor(ShooterConstants::kShooterVoltage);
        },

        [this] {Stop(); });
}

frc2::CommandPtr Shooter::GetReverseShootCommand() {
    return StartEnd(

        [this] {
            SetShooterMotor(ShooterConstants::kReverseShooterVoltage);
        },

        [this] { Stop(); });
    
}

void Shooter::SetShooterMotor(units::volt_t voltage){
    m_shooterTopMotor.SetVoltage(voltage);
}

void Shooter::Stop(){
    m_shooterTopMotor.Set(ControlMode::PercentOutput, 0);
}

void Shooter::OnUpdate(units::second_t dt){
   std::cout << "Shooter Voltage: " << IntakeConstants::kIntakeVoltage.value() << std::endl;
   std::cout << "ShooterMotor Voltage: " << m_shooterTopMotor.GetMotorOutputVoltage() << std::endl;
}

