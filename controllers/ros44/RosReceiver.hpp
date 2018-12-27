#ifndef ROS_RECEIVER_HPP
#define ROS_RECEIVER_HPP

#include <webots/Receiver.hpp>
#include "RosSensor.hpp"

#include <webots_ros/get_float.h>
#include <webots_ros/get_int.h>
#include <webots_ros/set_bool.h>
#include <webots_ros/set_int.h>

#include <webots_ros/receiver_get_emitter_direction.h>

using namespace webots;

class RosReceiver : public RosSensor
{
  public :
    RosReceiver(Receiver *receiver, Ros *ros);
    virtual ~RosReceiver();

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    bool                   setChannelCallback(webots_ros::set_int::Request &req, webots_ros::set_int::Response &res);
    bool                   getChannelCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool                   getQueueLengthCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool                   getDataSizeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool                   getSignalStrengthCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    bool                   getEmitterDirectionCallback(webots_ros::receiver_get_emitter_direction::Request &req, webots_ros::receiver_get_emitter_direction::Response &res);
    bool                   nextPacketCallback(webots_ros::get_bool::Request &req, webots_ros::get_bool::Response &res);

    virtual void           rosEnable(int samplingPeriod){mReceiver->enable(samplingPeriod);}
    virtual void           rosDisable(){mReceiver->disable();}
    virtual int            rosSamplingPeriod(){return mReceiver->getSamplingPeriod();}

  private :
    Receiver          *mReceiver;
    ros::ServiceServer mSetServer;
    ros::ServiceServer mSamplingPeriodServer;
    ros::ServiceServer mSetChannelServer;
    ros::ServiceServer mGetChannelServer;
    ros::ServiceServer mGetQueueLengthServer;
    ros::ServiceServer mGetDataSizeServer;
    ros::ServiceServer mGetSignalStrengthServer;
    ros::ServiceServer mGetEmitterDirectionServer;
    ros::ServiceServer mNextPacketServer;
};

#endif //ROS_RECEIVER_HPP
