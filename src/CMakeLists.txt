#设置了 C++ 编译器的标志，向现有的编译器标志中添加了 -frtti 标志。-frtti 用于开启运行时类型信息（RTTI），允许在运行时进行类型检查。
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti")
 # 设置可执行文件的输出路径为项目根目录下的 out 文件夹
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out)
# 配置头文件search目录 这样编译时就能找到在这个目录下的头文件。
include_directories(
        ${PROJECT_SOURCE_DIR}/include
)
# 使用 GLOB 命令获取当前目录下所有的 .cpp 文件，存储在 files 变量中。
file(GLOB files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

#遍历文件夹下的所有文件(遍历了 files 列表中的所有 .cpp 文件)
foreach(file ${files})
    #利用正则表达式将 .cpp 文件名的扩展名部分去除，将得到的文件名赋给 ${exe} 变量。
    string(REGEX REPLACE "(.+).cpp$" "\\1" exe ${file})
    #为每个 .cpp 文件创建一个相应的可执行文件（使用上一步生成的 ${exe} 变量作为可执行文件的名称）。
    add_executable(${exe} ${file})

    #替换依赖库名称YOUR_LIBRARY_NAME,名称就是在include下  cmake文件中定义的LIBRARY_NAME
    target_link_libraries(${exe} practices_lib ${dependency_LIBS})    
    # 安装可执行文件
    # 将可执行文件 ${exe} 安装到指定的目标位置 "out" out在第四行set过了
    install(TARGETS ${exe}
        RUNTIME
        DESTINATION "out"
        BUNDLE DESTINATION "out"
        )
endforeach()
