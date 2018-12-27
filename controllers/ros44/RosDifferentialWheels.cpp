#include "RosDifferentialWheels.hpp"
#include "webots_ros/Float64Stamped.h"

RosDifferentialWheels::RosDifferentialWheels(Ros *ros, DifferentialWheels *differentialWheels) : RosSensor("differential_wheels_encoders", NULL, ros) {
  mRos                       = ros;
  mSetEncodersServer         = mRos->nodeHandle()->advertiseService(ros->name()+"/differential_wheels/set_encoders", &RosDifferentialWheels::setEncodersCallback, this);
  mSetSpeedServer            = mRos->nodeHandle()->advertiseService(ros->name()+"/differential_wheels/set_speed", &RosDifferentialWheels::setSpeedCallback, this);
  mSubscribeTwistSpeedServer = mRos->nodeHandle()->advertiseService(ros->name()+"/differential_wheels/subscribe_twist_commands", &RosDifferentialWheels::subscribeTwistSpeedCallback, this);
  mGetMaxSpeedServer         = mRos->nodeHandle()->advertiseService(ros->name()+"/differential_wheels/get_max_speed", &RosDifferentialWheels::getMaxSpeedCallback, this);
  mGetSpeedServer            = mRos->nodeHandle()->advertiseService(ros->name()+"/differential_wheels/get_speed", &RosDifferentialWheels::getSpeedCallback, this);
  mGetSpeedUnitServer        = mRos->nodeHandle()->advertiseService(ros->name()+"/differential_wheels/get_speed_unit", &RosDifferentialWheels::getSpeedUnitCallback, this);
  mDifferentialWheels        = differentialWheels;
  mCommand[0]                = 0;
  mCommand[1]                = 0;
}

RosDifferentialWheels::~RosDifferentialWheels() {
  if (mSubscriber)
    mSubscriber.shutdown();
  mSetEncodersServer.shutdown();
  mSetSpeedServer.shutdown();
  mSubscribeTwistSpeedServer.shutdown();
  mGetMaxSpeedServer.shutdown();
  mGetSpeedServer.shutdown();
  mGetSpeedUnitServer.shutdown();
  rosDisable();
}

// creates or destroy the subscriber to receive wheels command from ros
bool RosDifferentialWheels::subscribeTwistSpeedCallback(webots_ros::differential_wheels_subscribe_twist_commands::Request &req, webots_ros::differential_wheels_subscribe_twist_commands::Response &res) {
  if (req.subscribe == 1) {
    mSubscriber = (mRos->nodeHandle())->subscribe(mRos->name()+"/differential_wheels/twist_commands", 10, &RosDifferentialWheels::topicCallback, this);
    if (mSubscriber) {
      res.success = 1;
    } else {
      ROS_ERROR("Attempt to subscribe to topic '%s/differential_wheels/twist_commands' failed.", mRos->name().c_str());
      res.success = 0;
    }
  } else if (req.subscribe == 0) {
    mSubscriber.shutdown();
    mCommand[0] = 0;
    mCommand[1] = 0;
    mDifferentialWheels->setSpeed(mCommand[0], mCommand[1]);
    res.success = 2;
  }
  return true;
}

bool RosDifferentialWheels::setSpeedCallback(webots_ros::set_float_array::Request &req, webots_ros::set_float_array::Response &res) {
  if (req.values.size() == 2) {
    mDifferentialWheels->setSpeed(req.values[0], req.values[1]);
    res.success = true;
  } else
    res.success = false;
  return true;
}

bool RosDifferentialWheels::setEncodersCallback(webots_ros::set_float_array::Request &req, webots_ros::set_float_array::Response &res) {
  if (req.values.size() == 2) {
    mDifferentialWheels->setEncoders(req.values[0], req.values[1]);
    res.success = true;
  } else
    res.success = false;
  return true;
}

bool RosDifferentialWheels::getMaxSpeedCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res) {
  res.value = mDifferentialWheels->getMaxSpeed();
  return true;
}

// send back speed for asked wheel : 0 = left, 1 = right
bool RosDifferentialWheels::getSpeedCallback(webots_ros::differential_wheels_get_speed::Request &req, webots_ros::differential_wheels_get_speed::Response &res) {
  if (req.side == 0)
    res.speed = mDifferentialWheels->getLeftSpeed();
  else if (req.side == 1)
    res.speed = mDifferentialWheels->getRightSpeed();
  return true;
}

bool RosDifferentialWheels::getSpeedUnitCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res) {
  res.value = mDifferentialWheels->getSpeedUnit();
  return true;
}

// translate linear and angular velocity received into left and right speed
// for the DifferentialWheels node and check if they aren't out of range
void RosDifferentialWheels::topicCallback(const geometry_msgs::Twist::ConstPtr& command) {
  if ((command->linear.x + command->angular.z) >= 1000)
    mCommand[0] = 1000;
  else if ((command->linear.x + command->angular.z) <= -1000)
    mCommand[0] = -1000;
  else
    mCommand[0] = (command->linear.x - command->angular.z);

  if ((command->linear.x - command->angular.z) >= 1000)
    mCommand[1] = 1000;
  else if ((command->linear.x - command->angular.z) <= -1000)
    mCommand[1] = -1000;
  else
    mCommand[1] = (command->linear.x + command->angular.z);

  mDifferentialWheels->setSpeed(mCommand[0], mCommand[1]);
}

// creates a publisher for encoders values with two float topics
// for right and left encoder
ros::Publisher RosDifferentialWheels::createPublisher() {
  webots_ros::Float64Stamped type;
  publisherDetails details;
  int period = mPublishList.back().mSamplingPeriod;
  details.mSamplingPeriod = period;
  details.mNewPublisher = true;
  details.mPublisher = RosDevice::rosAdvertiseTopic(mRos->name()+"/differential_wheels/lwheel", type);
  mPublishList.push_back(details);
  mPublishList.push_back(details);
  rosEnable(period);

  return RosDevice::rosAdvertiseTopic(mRos->name()+"/differential_wheels/rwheel", type);
}

// get value from the encoders and publish them
void RosDifferentialWheels::publishValue(ros::Publisher publisher) {
  webots_ros::Float64Stamped value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + "/differential_wheels";
  std::string topicName = publisher.getTopic();
  if (topicName.compare(topicName.size()-6, 6, "rwheel") == 0)
    value.data = mDifferentialWheels->getRightEncoder();
  else
    value.data = mDifferentialWheels->getLeftEncoder();
  publisher.publish(value);
}
