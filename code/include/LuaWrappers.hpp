#include <cstdio>
#include <tuple>

extern "C"
{
    #include "../include/lua/include/lauxlib.h"
    #include "../include/lua/include/lualib.h"
    #include "../include/lua/include/lua.h"
}

#ifdef _WIN32
#pragma comment(lib, "../include/lua/liblua54.a")
#endif

class LuaInitializer
{
public:
    static lua_State* L;
public:
    LuaInitializer();
    ~LuaInitializer();
    static void InsertLuaFunctions();
};