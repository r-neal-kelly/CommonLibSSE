#pragma once

#include "skse64/GameFormComponents.h"  // TESIcon, TESEnchantableForm, TESValueForm, TESWeightForm, TESAttackDamageForm, BGSDestructibleObjectForm, BGSEquipType, BGSPreloadable, BGSMessageIcon, BGSPickupPutdownSounds, BGSBlockBashData, TESDescription

#include "RE/ActorValues.h"  // ActorValue
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm


namespace RE
{
	class TESObjectWEAP :
		public TESBoundObject,				// 000
		public TESFullName,					// 030
		public TESModelTextureSwap,			// 040
		public TESIcon,						// 078
		public TESEnchantableForm,			// 088
		public TESValueForm,				// 0A0
		public TESWeightForm,				// 0B0
		public TESAttackDamageForm,			// 0C0
		public BGSDestructibleObjectForm,	// 0D0
		public BGSEquipType,				// 0E0
		public BGSPreloadable,				// 0F0
		public BGSMessageIcon,				// 0F8
		public BGSPickupPutdownSounds,		// 110
		public BGSBlockBashData,			// 128
		public BGSKeywordForm,				// 140
		public TESDescription				// 158
	{
	public:
		enum { kTypeID = FormType::Weapon };


		struct Data	// DATA
		{
			struct ExtraData
			{
				float	sightFOV;					// 00
				float	unk04;						// 04
				float	rumbleLeftMotorStrength;	// 08
				float	rumbleRightMotorStrength;	// 0C
				float	rumbleDuration;				// 10
				UInt32	unk14;						// 14
				UInt32	numProjectiles;				// 18
				UInt32	unk1C;						// 1C
			};


			enum class OnHit : UInt32
			{
				kNoFormulaBehavior,
				kDismemberOnly,
				kExplodeOnly,
				kNoDismemberExplode
			};


			enum class Flag2 : UInt16
			{
				kNone = 0,
				kPlayerOnly = 1 << 0,
				kNPCsUseAmmo = 1 << 1,
				kNoJamAfterReload = 1 << 2,			// unused
				kMinorCrime = 1 << 4,
				kRangeFixed = 1 << 5,
				kNotUsedInNormalCombat = 1 << 6,
				kDontUse3rdPersonISAnim = 1 << 8,	// unused
				kBurstShot = 1 << 9,
				kRumbleAlternate = 1 << 10,
				kLongBursts = 1 << 11,
				kNonHostile = 1 << 12,
				kBoundWeapon = 1 << 13,
			};


			enum class AnimationType : UInt8
			{
				kHandToHandMelee = 0,
				kOneHandSword = 1,
				kOneHandDagger = 2,
				kOneHandAxe = 3,
				kOneHandMace = 4,
				kTwoHandSword = 5,
				kTwoHandAxe = 6,
				kBow = 7,
				kStaff = 8,
				kCrossbow = 9
			};


			enum class Flag : UInt8
			{
				kNone = 0,
				kIgnoresNormalWeaponResistance = 1 << 0,
				kAutomatic = 1 << 1,						// unused
				kHasScope = 1 << 2,							// unused
				kCantDrop = 1 << 3,
				kHideBackpack = 1 << 4,						// unused
				kEmbeddedWeapon = 1 << 5,					// unused
				kDontUseFirstPersonISAnim = 1 << 6,			// unused
				kNonPlayable = 1 << 7,
			};


			ExtraData*		extraData;				// 00
			float			speed;					// 08
			float			reach;					// 0C
			float			rangeMin;				// 10
			float			rangeMax;				// 14
			float			animationAttackMult;	// 18
			float			unk1C;					// 1C
			float			stagger;				// 20
			OnHit			onHit;					// 24
			ActorValue		skill;					// 28
			ActorValue		resist;					// 2C - unconfirmed
			Flag2			flags2;					// 30
			UInt8			baseVATSToHitChance;	// 32
			UInt8			attackAnimation;		// 33
			UInt8			embeddedWeaponAV;		// 34 - unused
			AnimationType	animationType;			// 35
			Flag			flags;					// 36
			UInt8			pad37;					// 37
		};
		STATIC_ASSERT(sizeof(Data) == 0x38);


		struct CriticalData	// CRDT
		{
			enum Flag : UInt8
			{
				kNone = 0,
				kOnDeath = 1 << 0
			};


			float		prcntMult;		// 00
			UInt32		pad04;			// 04
			SpellItem*	effect;			// 08
			UInt16		damage;			// 10
			Flag		flags;			// 12
			UInt8		pad13;			// 13
			UInt32		pad14;			// 14
		};
		STATIC_ASSERT(sizeof(CriticalData) == 0x18);


		float				speed();
		float				reach();
		float				stagger();
		float				minRange();
		float				maxRange();
		Data::AnimationType	animationType();
		UInt16				critDamage();
		void				GetNodeName(char* a_dstBuff);
		bool				IsBound();
		bool				IsMelee();
		bool				IsRanged();


		// members
		Data					data;					// 168
		CriticalData			criticalData;			// 1A0
		TESForm*				scopeEffect;			// 1B8
		BGSSoundDescriptorForm*	attackSound;			// 1C0 - SNAM
		BGSSoundDescriptorForm*	attackSound2D;			// 1C8 - XNAM
		BGSSoundDescriptorForm*	attackLoopSound;		// 1D0 - NAM7
		BGSSoundDescriptorForm*	attackFailSound;		// 1D8 - TNAM
		BGSSoundDescriptorForm*	idleSound;				// 1E0 - UNAM
		BGSSoundDescriptorForm*	equipSound;				// 1E8 - NAM9
		BGSSoundDescriptorForm*	unequipSound;			// 1F0 - NAM8
		BGSImpactDataSet*		impactDataSet;			// 1F8
		TESObjectSTAT*			model;					// 200
		TESObjectWEAP*			templateForm;			// 208 - CNAM
		BSFixedString			embeddedNode;			// 210
		UInt32					detectionSoundLevel;	// 218
		UInt32					pad21C;					// 21C
	};
	STATIC_ASSERT(sizeof(TESObjectWEAP) == 0x220);
}
