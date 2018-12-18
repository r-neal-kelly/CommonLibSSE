#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/FormTypes.h"  // BGSEquipSlot


namespace RE
{
	class BGSEquipType : public BaseFormComponent
	{
	public:
		virtual ~BGSEquipType();													// 00

		// override (BaseFormComponent)
		virtual void			Init() override;									// 01
		virtual void			ReleaseRefs() override;								// 02
		virtual void			CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual	BGSEquipSlot*	GetEquipSlot();										// 04
		virtual void			SetEquipSlot(BGSEquipSlot* a_slot);					// 05


		// members
		BGSEquipSlot* equipSlot;	// 08
	};
	STATIC_ASSERT(sizeof(BGSEquipType) == 0x10);
}
