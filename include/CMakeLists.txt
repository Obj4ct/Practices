# 使用 GLOB_RECURSE 命令查找项目中所有匹配 *.h* 模式的头文件，并将结果存储在 PUBLIC_HEADERS 变量中。这里的 *.h* 通配符表示匹配项目中所有扩展名为 .h 或 .hpp 的头文件。
file(GLOB_RECURSE PUBLIC_HEADERS
       *.h*
        )
# 将项目中所有匹配 *.cpp 模式的源代码文件的列表存储在 SOURCE_FILES 变量中
file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# 头文件会在以下目录进行搜索
include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

# 替换YOUR_LIBRARY_NAME为库名 将库的名称设置为 YOUR_LIBRARY_NAME
set(LIBRARY_NAME "practices_lib")

# 选择你需要生成的库

add_library(${LIBRARY_NAME} STATIC ${SOURCE_FILES}) # 配置静态库 静态库在链接时会被直接嵌入到可执行文件中，使得生成的可执行文件比较大。
# add_library(${LIBRARY_NAME} SHARED ${SOURCE_FILES}) # 配置动态库 动态库在程序运行时会被动态加载，使得生成的可执行文件比较小，但运行时需要依赖相应的动态库文件。
