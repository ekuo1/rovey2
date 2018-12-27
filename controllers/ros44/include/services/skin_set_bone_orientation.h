#ifndef WEBOTS_ROS_MESSAGE_SKIN_SET_BONE_ORIENTATION_H
#define WEBOTS_ROS_MESSAGE_SKIN_SET_BONE_ORIENTATION_H

#include "ros/service_traits.h"


#include "skin_set_bone_orientationRequest.h"
#include "skin_set_bone_orientationResponse.h"


namespace webots_ros
{

struct skin_set_bone_orientation
{

typedef skin_set_bone_orientationRequest Request;
typedef skin_set_bone_orientationResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

};
} // namespace webots_ros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::webots_ros::skin_set_bone_orientation > {
  static const char* value()
  {
    return "3902caf1e5bc44580e05f53048f6318b";
  }

  static const char* value(const ::webots_ros::skin_set_bone_orientation&) { return value(); }
};

template<>
struct DataType< ::webots_ros::skin_set_bone_orientation > {
  static const char* value()
  {
    return "webots_ros/skin_set_bone_orientation";
  }

  static const char* value(const ::webots_ros::skin_set_bone_orientation&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::skin_set_bone_orientationRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::skin_set_bone_orientation >::value();
  }
  static const char* value(const ::webots_ros::skin_set_bone_orientationRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::skin_set_bone_orientationRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::skin_set_bone_orientation >::value();
  }
  static const char* value(const ::webots_ros::skin_set_bone_orientationRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::skin_set_bone_orientationResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::skin_set_bone_orientation >::value();
  }
  static const char* value(const ::webots_ros::skin_set_bone_orientationResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::skin_set_bone_orientationResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::skin_set_bone_orientation >::value();
  }
  static const char* value(const ::webots_ros::skin_set_bone_orientationResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_SKIN_SET_BONE_ORIENTATION_H
