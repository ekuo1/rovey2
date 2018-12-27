#ifndef ROS_LIDAR_HPP
#define ROS_LIDAR_HPP

#include <webots/Lidar.hpp>
#include "RosSensor.hpp"

#include <webots_ros/set_bool.h>
#include <webots_ros/set_float.h>

#include <webots_ros/lidar_get_frequency_info.h>
#include <webots_ros/lidar_get_info.h>
#include <webots_ros/lidar_get_layer_range_image.h>
#include <webots_ros/lidar_get_layer_point_cloud.h>
#include <webots_ros/node_get_status.h>

using namespace webots;

class RosLidar : public RosSensor
{
  public :
    RosLidar(Lidar *lidar, Ros *ros);
    virtual ~RosLidar();

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    virtual void           publishAuxiliaryValue();
    bool                   enablePointCloudCallback(webots_ros::set_bool::Request &req, webots_ros::set_bool::Response &res);
    bool                   getFrequencyInfoCallback(webots_ros::lidar_get_frequency_info::Request &req, webots_ros::lidar_get_frequency_info::Response &res);
    bool                   getInfoCallback(webots_ros::lidar_get_info::Request &req, webots_ros::lidar_get_info::Response &res);
    bool                   isPointCloudEnabledCallback(webots_ros::node_get_status::Request &req, webots_ros::node_get_status::Response &res);
    bool                   setFrequencyCallback(webots_ros::set_float::Request &req, webots_ros::set_float::Response &res);
    bool                   getLayerRangeImage(webots_ros::lidar_get_layer_range_image::Request &req, webots_ros::lidar_get_layer_range_image::Response &res);
    bool                   getLayerPointCloud(webots_ros::lidar_get_layer_point_cloud::Request &req, webots_ros::lidar_get_layer_point_cloud::Response &res);

    virtual void           rosEnable(int samplingPeriod) { mLidar->enable(samplingPeriod); }
    virtual void           rosDisable()                  { mLidar->disable(); }
    virtual int            rosSamplingPeriod()           { return mLidar->getSamplingPeriod(); }

  private :
    void               publishPointCloud();
    void               publishLaserScan(int layer);

    Lidar             *mLidar;
    bool               mIsPointCloudEnabled;
    ros::Publisher     mPointCloudPublisher;
    ros::Publisher    *mLaserScanPublisher;

    ros::ServiceServer mEnablePointCloudServer;
    ros::ServiceServer mGetFrequencyInfoServer;
    ros::ServiceServer mGetInfoServer;
    ros::ServiceServer mIsPointCloudEnabledServer;
    ros::ServiceServer mSetFrequencyServer;
    ros::ServiceServer mGetLayerRangeImage;
    ros::ServiceServer mGetLayerPointCloud;
};

#endif //ROS_LIDAR_HPP
