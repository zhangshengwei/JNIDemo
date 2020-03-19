# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

### 指定 Cmake 需要的最低版本
cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

## 创建和命名该库
add_library( # Sets the name of the library.
        native-lib    ## 库的名字，取名为 native-lib，将会生成一个命名为 libnative-lib.so 的库。

        # Sets the library as a shared library.
        # 这个参数表示共享so库文件，也就是在Run项目或者build项目时会在目录
        # intermediates\transforms\mergeJniLibs\debug\folders\2000\1f\main下生成so库文。
        # 此外，so库文件都会在打包到.apk里面，可以通过选择菜单栏的Build->Analyze Apk…*查看apk中是否存在so库文件，一般它会存放在lib目录下。
        SHARED   ## 指定库的类型，一般为 SHARED，即动态库（以 .so 为后缀），还有一种是静态库 STATIC，即静态库（以 .a 为后缀）

        # Provides a relative path to your source file(s).
        native-lib.cpp  ## 指定该库使用的源文件路径
        JNILogUtils.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

# 设置链接动态库或者静态库
target_link_libraries( # Specifies the target library.
        native-lib

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})


