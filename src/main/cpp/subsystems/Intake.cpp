#include "subsystems/Intake.h"
#include "Constants.h"
#include <iostream>

Intake::Intake() 
    : m_intakeMotor{IntakeConstants::kIntakeID}, 
      m_indexMotor{IntakeConstants::kIndexID} {
        m_indexMotor.Follow(m_intakeMotor, ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);
    }

frc2::CommandPtr Intake::GetIntakeCommand() {
    return StartEnd(

        [this] {
            SetIntakeMotor(IntakeConstants::kIntakeMotorSpeed);
        },

        [this] { Stop(); });
    
}

frc2::CommandPtr Intake::GetReverseIntakeCommand() {
    return StartEnd(

        [this] {
            SetIntakeMotor(IntakeConstants::kReverseIntakeMotorSpeed);
        },

        [this] { Stop(); });
    
}

// void Intake::SetIntakeMotor(units::volt_t voltage){
//     m_intakeMotor.Set(ControlMode::Current, voltage);
// }

void Intake::SetIntakeMotor(double output){
    m_intakeMotor.Set(ControlMode::PercentOutput, output);
}

void Intake::Stop(){
    m_intakeMotor.Set(ControlMode::PercentOutput, 0);
}

void Intake::OnUpdate(units::second_t dt){
   std::cout << "Voltage: " << IntakeConstants::kIntakeVoltage.value() << std::endl;
}
