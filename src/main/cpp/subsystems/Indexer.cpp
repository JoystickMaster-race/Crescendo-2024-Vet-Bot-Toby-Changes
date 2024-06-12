#include "Subsystems/Indexer.h"
#include "Constants.h"

Indexer::Indexer()
   :m_indexMotor{IndexerConstants::kIndexID} {}

frc2::CommandPtr Indexer::GetIndexCommand() {
    return StartEnd(

        [this] {
            SetIndexMotor(IndexerConstants::kIndexVoltage);
        },

        [this] { stop(); });
    
}

frc2::CommandPtr Indexer::GetReverseIndexCommand() {
        return StartEnd(

        [this] {
            SetIndexMotor(IndexerConstants::kReverseIndexVoltage);
        },

        [this] { stop(); });
}

void Indexer::SetIndexMotor(units::volt_t voltage){
    m_indexMotor.SetVoltage(voltage);
}

void Indexer::stop(){
    m_indexMotor.Set(ControlMode::PercentOutput, 0);
}