# 仓库机器人示例
参考：https://automaticaddison.com/how-to-simulate-a-robot-using-gazebo-and-ros-2/#Prerequisites

## 启动gazebo并加载模型
### 启动gazebo
```shell
$ gazebo
```
### 加载模型
- 设置模型路径
```shell
$ export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:~/demo_WarehouseRobot/models
```

- 插入模型 
在gazebo中，在insert面板内，选择模型mobile_warehouse_robot进行插入！

- 查看当前消息
```shell
$ ros2 topic list -t

/clock [rosgraph_msgs/msg/Clock]
/demo/cmd_vel [geometry_msgs/msg/Twist]
/demo/laser/out [sensor_msgs/msg/LaserScan]
/demo/odom [nav_msgs/msg/Odometry]
/parameter_events [rcl_interfaces/msg/ParameterEvent]
/rosout [rcl_interfaces/msg/Log]
/tf [tf2_msgs/msg/TFMessage]
```
> 这里/tf消息包括了机器人各link之间的转换关系。
> /tf话题是由插件`libgazebo_ros_diff_drive.so`生成的。


- 速度控制
```shell
ros2 topic pub /demo/cmd_vel geometry_msgs/Twist '{linear: {x: 0.05}}' -1
```

## ROS2编程
### 通过ROS2节点加载模型
- 编译
```shell
$ cd ws_ros2
$ colcon build
```
- 添加环境变量
在打开的终端1，进入工程目录，增加ROS2包的路径至环境变量
```shell
$ cd ws_ros2
$ . install/setup.bash
```
增加models的路径至环境变量
```shell
$ export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:~/demo_WarehouseRobot/ws_ros2/src/warehouse_robot_spawner_pkg/models
```

- 通过launch启动一个空白世界
新建一个终端2，启动launch
```shell
$ ros2 launch gazebo_ros gazebo.launch.py
```
- 运行ROS2节点
在终端1中，运行节点
```shell
$ ros2 run warehouse_robot_spawner_pkg spawn_demo
```

> 注意：
> 1. 必须使用launch启动一个空白世界，这样才会产生`/spawn_entity`服务！

## 通过launch启动世界并加载模型
- 编译
```shell
$ cd ws_ros2
$ colcon build
```
- 添加环境变量
在打开的终端1，进入工程目录，增加ROS2包的路径至环境变量
```shell
$ cd ws_ros2
$ . install/setup.bash
```
- 启动
```shell
$ ros2 launch warehouse_robot_spawner_pkg spawn_demo.launch.py
```

> 在launch运行过程中，通过`os.path.join`函数将模型路径添加至`$GAZEBO_MODEL_PATH`环境变量中。
> 每次改动了models或worlds后，都需要重新编译包。

## 手动控制机器人
- 下载turtlebot3包
```shell
$ sudo apt install ros-foxy-turtlebot3*
```

- 启动warehouse世界
```shell
$ ros2 launch warehouse_robot_spawner_pkg spawn_demo.launch.py
```

- 键盘控制
```shell
$ export TURTLEBOT3_MODEL=burger 
$ ros2 run turtlebot3_teleop teleop_keyboard --ros-args --remap /cmd_vel:=/demo/cmd_vel
```


## 自主导航
- 启动warehouse世界
打开终端1
```shell
$ ros2 launch warehouse_robot_spawner_pkg spawn_demo.launch.py
```
- 启动控制
```shell
$ ros2 launch warehouse_robot_controller_pkg controller_estimator.launch.py
```



查看机器人各link的转换关系：
```shell
$ ros2 topic echo /tf
```