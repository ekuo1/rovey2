#ifndef ROS_POSITION_SENSOR_HPP
#define ROS_POSITION_SENSOR_HPP

#include <webots/PositionSensor.hpp>
#include "RosSensor.hpp"

#include <webots_ros/get_int.h>

using namespace webots;

class RosPositionSensor : public RosSensor
{
  public :
    RosPositionSensor(PositionSensor *positionSensor, Ros *ros);
    virtual ~RosPositionSensor();

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod){mPositionSensor->enable(samplingPeriod);}
    virtual void           rosDisable(){mPositionSensor->disable();}
    virtual int            rosSamplingPeriod() {return mPositionSensor->getSamplingPeriod();}
    bool                   getTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool                   getBrakeNameCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool                   getMotorNameCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);

  private :
    PositionSensor    *mPositionSensor;
    ros::ServiceServer mTypeServer;
    ros::ServiceServer mGetBrakeNameServer;
    ros::ServiceServer mGetMotorNameServer;
};

#endif //ROS_POSITION_SENSOR_HPP
