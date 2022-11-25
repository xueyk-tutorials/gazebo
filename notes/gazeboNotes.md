

https://gitee.com/bingda-robot/bingda_tutorials



## 插件

### 运动控制类

libgazebo_ros_skid_steer_drive.so

```shell
$ sudo apt-get install ros-melodic-effort-controllers
$ sudo apt-get install ros-melodic-velocity-controllers
$ sudo apt-get install ros-melodic-position-controllers
```







libgazebo_ros_control.so

### 传感器类

#### RGB-D相机

libgazebo_ros_openni_kinect.so



# gazebo

## 打开gazebo

### 直接打开

```shell
$ gazebo
```

### 通过ROS打开

```shell
$ roslaunch gazebo_ros empty_world.launch
```

查看launch文件的内容

```shell
$ roscd gazebo_ros
alex@alex-Mi:/opt/ros/melodic/share/gazebo_ros$ roscd gazebo_ros
alex@alex-Mi:/opt/ros/melodic/share/gazebo_ros$
elevator_world.launch  range_world.launch   willowgarage_world.launch
empty_world.launch     rubble_world.launch
mud_world.launch       shapes_world.launch
```



### 场景与模型

gazebo模型一般默认存放在`/home/alex/.gazebo/models`下

#### 下载模型

使用国内的仓库下载。

```shell
git clone https://gitee.com/bingda-robot/gazebo_models.git
```



#### 添加模型

通过选择左侧`Insert`，添加模型。



#### 保存场景

如果经过一系列模型添加、摆放、编辑好了一个场景，希望保存，那么执行`File->Save World As`，并保存为`.world`格式文件。



> Bug: 在保存时需要将gazebo窗口最小化才可以弹出文件选择菜单！

# URDF

Unified Robot Description Format统一的机器人描述文件格式。

http://wiki.ros.org/urdf/Tutorials

http://wiki.ros.org/urdf/XML

http://wiki.ros.org/urdf/XML/model

http://wiki.ros.org/urdf/XML/sensor



# xacro



http://wiki.ros.org/xacro