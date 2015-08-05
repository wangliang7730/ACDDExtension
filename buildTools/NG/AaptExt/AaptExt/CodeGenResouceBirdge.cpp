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
    content.append(" int  getResourceId(std::string type,std::string resName);\n");
    content.append(" void cacheSharedResource();\n");
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
//procese  shared resource
string CodeGenResouceBirdge::genFunctionBridge_AnalyticsSharedResource(){
    string  content("//auto gen function  OpenAtlasResourceBridge::AnalyticsSharedResource\n");
    content.append("void  cacheSharedResource(){\n");
    CodeGen mCodeGen;
    content.append("std::string dumpline;\n");
    content.append("std::string type;\n");
//    std::istringstream streamStr(ret);
//    std::string line;
//    string  type="";
//    while (std::getline(streamStr, line)) {
//        
//        //gen class
//        if (line.find("final class") != string::npos) {
//            
//            type=getInfoType(line);
//            
//        }
//        
//        if (line.find("public static final int") != string::npos) {
    content.append(" while (std::getline(streamStr, dumpline)) {\n");
    content.append(" if (line.find(\"final class\") != string::npos) {\n\n");
    content.append("type=getIDType(line);");
    content.append("\n}\n");
    content.append(" if (line.find(\"public static final int\") != string::npos) {\n");
    int arrayIndex=0;
    for(arrayIndex=0;arrayIndex< sizeof( mCodeGen.resTypeList)/sizeof(string);arrayIndex++){
        string funName( mCodeGen.resTypeList[arrayIndex]);
        // f
        content.append(" if (!type.compare(\"").append(funName);
        content.append("\")){\n");
        funName[0] = toupper(funName[0]);
        content.append("   OpenAtlasResource::getInstance()->set").append(funName);
        content.append("(getSharedId(dumpline),getSharedValue(dumpline)");
        content.append( ");\n");
        content.append("}else\n");
        
        
    }
    content.append("{}\n" );
    content.append("}\n}\n");
    content.append("};\n\n");
    
    return content;
};
