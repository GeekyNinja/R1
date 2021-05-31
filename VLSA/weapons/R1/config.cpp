class CfgPatches
{
	class R1Tagger_F
	{
		// Meta information for editor
		name = "R1 Tag Gun";
		author = "That Awesome Guy";
		url = "http://www.thatawesomeguy.com";

		// Minimum compatible version. When the game's version is lower, pop-up warning will appear when launching the game.
		requiredVersion = 0.1; 
		// Required addons, used for setting load order.
		// When any of the addons is missing, pop-up warning will appear when launching the game.
		//requiredAddons[] = {"A3_Weapons_F"};
		requiredAddons[] = {"A3_Data_F_Oldman_Loadorder"};
		// List of objects (CfgVehicles classes) contained in the addon. Important also for Zeus content (units and groups) unlocking.
		units[] = {};
		// List of weapons (CfgWeapons classes) contained in the addon.
		weapons[] = {"R1Tagger_01_F"};
	};
};

class CfgMovesBasic
{
    class DefaultDie;
    class ManActions
    {
		VLSA_GestureReloadR1 = "VLSA_GestureReloadR1";
    };

	class Actions
	{
		class NoActions : ManActions
		{
			VLSA_GestureReloadR1[] = { "VLSA_GestureReloadR1", "Gesture"};
		};
	};
};

class CfgGesturesMale
{
	class Default;
	class States
	{
		class GestureReloadBase;
		class VLSA_GestureReloadR1: GestureReloadBase
		{
			file = "\VLSA\weapons\R1\data\Anim\GestureReloadR1.rtm";
            speed=0.42;

			leftHandIKCurve[] = {0, 1, 0.05, 0, 0.95, 0, 1, 1};
            rightHandIKCurve[] = {1};
		};
        class VLSA_GestureReloadR1Prone: VLSA_GestureReloadR1
		{
			mask = "ReloadMask";
		};
        class VLSA_GestureReloadR1Context: VLSA_GestureReloadR1
		{
			mask = "handsWeapon_context";
		};
		class VLSA_GestureReloadR1ContextAnimDrive: VLSA_GestureReloadR1Context
		{
			mask = "handsWeapon_contextAnimDrive";
		};
	};
};

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class MuzzleSlot;
class SlotInfo;
class CowsSlot;
class UnderBarrelSlot;
class PointerSlot;
class arifle_SPAR_01_base_F;

class CfgWeapons
{
	/*class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};*/

	class VLSA_Rifle_Base_F: arifle_SPAR_01_base_F
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};

	class R1Tagger_01_Base_F: VLSA_Rifle_Base_F
	{
		magazines[]=
		{
			"30Rnd_556x45_Stanag",
			"30Rnd_556x45_Stanag_Tracer_Red",
			"30Rnd_556x45_Stanag_Tracer_Green",
			"30Rnd_556x45_Stanag_Tracer_Yellow",
			"30Rnd_556x45_Stanag_red",
			"30Rnd_556x45_Stanag_green"
		};
		magazineWell[]=
		{
			"STANAG_556x45"
		};
		reloadAction = "VLSA_GestureReloadR1"; /// MX hand animation actually fits this rifle well
		magazineReloadSwitchPhase = 0.57; /// part of reload animation when new magazine ammo count should affect "revolving" animation source
		discreteDistanceInitIndex = 0; /// Ironsight zeroing is the lowest value by default

		// Size of recoil sway of the cursor
		//maxRecoilSway=0.0125;
        // Speed at which the recoil sway goes back to zero (from maxRecoilSway to 0 in 1/swayDecaySpeed seconds)
        //swayDecaySpeed=1.25;
		/// inertia coefficient of the weapon
		inertia = 0.4;

		/// positive value defines speed of the muzzle independent on the magazine setting, negative value is a coefficient of magazine initSpeed
		//initSpeed = -1; /// this means that initSpeed of magazine is used
		initSpeed = 720;

		class GunParticles : GunParticles
		{
			class SecondEffect
			{
				positionName = "Nabojnicestart";
				directionName = "Nabojniceend";
				effectName = "CaselessAmmoCloud";
			};
		};

		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"VLSA\weapons\R1\data\R1Tagger_Base_CO.paa"};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot /// default accessories for this slot
			{
				iconPosition[] = {0.5, 0.35};
				iconScale = 0.2;
			};
			class UnderBarrelSlot: UnderBarrelSlot /// Bipod
			{
				iconPosition[] = {0.1, 0.8};
				iconScale = 0.2;
			};
			class PointerSlot: PointerSlot
			{
				iconPosition[] = {0.2,0.45};
				iconScale = 0.25;
			};
		};

		/////////////////////////////////////////////////////  I R O N S I G H T S  /////////////////////////////////////////////////////
		opticsZoomMin = 0.25;
		opticsZoomMax = 1.25;
		opticsZoomInit = 0.75;

		distanceZoomMin = 300;
		distanceZoomMax = 300;
		/////////////////////////////////////////////////////  I R O N S I G H T S  /////////////////////////////////////////////////////

		descriptionShort = "Razor Custom Tagger Model R1"; /// displayed on mouseOver in Inventory
		//handAnim[] = {"OFP2_ManSkeleton", "\A3\Weapons_F\Rifles\MX\data\Anim\MX.rtm"}; /// MX hand animation actually fits this rifle well
		handAnim[] = {"OFP2_ManSkeleton", "\VLSA\weapons\R1\data\Anim\R1.rtm"};
		dexterity = 1.8;


		//caseless ammo//
		caseless[] = {"",1,1,1};  /// no sound of ejected brass
		soundBullet[] = {caseless,1};

		selectionFireAnim = "zasleh"; /// are we able to get rid of all the zaslehs?

		modes[] = {Single, FullAuto, fullauto_medium}; /// Includes fire modes for AI
		////////////////////////////////////////////////////// NO OPTICS ///////////////////////////////////////////////////////////

		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType
			{
				closure1[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Closure_TRG20_01",
					0.50118721,
					1,
					10
				};
				closure2[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Closure_TRG20_02",
					0.50118721,
					1,
					10
				};
				soundClosure[]=
				{
					"closure1",
					0.5,
					"closure2",
					0.5
				};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_short_01",
					1.9952624,
					1,
					1400
				};
				begin2[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_short_02",
					1.9952624,
					1,
					1400
				};
				begin3[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_short_03",
					1.9952624,
					1,
					1400
				};
				soundBegin[]=
				{
					"begin1",
					0.33000001,
					"begin2",
					0.33000001,
					"begin3",
					0.34
				};
				class SoundTails
				{
					class TailTrees
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_trees",
							1,
							1,
							1400
						};
						frequency=1;
						volume="(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_forest",
							1,
							1,
							1400
						};
						frequency=1;
						volume="(1-interior/1.4)*forest";
					};
					class TailInterior
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_interior",
							1.5848932,
							1,
							1400
						};
						frequency=1;
						volume="interior";
					};
					class TailMeadows
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_meadows",
							1,
							1,
							1400
						};
						frequency=1;
						volume="(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_houses",
							1,
							1,
							1400
						};
						frequency=1;
						volume="(1-interior/1.4)*houses";
					};
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_01",
					1,
					1,
					400
				};
				begin2[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_02",
					1,
					1,
					400
				};
				begin3[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_03",
					1,
					1,
					400
				};
				soundBegin[]=
				{
					"begin1",
					0.33000001,
					"begin2",
					0.33000001,
					"begin3",
					0.34
				};
				class SoundTails
				{
					class TailTrees
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_trees",
							1,
							1,
							400
						};
						frequency=1;
						volume="(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_forest",
							1,
							1,
							400
						};
						frequency=1;
						volume="(1-interior/1.4)*forest";
					};
					class TailInterior
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_tail_interior",
							1,
							1,
							400
						};
						frequency=1;
						volume="interior";
					};
					class TailMeadows
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_meadows",
							1,
							1,
							400
						};
						frequency=1;
						volume="(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_houses",
							1,
							1,
							400
						};
						frequency=1;
						volume="(1-interior/1.4)*houses";
					};
				};
			};
			reloadTime=0.079999998;
			dispersion=0.00116;
			recoil="recoil_single_trg";
			recoilProne="recoil_single_prone_trg";
			minRange=2;
			minRangeProbab=0.5;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=250;
			maxRangeProbab=0.2;
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType
			{
				closure1[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\closure_TRG20_01",
					0.50118721,
					1,
					10
				};
				closure2[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\closure_TRG20_02",
					0.50118721,
					1,
					10
				};
				soundClosure[]=
				{
					"closure1",
					0.5,
					"closure2",
					0.5
				};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_short_01",
					1.9952624,
					1,
					1400
				};
				begin2[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_short_02",
					1.9952624,
					1,
					1400
				};
				begin3[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_short_03",
					1.9952624,
					1,
					1400
				};
				soundBegin[]=
				{
					"begin1",
					0.33000001,
					"begin2",
					0.33000001,
					"begin3",
					0.34
				};
				class SoundTails
				{
					class TailTrees
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_trees",
							1,
							1,
							1400
						};
						frequency=1;
						volume="(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_forest",
							1,
							1,
							1400
						};
						frequency=1;
						volume="(1-interior/1.4)*forest";
					};
					class TailInterior
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_interior",
							1.5848932,
							1,
							1400
						};
						frequency=1;
						volume="interior";
					};
					class TailMeadows
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_meadows",
							1,
							1,
							1400
						};
						frequency=1;
						volume="(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_houses",
							1,
							1,
							1400
						};
						frequency=1;
						volume="(1-interior/1.4)*houses";
					};
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_01",
					1,
					1,
					400
				};
				begin2[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_02",
					1,
					1,
					400
				};
				begin3[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_03",
					1,
					1,
					400
				};
				soundBegin[]=
				{
					"begin1",
					0.33000001,
					"begin2",
					0.33000001,
					"begin3",
					0.34
				};
				class SoundTails
				{
					class TailTrees
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_trees",
							1,
							1,
							400
						};
						frequency=1;
						volume="(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_forest",
							1,
							1,
							400
						};
						frequency=1;
						volume="(1-interior/1.4)*forest";
					};
					class TailInterior
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_tail_interior",
							1,
							1,
							400
						};
						frequency=1;
						volume="interior";
					};
					class TailMeadows
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_meadows",
							1,
							1,
							400
						};
						frequency=1;
						volume="(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[]=
						{
							"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_houses",
							1,
							1,
							400
						};
						frequency=1;
						volume="(1-interior/1.4)*houses";
					};
				};
			};
			reloadTime=0.079999998;
			dispersion=0.00116;
			recoil="recoil_auto_trg";
			recoilProne="recoil_auto_prone_trg";
			minRange=2;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.050000001;
			aiRateOfFire=1e-006;
		};
		class fullauto_medium: FullAuto
		{
			showToPlayer=0;
			burst=3;
			minRange=2;
			minRangeProbab=0.5;
			midRange=75;
			midRangeProbab=0.69999999;
			maxRange=100;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
		};
		class single_medium_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=5;
			minRangeProbab=0.2;
			midRange=300;
			midRangeProbab=0.69999999;
			maxRange=450;
			maxRangeProbab=0.30000001;
			aiRateOfFire=5;
			aiRateOfFireDistance=500;
		};
		class single_medium_optics2: single_medium_optics1
		{
			requiredOpticType=2;
			minRange=100;
			minRangeProbab=0.1;
			midRange=400;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.050000001;
			aiRateOfFire=6;
			aiRateOfFireDistance=600;
		};
		
		aiDispersionCoefY=6.0; /// AI should have some degree of greater dispersion for initial shoots
		aiDispersionCoefX=4.0; /// AI should have some degree of greater dispersion for initial shoots
	};

	class R1Tagger_01_F: R1Tagger_01_Base_F
	{
		scope = 2; /// should be visible and useable in game
		displayName = "R1 Tagger (Sand)";
		model = "\VLSA\weapons\R1\r1.p3d"; /// path to model

		picture = "\VLSA\weapons\R1\data\UI\gear_R1Tagger_X_CA.paa"; /// different accessories have M, S, T instead of X
		UiPicture = "\A3\Weapons_F\Data\UI\icon_regular_CA.paa";

		weaponInfoType = "RscWeaponZeroing"; /// display with zeroing is good for iron sights

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 100; /// some rough estimate
		};
	};
	class R1Tagger_02_F: R1Tagger_01_F
	{
		displayName = "R1 Tagger (Camo)";
		picture = "\VLSA\weapons\R1\data\UI\gear_R1Tagger2_X_CA.paa"; /// different accessories have M, S, T instead of X
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"VLSA\weapons\R1\data\R1Tagger_Base2_CO.paa"};
	};
	class R1Tagger_03_F: R1Tagger_01_F
	{
		displayName = "R1 Tagger (Black)";
		picture = "\VLSA\weapons\R1\data\UI\gear_R1Tagger3_X_CA.paa"; /// different accessories have M, S, T instead of X
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"VLSA\weapons\R1\data\R1Tagger_Base3_CO.paa"};
	};
};