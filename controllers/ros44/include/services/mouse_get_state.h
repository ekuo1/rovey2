#ifndef WEBOTS_ROS_MESSAGE_MOUSE_GET_STATE_H
#define WEBOTS_ROS_MESSAGE_MOUSE_GET_STATE_H

#include "ros/service_traits.h"


#include "mouse_get_stateRequest.h"
#include "mouse_get_stateResponse.h"


namespace webots_ros
{

struct mouse_get_state
{

typedef mouse_get_stateRequest Request;
typedef mouse_get_stateResponse Response;
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
struct MD5Sum< ::webots_ros::mouse_get_state > {
  static const char* value()
  {
    return "f4314fc92ab9c1f74ef71e42c0634a99";
  }

  static const char* value(const ::webots_ros::mouse_get_state&) { return value(); }
};

template<>
struct DataType< ::webots_ros::mouse_get_state > {
  static const char* value()
  {
    return "webots_ros/mouse_get_state";
  }

  static const char* value(const ::webots_ros::mouse_get_state&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::mouse_get_stateRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::mouse_get_state >::value();
  }
  static const char* value(const ::webots_ros::mouse_get_stateRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::mouse_get_stateRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::mouse_get_state >::value();
  }
  static const char* value(const ::webots_ros::mouse_get_stateRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::mouse_get_stateResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::mouse_get_state >::value();
  }
  static const char* value(const ::webots_ros::mouse_get_stateResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::mouse_get_stateResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::mouse_get_state >::value();
  }
  static const char* value(const ::webots_ros::mouse_get_stateResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_MOUSE_GET_STATE_H
