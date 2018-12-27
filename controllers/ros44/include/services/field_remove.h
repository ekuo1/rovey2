#ifndef WEBOTS_ROS_MESSAGE_FIELD_REMOVE_H
#define WEBOTS_ROS_MESSAGE_FIELD_REMOVE_H

#include "ros/service_traits.h"


#include "field_removeRequest.h"
#include "field_removeResponse.h"


namespace webots_ros
{

struct field_remove
{

typedef field_removeRequest Request;
typedef field_removeResponse Response;
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
struct MD5Sum< ::webots_ros::field_remove > {
  static const char* value()
  {
    return "722e922dddeea014e5ea68aa3843aeba";
  }

  static const char* value(const ::webots_ros::field_remove&) { return value(); }
};

template<>
struct DataType< ::webots_ros::field_remove > {
  static const char* value()
  {
    return "webots_ros/field_remove";
  }

  static const char* value(const ::webots_ros::field_remove&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::field_removeRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::field_remove >::value();
  }
  static const char* value(const ::webots_ros::field_removeRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::field_removeRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::field_remove >::value();
  }
  static const char* value(const ::webots_ros::field_removeRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::field_removeResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::field_remove >::value();
  }
  static const char* value(const ::webots_ros::field_removeResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::field_removeResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::field_remove >::value();
  }
  static const char* value(const ::webots_ros::field_removeResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_FIELD_REMOVE_H
