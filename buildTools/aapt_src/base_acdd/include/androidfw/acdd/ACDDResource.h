#ifndef __AaptExt__ACDDResource__
#define __AaptExt__ACDDResource__
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;
class ACDDResource {
map<std::string,int> animMaps;
map<std::string,int> animatorMaps;
map<std::string,int> arrayMaps;
map<std::string,int> attrMaps;
map<std::string,int> boolMaps;
map<std::string,int> colorMaps;
map<std::string,int> dimenMaps;
map<std::string,int> drawableMaps;
map<std::string,int> fractionMaps;
map<std::string,int> idMaps;
map<std::string,int> integerMaps;
map<std::string,int> interpolatorMaps;
map<std::string,int> layoutMaps;
map<std::string,int> menuMaps;
map<std::string,int> mipmapMaps;
map<std::string,int> pluralsMaps;
map<std::string,int> rawMaps;
map<std::string,int> stringMaps;
map<std::string,int> styleMaps;
map<std::string,int> transitionMaps;
map<std::string,int> xmlMaps;



public:
    static ACDDResource* getInstance()
    {
        static ACDDResource instance;
        return &instance;
    }
// start gen function anim


void setAnim(std::string resName,int resId);
int getAnim(std::string resName);
// end gen function anim


// start gen function animator


void setAnimator(std::string resName,int resId);
int getAnimator(std::string resName);
// end gen function animator


// start gen function array


void setArray(std::string resName,int resId);
int getArray(std::string resName);
// end gen function array


// start gen function attr


void setAttr(std::string resName,int resId);
int getAttr(std::string resName);
// end gen function attr


// start gen function bool


void setBool(std::string resName,int resId);
int getBool(std::string resName);
// end gen function bool


// start gen function color


void setColor(std::string resName,int resId);
int getColor(std::string resName);
// end gen function color


// start gen function dimen


void setDimen(std::string resName,int resId);
int getDimen(std::string resName);
// end gen function dimen


// start gen function drawable


void setDrawable(std::string resName,int resId);
int getDrawable(std::string resName);
// end gen function drawable


// start gen function fraction


void setFraction(std::string resName,int resId);
int getFraction(std::string resName);
// end gen function fraction


// start gen function id


void setId(std::string resName,int resId);
int getId(std::string resName);
// end gen function id


// start gen function integer


void setInteger(std::string resName,int resId);
int getInteger(std::string resName);
// end gen function integer


// start gen function interpolator


void setInterpolator(std::string resName,int resId);
int getInterpolator(std::string resName);
// end gen function interpolator


// start gen function layout


void setLayout(std::string resName,int resId);
int getLayout(std::string resName);
// end gen function layout


// start gen function menu


void setMenu(std::string resName,int resId);
int getMenu(std::string resName);
// end gen function menu


// start gen function mipmap


void setMipmap(std::string resName,int resId);
int getMipmap(std::string resName);
// end gen function mipmap


// start gen function plurals


void setPlurals(std::string resName,int resId);
int getPlurals(std::string resName);
// end gen function plurals


// start gen function raw


void setRaw(std::string resName,int resId);
int getRaw(std::string resName);
// end gen function raw


// start gen function string


void setString(std::string resName,int resId);
int getString(std::string resName);
// end gen function string


// start gen function style


void setStyle(std::string resName,int resId);
int getStyle(std::string resName);
// end gen function style


// start gen function transition


void setTransition(std::string resName,int resId);
int getTransition(std::string resName);
// end gen function transition


// start gen function xml


void setXml(std::string resName,int resId);
int getXml(std::string resName);
// end gen function xml
protected:
    struct Object_Creator
    {
        Object_Creator()
        {
            ACDDResource::getInstance();
        }
    };
    static Object_Creator _object_creator;

    ACDDResource(){};
    ~ACDDResource() {}

};
#endif
