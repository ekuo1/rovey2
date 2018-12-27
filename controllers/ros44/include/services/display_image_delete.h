#ifndef WEBOTS_ROS_MESSAGE_DISPLAY_IMAGE_DELETE_H
#define WEBOTS_ROS_MESSAGE_DISPLAY_IMAGE_DELETE_H

#include "ros/service_traits.h"


#include "display_image_deleteRequest.h"
#include "display_image_deleteResponse.h"


namespace webots_ros
{

struct display_image_delete
{

typedef display_image_deleteRequest Request;
typedef display_image_deleteResponse Response;
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
struct MD5Sum< ::webots_ros::display_image_delete > {
  static const char* value()
  {
    return "21daf18e23f8cc4ce4452efc995e69da";
  }

  static const char* value(const ::webots_ros::display_image_delete&) { return value(); }
};

template<>
struct DataType< ::webots_ros::display_image_delete > {
  static const char* value()
  {
    return "webots_ros/display_image_delete";
  }

  static const char* value(const ::webots_ros::display_image_delete&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::display_image_deleteRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::display_image_delete >::value();
  }
  static const char* value(const ::webots_ros::display_image_deleteRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::display_image_deleteRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::display_image_delete >::value();
  }
  static const char* value(const ::webots_ros::display_image_deleteRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::display_image_deleteResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::display_image_delete >::value();
  }
  static const char* value(const ::webots_ros::display_image_deleteResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::display_image_deleteResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::display_image_delete >::value();
  }
  static const char* value(const ::webots_ros::display_image_deleteResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_DISPLAY_IMAGE_DELETE_H
