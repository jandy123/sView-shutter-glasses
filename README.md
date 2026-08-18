# sView-shutter-glasses
### sView with support for android and various shutter glasses

**sView-shutter-glasses is an extended version of [sView](https://sview.ru/en/) which works on android, linux and windows devices with displays supporting refresh rates larger than 120Hz.** Various shutter glasses can be used to watch 3D content (photos and videos) through a custom-made infrared emitter based on cheap RP2040 USB dongles. The current setup uses the emitter documented here: [RP2040-3D-Vision-Emitter](https://github.com/NTM-3D/RP2040-3D-Vision-Emitter). Only Panasonic and NVidia 3D Vision glasses have been tested.

A pre-built android app is available for download, see the current pre-release. The app should work on Android 13 and 16 and has been tested on Samsung S20 and S26 Ultra. The IR emitter has to be connected to the phone/tablet via a USB-A to USB-C (OTG) adapter.  

#### Setup
To be updated...

#### Building

##### Linux
Check out the prerequisites for sView and make sure that they are installed. Once this is done, just type `make` to build the application and `make install` to install it under `/usr/local/`.

##### Android
Execute the script `andy_build_android.sh` under `./continuousIntegration`. I assume a linux machine is used to build the android apk.

##### Windows
Help needed, since I do not use.

#### Credits

* sView by Kirill Gavrilov Tartynskih, see https://sview.ru/en/
* RP2040-3D-Vision-Emitter by NTM-3D, see https://github.com/NTM-3D/RP2040-3D-Vision-Emitter
* 3DJ ThreeDeeJay, see https://github.com/ThreeDeeJay/sview/tree/master?tab=readme-ov-file

