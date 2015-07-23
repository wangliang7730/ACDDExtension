//
//  CodeGen.cpp
//  AaptExt
//
//  Created by BunnyBlue on 7/11/15.
//  Copyright (c) 2015 BunnyBlue. All rights reserved.
//

#include "CodeGen.h"
string CodeGen_internal_genClass_maps(CodeGen *mCodeGen);


string CodeGen::getFunctionMapName(string typeName){
        string mapName(typeName);
        mapName.append("Maps");
        return mapName;
}
string CodeGen::genOPENATLAS_NS_RESOURCE_CLASS(){
        string contentRESOURCE_CLASS("");

        contentRESOURCE_CLASS.append("#ifndef __AaptExt__OpenAtlasResource__\n");

        contentRESOURCE_CLASS.append("#define __AaptExt__OpenAtlasResource__\n");
        contentRESOURCE_CLASS.append("#include <stdio.h>\n");
        contentRESOURCE_CLASS.append("#include <string>\n");
        contentRESOURCE_CLASS.append("#include <iostream>\n");
        contentRESOURCE_CLASS.append("#include <map>\n");
        //gen header body start
       contentRESOURCE_CLASS.append("class OpenAtlasResource{\n");
        contentRESOURCE_CLASS.append( CodeGen_internal_genClass_maps(this));
        //gen header body end
    contentRESOURCE_CLASS.append(genOPENATLAS_NS_RESOURCE_CLASS_PUBLIC_FUNCTION());
    //gen  function start
    //gen function end;
    contentRESOURCE_CLASS.append("//gen  instance function\n");
    contentRESOURCE_CLASS.append("protected:\n");
    contentRESOURCE_CLASS.append("struct Object_Creator\n{\n");
    contentRESOURCE_CLASS.append(" Object_Creator()\n{\n");
    contentRESOURCE_CLASS.append("OpenAtlasResource::getInstance();\n");
    contentRESOURCE_CLASS.append("}\n};\n\n\n");
    contentRESOURCE_CLASS.append("static Object_Creator _object_creator;\n\n");
    contentRESOURCE_CLASS.append("OpenAtlasResource();\n\n"); contentRESOURCE_CLASS.append("~PreBuildResources() {};\n\n");
        contentRESOURCE_CLASS.append("};\n");
    


        contentRESOURCE_CLASS.append("#endif ");
        cout<<contentRESOURCE_CLASS;

        return contentRESOURCE_CLASS;
}
//gen  public  function
string CodeGen::genOPENATLAS_NS_RESOURCE_CLASS_PUBLIC_FUNCTION(){
    //void get
    string contentFunctions("public :\n");
    contentFunctions.append("static OpenAtlasResource* getInstance()\n{\n");
    contentFunctions.append(" static OpenAtlasResource instance;\n");
     contentFunctions.append(" return &instance;\n}\n");

    
    int arrayIndex=0;
    for(arrayIndex=0;arrayIndex< sizeof(resTypeList)/sizeof(string);arrayIndex++){
        string funName(resTypeList[arrayIndex]);
        
        funName[0] = toupper(funName[0]);
        contentFunctions.append("   // start gen function ").append(resTypeList[arrayIndex]).append("\n\n\n");
        contentFunctions.append("  void set");
        contentFunctions.append(funName);
        contentFunctions.append("(std::string resName,int resId);\n");//gen set
        
        contentFunctions.append("  int get");
        contentFunctions.append(funName);
        contentFunctions.append("(std::string resName);\n");
        
          contentFunctions.append("   // end gen function ").append(resTypeList[arrayIndex]).append("\n\n\n");
   
    }
    
    return contentFunctions;
    

}
//生成实现类
string CodeGen::genOPENATLAS_NS_RESOURCE_CLASS_PUBLIC_FUNCTION_IMPL()
{
    string contentFunImpl("//auto gen by aaptExt");
    contentFunImpl.append("#include \"OpenAtlasResource.h\"\n\n");
    
    
    int arrayIndex=0;
    for(arrayIndex=0;arrayIndex< sizeof(resTypeList)/sizeof(string);arrayIndex++){
        string funName(resTypeList[arrayIndex]);
         funName[0] = toupper(funName[0]);
        //gen  getter
        contentFunImpl.append("int ").append(OPENATLAS_NS_RESOURCE_CLASS);
        contentFunImpl.append("::get").append(funName);
        contentFunImpl.append("(std::string resName){\n");
        contentFunImpl.append("map<string, int>::iterator itr =");
                              
        contentFunImpl.append(getFunctionMapName(resTypeList[arrayIndex]));
        contentFunImpl.append(".find(resName);\n");
        contentFunImpl.append("if (itr == ").append(getFunctionMapName(resTypeList[arrayIndex])).append(".end()){\n");
        contentFunImpl.append("return 0x0000;\n}\n");
        contentFunImpl.append("return itr->second;");
        contentFunImpl.append(" \n}\n\n\n\n");
        
        //gen  getter end
        
        
        //get setter
        
        
       
        
        cout<<"//function auto gen bye AaptExt\n";
        
        contentFunImpl.append("void ").append(OPENATLAS_NS_RESOURCE_CLASS);
        contentFunImpl.append("::set").append(funName).append("(std::string resName,int resVal){\n");
        contentFunImpl.append(getFunctionMapName(resTypeList[arrayIndex]));
      
        contentFunImpl.append(".insert(std::pair<std::string, int>");
        contentFunImpl.append("(resName,resVal));\n");
 
          contentFunImpl.append(" \n}\n\n");
     
    
    }
    
    
    return contentFunImpl;
}
string CodeGen_internal_genClass_maps(CodeGen *mCodeGen){
    string contentClassMaps("");
    
    int arrayIndex=0;
    for(arrayIndex=0;arrayIndex< sizeof(mCodeGen->resTypeList)/sizeof(string);arrayIndex++){
        contentClassMaps.append("   map<std::string ,int> ");
        contentClassMaps.append(mCodeGen->resTypeList[arrayIndex]).append("Maps ;\n");
       
        cout<<"dump "<<mCodeGen->resTypeList[arrayIndex];
    }
    
    return contentClassMaps;

}
