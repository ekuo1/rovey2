#ifndef ROS_INERTIAL_UNIT_HPP
#define ROS_INERTIAL_UNIT_HPP

#include <webots/InertialUnit.hpp>
#include "RosSensor.hpp"

using namespace webots;

class RosInertialUnit : public RosSensor
{
  public :
    RosInertialUnit(InertialUnit *inertialUnit, Ros *ros);
    virtual ~RosInertialUnit() { rosDisable(); }

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod){mInertialUnit->enable(samplingPeriod);}
    virtual void           rosDisable(){mInertialUnit->disable();}
    virtual int            rosSamplingPeriod() {return mInertialUnit->getSamplingPeriod();}

  private :
    InertialUnit *mInertialUnit;
};

#endif //ROS_INERTIAL_UNIT_HPP
