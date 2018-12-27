#ifndef ROS_MOTOR_SENSOR_HPP
#define ROS_MOTOR_SENSOR_HPP

#include <webots/Motor.hpp>
#include "RosSensor.hpp"

using namespace webots;

class RosMotorSensor : public RosSensor
{
  public :
    RosMotorSensor(Motor *motor, std::string sensorName, Ros *ros);
    virtual ~RosMotorSensor() { rosDisable(); }

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod);
    virtual void           rosDisable();
    virtual std::string    deviceName();
    virtual int            rosSamplingPeriod();

  private :
    Motor *mMotor;
    int    mType;
};

#endif //ROS_MOTOR_SENSOR_HPP
