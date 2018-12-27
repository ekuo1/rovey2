#ifndef WEBOTS_ROS_MESSAGE_SKIN_SET_BONE_POSITION_H
#define WEBOTS_ROS_MESSAGE_SKIN_SET_BONE_POSITION_H

#include "ros/service_traits.h"


#include "skin_set_bone_positionRequest.h"
#include "skin_set_bone_positionResponse.h"


namespace webots_ros
{

struct skin_set_bone_position
{

typedef skin_set_bone_positionRequest Request;
typedef skin_set_bone_positionResponse Response;
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
struct MD5Sum< ::webots_ros::skin_set_bone_position > {
  static const char* value()
  {
    return "f009d6c1aead25b455139f2460ea63da";
  }

  static const char* value(const ::webots_ros::skin_set_bone_position&) { return value(); }
};

template<>
struct DataType< ::webots_ros::skin_set_bone_position > {
  static const char* value()
  {
    return "webots_ros/skin_set_bone_position";
  }

  static const char* value(const ::webots_ros::skin_set_bone_position&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::skin_set_bone_positionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::skin_set_bone_position >::value();
  }
  static const char* value(const ::webots_ros::skin_set_bone_positionRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::skin_set_bone_positionRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::skin_set_bone_position >::value();
  }
  static const char* value(const ::webots_ros::skin_set_bone_positionRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::skin_set_bone_positionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::skin_set_bone_position >::value();
  }
  static const char* value(const ::webots_ros::skin_set_bone_positionResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::skin_set_bone_positionResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::skin_set_bone_position >::value();
  }
  static const char* value(const ::webots_ros::skin_set_bone_positionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_SKIN_SET_BONE_POSITION_H
