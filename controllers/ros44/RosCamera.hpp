#ifndef ROS_CAMERA_HPP
#define ROS_CAMERA_HPP

#include <webots/Camera.hpp>
#include "RosSensor.hpp"

#include <webots_ros/get_bool.h>
#include <webots_ros/set_float.h>

#include <webots_ros/camera_get_info.h>
#include <webots_ros/camera_get_focus_info.h>
#include <webots_ros/camera_get_zoom_info.h>
#include <webots_ros/save_image.h>

using namespace webots;

class RosCamera : public RosSensor
{
  public :
    RosCamera(Camera *camera, Ros *ros);
    virtual ~RosCamera();

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    bool                   getInfoCallback(webots_ros::camera_get_info::Request &req, webots_ros::camera_get_info::Response &res);
    bool                   getFocusInfoCallback(webots_ros::camera_get_focus_info::Request &req, webots_ros::camera_get_focus_info::Response &res);
    bool                   getZoomInfoCallback(webots_ros::camera_get_zoom_info::Request &req, webots_ros::camera_get_zoom_info::Response &res);
    bool                   saveImageCallback(webots_ros::save_image::Request &req, webots_ros::save_image::Response &res);
    bool                   setFovCallback(webots_ros::set_float::Request &req, webots_ros::set_float::Response &res);
    bool                   setFocalDistanceCallback(webots_ros::set_float::Request &req, webots_ros::set_float::Response &res);
    bool                   recognitionEnableCallback(webots_ros::set_int::Request &req, webots_ros::set_int::Response &res);
    bool                   recognitionSamplingPeriodCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool                   hasRecognitionCallback(webots_ros::get_bool::Request &req, webots_ros::get_bool::Response &res);

    virtual void           rosEnable(int samplingPeriod) {mCamera->enable(samplingPeriod);}
    virtual void           rosDisable()                  {mCamera->disable();}
    virtual int            rosSamplingPeriod()           {return mCamera->getSamplingPeriod();}

  private :
    Camera            *mCamera;
    ros::Publisher     mRecognitionObjectsPublisher;
    std::string        mColorTopic;
    ros::ServiceServer mInfoServer;
    ros::ServiceServer mFocusInfoServer;
    ros::ServiceServer mZoomInfoServer;
    ros::ServiceServer mImageServer;
    ros::ServiceServer mSetFovServer;
    ros::ServiceServer mSetFocalDistanceServer;
    ros::ServiceServer mRecognitionEnableServer;
    ros::ServiceServer mRecognitionSamplingPeriodServer;
    ros::ServiceServer mHasRecognitionServer;
};

#endif //ROS_CAMERA_HPP
