//
//  CodeGen.h
//  AaptExt
//
//  Created by BunnyBlue on 7/11/15.
//  Copyright (c) 2015 BunnyBlue. All rights reserved.
//

#ifndef __AaptExt__CodeGen__
#define __AaptExt__CodeGen__

#include <stdio.h>
#include <string>
#include <iostream>
#include <locale> 
#include <algorithm>
#include <map>
using namespace std;
#define  OPENATLAS_NS_RESOURCE_CLASS "OpenAtlasResource"
class CodeGen{


public:
     enum FUN_TYPE {FUN_TYPE_INT, FUN_TYPE_STRING, FUN_TYPE_VOID,FUN_TYPE_FUNCTION_SET,FUN_TYPE_FUNCTION_GET};
    //gen environment  valid function
    
    string  genOPENATLAS_NS_RESOURCE_CLASS();
    string  genOPENATLAS_NS_RESOURCE_CLASS_PUBLIC_FUNCTION();
      string  genOPENATLAS_NS_RESOURCE_CLASS_PUBLIC_FUNCTION_IMPL();
    void  genEnvValidFunction();
    void  genSetFuntion();
    string getFunctionMapName(string typeName);
//    void genGetterFunction(string resType,string resName);
//    void  genSetterFuntion(string  name,FUN_TYPE  functionTYpe);
    
    
    const string resTypeList[21]={//resource type ,version  android  22
        "anim",
        "animator",
        "array",
        "attr",
        "bool",
        "color",
        "dimen",
        "drawable",
        "fraction",
        "id",
        "integer",
        "interpolator",
        "layout",
        "menu",
        "mipmap",
        "plurals",
        "raw",
        "string",
        "style",
        "transition",
        "xml"
    };
};

#endif /* defined(__AaptExt__CodeGen__) */
