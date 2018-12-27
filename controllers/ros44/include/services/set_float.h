#ifndef WEBOTS_ROS_MESSAGE_SET_FLOAT_H
#define WEBOTS_ROS_MESSAGE_SET_FLOAT_H

#include "ros/service_traits.h"


#include "set_floatRequest.h"
#include "set_floatResponse.h"


namespace webots_ros
{

struct set_float
{

typedef set_floatRequest Request;
typedef set_floatResponse Response;
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
struct MD5Sum< ::webots_ros::set_float > {
  static const char* value()
  {
    return "0f0509b4253b73657cb37e93f4f2960c";
  }

  static const char* value(const ::webots_ros::set_float&) { return value(); }
};

template<>
struct DataType< ::webots_ros::set_float > {
  static const char* value()
  {
    return "webots_ros/set_float";
  }

  static const char* value(const ::webots_ros::set_float&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::set_floatRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::set_float >::value();
  }
  static const char* value(const ::webots_ros::set_floatRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::set_floatRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::set_float >::value();
  }
  static const char* value(const ::webots_ros::set_floatRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::set_floatResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::set_float >::value();
  }
  static const char* value(const ::webots_ros::set_floatResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::set_floatResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::set_float >::value();
  }
  static const char* value(const ::webots_ros::set_floatResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_SET_FLOAT_H
