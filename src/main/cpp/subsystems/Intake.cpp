#include "subsystems/Intake.h"
#include <iostream>

Intake::Intake()
    : m_intakeMotor{IntakeConstants::kIntakeID} {}

frc2::CommandPtr Intake::GetIntakeCommand() {
    return StartEnd(

        [this] {
            SetIntakeMotor(IntakeConstants::kIntakeVoltage);
        },

        [this] { Stop(); });
    
}

frc2::CommandPtr Intake::GetReverseIntakeCommand() {
    return StartEnd(

        [this] {
            SetIntakeMotor(IntakeConstants::kReverseIntakeVoltage);
        },

        [this] { Stop(); });
    
}

void Intake::SetIntakeMotor(units::volt_t voltage){
    m_intakeMotor.SetVoltage(voltage);
}

void Intake::Stop(){
    m_intakeMotor.Set(ControlMode::PercentOutput, 0);
}

void Intake::OnUpdate(units::second_t dt){
   std::cout << "Voltage: " << IntakeConstants::kIntakeVoltage.value() << std::endl;
}
