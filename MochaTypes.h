/*****************************************************************************/
// Filename: MochaTypes.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef MOCHA_TYPES_H_DEFINED
#define MOCHA_TYPES_H_DEFINED

#include <Point.h>
#include <vector>
#include <stack>
#include <string>
#include <map>
using std::vector;
using std::stack;
using std::string;
using std::map;

namespace Mocha
{

class CSceneNode;
class CBoundAreaNode;
class CDOFNode;
class CMapSystemNode;
class CGeoNode;
class CProjectionNode;

typedef vector<CSceneNode*> SceneNodeList;

typedef stack<CBoundAreaNode*> BoundAreaNodeStack;
typedef stack<CMapSystemNode*> MapSystemNodeStack;
typedef stack<CProjectionNode*> ProjectionNodeStack;

enum MochaEventType
{
    ME_MOUSE_LEFT_DOWN         = 1,
    ME_MOUSE_LEFT_UP           = 2,
    ME_MOUSE_LEFT_DOUBLECLICK  = 4,
    ME_MOUSE_MOVE              = 8,
    ME_MOUSE_RIGHT_DOWN        = 16,
    ME_MOUSE_RIGHT_UP          = 32,
    ME_MOUSE_RIGHT_DOUBLECLICK = 64,
    ME_KEY_DOWN                = 128,
    ME_KEY_UP                  = 256,
    ME_WINDOW_RESIZE           = 512,
    ME_WINDOW_MOVE             = 1024,
    ME_PRERENDER               = 2048,
    ME_UPDATE                  = 4096
};

};
#endif
