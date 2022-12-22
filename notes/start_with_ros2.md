# gazebo与ros2的结合使用
## 简介
Gazebo是一个独立的应用程序，可以独立于ROS或ROS2使用。Gazebo与这两个ROS版本中任一版本的集成都是通过一组称为gazebo_ros_pkgs的软件包来完成和实现的。这些软件包在Gazebo的C++ API和传输系统与ROS2的消息和服务之间架起了桥梁。
> 本质上，在编写gazebo plugin时通过使用ROS2的API（实例化Node、Subscription等）创建与其他ROS2节点的通信！

ROS2的gazebo_ros_pkgs是一个元软件包，其中包含以下4个具体的软件包：

- gazebo_dev软件包：为ROS发行版的默认Gazebo版本提供cmake配置。因此，下游软件包可以仅依赖于gazebo_dev软件包，而无需自己查找Gazebo。

- gazebo_msgs软件包：用于提供ROS2与Gazebo交互所使用的消息和服务的数据结构。

- gazebo_ros软件包：提供方便的C++类和函数，其他插件可以使用这些类和函数，例如gazebo_ros::Node，以及转换和测试实用程序。此外该软件包还提供一些有用的插件。

- gazebo_plugins软件包：提供一系列Gazebo插件，用于将传感器和其他功能提供给ROS2使用。例如，gazebo_ros_camera插件用于发布ROS2图像，而gazebo_ros_diff_drive插件则提供了一个接口，用于通过ROS2控制差分驱动机器人并对其进行自检。

## 参考资料

### gazebo_msgs

https://docs.ros.org/en/jade/api/gazebo_msgs/html/index-msg.html



## 环境配置

### gazebo11
首先安装gazebo11（如果已经安装了gazebo9请先卸载）

### gazebo_ros_pkgs

通过命令安装ros2相关的gazebo包。
```shell
sudo apt install ros-foxy-gazebo-*
```
会安装如下ros2包
```shell
The following additional packages will be installed:
  ros-foxy-camera-calibration-parsers ros-foxy-camera-info-manager
  ros-foxy-control-msgs ros-foxy-controller-interface
  ros-foxy-controller-manager ros-foxy-controller-manager-msgs
  ros-foxy-diff-drive-controller ros-foxy-effort-controllers
  ros-foxy-force-torque-sensor-broadcaster ros-foxy-forward-command-controller
  ros-foxy-hardware-interface ros-foxy-imu-sensor-broadcaster
  ros-foxy-joint-state-broadcaster ros-foxy-joint-state-controller
  ros-foxy-joint-trajectory-controller ros-foxy-position-controllers
  ros-foxy-realtime-tools ros-foxy-ros2-control
  ros-foxy-ros2-control-test-assets ros-foxy-ros2-controllers
  ros-foxy-ros2controlcli ros-foxy-velocity-controllers ros-foxy-xacro
The following NEW packages will be installed:
  ros-foxy-camera-calibration-parsers ros-foxy-camera-info-manager
  ros-foxy-control-msgs ros-foxy-controller-interface
  ros-foxy-controller-manager ros-foxy-controller-manager-msgs
  ros-foxy-diff-drive-controller ros-foxy-effort-controllers
  ros-foxy-force-torque-sensor-broadcaster ros-foxy-forward-command-controller
  ros-foxy-gazebo-dev ros-foxy-gazebo-msgs ros-foxy-gazebo-msgs-dbgsym
  ros-foxy-gazebo-plugins ros-foxy-gazebo-plugins-dbgsym ros-foxy-gazebo-ros
  ros-foxy-gazebo-ros-dbgsym ros-foxy-gazebo-ros-pkgs
  ros-foxy-gazebo-ros2-control ros-foxy-gazebo-ros2-control-dbgsym
  ros-foxy-gazebo-ros2-control-demos ros-foxy-gazebo-ros2-control-demos-dbgsym
  ros-foxy-hardware-interface ros-foxy-imu-sensor-broadcaster
  ros-foxy-joint-state-broadcaster ros-foxy-joint-state-controller
  ros-foxy-joint-trajectory-controller ros-foxy-position-controllers
  ros-foxy-realtime-tools ros-foxy-ros2-control
  ros-foxy-ros2-control-test-assets ros-foxy-ros2-controllers
  ros-foxy-ros2controlcli ros-foxy-velocity-controllers ros-foxy-xacro
0 upgraded, 35 newly installed, 0 to remove and 252 not upgraded.
```
 通过`ros2 pkg list`命令可以看到新增的packages如下：
```shell
camera_calibration_parsers
camera_info_manager
control_msgs
controller_interface
controller_manager
controller_manager_msgs
cv_bridge
demo_nodes_cpp
demo_nodes_cpp_native
demo_nodes_py
depthimage_to_laserscan
desktop
diagnostic_msgs
diff_drive_controller
effort_controllers
force_torque_sensor_broadcaster
forward_command_controller
gazebo_dev
gazebo_msgs
gazebo_plugins
gazebo_ros
gazebo_ros2_control
gazebo_ros2_control_demos
gazebo_ros_pkgs
hardware_interface
imu_sensor_broadcaster
joint_state_broadcaster
joint_state_controller
joint_trajectory_controller
position_controllers
realtime_tools
ros2_control
ros2_control_test_assets
ros2_controllers
ros2controlcli
velocity_controllers
xacro
```
### 下载models
方式一：通过git仓库下载(推荐)
```shell
$ git clone https://github.91chi.fun/https://github.com/osrf/gazebo_models.git
```
方式二：通过wget下载
```shell
$ wget -r http://models.gazebosim.org/
```
下载好的模型文件拷贝至`~/.gazebo/models`下即可。

### gazebo资源
- gazebo API头文件
`/usr/include/gazebo-11/gazebo`，例如gazebo.hh、plugins/CameraPlugin.hh等文件。

- 消息与服务定义
可以在`/opt/ros/foxy/include/gazebo_*`下查看相关消息和服务

- launch
可以在`/opt/ros/foxy/share/gazebo_*/launch`下查看launch.py文件

- 插件.so
可以在`/opt/ros/foxy/lib`下查看安装的插件

### 测试
#### 差速机器人
可以启动一个差速控制机器人，并通过发布消息控制机器人移动，确定环境配置完成。
- 启动机器人
```shell
$ gazebo --verbose /opt/ros/foxy/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
```
- 控制机器人移动
```shell
ros2 topic pub /demo/cmd_demo geometry_msgs/Twist '{linear: {x: 1.0}}' -1
```
机器人会往前运动。
#### 深度相机
```shell
gazebo --verbose /opt/ros/foxy/share/gazebo_plugins/worlds/gazebo_ros_depth_camera_demo.world
```
打开rviz2，增加image，可以订阅并显示话题

## ros2 launch启动gazebo
### 使用gazebo_ros包
- 通过launch启动一个空白的世界
```shell
$ ros2 launch gazebo_ros gazebo.launch.py
```
- 启动一个摆锤模型
```shell
$ ros2 launch gazebo_ros spawn_entity_demo.launch.py
```

### 参数
launch接受的参数如下：
- pause参数：若设置为true，则会以仿真暂停状态启动Gazebo；默认为false，这样会以仿真运行状态启动Gazebo；
- use_sim_time参数：默认为true，这会告知 ROS 2节点请求时间来获取 Gazebo 发布的仿真时间，并将该仿真时间发布在 ROS 2话题 /clock 上；若设置为false，则不获取和发布仿真时间；
- gui参数：默认为true，这样会启动Gazebo的用户界面窗口；若设置为false，则不会打开Gazebo的用户界面；
- recording参数：用于设置是否启用Gazebo状态日志记录功能；
- debug参数：若设置为true，则会以调试模式启动Gazebo服务器gzserver；默认为false；
- verbose参数：若设置为true运行 gzserver 和 gzclient，则会向终端打印错误和警告消息（默认为 false）；
- server_required参数：若设置为true，当Gazebo 服务器gzserver退出时会终止启动脚本（默认为 false）；
- gui_required参数：若设置为true，当Gazebo客户端gzclient退出时会终止启动脚本（默认为false）。

例如：
```shell
$ ros2 launch gazebo_ros gazebo.launch.py pause:=true use_sim_time:=false gui:=true recording:=false debug:=true verbose:=true gui_required:=true
```
### 查看话题和服务
```shell
ros2 topic list -t
ros2 service list -t
```
### 通过launch启动worlds
```python
import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import ThisLaunchFileDir
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    world_file_name = 'underwater.world'
    world = os.path.join('/usr/share/gazebo-11', 'worlds', world_file_name)
    gazebo = ExecuteProcess(cmd=['gazebo', '--verbose', world, '-s', 'libgazebo_ros_init.so', '-s', 'libgazebo_ros_factory.so'], output='screen')

    return LaunchDescription([
        gazebo])
```
然后通过`ros2 launch underwarter_world.launch.py`即可启动gazebo。

### 通过launch加载model
```python
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import ThisLaunchFileDir
from launch_ros.actions import Node

def generate_launch_description():
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([ThisLaunchFileDir(), '/gazebo.launch.py']),
             )
    # GAZEBO_MODEL_PATH has to be correctly set for Gazebo to be able to find the model
    spawn_entity = Node(package='gazebo_ros', node_executable='spawn_entity.py',
                        arguments=['-entity', 'demo', '-database', 'double_pendulum_with_base'],
                        output='screen')
    return LaunchDescription([
        gazebo,
        spawn_entity,
    ])
```
## 开源示例
### dolly
https://github.com/chapulina/dolly