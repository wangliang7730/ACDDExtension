//
//  CodeGen.cpp
//  AaptExt
//
//  Created by BunnyBlue on 7/11/15.
//  Copyright (c) 2015 BunnyBlue. All rights reserved.
//

#include "CodeGen.h"
string CodeGen_internal_genClass_maps(CodeGen *mCodeGen);
void CodeGen::genGetterFunction(string resType, string resName){
        //    map<string, int>::iterator itr = mValue.find(inName);
        //    if (itr == mValue.end())
        //    {
        //        throw "No value could be found.";
        //    }
        //
        //    int value = itr->second;
        cout<<"void gen "<<resType <<" function  type"<<resType<<endl;


        std::locale loc;
        string funName(resType);

        funName[0] = toupper(funName[0]);


        cout<<"//function auto gen bye AaptExt\n";
        cout<<"int "<<OPENATLAS_NS_RESOURCE_CLASS<<"::get"<<funName<<"(std::string resType,std::string resName){\n"
            <<"map<string, int>::iterator itr ="<<getFunctionMapName(resType)<<".find("<<resName<<");\n"//gen  map find
            <<" if (itr == "<<getFunctionMapName(resType)<<".end()){\n"
            <<" return 0x0000;\n}\n"
            <<"return itr->second;"
            <<" \n}"<<endl;
}

void CodeGen::genSetterFuntion(string name, CodeGen::FUN_TYPE functionType){
//    map<string, int>::iterator itr = mValue.find(inName);
//    if (itr == mValue.end())
//    {
//        throw "No value could be found.";
//    }
//
//    int value = itr->second;
        cout<<"void gen "<<name <<" function  type"<<functionType<<endl;

        if (functionType==FUN_TYPE_FUNCTION_GET) {//produce  get function
                std::locale loc;
                string funName(name);

                funName[0] = toupper(funName[0]);


                cout<<"//function auto gen bye AaptExt\n";
                cout<<"int "<<OPENATLAS_NS_RESOURCE_CLASS<<"::get"<<funName<<"(std::string resType,std::string resName){\n"
                    <<"map<string, int>::iterator itr ="<<getFunctionMapName(name)<<".find("//gen  map find
                    <<"; }"<<endl;
        }


}

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
    
        contentRESOURCE_CLASS.append("};\n");
        //gen header body end


        contentRESOURCE_CLASS.append("#endif ");
        cout<<contentRESOURCE_CLASS;

        return contentRESOURCE_CLASS;
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
