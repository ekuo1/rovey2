#ifndef ROS_TOUCH_SENSOR_HPP
#define ROS_TOUCH_SENSOR_HPP

#include <webots/TouchSensor.hpp>
#include "RosSensor.hpp"

#include <webots_ros/get_int.h>

using namespace webots;

class RosTouchSensor : public RosSensor
{
  public :
    RosTouchSensor(TouchSensor *touchSensor, Ros *ros);
    virtual ~RosTouchSensor();

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod) {mTouchSensor->enable(samplingPeriod);}
    virtual void           rosDisable() {mTouchSensor->disable();}
    virtual int            rosSamplingPeriod() {return mTouchSensor->getSamplingPeriod();}
    bool                   getTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);

  private :
    TouchSensor       *mTouchSensor;
    ros::ServiceServer mTypeServer;
};

#endif //ROS_TOUCH_SENSOR_HPP
