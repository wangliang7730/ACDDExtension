//
//  CodeGenResouceBirdge.cpp
//  AaptExt
//
//  Created by BunnyBlue on 7/23/15.
//  Copyright (c) 2015 BunnyBlue. All rights reserved.
//

#include "CodeGenResouceBirdge.h"
string CodeGenResouceBirdge::genResourceBridgeClass(){
    string content("//auto gen CodeGenResouceBirdge class \n");
    content.append("#ifndef __OpenAtlasResourceBridge__\n");
    content.append("#define __OpenAtlasResourceBridge__\n");
    content.append("class OpenAtlasResourceBridge{\n");
    content.append("public:\n");
    content.append(" int  getResourceId(std::string type,std::string resName);");
    content.append("};\n");
    content.append("#endif /* defined(__OpenAtlasResourceBridge__) */");
    
    return content;
    
};
std::string CodeGenResouceBirdge::genResourceBridgeHeader(){
  

    return "";
};

string CodeGenResouceBirdge::genFunctionBridge_getResource(){
    string  content("//auto gen function  OpenAtlasResourceBridge::getResourceId\n");
    content.append("int  getResourceId(string type,string resName){\n");
    CodeGen mCodeGen;
   
    
    
    int arrayIndex=0;
    for(arrayIndex=0;arrayIndex< sizeof( mCodeGen.resTypeList)/sizeof(string);arrayIndex++){
        string funName( mCodeGen.resTypeList[arrayIndex]);
       // f
        content.append(" if (!type.compare(\"").append(funName);
        content.append("\")){\n");
        funName[0] = toupper(funName[0]);
        content.append("return   OpenAtlasResource::getInstance()->get").append(funName);
        content.append("(resName);\n");
        content.append("};\n");
        
        
    }
    content.append("};\n\n");
    
    return content;
};
