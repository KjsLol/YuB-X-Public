#pragma once
#define REBASE(Address) (Address + reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

namespace Offsets
{
	const uintptr_t Print = REBASE(0x1542550);
	const uintptr_t TaskDefer = REBASE(0x108C1E0);
	const uintptr_t RawScheduler = REBASE(0x70F31E0);
	const uintptr_t OpcodeLookupTable = REBASE(0x53E6BD0);

	namespace Luau
	{
		const uintptr_t LuaD_throw = REBASE(0x2779CB0);
		const uintptr_t Luau_Execute = REBASE(0x27ACBE0);
		const uintptr_t LuaO_NilObject = REBASE(0x4DC0C28);
		const uintptr_t LuaH_DummyNode = REBASE(0x4DC0648);
	}

	namespace DataModel
	{
		const uintptr_t Children = 0x68;
		const uintptr_t GameLoaded = 0x668;
		const uintptr_t ScriptContext = 0x3D0;
		const uintptr_t FakeDataModelToDataModel = 0x1C0;

		const uintptr_t FakeDataModelPointer = REBASE(0x7022FA8);
	}

	namespace ExtraSpace
	{
		const uintptr_t Identity = 0x30;
		const uintptr_t Capabilities = 0x48;
	}
}

//Dont forget to update TaskScheduler::DecryptLuaState