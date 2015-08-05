//
//  AaptConfig.h
//  AaptExt
//
//  Created by BunnyBlue on 6/25/15.
//  Copyright © 2015 BunnyBlue. All rights reserved.
//

#ifndef AaptConfig_h
#define AaptConfig_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#define AAPT_CONFIG_PKG "pkg"//define    prebuild  source  package name
#define AAPT_CONFIG_PREBUILD_PKG_PATH "preBuildJarPath"//prebuild Shared  Package Resouces
#define AAPT_CONFIG_PKG_GROUP_ID "pkgGroupId"// plugin package group id
#define AAPT_CONFIG_PKG_VERSION_NAME "versionName"//plugin package versionName
using namespace std;
class AaptConfig
{
public:
    static AaptConfig* getInstance()
    {
        static AaptConfig instance;
        return &instance;
    }
  void  initConfigFile(std::string path);
    std::string getConfigByKey(const std::string key);
  
protected:
    struct Object_Creator
    {
        Object_Creator()
        {
            AaptConfig::getInstance();
        }
    };
    static Object_Creator _object_creator;
    std::string _conFilePath;
    
    std::map<std::string, std::string> options;
    void read_file(std::istream& is);
    AaptConfig() {
    
    }
    ~AaptConfig() {}
};

#endif /* AaptConfig_cpp */
/*
 config  should be
 pkg=io.github.bunnyblue.pkg
 preBuildJarPath=/Users/Downloads/prebuild.jar
 pkgGroupId=0x1a
 unusedkey=unusedvalue
 */
