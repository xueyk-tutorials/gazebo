# gazebo插件
参考：
https://classic.gazebosim.org/tutorials?tut=plugins_model&cat=write_plugin

## 介绍
gazebo有六种plugin
World、Model、Sensor、System、Visual、GUI

插件列表：

| Camera             | Multicamera         | Depth Camera     | Openni Kinect         |
| ------------------ | ------------------- | ---------------- | --------------------- |
| GPU Laser          | Laser               | Block Laser      | F3D                   |
| Force              | IMU                 | IMU sensor       | Joint Pose Trajectory |
| P3D                | Projector           | Prosilica Camera | Bumper                |
| Differential Drive | Skid Steering Drive | Video Plugin     | Planar Move Plugin    |

## 自定义plugin类

- 所有plugin都要在gazebo的命名空间中
- 每个plugin必须有Load函数
- 一般每个plugin都会定义一个类，且必须继承一个父类
- 定义完插件类后，必须进行注册才可以使用

### 插件类

gazebo有六个父类：

WorldPlugin、SensorPlugin、GuiPlugin、SystemPlugin、VisualPlugin、ModelPlugin

### 注册

GZ_REGISTER_WORLD_PLUGIN (你的类名)
GZ_REGISTER_MODEL_PLUGIN（你的类名）
GZ_REGISTER_SENSOR_PLUGIN（你的类名）
GZ_REGISTER_GUI_PLUGIN（你的类名）
GZ_REGISTER_SYSTEM_PLUGIN（你的类名）
GZ_REGISTER_VISUAL_PLUGIN（你的类名）

## 使用

### 设置插件链接库路径

插件工程编译完成后，会在工程的build文件夹下生产动态链接库，如果要使用该插件，则需要增加该build文件夹的路径至环境变量：

```shell
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:~/gazebo_plugin_tutorial/build
```
> 请对应修改路径

### 模型使用插件

通过`plugin` 标签，使用插件。

```shell
<plugin>
```



### 启动gazebo

打开终端输入命令

```shell
$ gazebo
```

然后选择插入相关模型即可。
