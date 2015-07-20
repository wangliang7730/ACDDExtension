//
//  main.cpp
//  AaptExt
//
//  Created by BunnyBlue on 6/25/15.
//  Copyright © 2015 BunnyBlue. All rights reserved.
//

#include <iostream>
#include "AaptConfig.h"

#include "CodeGen.h"
#include "CodeGenFileUtil.h"
void  testCodeGen();
void  testFile(std::string content);
void  genOpenAtlasResourceHeader();
void  genOpenAtlasResourceImpl();
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
   
   AaptConfig *mAaptConfig= AaptConfig::getInstance();
    mAaptConfig->initConfigFile("/Users/BunnyBlue/Downloads/aapt_config.txt");
    cout<<mAaptConfig->getConfigByKey(AAPT_CONFIG_PKG);
    //testCodeGen();
    genOpenAtlasResourceHeader();
    genOpenAtlasResourceImpl();
    return 0;
}


void  testCodeGen(){
    CodeGen mCode;
    ;
    //testFile(mCode.genOPENATLAS_NS_RESOURCE_CLASS());
      testFile(mCode.genOPENATLAS_NS_RESOURCE_CLASS_PUBLIC_FUNCTION_IMPL());
   // mCode.genSetterFuntion("drawable", CodeGen::FUN_TYPE_FUNCTION_GET);
   // mCode.genGetterFunction("drawable", "icon");
    
    
    

}
void  genOpenAtlasResourceHeader(){
     CodeGen mCode;
    CodeGenFileUtil mCodeGen;
    mCodeGen.genFile("/Users/BunnyBlue/Downloads/aapt.h", mCode.genOPENATLAS_NS_RESOURCE_CLASS());
}

void  genOpenAtlasResourceImpl(){
    CodeGen mCode;
    CodeGenFileUtil mCodeGen;
    mCodeGen.genFile("/Users/BunnyBlue/Downloads/aapt.cpp", mCode.genOPENATLAS_NS_RESOURCE_CLASS_PUBLIC_FUNCTION_IMPL());
}
void  testFile(std::string content){
    CodeGenFileUtil mCodeGen;
    mCodeGen.genFile("/Users/BunnyBlue/Downloads/aapt.h", content);
    
}