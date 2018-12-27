#ifndef ROS_CONNECTOR_HPP
#define ROS_CONNECTOR_HPP

#include <webots/Connector.hpp>
#include "RosSensor.hpp"

#include <webots_ros/set_bool.h>

using namespace webots;

class RosConnector : public RosSensor
{
  public :
    RosConnector(Connector *connector, Ros *ros);
    virtual ~RosConnector();

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           rosEnable(int samplingPeriod) { mConnector->enablePresence(samplingPeriod); }
    virtual void           rosDisable() { mConnector->disablePresence(); }
    virtual int            rosSamplingPeriod() { return mConnector->getPresenceSamplingPeriod(); }

    bool lockCallback(webots_ros::set_bool::Request &req, webots_ros::set_bool::Response &res);

  private :
    Connector         *mConnector;
    ros::ServiceServer mLockServer;
};

#endif //ROS_CONNECTOR_HPP
