#pragma once
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/PIDCommand.h>
#include <frc2/command/PIDSubsystem.h>
#include "Constants.h"
#include "ctre/Phoenix.h"
#include <units/voltage.h>
#include <units/time.h>
#include <units/angular_velocity.h>
#include <frc/DutyCycleEncoder.h>
#include <units/angle.h>
#include <frc/Encoder.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <networktables/NetworkTableInstance.h>

#include <memory>
#include <string>

class ShooterPID : public frc2::PIDSubsystem {
public:
    ShooterPID();
 
  //frc2::CommandPtr GetToSpeedCommand();
  void UseOutput(double output, double setpoint) override;

  double GetMeasurement() override;

  bool AtSetpoint();

  void OnUpdate(units::second_t);

  //frc::CommandPtr GetToSpeedCommand();

  //void SetIndexer(units::volt_t voltage)

//  void SetShooterMotor();

 private:

 WPI_VictorSPX m_shooterTopMotor;
 WPI_VictorSPX m_shooterBottomMotor;
 frc::Encoder m_shooterEncoder;
 frc::SimpleMotorFeedforward<units::turns> m_shooterFeedforward;
 std::shared_ptr<nt::NetworkTable> _table = nt::NetworkTableInstance::GetDefault().GetTable("ShooterPID");

};