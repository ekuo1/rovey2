#ifndef WEBOTS_ROS_MESSAGE_SUPERVISOR_VIRTUAL_REALITY_HEADSET_GET_POSITION_H
#define WEBOTS_ROS_MESSAGE_SUPERVISOR_VIRTUAL_REALITY_HEADSET_GET_POSITION_H

#include "ros/service_traits.h"


#include "supervisor_virtual_reality_headset_get_positionRequest.h"
#include "supervisor_virtual_reality_headset_get_positionResponse.h"


namespace webots_ros
{

struct supervisor_virtual_reality_headset_get_position
{

typedef supervisor_virtual_reality_headset_get_positionRequest Request;
typedef supervisor_virtual_reality_headset_get_positionResponse Response;
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
struct MD5Sum< ::webots_ros::supervisor_virtual_reality_headset_get_position > {
  static const char* value()
  {
    return "a1afe95e0bfbfc2663c9e2313392f01d";
  }

  static const char* value(const ::webots_ros::supervisor_virtual_reality_headset_get_position&) { return value(); }
};

template<>
struct DataType< ::webots_ros::supervisor_virtual_reality_headset_get_position > {
  static const char* value()
  {
    return "webots_ros/supervisor_virtual_reality_headset_get_position";
  }

  static const char* value(const ::webots_ros::supervisor_virtual_reality_headset_get_position&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::supervisor_virtual_reality_headset_get_positionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::supervisor_virtual_reality_headset_get_position >::value();
  }
  static const char* value(const ::webots_ros::supervisor_virtual_reality_headset_get_positionRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::supervisor_virtual_reality_headset_get_positionRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::supervisor_virtual_reality_headset_get_position >::value();
  }
  static const char* value(const ::webots_ros::supervisor_virtual_reality_headset_get_positionRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::supervisor_virtual_reality_headset_get_positionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::supervisor_virtual_reality_headset_get_position >::value();
  }
  static const char* value(const ::webots_ros::supervisor_virtual_reality_headset_get_positionResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::supervisor_virtual_reality_headset_get_positionResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::supervisor_virtual_reality_headset_get_position >::value();
  }
  static const char* value(const ::webots_ros::supervisor_virtual_reality_headset_get_positionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_SUPERVISOR_VIRTUAL_REALITY_HEADSET_GET_POSITION_H
