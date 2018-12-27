#ifndef ROS_RANGE_FINDER_HPP
#define ROS_RANGE_FINDER_HPP

#include <webots/RangeFinder.hpp>
#include "RosSensor.hpp"
#include <webots_ros/range_finder_get_info.h>
#include <webots_ros/save_image.h>

using namespace webots;

class RosRangeFinder : public RosSensor
{
  public :
    RosRangeFinder(RangeFinder *range_finder, Ros *ros);
    virtual ~RosRangeFinder();

    virtual ros::Publisher createPublisher();
    virtual void           publishValue(ros::Publisher publisher);
    bool                   getInfoCallback(webots_ros::range_finder_get_info::Request &req, webots_ros::range_finder_get_info::Response &res);
    bool                   saveImageCallback(webots_ros::save_image::Request &req, webots_ros::save_image::Response &res);

    virtual void           rosEnable(int samplingPeriod) {mRangeFinder->enable(samplingPeriod);}
    virtual void           rosDisable()                  {mRangeFinder->disable();}
    virtual int            rosSamplingPeriod()           {return mRangeFinder->getSamplingPeriod();}

  private :
    RangeFinder       *mRangeFinder;
    std::string        mRangeTopic;
    ros::ServiceServer mInfoServer;
    ros::ServiceServer mImageServer;
};

#endif //ROS_RANGE_FINDER_HPP
