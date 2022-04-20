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

#交叉编译Linux
crosstool-ng 

#MSV2017 qt5 clang
#VS 环境变量
VSDIR=C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise
INCLUDE=VSDIR\VC\include;C:\Program Files (x86)\Windows Kits\10\Include\10.0.16299.0\ucrt
LIB=VSDIR\VC\lib\amd64;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.16299.0\ucrt\x64;C:\Program Files (x86)\Windows Kits\8.1\Lib\winv6.3\um\x64
PATH=VSDIR\Common7\IDE;VSDIR\VC\bin

#MSYS2 qt5 clang
pacman -S mingw-w64-i686-qt5 mingw-w64-i686-qt5-static mingw-w64-i686-clang
pacman -S mingw-w64-x86_64-qt5 mingw-w64-x86_64-qt5-static mingw-w64-x86_64-clang

使用 MinGW 的，要设置：
C_INCLUDE_PATH
CPLUS_INCLUDE_PATH
使用 Visual C++ 的，要设置：
INCLUDE

附加的链接库
MinGW 设置LIBRARY_PATH
VisualC++ 设置LIB

C_INCLUDE_PATH=%MINGW_HOME%\include
CPLUS_INCLUDE_PATH=%MINGW_HOME%\include;%MINGW_HOME%\lib\gcc\mingw32\%MINGW_VERSION%\include;%MINGW_HOME%\lib\gcc\mingw32\%MINGW_VERSION%\include\c++;%MINGW_HOME%\lib\gcc\mingw32\%MINGW_VERSION%\include\c++\mingw32;%MINGW_HOME%\lib\gcc\mingw32\%MINGW_VERSION%\include\c++\backward

LLVM

clang++ -v hello.c
