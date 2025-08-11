#ifndef SCIPTCONTAINER_H
#define SCIPTCONTAINER_H
#include <vector>
#include <memory>
#include "ScriptRead.h"

class ScriptContainer
{
public:
    void addScript(const ScriptReader& script)
    {
        scripts.push_back(script); // makes a copy
    }

    std::vector<ScriptReader>& getScripts()
    {
        return scripts;
    }


private:
    std::vector<ScriptReader> scripts;
};



#endif