#ifndef ROS_COMPASS_HPP
#define ROS_COMPASS_HPP

#include <webots/Compass.hpp>
#include "RosSensor.hpp"

using namespace webots;

class RosCompass : public RosSensor
{
  public :
    RosCompass(Compass *compass, Ros *ros);
    virtual ~RosCompass() { rosDisable(); }

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod) {mCompass->enable(samplingPeriod);}
    virtual void           rosDisable() {mCompass->disable();}
    virtual int            rosSamplingPeriod() {return mCompass->getSamplingPeriod();}

  private :
    Compass *mCompass;
};

#endif //ROS_COMPASS_HPP
