//auto gen by aaptExt#include "OpenAtlasResource.h"
include "OpenAtlasResource.h"
int OpenAtlasResource::getAnim(std::string resName){
        map<string, int>::iterator itr =animMaps.find(resName);
        if (itr == animMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setAnim(std::string resName,int resVal){
        animMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getAnimator(std::string resName){
        map<string, int>::iterator itr =animatorMaps.find(resName);
        if (itr == animatorMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setAnimator(std::string resName,int resVal){
        animatorMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getArray(std::string resName){
        map<string, int>::iterator itr =arrayMaps.find(resName);
        if (itr == arrayMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setArray(std::string resName,int resVal){
        arrayMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getAttr(std::string resName){
        map<string, int>::iterator itr =attrMaps.find(resName);
        if (itr == attrMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setAttr(std::string resName,int resVal){
        attrMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getBool(std::string resName){
        map<string, int>::iterator itr =boolMaps.find(resName);
        if (itr == boolMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setBool(std::string resName,int resVal){
        boolMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getColor(std::string resName){
        map<string, int>::iterator itr =colorMaps.find(resName);
        if (itr == colorMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setColor(std::string resName,int resVal){
        colorMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getDimen(std::string resName){
        map<string, int>::iterator itr =dimenMaps.find(resName);
        if (itr == dimenMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setDimen(std::string resName,int resVal){
        dimenMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getDrawable(std::string resName){
        map<string, int>::iterator itr =drawableMaps.find(resName);
        if (itr == drawableMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setDrawable(std::string resName,int resVal){
        drawableMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getFraction(std::string resName){
        map<string, int>::iterator itr =fractionMaps.find(resName);
        if (itr == fractionMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setFraction(std::string resName,int resVal){
        fractionMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getId(std::string resName){
        map<string, int>::iterator itr =idMaps.find(resName);
        if (itr == idMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setId(std::string resName,int resVal){
        idMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getInteger(std::string resName){
        map<string, int>::iterator itr =integerMaps.find(resName);
        if (itr == integerMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setInteger(std::string resName,int resVal){
        integerMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getInterpolator(std::string resName){
        map<string, int>::iterator itr =interpolatorMaps.find(resName);
        if (itr == interpolatorMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setInterpolator(std::string resName,int resVal){
        interpolatorMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getLayout(std::string resName){
        map<string, int>::iterator itr =layoutMaps.find(resName);
        if (itr == layoutMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setLayout(std::string resName,int resVal){
        layoutMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getMenu(std::string resName){
        map<string, int>::iterator itr =menuMaps.find(resName);
        if (itr == menuMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setMenu(std::string resName,int resVal){
        menuMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getMipmap(std::string resName){
        map<string, int>::iterator itr =mipmapMaps.find(resName);
        if (itr == mipmapMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setMipmap(std::string resName,int resVal){
        mipmapMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getPlurals(std::string resName){
        map<string, int>::iterator itr =pluralsMaps.find(resName);
        if (itr == pluralsMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setPlurals(std::string resName,int resVal){
        pluralsMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getRaw(std::string resName){
        map<string, int>::iterator itr =rawMaps.find(resName);
        if (itr == rawMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setRaw(std::string resName,int resVal){
        rawMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getString(std::string resName){
        map<string, int>::iterator itr =stringMaps.find(resName);
        if (itr == stringMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setString(std::string resName,int resVal){
        stringMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getStyle(std::string resName){
        map<string, int>::iterator itr =styleMaps.find(resName);
        if (itr == styleMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setStyle(std::string resName,int resVal){
        styleMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getTransition(std::string resName){
        map<string, int>::iterator itr =transitionMaps.find(resName);
        if (itr == transitionMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setTransition(std::string resName,int resVal){
        transitionMaps.insert(std::pair<std::string, int>(resName,resVal));

}

int OpenAtlasResource::getXml(std::string resName){
        map<string, int>::iterator itr =xmlMaps.find(resName);
        if (itr == xmlMaps.end()) {
                return 0x0000;
        }
        return itr->second;
}



void OpenAtlasResource::setXml(std::string resName,int resVal){
        xmlMaps.insert(std::pair<std::string, int>(resName,resVal));

}
