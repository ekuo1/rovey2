#ifndef WEBOTS_ROS_MESSAGE_DISPLAY_IMAGE_COPYREQUEST_H
#define WEBOTS_ROS_MESSAGE_DISPLAY_IMAGE_COPYREQUEST_H


#include <string>
#include <vector>
#include <map>

#include "ros/types.h"
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"



namespace webots_ros
{
template <class ContainerAllocator>
struct display_image_copyRequest_
{
  typedef display_image_copyRequest_<ContainerAllocator> Type;

  display_image_copyRequest_()
    : x(0)
    , y(0)
    , width(0)
    , height(0)  {
    }
  display_image_copyRequest_(const ContainerAllocator& _alloc)
    : x(0)
    , y(0)
    , width(0)
    , height(0)  {
    }


   typedef int32_t  _x_type;
  _x_type x;

   typedef int32_t  _y_type;
  _y_type y;

   typedef int32_t  _width_type;
  _width_type width;

   typedef int32_t  _height_type;
  _height_type height;




  typedef boost::shared_ptr< ::webots_ros::display_image_copyRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::webots_ros::display_image_copyRequest_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

};

typedef ::webots_ros::display_image_copyRequest_<std::allocator<void> > display_image_copyRequest;

typedef boost::shared_ptr< ::webots_ros::display_image_copyRequest > display_image_copyRequestPtr;
typedef boost::shared_ptr< ::webots_ros::display_image_copyRequest const> display_image_copyRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::webots_ros::display_image_copyRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::webots_ros::display_image_copyRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace webots_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/groovy/share/std_msgs/msg'], 'webots_ros

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::webots_ros::display_image_copyRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::webots_ros::display_image_copyRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::webots_ros::display_image_copyRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::webots_ros::display_image_copyRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::display_image_copyRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::display_image_copyRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::webots_ros::display_image_copyRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "631fd4626b960a90b6a634bededf2cea";
  }

  static const char* value(const ::webots_ros::display_image_copyRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf9df5232b65af94fULL;
  static const uint64_t static_value2 = 0x73f79fe6d84301bbULL;
};

template<class ContainerAllocator>
struct DataType< ::webots_ros::display_image_copyRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "webots_ros/display_image_copyRequest";
  }

  static const char* value(const ::webots_ros::display_image_copyRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::webots_ros::display_image_copyRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 x\n\
int32 y\n\
int32 width\n\
int32 height\n\\n\
\n\
";
  }

  static const char* value(const ::webots_ros::display_image_copyRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::webots_ros::display_image_copyRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
            stream.next(m.x);
      stream.next(m.y);
      stream.next(m.width);
      stream.next(m.height);

    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  };

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::webots_ros::display_image_copyRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::webots_ros::display_image_copyRequest_<ContainerAllocator>& v)
  {
        s << indent << "x: ";
    Printer<int32_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<int32_t>::stream(s, indent + "  ", v.y);
    s << indent << "width: ";
    Printer<int32_t>::stream(s, indent + "  ", v.width);
    s << indent << "height: ";
    Printer<int32_t>::stream(s, indent + "  ", v.height);

  }
};

} // namespace message_operations
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_DISPLAY_IMAGE_COPYREQUEST_H
