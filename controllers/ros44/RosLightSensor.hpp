#ifndef ROS_LIGHT_SENSOR_HPP
#define ROS_LIGHT_SENSOR_HPP

#include <webots/LightSensor.hpp>
#include "RosSensor.hpp"

using namespace webots;

class RosLightSensor : public RosSensor
{
  public :
    RosLightSensor(LightSensor *lightSensor, Ros *ros);
    virtual ~RosLightSensor() { rosDisable(); }

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod){mLightSensor->enable(samplingPeriod);}
    virtual void           rosDisable(){mLightSensor->disable();}
    virtual int            rosSamplingPeriod() {return mLightSensor->getSamplingPeriod();}

  private :
    LightSensor *mLightSensor;
};

#endif //ROS_LIGHT_SENSOR_HPP
