#ifndef ROS_SKIN_HPP
#define ROS_SKIN_HPP

#include <webots/Skin.hpp>
#include "RosDevice.hpp"

#include "webots_ros/get_int.h"

#include "webots_ros/skin_get_bone_name.h"
#include "webots_ros/skin_get_bone_orientation.h"
#include "webots_ros/skin_get_bone_position.h"
#include "webots_ros/skin_set_bone_orientation.h"
#include "webots_ros/skin_set_bone_position.h"

using namespace webots;

class RosSkin : public RosDevice
{
  public :
    RosSkin(Skin *skin, Ros *ros);
    virtual ~RosSkin() {};

    bool setBoneOrientationCallback(webots_ros::skin_set_bone_orientation::Request &req, webots_ros::skin_set_bone_orientation::Response &res);
    bool setBonePositionCallback(webots_ros::skin_set_bone_position::Request &req, webots_ros::skin_set_bone_position::Response &res);
    bool getBoneNameCallback(webots_ros::skin_get_bone_name::Request &req, webots_ros::skin_get_bone_name::Response &res);
    bool getBoneCountCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool getBoneOrientationCallback(webots_ros::skin_get_bone_orientation::Request &req, webots_ros::skin_get_bone_orientation::Response &res);
    bool getBonePositionCallback(webots_ros::skin_get_bone_position::Request &req, webots_ros::skin_get_bone_position::Response &res);

  private :
    Skin              *mSkin;
    ros::ServiceServer mSetBoneOrientationServer;
    ros::ServiceServer mSetBonePositionServer;
    ros::ServiceServer mGetBoneNameServer;
    ros::ServiceServer mGetBoneCountServer;
    ros::ServiceServer mGetBoneOrientationServer;
    ros::ServiceServer mGetBonePositionServer;
    ros::Publisher     mPublisher;
};

#endif // ROS_SKIN_HPP
