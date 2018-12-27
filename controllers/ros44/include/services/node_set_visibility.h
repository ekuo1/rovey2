#ifndef WEBOTS_ROS_MESSAGE_NODE_SET_VISIBILITY_H
#define WEBOTS_ROS_MESSAGE_NODE_SET_VISIBILITY_H

#include "ros/service_traits.h"


#include "node_set_visibilityRequest.h"
#include "node_set_visibilityResponse.h"


namespace webots_ros
{

struct node_set_visibility
{

typedef node_set_visibilityRequest Request;
typedef node_set_visibilityResponse Response;
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
struct MD5Sum< ::webots_ros::node_set_visibility > {
  static const char* value()
  {
    return "b6fcfa2c79ae79467e085318b3617289";
  }

  static const char* value(const ::webots_ros::node_set_visibility&) { return value(); }
};

template<>
struct DataType< ::webots_ros::node_set_visibility > {
  static const char* value()
  {
    return "webots_ros/node_set_visibility";
  }

  static const char* value(const ::webots_ros::node_set_visibility&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::node_set_visibilityRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::node_set_visibility >::value();
  }
  static const char* value(const ::webots_ros::node_set_visibilityRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::node_set_visibilityRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::node_set_visibility >::value();
  }
  static const char* value(const ::webots_ros::node_set_visibilityRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::node_set_visibilityResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::node_set_visibility >::value();
  }
  static const char* value(const ::webots_ros::node_set_visibilityResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::node_set_visibilityResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::node_set_visibility >::value();
  }
  static const char* value(const ::webots_ros::node_set_visibilityResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_NODE_SET_VISIBILITY_H
