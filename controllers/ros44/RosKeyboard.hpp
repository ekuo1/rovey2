#ifndef ROS_KEYBOARD_HPP
#define ROS_KEYBOARD_HPP

#include <webots/Keyboard.hpp>
#include "RosSensor.hpp"

using namespace webots;

class RosKeyboard : public RosSensor
{
  public :
    RosKeyboard(Keyboard *keyboard, Ros *ros);
    virtual ~RosKeyboard() { rosDisable(); }

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod) {mKeyboard->enable(samplingPeriod);}
    virtual void           rosDisable() {mKeyboard->disable();}
    virtual int            rosSamplingPeriod() {return mKeyboard->getSamplingPeriod();}

  private :
    Keyboard *mKeyboard;
};

#endif //ROS_KEYBOARD_HPP
