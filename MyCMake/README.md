# MyCMake

Some CMake commands and solutions.

## CMake Commands

| Command | Description |
| :--- | :--- |
| cmake_minimum_required(VERSION \<min\>) | CMake version |
| project(\<PROJECT-NAME\>) | Project name |
| add_executable(\<name\><br/>&emsp;\<sources...\><br/>) | Add an executable to the project using the specified source files |
| set(\<variable\> \<value\>) | Set a normal variable to a given value |
| target_include_directories(\<target\><br/>&emsp;[INTERFACE\|PUBLIC\|PRIVATE]<br/>&emsp;&emsp;\<items...\><br/>) | Add include directories to a target |
| add_library(\<name\> [STATIC\|SHARED\|MODULE]<br/>&emsp;\<sources...\><br/>) | Add a library to the project using the specified source files |
| target_link_libraries(\<target\><br/>&emsp;[PRIVATE\|PUBLIC\|INTERFACE]<br/>&emsp;&emsp;\<items...\><br/>) | Specify libraries to use when linking a given target and/or its dependents |
| add_library(\<name\> ALIAS \<target\>) | Create an alias target |
| install(TARGETS \<targets...\><br/>&emsp;[ARCHIVE\|LIBRARY\|RUNTIME\|...] DESTINATION \<dir\><br/>) | Install targets to the specified destination |
| install(DIRECTORY \<dirs...\><br/>&emsp;DESTINATION \<dir\><br/>) | Install directories to the specified destination |
| install(FILES \<files...\><br/>&emsp;DESTINATION \<dir\><br/>) | Install files to the specified destination |
| message(\<mode\> "message text") | Log a message |
| set(\<variable\> \<value...\> CACHE \<type\> \<docstring\> FORCE) | Set cache entry |
| set_property(CACHE \<entries...\> PROPERTY \<name\> \<values...\>) | Set a named property in cache scope |
| target_compile_definitions(\<target\><br/>&emsp;[INTERFACE\|PUBLIC\|PRIVATE] \<items...\><br/>) | Add compile definitions to a target |

## Solutions

- [CMake target_include_directories meaning of scope](https://stackoverflow.com/questions/26243169/cmake-target-include-directories-meaning-of-scope)
- [CMake target_link_libraries Interface Dependencies](https://stackoverflow.com/questions/26037954/cmake-target-link-libraries-interface-dependencies)
