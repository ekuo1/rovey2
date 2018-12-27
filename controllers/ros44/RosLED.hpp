#ifndef ROS_LED_HPP
#define ROS_LED_HPP

#include <webots/LED.hpp>
#include "RosDevice.hpp"

#include <webots_ros/get_int.h>
#include <webots_ros/set_int.h>

using namespace webots;

class RosLED : public RosDevice
{
  public :
    RosLED(LED *led, Ros *ros);
    virtual ~RosLED();

    bool setCallback(webots_ros::set_int::Request &req, webots_ros::set_int::Response &res);
    bool getCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);

  private :
    LED               *mLED;
    ros::ServiceServer mSetServer;
    ros::ServiceServer mGetServer;
};

#endif //ROS_LED_HPP
