# sView-shutter-glasses
### sView with support for android and various shutter glasses

**sView-shutter-glasses is an extended version of [sView](https://sview.ru/en/) which works on android, linux and windows devices with displays supporting refresh rates larger than 120Hz.** Various shutter glasses can be used to watch 3D content (photos and videos) through a custom-made infrared emitter based on cheap RP2040 USB dongles. The current setup uses the emitter documented here: [RP2040-3D-Vision-Emitter](https://github.com/NTM-3D/RP2040-3D-Vision-Emitter). Only Panasonic and NVidia 3D Vision glasses have been tested. Also, currently only a refresh rate of 120Hz is supported by the emitter firmware. 

A pre-built android app is available for download, see the current pre-release. The app should work on Android 13 and 16 and has been tested on Samsung S20 and S26 Ultra. The IR emitter has to be connected to the phone/tablet via a USB-A to USB-C (OTG) adapter. The emitter firmware, modified for Panasonic glasses and for dealing with ghosting can be found also under Releases. The modified code of the emitter firmware can be found here: [RP2040-3D-Vision-Emitter-sView](https://github.com/jandy123/RP2040-3D-Vision-Emitter-sView/tree/main).

#### Setup

##### Android

* Once the app is installed and the USB emitter attached, start the app (either sView Image Viewer or sView Media player), accept permissions, access to USB device, etc.
* Go to Menu and select Settings. In Settings:
  * Modify "Change device": "Anaglyph glasses" to "Shutter glasses". An error will pop-up, accept close.
* Go to Menu and select Settings. In Settings:
  * Check "Show extra options". An error will pop-up, accept close.
* Go to Menu and select Settings. In Settings:       
  * Modify "Quad Buffer type": "OpenGL Hardware" to "OpenGL Emulated".
* Finally, open some 3D media file, change maybe the output type to "Stereo" and play.
* One 3D media plays, glasses synchronization can be adjusted by clicking the right-most option on the OSD and changing the value of the slider "Render delay". Ideally, you would get stable, ghost-free 3D experience :).     
      
To be updated...

#### Building

##### Linux
Check out the prerequisites for sView and make sure that they are installed. Once this is done, just type `make` to build the application and `make install` to install it under `/usr/local/`.

##### Android
Execute the script `andy_build_android.sh` under `./continuousIntegration`. I assume a linux machine is used to build the android apk.

##### Windows
Help needed, since I do not use.

#### TODO
* Currently the code is very experimental; a lot of code cleanup and refactoring has to be done.
* Improve the building system; currently all binary tools and required libraries for building sView for android are shipped within this repository.
* Allow choices for refresh rate, glasses, delay parameter, etc., via the sView GUI and apss them to the emitter firmware. This will require a lot of modifications of the emitter firmware.
* Merge with current sView version. Probably this will be a lot of work due to the above...

#### Credits

* sView by Kirill Gavrilov Tartynskih, see https://sview.ru/en/
* RP2040-3D-Vision-Emitter by NTM-3D, see https://github.com/NTM-3D/RP2040-3D-Vision-Emitter
* libnvstusb by eruffaldi, see https://github.com/eruffaldi/libnvstusb
* libusb, see https://github.com/libusb/libusb
* Various other libraries and software packages used by sView.
* Peter of open3doled, see https://github.com/open3doled/open-3d-oled
* 3DJ ThreeDeeJay, see https://github.com/ThreeDeeJay/sview/tree/master?tab=readme-ov-file

