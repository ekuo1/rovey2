#ifndef ROS_JOYSTICK_HPP
#define ROS_JOYSTICK_HPP

#include <webots/Joystick.hpp>
#include "RosSensor.hpp"

#include <webots_ros/get_bool.h>
#include <webots_ros/get_int.h>
#include <webots_ros/get_string.h>
#include <webots_ros/set_float.h>
#include <webots_ros/set_int.h>

using namespace webots;

class RosJoystick : public RosSensor
{
  public :
    RosJoystick(Joystick *joystick, Ros *ros);
    virtual ~RosJoystick();

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           publishAuxiliaryValue();
    bool                   getModelCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool                   getNumberOfAxesCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool                   getNumberOfPovsCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool                   isConnectedCallback(webots_ros::get_bool::Request &req, webots_ros::get_bool::Response &res);
    bool                   setConstantForceCallback(webots_ros::set_int::Request &req, webots_ros::set_int::Response &res);
    bool                   setConstantForceDurationCallback(webots_ros::set_float::Request &req, webots_ros::set_float::Response &res);
    bool                   setAutoCenteringCallback(webots_ros::set_float::Request &req, webots_ros::set_float::Response &res);
    bool                   setResistanceGainCallback(webots_ros::set_float::Request &req, webots_ros::set_float::Response &res);
    bool                   setForceAxisCallback(webots_ros::set_int::Request &req, webots_ros::set_int::Response &res);

    virtual void           rosEnable(int samplingPeriod) {mJoystick->enable(samplingPeriod);}
    virtual void           rosDisable() {mJoystick->disable();}
    virtual int            rosSamplingPeriod() {return mJoystick->getSamplingPeriod();}

  private :
    void            publishAxesValue();

    Joystick       *mJoystick;
    ros::Publisher *mAxesValuePublisher;
    ros::Publisher *mPovsValuePublisher;

    ros::ServiceServer mGetModelServer;
    ros::ServiceServer mGetNumberOfAxesServer;
    ros::ServiceServer mGetNumberOfPovsServer;
    ros::ServiceServer mIsConnectedServer;
    ros::ServiceServer mSetConstantForceServer;
    ros::ServiceServer mSetConstantForceDurationServer;
    ros::ServiceServer mSetAutoCenteringGainServer;
    ros::ServiceServer mSetResistanceGainServer;
    ros::ServiceServer mSetForceAxisServer;
};

#endif //ROS_JOYSTICK_HPP
