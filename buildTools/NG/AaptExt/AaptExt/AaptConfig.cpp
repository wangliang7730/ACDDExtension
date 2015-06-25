//
//  AaptConfig.cpp
//  AaptExt
//
//  Created by BunnyBlue on 6/25/15.
//  Copyright © 2015 BunnyBlue. All rights reserved.
//

#include "AaptConfig.h"
AaptConfig::Object_Creator AaptConfig::_object_creator;

std::string   inline delSpaces(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

bool  acceptKey(std::string key){

    if(key.compare(AAPT_CONFIG_PKG)==0){
        return true;
    }
    if (key.compare(AAPT_CONFIG_PREBUILD_PKG_PATH)==0) {
        return  true;
    }
    if (key.compare(AAPT_CONFIG_PKG_GROUP_ID)==0) {
        return  true;
    }
    if (key.compare(AAPT_CONFIG_PKG_VERSION_NAME)==0) {
        return true;
    }
    
    return  false;
    
}
void AaptConfig::read_file(std::istream& is)
{
    
    options.clear();
    for(;;) {
        std::string line;
        std::getline(is, line);
        if(!is) break;
        std::istringstream is_line(line);
            std::string key;
            if( std::getline(is_line, key, '=') )
            {
                std::string value;
                if( std::getline(is_line, value) ){
                    key=delSpaces(key);
                    value=delSpaces(value);
                    if (acceptKey(key)) {
                          options.insert(std::pair<std::string, std::string>(key,value));
                    }else{
                        std::cout<<"unknown key!!! "<<key<<"\n";
                    }
                  
              
                }
            }

    }
    if(!is.eof()) {
        return;
    }
}
std::string AaptConfig::getConfigByKey(const std::string key){
    map<string,string>::iterator itr=options.find(key);
    if (itr==options.end()) {
        return  nullptr;
    }
    return itr->second;

}
void AaptConfig::initConfigFile(std::string path){
    std::ifstream ifs( path.c_str());
    if(!ifs.good()) {
    
        return;
    }
    read_file(ifs);

}