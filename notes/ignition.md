# gazebo ignition
## 安装
https://gazebosim.org/docs/garden/install_ubuntu

```shell
alex@alex:~$ sudo apt-get install gz-garden
Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following additional packages will be installed:
  comerr-dev fonts-lato gz-launch6-cli gz-plugin2-cli gz-sim7-cli gz-tools2 gz-transport12-cli
  krb5-multidev libass9 libavdevice-dev libavdevice58 libavfilter-dev libavfilter7 libbs2b0
  libcap-dev libccd-dev libccd2 libcom-err2 libdart-collision-bullet-dev libdart-collision-ode-dev
  libdart-dev libdart-external-ikfast-dev libdart-external-odelcpsolver-dev libdart-utils-dev
  libdart-utils-urdf-dev libdart6 libdart6-collision-bullet libdart6-collision-ode
  libdart6-external-odelcpsolver libdart6-utils libdart6-utils-urdf libev-dev libev4 libfcl-dev
  libfcl0.5 libfftw3-double3 libflite1 libfreeimage3 libgssrpc4 libgts-dev libgz-cmake3-dev
  libgz-common5 libgz-common5-av libgz-common5-av-dev libgz-common5-core-dev libgz-common5-dev
  libgz-common5-events libgz-common5-events-dev libgz-common5-geospatial libgz-common5-geospatial-dev
  libgz-common5-graphics libgz-common5-graphics-dev libgz-common5-io libgz-common5-io-dev
  libgz-common5-profiler libgz-common5-profiler-dev libgz-common5-testing libgz-common5-testing-dev
  libgz-fuel-tools8 libgz-fuel-tools8-dev libgz-gui7 libgz-gui7-dev libgz-launch6 libgz-launch6-dev
  libgz-math7 libgz-math7-dev libgz-math7-eigen3-dev libgz-msgs9 libgz-msgs9-dev libgz-physics6
  libgz-physics6-bullet libgz-physics6-bullet-dev libgz-physics6-core-dev libgz-physics6-dartsim
  libgz-physics6-dartsim-dev libgz-physics6-dev libgz-physics6-heightmap-dev libgz-physics6-mesh-dev
  libgz-physics6-sdf-dev libgz-physics6-tpe libgz-physics6-tpe-dev libgz-physics6-tpelib
  libgz-physics6-tpelib-dev libgz-plugin2 libgz-plugin2-dev libgz-rendering7
  libgz-rendering7-core-dev libgz-rendering7-dev libgz-rendering7-ogre1 libgz-rendering7-ogre1-dev
  libgz-rendering7-ogre2 libgz-rendering7-ogre2-dev libgz-sensors7 libgz-sensors7-air-pressure
  libgz-sensors7-air-pressure-dev libgz-sensors7-altimeter libgz-sensors7-altimeter-dev
  libgz-sensors7-boundingbox-camera libgz-sensors7-boundingbox-camera-dev libgz-sensors7-camera
  libgz-sensors7-camera-dev libgz-sensors7-core-dev libgz-sensors7-depth-camera
  libgz-sensors7-depth-camera-dev libgz-sensors7-dev libgz-sensors7-force-torque
  libgz-sensors7-force-torque-dev libgz-sensors7-gpu-lidar libgz-sensors7-gpu-lidar-dev
  libgz-sensors7-imu libgz-sensors7-imu-dev libgz-sensors7-lidar libgz-sensors7-lidar-dev
  libgz-sensors7-logical-camera libgz-sensors7-logical-camera-dev libgz-sensors7-magnetometer
  libgz-sensors7-magnetometer-dev libgz-sensors7-navsat libgz-sensors7-navsat-dev
  libgz-sensors7-rendering libgz-sensors7-rendering-dev libgz-sensors7-rgbd-camera
  libgz-sensors7-rgbd-camera-dev libgz-sensors7-segmentation-camera
  libgz-sensors7-segmentation-camera-dev libgz-sensors7-thermal-camera
  libgz-sensors7-thermal-camera-dev libgz-sensors7-wide-angle-camera
  libgz-sensors7-wide-angle-camera-dev libgz-sim7 libgz-sim7-dev libgz-sim7-plugins libgz-tools2-dev
  libgz-transport12 libgz-transport12-core-dev libgz-transport12-dev libgz-transport12-log
  libgz-transport12-log-dev libgz-utils2 libgz-utils2-cli-dev libgz-utils2-dev libignition-cmake3-dev
  libignition-common5-geospatial-dev libignition-common5-graphics-dev libignition-math7-dev
  libignition-math7-eigen3-dev libignition-physics6 libignition-physics6-bullet
  libignition-physics6-bullet-dev libignition-physics6-core-dev libignition-physics6-dartsim
  libignition-physics6-dartsim-dev libignition-physics6-heightmap-dev libignition-physics6-mesh-dev
  libignition-physics6-sdf-dev libignition-physics6-tpe libignition-physics6-tpe-dev
  libignition-physics6-tpelib libignition-physics6-tpelib-dev libignition-plugin2-dev
  libignition-utils2-dev libjxr0 libkadm5clnt-mit11 libkadm5srv-mit11 libkdb5-9 libkrb5-dev
  liblilv-0-0 libmysofa1 libnorm-dev libnorm1 liboctomap-dev liboctomap1.9 libode-dev libode8
  libogre-1.9-dev libogre-1.9.0v5 libogre-next-2.3-dev libogre-next-2.3.0 libopenal-data libopenal1
  libpgm-5.2-0 libpgm-dev libpostproc-dev libpostproc55 libprotobuf-dev libprotobuf-lite17
  libprotoc-dev libprotoc17 libqt5charts5 libqt5quickcontrols2-5 libqt5quicktemplates2-5
  librubberband2 libruby2.7 libsdformat13 libsdformat13-dev libserd-0-0 libsodium-dev libsord-0-0
  libsratom-0-0 liburdfdom-dev liburdfdom-headers-dev liburdfdom-model liburdfdom-model-state
  liburdfdom-sensor liburdfdom-world libuv1-dev libvidstab1.1 libwebsockets-dev libwebsockets15
  libzip-dev libzip5 libzmq3-dev libzmq5 libzzip-0-13 protobuf-compiler pybind11-dev python3-gz-math7
  python3-gz-sim7 python3-pybind11 qml-module-qt-labs-folderlistmodel qml-module-qt-labs-platform
  qml-module-qt-labs-settings qml-module-qtcharts qml-module-qtgraphicaleffects
  qml-module-qtqml-models2 qml-module-qtquick-controls qml-module-qtquick-controls2
  qml-module-qtquick-dialogs qml-module-qtquick-layouts qml-module-qtquick-privatewidgets
  qml-module-qtquick-templates2 qml-module-qtquick-window2 qml-module-qtquick2 qtquickcontrols2-5-dev
  rake ruby ruby-minitest ruby-net-telnet ruby-power-assert ruby-test-unit ruby-xmlrpc ruby2.7
  rubygems-integration sdformat13-sdf
Suggested packages:
  doc-base krb5-doc libfftw3-bin libfftw3-dev krb5-user libgts-doc libnorm-doc ogre-1.9-doc
  libogre-1.9.0v5-dbg ogre-next-2.3-doc libportaudio2 serdi sordi pybind11-doc ri ruby-dev bundler
The following NEW packages will be installed:
  comerr-dev fonts-lato gz-garden gz-launch6-cli gz-plugin2-cli gz-sim7-cli gz-tools2
  gz-transport12-cli krb5-multidev libass9 libavdevice-dev libavdevice58 libavfilter-dev libavfilter7
  libbs2b0 libcap-dev libccd-dev libccd2 libdart-collision-bullet-dev libdart-collision-ode-dev
  libdart-dev libdart-external-ikfast-dev libdart-external-odelcpsolver-dev libdart-utils-dev
  libdart-utils-urdf-dev libdart6 libdart6-collision-bullet libdart6-collision-ode
  libdart6-external-odelcpsolver libdart6-utils libdart6-utils-urdf libev-dev libev4 libfcl-dev
  libfcl0.5 libfftw3-double3 libflite1 libfreeimage3 libgssrpc4 libgts-dev libgz-cmake3-dev
  libgz-common5 libgz-common5-av libgz-common5-av-dev libgz-common5-core-dev libgz-common5-dev
  libgz-common5-events libgz-common5-events-dev libgz-common5-geospatial libgz-common5-geospatial-dev
  libgz-common5-graphics libgz-common5-graphics-dev libgz-common5-io libgz-common5-io-dev
  libgz-common5-profiler libgz-common5-profiler-dev libgz-common5-testing libgz-common5-testing-dev
  libgz-fuel-tools8 libgz-fuel-tools8-dev libgz-gui7 libgz-gui7-dev libgz-launch6 libgz-launch6-dev
  libgz-math7 libgz-math7-dev libgz-math7-eigen3-dev libgz-msgs9 libgz-msgs9-dev libgz-physics6
  libgz-physics6-bullet libgz-physics6-bullet-dev libgz-physics6-core-dev libgz-physics6-dartsim
  libgz-physics6-dartsim-dev libgz-physics6-dev libgz-physics6-heightmap-dev libgz-physics6-mesh-dev
  libgz-physics6-sdf-dev libgz-physics6-tpe libgz-physics6-tpe-dev libgz-physics6-tpelib
  libgz-physics6-tpelib-dev libgz-plugin2 libgz-plugin2-dev libgz-rendering7
  libgz-rendering7-core-dev libgz-rendering7-dev libgz-rendering7-ogre1 libgz-rendering7-ogre1-dev
  libgz-rendering7-ogre2 libgz-rendering7-ogre2-dev libgz-sensors7 libgz-sensors7-air-pressure
  libgz-sensors7-air-pressure-dev libgz-sensors7-altimeter libgz-sensors7-altimeter-dev
  libgz-sensors7-boundingbox-camera libgz-sensors7-boundingbox-camera-dev libgz-sensors7-camera
  libgz-sensors7-camera-dev libgz-sensors7-core-dev libgz-sensors7-depth-camera
  libgz-sensors7-depth-camera-dev libgz-sensors7-dev libgz-sensors7-force-torque
  libgz-sensors7-force-torque-dev libgz-sensors7-gpu-lidar libgz-sensors7-gpu-lidar-dev
  libgz-sensors7-imu libgz-sensors7-imu-dev libgz-sensors7-lidar libgz-sensors7-lidar-dev
  libgz-sensors7-logical-camera libgz-sensors7-logical-camera-dev libgz-sensors7-magnetometer
  libgz-sensors7-magnetometer-dev libgz-sensors7-navsat libgz-sensors7-navsat-dev
  libgz-sensors7-rendering libgz-sensors7-rendering-dev libgz-sensors7-rgbd-camera
  libgz-sensors7-rgbd-camera-dev libgz-sensors7-segmentation-camera
  libgz-sensors7-segmentation-camera-dev libgz-sensors7-thermal-camera
  libgz-sensors7-thermal-camera-dev libgz-sensors7-wide-angle-camera
  libgz-sensors7-wide-angle-camera-dev libgz-sim7 libgz-sim7-dev libgz-sim7-plugins libgz-tools2-dev
  libgz-transport12 libgz-transport12-core-dev libgz-transport12-dev libgz-transport12-log
  libgz-transport12-log-dev libgz-utils2 libgz-utils2-cli-dev libgz-utils2-dev libignition-cmake3-dev
  libignition-common5-geospatial-dev libignition-common5-graphics-dev libignition-math7-dev
  libignition-math7-eigen3-dev libignition-physics6 libignition-physics6-bullet
  libignition-physics6-bullet-dev libignition-physics6-core-dev libignition-physics6-dartsim
  libignition-physics6-dartsim-dev libignition-physics6-heightmap-dev libignition-physics6-mesh-dev
  libignition-physics6-sdf-dev libignition-physics6-tpe libignition-physics6-tpe-dev
  libignition-physics6-tpelib libignition-physics6-tpelib-dev libignition-plugin2-dev
  libignition-utils2-dev libjxr0 libkadm5clnt-mit11 libkadm5srv-mit11 libkdb5-9 libkrb5-dev
  liblilv-0-0 libmysofa1 libnorm-dev libnorm1 liboctomap-dev liboctomap1.9 libode-dev libode8
  libogre-1.9-dev libogre-1.9.0v5 libogre-next-2.3-dev libogre-next-2.3.0 libopenal-data libopenal1
  libpgm-5.2-0 libpgm-dev libpostproc-dev libpostproc55 libprotobuf-dev libprotobuf-lite17
  libprotoc-dev libprotoc17 libqt5charts5 libqt5quickcontrols2-5 libqt5quicktemplates2-5
  librubberband2 libruby2.7 libsdformat13 libsdformat13-dev libserd-0-0 libsodium-dev libsord-0-0
  libsratom-0-0 liburdfdom-dev liburdfdom-headers-dev liburdfdom-model liburdfdom-model-state
  liburdfdom-sensor liburdfdom-world libuv1-dev libvidstab1.1 libwebsockets-dev libwebsockets15
  libzip-dev libzip5 libzmq3-dev libzmq5 libzzip-0-13 protobuf-compiler pybind11-dev python3-gz-math7
  python3-gz-sim7 python3-pybind11 qml-module-qt-labs-folderlistmodel qml-module-qt-labs-platform
  qml-module-qt-labs-settings qml-module-qtcharts qml-module-qtgraphicaleffects
  qml-module-qtqml-models2 qml-module-qtquick-controls qml-module-qtquick-controls2
  qml-module-qtquick-dialogs qml-module-qtquick-layouts qml-module-qtquick-privatewidgets
  qml-module-qtquick-templates2 qml-module-qtquick-window2 qml-module-qtquick2 qtquickcontrols2-5-dev
  rake ruby ruby-minitest ruby-net-telnet ruby-power-assert ruby-test-unit ruby-xmlrpc ruby2.7
  rubygems-integration sdformat13-sdf
The following packages will be upgraded:
  libcom-err2
1 upgraded, 244 newly installed, 0 to remove and 283 not upgraded.
```


## 卸载
```shell
sudo apt remove gz-garden && sudo apt autoremove
```

如果又安装了gazebo9，卸载出现如下问题：
```shell
alex@alex:~$ sudo apt remove gz-garden && sudo apt autoremove
Reading package lists... Done
Building dependency tree       
Reading state information... Done
You might want to run 'apt --fix-broken install' to correct these.
The following packages have unmet dependencies:
 gazebo9-plugin-base : Depends: gazebo9 (= 9.19.0-2~focal) but it is not going to be installed
E: Unmet dependencies. Try 'apt --fix-broken install' with no packages (or specify a solution).
```
首先把gazebo9-plugin-base删除
```shell
$ sudo apt-get remove gazebo9-plugin-base
```
