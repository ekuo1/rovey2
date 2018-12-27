#ifndef WEBOTS_ROS_MESSAGE_FIELD_IMPORT_NODE_FROM_STRING_H
#define WEBOTS_ROS_MESSAGE_FIELD_IMPORT_NODE_FROM_STRING_H

#include "ros/service_traits.h"


#include "field_import_node_from_stringRequest.h"
#include "field_import_node_from_stringResponse.h"


namespace webots_ros
{

struct field_import_node_from_string
{

typedef field_import_node_from_stringRequest Request;
typedef field_import_node_from_stringResponse Response;
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
struct MD5Sum< ::webots_ros::field_import_node_from_string > {
  static const char* value()
  {
    return "f47a09684279b85c2c8ae161048ce7d0";
  }

  static const char* value(const ::webots_ros::field_import_node_from_string&) { return value(); }
};

template<>
struct DataType< ::webots_ros::field_import_node_from_string > {
  static const char* value()
  {
    return "webots_ros/field_import_node_from_string";
  }

  static const char* value(const ::webots_ros::field_import_node_from_string&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::field_import_node_from_stringRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::field_import_node_from_string >::value();
  }
  static const char* value(const ::webots_ros::field_import_node_from_stringRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::field_import_node_from_stringRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::field_import_node_from_string >::value();
  }
  static const char* value(const ::webots_ros::field_import_node_from_stringRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::field_import_node_from_stringResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::field_import_node_from_string >::value();
  }
  static const char* value(const ::webots_ros::field_import_node_from_stringResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::field_import_node_from_stringResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::field_import_node_from_string >::value();
  }
  static const char* value(const ::webots_ros::field_import_node_from_stringResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_FIELD_IMPORT_NODE_FROM_STRING_H
