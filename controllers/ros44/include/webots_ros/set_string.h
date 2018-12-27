#ifndef WEBOTS_ROS_MESSAGE_SET_STRING_H
#define WEBOTS_ROS_MESSAGE_SET_STRING_H

#include "ros/service_traits.h"


#include "set_stringRequest.h"
#include "set_stringResponse.h"


namespace webots_ros
{

struct set_string
{

typedef set_stringRequest Request;
typedef set_stringResponse Response;
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
struct MD5Sum< ::webots_ros::set_string > {
  static const char* value()
  {
    return "0462bc0e878964615c49ad8ef45df667";
  }

  static const char* value(const ::webots_ros::set_string&) { return value(); }
};

template<>
struct DataType< ::webots_ros::set_string > {
  static const char* value()
  {
    return "webots_ros/set_string";
  }

  static const char* value(const ::webots_ros::set_string&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::set_stringRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::set_string >::value();
  }
  static const char* value(const ::webots_ros::set_stringRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::set_stringRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::set_string >::value();
  }
  static const char* value(const ::webots_ros::set_stringRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::set_stringResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::set_string >::value();
  }
  static const char* value(const ::webots_ros::set_stringResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::set_stringResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::set_string >::value();
  }
  static const char* value(const ::webots_ros::set_stringResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_SET_STRING_H
