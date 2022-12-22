# gazebo

## 参考

- API： https://osrf-distributions.s3.amazonaws.com/gazebo/api/dev/index.html

https://osrf-distributions.s3.amazonaws.com/gazebo/api/dev/classgazebo_1_1physics_1_1Joint.html


## 安装
https://www.guyuehome.com/20642

```shell
lex@alex:~$ sudo apt-get install gazebo9
Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following additional packages will be installed:
  gazebo9-common gazebo9-plugin-base libgazebo9 libignition-math4
  libignition-msgs libignition-transport4 libqwt-qt5-6 libsdformat6
  libsimbody3.6 libspnav0 libtar0 sdformat-sdf ttf-dejavu-core
Suggested packages:
  gazebo9-doc spacenavd
The following NEW packages will be installed:
  gazebo9 gazebo9-common gazebo9-plugin-base libgazebo9 libignition-math4
  libignition-msgs libignition-transport4 libqwt-qt5-6 libsdformat6
  libsimbody3.6 libspnav0 libtar0 sdformat-sdf ttf-dejavu-core
```

## 下载模型
方式一：通过git仓库下载(推荐)
```shell
$ git clone https://github.91chi.fun/https://github.com/osrf/gazebo_models.git
```
方式二：通过wget下载
```shell
$ wget -r http://models.gazebosim.org/
```
下载好的模型文件拷贝至`~/.gazebo/models`下即可。
## 相关文件路径

```shell
GAZEBO_INCLUDE_DIRS=/usr/include;/usr/include/gazebo-9;/usr/include/bullet;/usr/include/simbody;/usr/include;/usr/include;/usr/include/sdformat-6.0;/usr/include/ignition/math4;/usr/include;/usr/include/OGRE;/usr/include;/usr/include;/usr/include/OGRE/Terrain;/usr/include/OGRE/Paging;/usr/include/ignition/math4;/usr/include/ignition/transport4;/usr/include/ignition/msgs1;/usr/include/ignition/common1;/usr/include/ignition/fuel_tools1 

GAZEBO_LIBRARY_DIRS=/usr/lib/x86_64-linux-gnu;/usr/lib/x86_64-linux-gnu/gazebo-9/plugins;/usr/lib/x86_64-linux-gnu
```
> 可以在终端通过命令`printenv`打印环境变量，例如：`printenv GAZEBO_MODEL_PATH`

- models文件
/usr/share/gazebo-11/models

- worlds文件
/usr/share/gazebo-11/worlds

- plugins文件
/usr/lib/x86_64-linux-gnu/plugins

## 启动gazebo

### 通过命令打开world

- 使用gazebo命令

  ```shell
  $ gazebo ./my_robot.world -u
  ```

  > 如果world中定义了模型（而不是引用本地非默认路径中的模型）则可以直接加载world文件时显示模型，如果是引用了非默认路径中的模型，则需要将该路径添加到环境变量中。

- 使用gzserver命令

  ```shell
  $ gzserver ~/gazebo_plugin_tutorial/hello.world --verbose
  ```

## gazebo界面
### 坐标系
gazebo的坐标系XYZ颜色依次为红绿蓝（RGB）

模型各link的坐标系原点为几何中心点

### 模型路径
gazebo模型默认路径为：~/.gazebo/models

可以通过设置环境变量GAZEBO_MODEL_PATH来增加查找模型的路径。在~/.bashrc添加：
```shell
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/media/allex/Develop/alex-github/drone_tutorials/gazebo/demos/models
```



## 坐标系



### Joint

- Joint Pose: 

- Relative Pose：child在parent坐标系下的坐标















