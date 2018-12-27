#ifndef ROS_GPS_HPP
#define ROS_GPS_HPP

#include <webots/GPS.hpp>
#include "RosSensor.hpp"

#include <webots_ros/get_int.h>

#include <webots_ros/gps_decimal_degrees_to_degrees_minutes_seconds.h>

using namespace webots;

class RosGPS : public RosSensor
{
  public :
    RosGPS(GPS *gps, Ros *ros);
    virtual ~RosGPS();

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod) {mGPS->enable(samplingPeriod);}
    virtual void           rosDisable() {mGPS->disable();}
    virtual int            rosSamplingPeriod() {return mGPS->getSamplingPeriod();}

    bool                   getCoordinateTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool                   convertToDegreesMinutesSecondsCallback(webots_ros::gps_decimal_degrees_to_degrees_minutes_seconds::Request &req, webots_ros::gps_decimal_degrees_to_degrees_minutes_seconds::Response &res);

  private :
    GPS                *mGPS;
    ros::Publisher      mSpeedPublisher;
    ros::ServiceServer  mCoordinateTypeServer;
    ros::ServiceServer  mConvertServer;
};

#endif //ROS_GPS_HPP
