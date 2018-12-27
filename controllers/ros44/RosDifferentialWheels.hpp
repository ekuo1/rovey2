#ifndef ROS_DIFFERENTIAL_WHEELS_HPP
#define ROS_DIFFERENTIAL_WHEELS_HPP

#include <webots/DifferentialWheels.hpp>

#include <webots_ros/get_float.h>
#include <webots_ros/set_float_array.h>

#include <webots_ros/differential_wheels_subscribe_twist_commands.h>
#include <webots_ros/differential_wheels_get_speed.h>

#include <geometry_msgs/Twist.h>

#include "Ros.hpp"
#include "RosSensor.hpp"

using namespace webots;

class RosDifferentialWheels : public RosSensor
{
  public :
    RosDifferentialWheels(Ros *ros, DifferentialWheels *differentialWheels);
    virtual ~RosDifferentialWheels();

    bool setEncodersCallback(webots_ros::set_float_array::Request &req, webots_ros::set_float_array::Response &res);
    bool setSpeedCallback(webots_ros::set_float_array::Request &req, webots_ros::set_float_array::Response &res);
    bool subscribeTwistSpeedCallback(webots_ros::differential_wheels_subscribe_twist_commands::Request &req, webots_ros::differential_wheels_subscribe_twist_commands::Response &res);
    bool getMaxSpeedCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    bool getSpeedCallback(webots_ros::differential_wheels_get_speed::Request &req, webots_ros::differential_wheels_get_speed::Response &res);
    bool getSpeedUnitCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    void topicCallback(const geometry_msgs::Twist::ConstPtr& command);
    void rosSetSpeed(int leftSpeed, int rightSpeed) {mDifferentialWheels->setSpeed(leftSpeed, rightSpeed);}

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod){mDifferentialWheels->enableEncoders(samplingPeriod);}
    virtual void           rosDisable(){mDifferentialWheels->disableEncoders();}
    virtual std::string    deviceName(){return mDifferentialWheels->getName();}
    virtual int            rosSamplingPeriod() {return mDifferentialWheels-> getEncodersSamplingPeriod();}

  private :
    DifferentialWheels *mDifferentialWheels;
    Ros                *mRos;
    ros::ServiceServer  mGetMaxSpeedServer;
    ros::ServiceServer  mGetSpeedServer;
    ros::ServiceServer  mGetSpeedUnitServer;
    ros::ServiceServer  mSetEncodersServer;
    ros::ServiceServer  mSetSpeedServer;
    ros::ServiceServer  mSubscribeTwistSpeedServer;
    ros::Subscriber     mSubscriber;
    int                 mCommand[2];
};

#endif //ROS_DIFFERENTIAL_WHEELS_HPP
