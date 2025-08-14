#pragma once
#define REBASE(Address) (Address + reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

namespace Offsets
{
	const uintptr_t Print = REBASE(0x1493A80);
	const uintptr_t TaskDefer = REBASE(0xFE7E60);
	const uintptr_t RawScheduler = REBASE(0x6F42320);
	const uintptr_t OpcodeLookupTable = REBASE(0x527BBB0);

	namespace Luau
	{
		const uintptr_t LuaD_throw = REBASE(0x267D700);
		const uintptr_t Luau_Execute = REBASE(0x26B02E0);
		const uintptr_t LuaO_NilObject = REBASE(0x4C5F858);
		const uintptr_t LuaH_DummyNode = REBASE(0x4C5F278);

		const uintptr_t Convention = 0x3C0;
	}

	namespace DataModel
	{
		const uintptr_t Children = 0x68;
		const uintptr_t GameLoaded = 0x668;
		const uintptr_t ScriptContext = 0x3D0;
		const uintptr_t FakeDataModelToDataModel = 0x1C0;

		const uintptr_t FakeDataModelPointer = REBASE(0x6E72138);
	}

	namespace ExtraSpace
	{
		const uintptr_t Identity = 0x30;
		const uintptr_t Capabilities = 0x48;
	}
}

// Dont forget to update TaskScheduler::DecryptLuaState