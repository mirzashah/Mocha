/*****************************************************************************/
// Filename: ContainerHelper.h
/*****************************************************************************/
// Description: This is a collection of functions for helping me manipulate STL containers.
// Even though STL has a bunch of great algorithms for doing things like sorting, and appending,
// I find their interface awkward as it depends on iterators. Being a person that likes functional
// languages, I prefer making copies of things as well, so all the functions here have no side-effects,
// they simply return a new list/vector/etc. This may be problematic for some people, because
// of performance or because they don't have an appropriate copy constructor for the objects they
// place into the container. My containers typically contain only primitive types (int, float, etc), or
// pointers to objects, so it's really not a concern.
/*****************************************************************************/


#ifndef CONTAINER_HELPER_H_DEFINED
#define CONTAINER_HELPER_H_DEFINED

#include <vector>
#include <string>
#include <map>
#include <list>
#include <algorithm>

using std::vector;
using std::list;
using std::string;
using std::map;

namespace ContainerHelper
{

/*****************************************************/
template <typename T>
struct LessThanFunctor : public std::binary_function<T, T, bool>
/*****************************************************/
{
    LessThanFunctor(bool (*lessThanFunc)(T, T))
    {
        _lessThanFunc = lessThanFunc;
    }
    bool operator()(T x, T y)
    {
        return(_lessThanFunc(x,y));
    }

    bool (*_lessThanFunc)(T, T);

};

/********************************************************/
template <typename T> vector<T> Append(const vector<T>& v1, const vector<T>& v2)
/********************************************************/
{
    vector<T> toReturn;
    for(unsigned int c=0; c<v1.size(); c++)
        toReturn.push_back(v1.at(c));
    for(unsigned int c=0; c<v2.size(); c++)
        toReturn.push_back(v2.at(c));
    return(toReturn);
}

/********************************************************/
template <typename T> vector<T> Append(const T& v1, const vector<T>& v2)
/********************************************************/
{
    return(Append(Construct(v1), v2));
}

/********************************************************/
template <typename T> vector<T> Append(const vector<T>& v1, const T& v2)
/********************************************************/
{
    return(Append(v1, Construct(v2)));
}

/********************************************************/
template <typename T> vector<T> Construct(const T& firstItem)
/********************************************************/
{
	vector<T> toReturn;
	toReturn.push_back(firstItem);
	return(toReturn);
}

/********************************************************/
template <typename T> bool Contains(const vector<T>& v, const T& item)
/********************************************************/
{
    return(FindIndex(v, item) != -1);
}

/********************************************************/
template <typename S, typename T> bool ContainsKey(const map<S,T>& m, const S& key)
/********************************************************/
{
    typename std::map<S, T>::iterator itr;
    for(itr = m.begin(); itr!=m.end(); itr++)
    {
        if(itr->first == key)
            return(true);
    }
    return(false);
}

/********************************************************/
template <typename T> int FindIndex(const vector<T>& v, const T& item)
/********************************************************/
{
    for(unsigned int c=0; c<v.size(); c++)
        if(v.at(c)==item)
            return(c);
    return(-1);
}

/********************************************************/
template <typename T> T FirstItem(const vector<T>& v)
/********************************************************/
{
    if(v.size()==0)
        return(T());
    else
        return(v.at(0));
}

/********************************************************/
template <typename T> T LastItem(const vector<T>& v)
/********************************************************/
{
    if(v.size()==0)
        return(T());
    else
        return(v.at(v.size()-1));
}

/********************************************************/
template <typename T> vector<T> RemoveFirst(const vector<T>& v)
/********************************************************/
{
    vector<T> toReturn;
    for(unsigned int c=0; c<v.size()-1; c++)
        toReturn.push_back(v.at(c));
    return(toReturn);
}

/********************************************************/
template <typename T> vector<T> RemoveLast(const vector<T>& v)
/********************************************************/
{
    vector<T> toReturn;
    for(unsigned int c=1; c<v.size(); c++)
        toReturn.push_back(v.at(c));
    return(toReturn);
}

/********************************************************/
template <typename T> vector<T> Remove(const vector<T>& v, const T& toRemove)
/********************************************************/
{
    vector<T> toReturn;
    for(unsigned int c=0; c<v.size(); c++)
    {
        if(v.at(c)!=toRemove)
            toReturn.push_back(v.at(c));
    }
    return(toReturn);
}

/********************************************************/
template <typename T> vector<T> Reverse(const vector<T>& v)
/********************************************************/
{
	vector<T> toReturn;
	for(int c=((int)(v.size()))-1; c>=0; c--)
		toReturn.push_back(v.at(c));
	return(toReturn);
}


/********************************************************/
template <typename T> vector<T> SortAscending(const vector<T>& v)
/********************************************************/
{
    vector<T> temp = v;
	std::sort(temp.begin(), temp.end());
	return(temp);
}

/********************************************************/
template <typename T> vector<T> SortAscending(const vector<T>& v, bool (*lessThanFunc)(T, T))
/********************************************************/
{
    vector<T> temp = v;
	std::sort(temp.begin(), temp.end(), LessThanFunctor<T>(lessThanFunc));
	return(temp);
}

/********************************************************/
template <typename T> vector<T> SortDescending(const vector<T>& v)
/********************************************************/
{
	return(Reverse(SortAscending(v)));
}

/********************************************************/
template <typename T> vector<T> SortDescending(const vector<T>& v, bool (*lessThanFunc)(T, T))
/********************************************************/
{
	return(Reverse(SortAscending(v, lessThanFunc)));
}

/********************************************************/
template <typename T> void Swap(T& v1, T& v2)
/********************************************************/
{
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

};

#endif
