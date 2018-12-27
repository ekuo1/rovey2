#ifndef WEBOTS_ROS_MESSAGE_NODE_SET_VISIBILITYREQUEST_H
#define WEBOTS_ROS_MESSAGE_NODE_SET_VISIBILITYREQUEST_H


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
struct node_set_visibilityRequest_
{
  typedef node_set_visibilityRequest_<ContainerAllocator> Type;

  node_set_visibilityRequest_()
    : node(0)
    , from(0)
    , visible(0)  {
    }
  node_set_visibilityRequest_(const ContainerAllocator& _alloc)
    : node(0)
    , from(0)
    , visible(0)  {
    }


   typedef uint64_t  _node_type;
  _node_type node;

   typedef uint64_t  _from_type;
  _from_type from;

   typedef uint8_t  _visible_type;
  _visible_type visible;




  typedef boost::shared_ptr< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

};

typedef ::webots_ros::node_set_visibilityRequest_<std::allocator<void> > node_set_visibilityRequest;

typedef boost::shared_ptr< ::webots_ros::node_set_visibilityRequest > node_set_visibilityRequestPtr;
typedef boost::shared_ptr< ::webots_ros::node_set_visibilityRequest const> node_set_visibilityRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b6fcfa2c79ae79467e085318b3617289";
  }

  static const char* value(const ::webots_ros::node_set_visibilityRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf9df5232b65af94fULL;
  static const uint64_t static_value2 = 0x73f79fe6d84301bbULL;
};

template<class ContainerAllocator>
struct DataType< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "webots_ros/node_set_visibilityRequest";
  }

  static const char* value(const ::webots_ros::node_set_visibilityRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint64 node\n\
uint64 from\n\
uint8 visible\n\\n\
\n\
";
  }

  static const char* value(const ::webots_ros::node_set_visibilityRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
            stream.next(m.node);
      stream.next(m.from);
      stream.next(m.visible);

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
struct Printer< ::webots_ros::node_set_visibilityRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::webots_ros::node_set_visibilityRequest_<ContainerAllocator>& v)
  {
        s << indent << "node: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.node);
    s << indent << "from: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.from);
    s << indent << "visible: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.visible);

  }
};

} // namespace message_operations
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_NODE_SET_VISIBILITYREQUEST_H
