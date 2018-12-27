#ifndef ROS_SPEAKER_HPP
#define ROS_SPEAKER_HPP

#include <webots/Speaker.hpp>
#include "RosDevice.hpp"

#include <webots_ros/get_string.h>
#include <webots_ros/set_string.h>

#include <webots_ros/speaker_speak.h>
#include <webots_ros/speaker_play_sound.h>

using namespace webots;

class RosSpeaker : public RosDevice
{
  public :
    RosSpeaker(Speaker *speaker, Ros *ros);
    virtual ~RosSpeaker();

    bool stopCallback(webots_ros::set_string::Request &req, webots_ros::set_string::Response &res);
    bool getEngineCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool getLanguageCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool setEngineCallback(webots_ros::set_string::Request &req, webots_ros::set_string::Response &res);
    bool setLanguageCallback(webots_ros::set_string::Request &req, webots_ros::set_string::Response &res);
    bool speakCallback(webots_ros::speaker_speak::Request &req, webots_ros::speaker_speak::Response &res);
    bool playCallback(webots_ros::speaker_play_sound::Request &req, webots_ros::speaker_play_sound::Response &res);


  private :
    Speaker           *mSpeaker;
    ros::ServiceServer mStopServer;
    ros::ServiceServer mGetEngineServer;
    ros::ServiceServer mGetLanguageServer;
    ros::ServiceServer mSetEngineServer;
    ros::ServiceServer mSetLanguageServer;
    ros::ServiceServer mSpeakServer;
    ros::ServiceServer mPlayServer;
};

#endif //ROS_SPEAKER_HPP
