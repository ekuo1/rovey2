#ifndef ROS_GYRO_HPP
#define ROS_GYRO_HPP

#include <webots/Gyro.hpp>
#include "RosSensor.hpp"

using namespace webots;

class RosGyro : public RosSensor
{
  public :
    RosGyro(Gyro *gyroscope, Ros *ros);
    virtual ~RosGyro() { rosDisable(); }

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod){mGyro->enable(samplingPeriod);}
    virtual void           rosDisable(){mGyro->disable();}
    virtual int            rosSamplingPeriod() {return mGyro->getSamplingPeriod();}

  private :
    Gyro *mGyro;
};

#endif //ROS_GYRO_HPP
