#ifndef ROS_BATTERY_SENSOR_HPP
#define ROS_BATTERY_SENSOR_HPP

#include <webots/Robot.hpp>
#include "RosSensor.hpp"

using namespace webots;

class RosBatterySensor : public RosSensor
{
  public :
    RosBatterySensor(Robot *robot, Ros *ros);
    virtual ~RosBatterySensor() { rosDisable(); }

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod) {mRobot->batterySensorEnable(samplingPeriod);}
    virtual void           rosDisable(){mRobot->batterySensorDisable();}
    virtual std::string    deviceName(){return "battery_sensor";}
    virtual int            rosSamplingPeriod() {return mRobot->batterySensorGetSamplingPeriod();}

  private :
    Robot *mRobot;
};

#endif //ROS_BATTERY_HPP
