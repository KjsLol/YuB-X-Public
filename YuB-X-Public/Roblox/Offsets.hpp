#pragma once

#include <Windows.h>

struct lua_State;
#define REBASE(Address) (Address + reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

namespace Offsets
{
	const uintptr_t Print = REBASE(0x14F0590);
	const uintptr_t TaskDefer = REBASE(0x1028250);
	const uintptr_t RawScheduler = REBASE(0x710ADA0);
	const uintptr_t OpcodeLookupTable = REBASE(0x53EFDB0);

	namespace Luau
	{
		const uintptr_t LuaD_throw = REBASE(0x2737060);
		const uintptr_t Luau_Execute = REBASE(0x276A1E0);
		const uintptr_t LuaO_NilObject = REBASE(0x4DC4D78);
		const uintptr_t LuaH_DummyNode = REBASE(0x4DC44A8);
	}

	namespace DataModel
	{
		const uintptr_t Children = 0x68;
		const uintptr_t GameLoaded = 0x668;
		const uintptr_t ScriptContext = 0x3D0;
		const uintptr_t FakeDataModelToDataModel = 0x1C0;

		const uintptr_t FakeDataModelPointer = REBASE(0x703A758);
	}

	namespace ExtraSpace
	{
		const uintptr_t Identity = 0x30;
		const uintptr_t Capabilities = 0x48;
	}
}

namespace Roblox
{
	inline auto TaskDefer = (int(__fastcall*)(lua_State*))Offsets::TaskDefer;
	inline auto Print = (uintptr_t(__fastcall*)(int, const char*, ...))Offsets::Print;
	inline auto Luau_Execute = (void(__fastcall*)(lua_State*))Offsets::Luau::Luau_Execute;
	inline auto LuaD_Throw = (void(__fastcall*)(lua_State*, int))Offsets::Luau::LuaD_throw;
}

//Dont forget to update TaskScheduler::DecryptLuaState and Encryptions