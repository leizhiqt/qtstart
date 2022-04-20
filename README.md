QT5 example

#静态编译
#Perl-5.28.1
#python-3.8.0-embed-win32

#vs2017
#jom

#qt-everywhere-src-5.12.12

#第一步 
qt-everywhere-src-5.12.12\qtbase\mkspecs\common\msvc-desktop.conf
全部替换 -MD -MT

#vs 2017 x64  			64位
#vs 2017 x86_x64  兼容模式	32位
#
####交叉编译
#-platform 主机平台
#-xplatform 目标平台

#win32-msvc->winrt-x64-msvc2017
-platform win32-msvc -xplatform  winrt-x64-msvc2017

#mingw73_64->mingw73_64
-platform win32-g++ -xplatform  winrt-x64-msvc2017

#编译
..\qt-everywhere-src-5.12.12\configure.bat -prefix "E:\qt\5.12.12\5.12.12_msvc2017_32_static"  -platform win32-msvc 
	-static -release  -confirm-license -opensource  
	-qt-zlib -qt-libpng -qt-libjpeg -opengl desktop -qt-freetype 
	-nomake tests -nomake examples  
	-no-qml-debug -no-angle  -no-rpath -no-egl 
	-skip qtwayland -skip qtwebengine -skip qtmacextras 
	-skip qtandroidextras -skip qtsensors 
	-skip qtconnectivity -skip qtquickcontrols2 -skip qtspeech -skip qtmultimedia 
	-skip qtserialbus  -skip qt3d  -skip qtdoc 
	-mp

..\qt-everywhere-src-5.12.12\configure.bat -prefix "E:\qt\5.12.12\5.12.12_msvc2017_32_static"  -platform win32-msvc 
	-static -debug-and-release  -confirm-license -opensource  
	-qt-zlib -qt-libpng -qt-libjpeg -opengl desktop -qt-freetype 
	-nomake tests -nomake examples  
	-no-qml-debug -no-angle  -no-rpath -no-egl 
	-mp

jom
jom install

##Linux
https://download.qt.io/archive/qt/5.15/5.15.2/single/qt-everywhere-src-5.15.2.tar.xz
https://www.linuxfromscratch.org/patches/blfs/11.1/qt-everywhere-src-5.15.2-kf5.15-2.patch
  
dnf install libxcb libxcb-devel xcb-util xcb-util-devel xcb-util-devel libX11-devel libXrender-devel
dnf install flex bison gperf libicu-devel libxslt-devel ruby fontconfig-devel freetype-devel libXext-devel libXtst-devel libX11-devel

#编辑参数
-xplatform linux-g++-64 -platform linux-g++-64

#编译
patch -Np1 -i ../qt-everywhere-src-5.15.2-kf5.15-2.patch
mkdir build
cd build

../qt-everywhere-src-5.12.12/configure  -v -prefix /qt-5.15.2-win32-g++-static -platform win32-g++  \
	-static -release -confirm-license -opensource \
	-qt-zlib -qt-libpng -qt-libjpeg -opengl desktop -qt-freetype \
	-nomake tests -nomake examples \
	-no-qml-debug -no-angle -no-rpath -no-egl \
	-skip qtdoc

../qt-everywhere-src-5.15.2/configure -v -prefix /home/zhi/qt-5.15.2-linux64-static \
	-static -release -confirm-license -opensource \
	-qt-zlib -qt-libpng -qt-libjpeg -opengl desktop -qt-freetype \
	-nomake tests -nomake examples \
	-no-qml-debug -no-angle -no-rpath -no-egl \
	-skip qtwayland -skip qtwebengine -skip qtmacextras \
	-skip qtandroidextras -skip qtsensors \
	-skip qtconnectivity -skip qtquickcontrols2 -skip qtspeech -skip qtmultimedia \
	-skip qtserialbus  -skip qt3d -skip qtquick3d \
	-skip qtdoc

make -j12
make install
