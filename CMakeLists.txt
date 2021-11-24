cmake_minimum_required(VERSION 3.15)
project(wolf_own)

set(CMAKE_CXX_STANDARD 20)

add_executable(wolf_own baumbartWolfHelp/baumbartWolf_beta.h
		baumbartLibraryPorts/baumbartDos.h
		wolfsrc/main.cpp wolfsrc/wl_menu.h wolfsrc/id_in.h wolfsrc/id_heads.h wolfsrc/version.h wolfsrc/wl_menu.cpp wolfsrc/wl_def.h baumbartWolfHelp/baumbartWolf_dataTypes.h wolfsrc/foreign.h baumbartAdditions/CSF/csf_file.cpp baumbartAdditions/CSF/csf_file.h baumbartAdditions/CSF/csf.h)