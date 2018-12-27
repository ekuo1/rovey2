#ifndef WEBOTS_ROS_MESSAGE_DISPLAY_DRAW_OVAL_H
#define WEBOTS_ROS_MESSAGE_DISPLAY_DRAW_OVAL_H

#include "ros/service_traits.h"


#include "display_draw_ovalRequest.h"
#include "display_draw_ovalResponse.h"


namespace webots_ros
{

struct display_draw_oval
{

typedef display_draw_ovalRequest Request;
typedef display_draw_ovalResponse Response;
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
struct MD5Sum< ::webots_ros::display_draw_oval > {
  static const char* value()
  {
    return "257804d9f2e4639bae589e190802d29f";
  }

  static const char* value(const ::webots_ros::display_draw_oval&) { return value(); }
};

template<>
struct DataType< ::webots_ros::display_draw_oval > {
  static const char* value()
  {
    return "webots_ros/display_draw_oval";
  }

  static const char* value(const ::webots_ros::display_draw_oval&) { return value(); }
};


template<>
struct MD5Sum< ::webots_ros::display_draw_ovalRequest>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::display_draw_oval >::value();
  }
  static const char* value(const ::webots_ros::display_draw_ovalRequest&)
  {
    return value();
  }
};


template<>
struct DataType< ::webots_ros::display_draw_ovalRequest>
{
  static const char* value()
  {
    return DataType< ::webots_ros::display_draw_oval >::value();
  }
  static const char* value(const ::webots_ros::display_draw_ovalRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::webots_ros::display_draw_ovalResponse>
{
  static const char* value()
  {
    return MD5Sum< ::webots_ros::display_draw_oval >::value();
  }
  static const char* value(const ::webots_ros::display_draw_ovalResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::webots_ros::display_draw_ovalResponse>
{
  static const char* value()
  {
    return DataType< ::webots_ros::display_draw_oval >::value();
  }
  static const char* value(const ::webots_ros::display_draw_ovalResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_DISPLAY_DRAW_OVAL_H
