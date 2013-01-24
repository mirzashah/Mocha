/*****************************************************************************/
// Filename: MochaObject.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef MOCHA_OBJECT_H_DEFINED
#define MOCHA_OBJECT_H_DEFINED

#include <cerrno>
#include <MaSUtilities.h>
#include <MochaTypes.h>
#ifdef WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>

using namespace MaSUtilities;

namespace Mocha
{

class CSceneManager;
class CMochaObject
{
    friend class CSceneManager;

    public:
        CMochaObject();
        virtual ~CMochaObject();

        CSceneManager*                  CurrentSceneManager();

    protected:
        template <typename T> vector<T> Append(const vector<T>& v1, const vector<T>& v2)
        {
            return(ContainerHelper::Append(v1,v2));
        }

        template <typename T> vector<T> Append(const T& v1, const vector<T>& v2)
        {
            return(ContainerHelper::Append(v1,v2));
        }

        template <typename T> vector<T> Append(const vector<T>& v1, const T& v2)
        {
            return(ContainerHelper::Append(v1,v2));
        }

        template <typename T> bool      Contains(const vector<T>& v, const T& item)
        {
            return(ContainerHelper::Contains(v,item));
        }

        template  <typename S, typename T> bool ContainsKey(const map<S,T>& m, const S& key)
        {
            return(ContainerHelper::ContainsKey(m,key));
        }

        template <typename T> vector<T> Construct(const T& firstItem)
        {
            return(ContainerHelper::Construct(firstItem));
        }

        template <typename T> int       FindIndex(const vector<T>& v, const T& item)
        {
            return(ContainerHelper::FindIndex(v, item));
        }

        template <typename T> T         FirstItem(const vector<T>& v)
        {
            return(ContainerHelper::FirstItem(v));
        }

        template <typename T> T         LastItem(const vector<T>& v)
        {
            return(ContainerHelper::LastItem(v));
        }

        template <typename T> vector<T> RemoveFirst(const vector<T>& v)
        {
            return(ContainerHelper::RemoveFirst(v));
        }

        template <typename T> vector<T> RemoveLast(const vector<T>& v)
        {
            return(ContainerHelper::RemoveLast(v));
        }

        template <typename T> vector<T> Remove(const vector<T>& v, const T& toRemove)
        {
            return(ContainerHelper::Remove(v,toRemove));
        }

        template <typename T> vector<T> Reverse(const vector<T>& v)
        {
            return(ContainerHelper::Reverse(v));
        }

        template <typename T> vector<T> SortAscending(const vector<T>& v)
        {
            return(ContainerHelper::SortAscending(v));
        }

        template <typename T> vector<T> SortAscending(const vector<T>& v, bool (*lessThanFunc)(T, T))
        {
            return(ContainerHelper::SortAscending(v, lessThanFunc));
        }

        template <typename T> vector<T> SortDescending(const vector<T>& v)
        {
            return(ContainerHelper::SortDescending(v));
        }

        template <typename T> vector<T> SortDescending(const vector<T>& v, bool (*lessThanFunc)(T, T))
        {
            return(ContainerHelper::SortDescending(v, lessThanFunc));
        }

        template <typename T> void Swap(T& v1, T& v2)
        {
            ContainerHelper::Swap(v1,v2);
        }

    private:
        void                CurrentSceneManager(CSceneManager* sceneManager);

    private:
        static CSceneManager* _currentSceneManager;

};

};

#endif
