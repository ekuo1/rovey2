#ifndef WEBOTS_ROS_MESSAGE_FIELD_SET_BOOL_H
#define WEBOTS_ROS_MESSAGE_FIELD_SET_BOOL_H

#include "ros/service_traits.h"


#include "field_set_boolRequest.h"
#include "field_set_boolResponse.h"


namespace webots_ros
{

struct field_set_bool
{

typedef field_set_boolRequest Request;
typedef field_set_boolResponse Response;
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
struct MD5Sum< ::webots_ros::field_set_bool > {
  static const char* value()
  {
    return "7a9b164ddc41cfd8469ce0cd504f469e";
  }

  static const char* value(const ::webots_ros::field_set_bool&) { return value(); }
};

template<>
struct DataType< ::webots_ros::field_set_bool > {
  static const char* value()
  {
    return "webots_ros/field_set_bool";
  }

  static const char* value(const ::webots_ros::field_set_bool&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::field_set_boolRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::field_set_bool >::value();
  }
  static const char* value(const ::webots_ros::field_set_boolRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::field_set_boolRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::field_set_bool >::value();
  }
  static const char* value(const ::webots_ros::field_set_boolRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::field_set_boolResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::field_set_bool >::value();
  }
  static const char* value(const ::webots_ros::field_set_boolResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::field_set_boolResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::field_set_bool >::value();
  }
  static const char* value(const ::webots_ros::field_set_boolResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_FIELD_SET_BOOL_H
