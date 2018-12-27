#ifndef ROS_HPP
#define ROS_HPP

#include <webots/Robot.hpp>
#include <ros/node_handle.h>

#include <webots_ros/get_bool.h>
#include <webots_ros/get_int.h>
#include <webots_ros/get_float.h>
#include <webots_ros/get_string.h>
#include <webots_ros/set_int.h>
#include <webots_ros/set_string.h>

#include <webots_ros/robot_get_device_list.h>
#include <webots_ros/robot_set_mode.h>
#include <webots_ros/robot_wait_for_user_input_event.h>

using namespace webots;

class RosSensor;
class RosDevice;
class RosDifferentialWheels;
class RosJoystick;
class RosKeyboard;
class RosSupervisor;

class Ros
{
  public:
    Ros();
    virtual ~Ros();

    void             run(int argc,char **argv);
    ros::NodeHandle *nodeHandle() {return mNodeHandle;}
    int              stepSize() {return mStepSize;}
    std::string      name() {return mRobotName;}
    Device *         getDevice(std::string name);


    static std::string  fixedNameString(std::string name);

  protected:
    virtual void setupRobot();
    virtual void setRosDevices(const char **hiddenDevices, int numberHiddenDevices);
    virtual void launchRos(int argc,char **argv);
    virtual int step(int duration) { return mRobot->step(duration); }
    Robot  *mRobot;

  private:
    void fixName();
    bool timeStepCallback(webots_ros::set_int::Request &req, webots_ros::set_int::Response &res);
    bool waitForUserInputEventCallback(webots_ros::robot_wait_for_user_input_event::Request &req, webots_ros::robot_wait_for_user_input_event::Response &res);
    bool getDeviceListCallback(webots_ros::robot_get_device_list::Request &req, webots_ros::robot_get_device_list::Response &res);
    bool getControllerNameCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool getControllerArgumentsCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool getTimeCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    bool getModelCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool getDataCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool setDataCallback(webots_ros::set_string::Request &req, webots_ros::set_string::Response &res);
    bool getCustomDataCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool setCustomDataCallback(webots_ros::set_string::Request &req, webots_ros::set_string::Response &res);
    bool getModeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool getSynchronizationCallback(webots_ros::get_bool::Request &req, webots_ros::get_bool::Response &res);
    bool getProjectPathCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool getWorldPathCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool getBasicTimeStepCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res);
    bool getNumberOfDevicesCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool getTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res);
    bool setModeCallback(webots_ros::robot_set_mode::Request &req, webots_ros::robot_set_mode::Response &res);
    bool wwiReceiveTextCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res);
    bool wwiSendTextCallback(webots_ros::set_string::Request &req, webots_ros::set_string::Response &res);

    std::string              mRobotName;
    std::vector<RosDevice *> mDeviceList;
    std::vector<RosSensor *> mSensorList;
    RosDifferentialWheels   *mRosDifferentialWheels;
    RosSupervisor           *mRosSupervisor;
    RosJoystick             *mRosJoystick;
    RosKeyboard             *mRosKeyboard;
    ros::NodeHandle         *mNodeHandle;
    ros::Publisher           mNamePublisher;
    ros::ServiceServer       mTimeStepService;
    ros::ServiceServer       mWaitForUserInputEventService;
    ros::ServiceServer       mDeviceListService;
    ros::ServiceServer       mGetControllerNameService;
    ros::ServiceServer       mGetControllerArgumentsService;
    ros::ServiceServer       mGetTimeService;
    ros::ServiceServer       mGetModelService;
    ros::ServiceServer       mGetDataService;
    ros::ServiceServer       mSetDataService;
    ros::ServiceServer       mGetCustomDataService;
    ros::ServiceServer       mSetCustomDataService;
    ros::ServiceServer       mGetModeService;
    ros::ServiceServer       mGetSynchronizationService;
    ros::ServiceServer       mGetProjectPathService;
    ros::ServiceServer       mGetWorldPathService;
    ros::ServiceServer       mGetBasicTimeStepService;
    ros::ServiceServer       mGetNumberOfDevicesService;
    ros::ServiceServer       mGetTypeService;
    ros::ServiceServer       mSetModeService;
    ros::ServiceServer       mWwiReceiveTextService;
    ros::ServiceServer       mWwiSendTextService;
    ros::Publisher           mClockPublisher;
    unsigned int             mStepSize;
    int                      mStep;
    bool                     mEnd;
    bool                     mShouldPublishClock;
    bool                     mIsSynchronized;
    bool                     mUseWebotsSimTime;
};

#endif //ROS_HPP
