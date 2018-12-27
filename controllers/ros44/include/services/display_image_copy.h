#ifndef WEBOTS_ROS_MESSAGE_DISPLAY_IMAGE_COPY_H
#define WEBOTS_ROS_MESSAGE_DISPLAY_IMAGE_COPY_H

#include "ros/service_traits.h"


#include "display_image_copyRequest.h"
#include "display_image_copyResponse.h"


namespace webots_ros
{

struct display_image_copy
{

typedef display_image_copyRequest Request;
typedef display_image_copyResponse Response;
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
struct MD5Sum< ::webots_ros::display_image_copy > {
  static const char* value()
  {
    return "631fd4626b960a90b6a634bededf2cea";
  }

  static const char* value(const ::webots_ros::display_image_copy&) { return value(); }
};

template<>
struct DataType< ::webots_ros::display_image_copy > {
  static const char* value()
  {
    return "webots_ros/display_image_copy";
  }

  static const char* value(const ::webots_ros::display_image_copy&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::display_image_copyRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::display_image_copy >::value();
  }
  static const char* value(const ::webots_ros::display_image_copyRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::display_image_copyRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::display_image_copy >::value();
  }
  static const char* value(const ::webots_ros::display_image_copyRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::display_image_copyResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::display_image_copy >::value();
  }
  static const char* value(const ::webots_ros::display_image_copyResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::display_image_copyResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::display_image_copy >::value();
  }
  static const char* value(const ::webots_ros::display_image_copyResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_DISPLAY_IMAGE_COPY_H
