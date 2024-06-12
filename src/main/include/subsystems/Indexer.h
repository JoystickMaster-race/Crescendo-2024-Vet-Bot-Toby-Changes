#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <units/voltage.h>

class Indexer : public frc2::SubsystemBase {
    public:
    Indexer();

    frc2::CommandPtr GetIndexCommand();
    frc2::CommandPtr GetReverseIndexCommand();

    void SetIndexMotor(units::volt_t voltage);

    void stop();

    private:
    WPI_VictorSPX m_indexMotor;
};