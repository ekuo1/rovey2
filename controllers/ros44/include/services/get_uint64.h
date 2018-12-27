#ifndef WEBOTS_ROS_MESSAGE_GET_UINT64_H
#define WEBOTS_ROS_MESSAGE_GET_UINT64_H

#include "ros/service_traits.h"


#include "get_uint64Request.h"
#include "get_uint64Response.h"


namespace webots_ros
{

struct get_uint64
{

typedef get_uint64Request Request;
typedef get_uint64Response Response;
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
struct MD5Sum< ::webots_ros::get_uint64 > {
  static const char* value()
  {
    return "d531f9d37648dc4de8bf2e757ee280a0";
  }

  static const char* value(const ::webots_ros::get_uint64&) { return value(); }
};

template<>
struct DataType< ::webots_ros::get_uint64 > {
  static const char* value()
  {
    return "webots_ros/get_uint64";
  }

  static const char* value(const ::webots_ros::get_uint64&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::get_uint64Request>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::get_uint64 >::value();
  }
  static const char* value(const ::webots_ros::get_uint64Request&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::get_uint64Request>
{
  static const char* value()
  {
    return DataType< ::webots_ros::get_uint64 >::value();
  }
  static const char* value(const ::webots_ros::get_uint64Request&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::get_uint64Response>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::get_uint64 >::value();
  }
  static const char* value(const ::webots_ros::get_uint64Response&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::get_uint64Response>
{
  static const char* value()
  {
    return DataType< ::webots_ros::get_uint64 >::value();
  }
  static const char* value(const ::webots_ros::get_uint64Response&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_GET_UINT64_H
