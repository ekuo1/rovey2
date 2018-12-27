#ifndef ROS_BRAKE_HPP
#define ROS_BRAKE_HPP

#include <webots/Brake.hpp>
#include "RosDevice.hpp"

#include <webots_ros/get_int.h>
#include <webots_ros/get_string.h>
#include <webots_ros/set_float.h>

using namespace webots;

class RosBrake : public RosDevice
{
  public :
    RosBrake(Brake *brake, Ros *ros);
    virtual ~RosBrake();

    bool setdampingConstantCallback(webots_ros::set_float::Request &req, webots_ros::set_float::Response &res);
    bool getTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool getMotorNameCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool getPositionSensorNameCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);

  private :
    Brake             *mBrake;
    ros::ServiceServer mSetDampingConstantServer;
    ros::ServiceServer mGetTypeServer;
    ros::ServiceServer mGetMotorNameServer;
    ros::ServiceServer mGetPositionSensorNameServer;
    ros::Publisher     mPublisher;
};

#endif //ROS_BRAKE_HPP
