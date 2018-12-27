#ifndef ROS_PEN_HPP
#define ROS_PEN_HPP

#include <webots/Pen.hpp>
#include "RosDevice.hpp"

#include <webots_ros/set_bool.h>

#include <webots_ros/pen_set_ink_color.h>

using namespace webots;

class RosPen : public RosDevice
{
  public :
    RosPen(Pen *pen, Ros *ros);
    virtual ~RosPen();

    bool writeCallback(webots_ros::set_bool::Request &req, webots_ros::set_bool::Response &res);
    bool setInkColorCallback(webots_ros::pen_set_ink_color::Request &req, webots_ros::pen_set_ink_color::Response &res);

  private :
    Pen               *mPen;
    ros::ServiceServer mWriteServer;
    ros::ServiceServer mSetInkColorServer;
};

#endif //ROS_PEN_HPP
