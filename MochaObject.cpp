#include <MochaObject.h>
#include <SceneManager.h>

namespace Mocha
{

/******************************************/
CSceneManager* CMochaObject::_currentSceneManager = NULL;
/******************************************/

/******************************************/
CMochaObject::CMochaObject()
/******************************************/
{
}

/******************************************/
CMochaObject::~CMochaObject()
/******************************************/
{
}

/******************************************/
CSceneManager* CMochaObject::CurrentSceneManager()
/******************************************/
{
    return(_currentSceneManager);
}

/******************************************/
void CMochaObject::CurrentSceneManager(CSceneManager* sceneManager)
/******************************************/
{
    _currentSceneManager = sceneManager;
}

};
