#include "RosSkin.hpp"

#include "RosMathUtils.hpp"

RosSkin::RosSkin(Skin *skin, Ros *ros) : RosDevice(skin, ros)
{
  std::string deviceNameFixed = skin->getName();
  for (size_t i = 0; i < deviceNameFixed.size(); i++)
  {
    if (deviceNameFixed[i] == '-' || deviceNameFixed[i] == ' ')
      deviceNameFixed[i] = '_';
  }

  mSetBoneOrientationServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+'/'+"set_bone_orientation", &RosSkin::setBoneOrientationCallback);
  mSetBonePositionServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+'/'+"set_bone_position", &RosSkin::setBonePositionCallback);
  mGetBoneNameServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+'/'+"get_bone_name", &RosSkin::getBoneNameCallback);
  mGetBoneCountServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+'/'+"get_bone_count", &RosSkin::getBoneCountCallback);
  mGetBoneOrientationServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+'/'+"get_bone_orientation", &RosSkin::getBoneOrientationCallback);
  mGetBonePositionServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+'/'+"get_bone_position", &RosSkin::getBonePositionCallback);

  mSkin = skin;
}

bool RosSkin::setBoneOrientationCallback(webots_ros::skin_set_bone_orientation::Request &req, webots_ros::skin_set_bone_orientation::Response &res) {
  double axisAngleValues[4];
  RosMathUtils::quaternionToAxisAngle(req.orientation, axisAngleValues);
  mSkin->setBoneOrientation(req.index, axisAngleValues, req.absolute);
  res.success = 1;
  return true;
}

bool RosSkin::setBonePositionCallback(webots_ros::skin_set_bone_position::Request &req, webots_ros::skin_set_bone_position::Response &res) {
  double values[4];
  values[0] = req.position.x;
  values[1] = req.position.y;
  values[2] = req.position.z;
  const double *value = values;
  mSkin->setBonePosition(req.index, value, req.absolute);
  res.success = 1;
  return true;
}

bool RosSkin::getBoneNameCallback(webots_ros::skin_get_bone_name::Request &req, webots_ros::skin_get_bone_name::Response &res) {
  res.name = mSkin->getBoneName(req.index);
  return true;
}

bool RosSkin::getBoneCountCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res) {
  res.value = mSkin->getBoneCount();
  return true;
}

bool RosSkin::getBoneOrientationCallback(webots_ros::skin_get_bone_orientation::Request &req, webots_ros::skin_get_bone_orientation::Response &res) {
  const double *axisAngleValues = mSkin->getBoneOrientation(req.index, req.absolute);
  RosMathUtils::axisAngleToQuaternion(axisAngleValues, res.orientation);
  return true;
}

bool RosSkin::getBonePositionCallback(webots_ros::skin_get_bone_position::Request &req, webots_ros::skin_get_bone_position::Response &res) {
  const double *values = mSkin->getBonePosition(req.index, req.absolute);
  res.position.x = values[0];
  res.position.y = values[1];
  res.position.z = values[2];
  return true;
}
