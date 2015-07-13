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
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
   
   AaptConfig *mAaptConfig= AaptConfig::getInstance();
    mAaptConfig->initConfigFile("/Users/BunnyBlue/Downloads/aapt_config.txt");
    cout<<mAaptConfig->getConfigByKey(AAPT_CONFIG_PKG);
    testCodeGen();
    return 0;
}


void  testCodeGen(){
    CodeGen mCode;
    ;
    testFile(mCode.genOPENATLAS_NS_RESOURCE_CLASS());
   // mCode.genSetterFuntion("drawable", CodeGen::FUN_TYPE_FUNCTION_GET);
    mCode.genGetterFunction("drawable", "icon");
    
    
    

}
void  testFile(std::string content){
    CodeGenFileUtil mCodeGen;
    mCodeGen.genFile("/Users/BunnyBlue/Downloads/aapt.h", content);
    
}