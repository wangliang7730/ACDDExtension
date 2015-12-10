//
// Copyright 2006 The Android Open Source Project
//
// Build resource files from raw assets.
//
#include "ACDDResourceImpl.h"
void acdd_parseResourceTable(){
std::string sharedResourceSymbol=ACDDAaptConfig::getInstance()->getSharedResourcePath();
                if(access(sharedResourceSymbol.c_str(),F_OK)==-1) {
                    fprintf(stderr, "PreDefine  Resource  Symbol file not access   ,process abort!!! \n");
                    exit(-0x01010000);
                }else{
                  fprintf(stderr, "PreDefine  Resource  Symbol  found \n");
sp<XMLNode> root = XMLNode::parse(sharedResourceSymbol.c_str());

Vector<sp<XMLNode> >mChildrenNodes= root->getChildren();
for (size_t i=0; i<mChildrenNodes.size(); i++) {
        sp<XMLNode> mCurrntNode=  mChildrenNodes.itemAt(i);
        //    <public type="attr" name="theme" id="0x01010000" />

        Vector<XMLNode::attribute_entry> mAttributes=mCurrntNode->getAttributes();
        std::string type;
        std::string name;
        int value=0;
        for (size_t i=0; i<mAttributes.size(); i++) {
                const XMLNode::attribute_entry& ae(mAttributes.itemAt(i));

              //  String8(attr->string).string()
                if(!ae.name.compare(android::String16("type"))){
                  type=  String8(ae.string).string();
                }else if (!ae.name.compare(android::String16("name"))) {
                  name=  String8(ae.string).string();
                }else if(!ae.name.compare(android::String16("id"))){
                    value=   strtol(String8(ae.string).string(),NULL,16);
                }
        }
        ACDDResourceBridge::getInstance()->addResourceSymbol(type,name,value);


}

                }

}

// void ACDD_old_injectmanifest(Bundle* bundle){
//
//
//         String8 srcFile(bundle->getAndroidManifestFile());
//
//         AaptFile *mAaptFile=new AaptFile(srcFile.getPathLeaf(), AaptGroupEntry(), srcFile.getPathDir());
//
//         const sp<AaptFile> manifestFile(mAaptFile);
//
//         String8 manifestPath(bundle->getAndroidManifestFile());
//         fprintf(stderr, "ResourceShareOld dump info ..get default versionName%s\n",manifestPath.string());
//
//         // Generate final compiled manifest file.
//         //manifestFile->clearData();
//         sp<XMLNode> root = XMLNode::parse(bundle->getAndroidManifestFile());
//
//         if (root == NULL) {
//                 if(!access(bundle->getAndroidManifestFile(),0)) {}else{
//                         fprintf(stderr, "ResourceShareOld  found \n");
//                 }
//                 fprintf(stderr, "no node \n");
//                 return;
//         }
//         hack_massageManifest(root);
//
//
//         fprintf(stderr, "ResourceShareOld version ibundle->getAndroidManifestFile()7\n");
//
// }
// void hack_massageManifest( sp<XMLNode> root)
// {
//         root = root->searchElement(String16(), String16("manifest"));
//
//         const XMLNode::attribute_entry* attrlocal = root->getAttribute(
//                 String16(RESOURCES_ANDROID_NAMESPACE), String16("versionName"));
//         if (attrlocal != NULL) {
//                 fprintf(stderr, "ResourceShareOld version dump info ..get default versionName%s\n",strdup(String8(attrlocal->string).string()));
//                 char * versionNameMisc=strdup(String8(attrlocal->string).string()); //bunny
//                 if(access(versionNameMisc,F_OK)!=-1) {
//                         fprintf(stdout, "WARNING ACDD  you should use shared resoures!!!!!!!!!\n");
//                         ACDDAaptConfig::getInstance()->initConfigFile(versionNameMisc);
//                         fprintf(stdout, "update ACDD shared resoures in old modle%s\n");
//                 }
//
//
//
//         }
//
//
//
//
// }
