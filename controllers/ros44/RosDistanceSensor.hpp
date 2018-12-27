#ifndef ROS_DISTANCE_SENSOR_HPP
#define ROS_DISTANCE_SENSOR_HPP

#include <webots/DistanceSensor.hpp>
#include "RosSensor.hpp"

#include <webots_ros/get_float.h>
#include <webots_ros/get_int.h>

using namespace webots;

class RosDistanceSensor : public RosSensor
{
  public :
    RosDistanceSensor(DistanceSensor *distanceSensor, Ros *ros);
    virtual ~RosDistanceSensor();

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod) {mDistanceSensor->enable(samplingPeriod);}
    virtual void           rosDisable() {mDistanceSensor->disable();}
    virtual int            rosSamplingPeriod() {return mDistanceSensor->getSamplingPeriod();}

    bool                   getMinValueCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    bool                   getMaxValueCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    bool                   getApertureCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    bool                   getTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);

  private :
    DistanceSensor     *mDistanceSensor;
    ros::ServiceServer  mMinValueServer;
    ros::ServiceServer  mMaxValueServer;
    ros::ServiceServer  mApertureServer;
    ros::ServiceServer  mTypeServer;
};

#endif //ROS_DISTANCE_SENSOR_HPP
