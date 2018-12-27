#ifndef ROS_EMITTER_HPP
#define ROS_EMITTER_HPP

#include <webots/Emitter.hpp>
#include "RosDevice.hpp"

#include <webots_ros/get_float.h>
#include <webots_ros/get_int.h>
#include <webots_ros/set_float.h>
#include <webots_ros/set_int.h>
#include <webots_ros/set_string.h>

using namespace webots;

class RosEmitter : public RosDevice
{
  public :
    RosEmitter(Emitter *emitter, Ros *ros);
    virtual ~RosEmitter();

    bool sendCallback(webots_ros::set_string::Request &req, webots_ros::set_string::Response &res);
    bool getBufferSizeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool getChannelCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool getRangeCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    bool setChannelCallback(webots_ros::set_int::Request &req, webots_ros::set_int::Response &res);
    bool setRangeCallback(webots_ros::set_float::Request &req, webots_ros::set_float::Response &res);

  private :
    Emitter           *mEmitter;
    ros::ServiceServer mSendServer;
    ros::ServiceServer mGetBufferSizeServer;
    ros::ServiceServer mGetChannelServer;
    ros::ServiceServer mGetRangeServer;
    ros::ServiceServer mSetChannelServer;
    ros::ServiceServer mSetRangeServer;
    ros::Publisher     mPublisher;
};

#endif //ROS_EMITTER_HPP
