//
//  CodeGenFileUtil.cpp
//  AaptExt
//
//  Created by BunnyBlue on 7/12/15.
//  Copyright (c) 2015 BunnyBlue. All rights reserved.
//
#include <fstream>
#include "CodeGenFileUtil.h"
void CodeGenFileUtil::genFile(std::string  filePath, std::string  content){
    std::ofstream outfile (filePath,std::ofstream::trunc);
    outfile.write (content.c_str(),strlen(content.c_str()));
    outfile.close();
    

}