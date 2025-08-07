#pragma once

#define REBASE(Address) (Address + reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

namespace Offsets
{
	const uintptr_t Print = REBASE(0x1490C90);
	const uintptr_t TaskDefer = REBASE(0xFE5EF0);
	const uintptr_t RawScheduler = REBASE(0x6F55720);
	const uintptr_t OpcodeLookupTable = REBASE(0x5291F70);

	namespace Luau
	{
		const uintptr_t LuaD_throw = REBASE(0x26A4240);
		const uintptr_t Luau_Execute = REBASE(0x26D6DE0);
		const uintptr_t LuaO_NilObject = REBASE(0x4C773B8);
		const uintptr_t LuaH_DummyNode = REBASE(0x4C76DD8);

		const uintptr_t Convention = 0x3C0;
	}

	namespace DataModel
	{
		const uintptr_t Children = 0x68;
		const uintptr_t GameLoaded = 0x668;
		const uintptr_t ScriptContext = 0x3D0;
		const uintptr_t FakeDataModelToDataModel = 0x1C0;

		const uintptr_t FakeDataModelPointer = REBASE(0x6E854F8);
	}

	namespace ExtraSpace
	{
		const uintptr_t Identity = 0x30;
		const uintptr_t Capabilities = 0x48;
	}
}