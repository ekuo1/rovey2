#ifndef ROS_RADAR_HPP
#define ROS_RADAR_HPP

#include <webots/Radar.hpp>
#include "RosSensor.hpp"

#include <webots_ros/get_float.h>

using namespace webots;

class RosRadar : public RosSensor
{
  public :
    RosRadar(Radar *radar, Ros *ros);
    virtual ~RosRadar();

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    bool                   getMaxRangeCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    bool                   getMinRangeCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    bool                   getVerticalFovCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    bool                   getHorizontalFovCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);

    virtual void           rosEnable(int samplingPeriod) { mRadar->enable(samplingPeriod); }
    virtual void           rosDisable()                  { mRadar->disable(); }
    virtual int            rosSamplingPeriod()           { return mRadar->getSamplingPeriod(); }

  private :
    Radar             *mRadar;
    ros::Publisher     mTargetsNumberPublisher;
    ros::ServiceServer mGetMaxRangeServer;
    ros::ServiceServer mGetMinRangeServer;
    ros::ServiceServer mGetVerticalFovServer;
    ros::ServiceServer mGetHorizontalFovServer;
};

#endif //ROS_RADAR_HPP
