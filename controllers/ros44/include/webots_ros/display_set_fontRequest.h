#ifndef WEBOTS_ROS_MESSAGE_DISPLAY_SET_FONTREQUEST_H
#define WEBOTS_ROS_MESSAGE_DISPLAY_SET_FONTREQUEST_H


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
struct display_set_fontRequest_
{
  typedef display_set_fontRequest_<ContainerAllocator> Type;

  display_set_fontRequest_()
    : font()
    , size(0)
    , antiAliasing(0)  {
    }
  display_set_fontRequest_(const ContainerAllocator& _alloc)
    : font(_alloc)
    , size(0)
    , antiAliasing(0)  {
    }


   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >   _font_type;
  _font_type font;

   typedef int32_t  _size_type;
  _size_type size;

   typedef uint8_t  _antiAliasing_type;
  _antiAliasing_type antiAliasing;




  typedef boost::shared_ptr< ::webots_ros::display_set_fontRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::webots_ros::display_set_fontRequest_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

};

typedef ::webots_ros::display_set_fontRequest_<std::allocator<void> > display_set_fontRequest;

typedef boost::shared_ptr< ::webots_ros::display_set_fontRequest > display_set_fontRequestPtr;
typedef boost::shared_ptr< ::webots_ros::display_set_fontRequest const> display_set_fontRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::webots_ros::display_set_fontRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::webots_ros::display_set_fontRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::webots_ros::display_set_fontRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::webots_ros::display_set_fontRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::webots_ros::display_set_fontRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::webots_ros::display_set_fontRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::display_set_fontRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::display_set_fontRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::webots_ros::display_set_fontRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "78ff6c1f16d92deedcc7d16bd2cddfbf";
  }

  static const char* value(const ::webots_ros::display_set_fontRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf9df5232b65af94fULL;
  static const uint64_t static_value2 = 0x73f79fe6d84301bbULL;
};

template<class ContainerAllocator>
struct DataType< ::webots_ros::display_set_fontRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "webots_ros/display_set_fontRequest";
  }

  static const char* value(const ::webots_ros::display_set_fontRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::webots_ros::display_set_fontRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string font\n\
int32 size\n\
uint8 antiAliasing\n\\n\
\n\
";
  }

  static const char* value(const ::webots_ros::display_set_fontRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::webots_ros::display_set_fontRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
            stream.next(m.font);
      stream.next(m.size);
      stream.next(m.antiAliasing);

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
struct Printer< ::webots_ros::display_set_fontRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::webots_ros::display_set_fontRequest_<ContainerAllocator>& v)
  {
        s << indent << "font: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.font);
    s << indent << "size: ";
    Printer<int32_t>::stream(s, indent + "  ", v.size);
    s << indent << "antiAliasing: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.antiAliasing);

  }
};

} // namespace message_operations
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_DISPLAY_SET_FONTREQUEST_H
