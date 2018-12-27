#ifndef WEBOTS_ROS_MESSAGE_FIELD_GET_STRING_H
#define WEBOTS_ROS_MESSAGE_FIELD_GET_STRING_H

#include "ros/service_traits.h"


#include "field_get_stringRequest.h"
#include "field_get_stringResponse.h"


namespace webots_ros
{

struct field_get_string
{

typedef field_get_stringRequest Request;
typedef field_get_stringResponse Response;
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
struct MD5Sum< ::webots_ros::field_get_string > {
  static const char* value()
  {
    return "a1926692206ecc55a7a2d2564a578c89";
  }

  static const char* value(const ::webots_ros::field_get_string&) { return value(); }
};

template<>
struct DataType< ::webots_ros::field_get_string > {
  static const char* value()
  {
    return "webots_ros/field_get_string";
  }

  static const char* value(const ::webots_ros::field_get_string&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::field_get_stringRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::field_get_string >::value();
  }
  static const char* value(const ::webots_ros::field_get_stringRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::field_get_stringRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::field_get_string >::value();
  }
  static const char* value(const ::webots_ros::field_get_stringRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::field_get_stringResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::field_get_string >::value();
  }
  static const char* value(const ::webots_ros::field_get_stringResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::field_get_stringResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::field_get_string >::value();
  }
  static const char* value(const ::webots_ros::field_get_stringResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_FIELD_GET_STRING_H
