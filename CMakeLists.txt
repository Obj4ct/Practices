#编译选项(可选)
add_compile_options(
    -std=c++17      # 明确指定 C++17 标准
    -pedantic       # 严格遵循 C++ 标准，禁止非标准扩展
    -Wall           # 启用所有常规警告
    -Wextra         # 启用额外的警告
    -Werror         # 警告当作报错
)
#指定了构建该项目所需的 CMake 的最低版本为 3.21。这确保在运行时使用符合或高于指定版本的 CMake。
cmake_minimum_required(VERSION 3.21)
#定义了项目的名称为 projectName，并指定了该项目将会用到 C 和 C++ 编程语言。
project(practices C CXX)
#将 C++ 标准设置为 C++17，这表示编译器将会使用 C++17 的特性和语法规则。
set(CMAKE_CXX_STANDARD 17)
#强制要求使用设定的 C++ 标准。
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#禁用编译器的扩展特性，确保不会使用除标准以外的扩展功能
set(CMAKE_CXX_EXTENSIONS OFF) 
#生成 compile_commands.json 文件，该文件记录了编译器执行的命令，可用于编辑器和其他工具对代码进行分析和补全。
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

# 添加子模块 这意味着 CMake 会在这些子目录中寻找更多的 CMakeLists.txt 文件以构建这些模块
# 如果在其他文件中还有cmake并且与这个cmake有关系,那就需要在这下面包含其他文件夹
add_subdirectory(include)
add_subdirectory(src)
