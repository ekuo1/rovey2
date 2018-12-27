#ifndef ROS_ACCELEROMETER_HPP
#define ROS_ACCELEROMETER_HPP

#include <webots/Accelerometer.hpp>
#include "RosSensor.hpp"

using namespace webots;

class RosAccelerometer : public RosSensor
{
  public :
    RosAccelerometer(Accelerometer *accelerometer, Ros *ros);
    virtual ~RosAccelerometer() { rosDisable(); }

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod) {mAccelerometer->enable(samplingPeriod);}
    virtual void           rosDisable(){mAccelerometer->disable();}
    virtual int            rosSamplingPeriod() {return mAccelerometer->getSamplingPeriod();}

  private :
    Accelerometer *mAccelerometer;
};

#endif //ROS_ACCELEROMETER_HPP
