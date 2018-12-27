#ifndef ROS_MOUSE_HPP
#define ROS_MOUSE_HPP

#include <webots/Mouse.hpp>
#include "RosSensor.hpp"

#include <webots_ros/mouse_get_state.h>
#include <webots_ros/get_bool.h>
#include <webots_ros/set_bool.h>

using namespace webots;

class RosMouse : public RosSensor
{
  public :
    RosMouse(Mouse *mouse, Ros *ros);
    virtual ~RosMouse();

    virtual ros::Publisher createPublisher() = 0;
    virtual void           publishValue(ros::Publisher publisher) = 0;

    virtual void           rosEnable(int samplingPeriod) { mMouse->enable(samplingPeriod); }
    virtual void           rosDisable() { mMouse->disable(); }
    virtual int            rosSamplingPeriod() { return mMouse->getSamplingPeriod(); }

    bool getStateCallback(webots_ros::mouse_get_state::Request &req, webots_ros::mouse_get_state::Response &res);
    bool enable3dPositionCallback(webots_ros::set_bool::Request &req, webots_ros::set_bool::Response &res);
    bool disable3dPositionCallback(webots_ros::set_bool::Request &req, webots_ros::set_bool::Response &res);
    bool is3dPositionEnabledCallback(webots_ros::get_bool::Request &req, webots_ros::get_bool::Response &res);

  private :
    Mouse *mMouse;

    ros::ServiceServer mGetStateServer;
    ros::ServiceServer mEnable3dPositionServer;
    ros::ServiceServer mDisable3dPositionServer;
    ros::ServiceServer mIs3dPositionEnabledServer;
};

#endif //ROS_MOUSE_HPP
