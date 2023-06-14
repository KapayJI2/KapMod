class CfgPatches
{
	class kap_mod
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Characters"
		};
	};
};
class CfgMods
{
	class KapMod
	{
		type = "mod";
		name = "KapMod";
		dir = "kap_mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{

			class gameScriptModule
			{
				value = "";
				files[] = {"KapMod/kap_mod/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"KapMod/kap_mod/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"KapMod/kap_mod/5_Mission"};
			};
		};
	};
};
class CfgSoundShaders
{
	class KapTriggerSound_base
	{
		range=50;
	};
	class KapTriggerSoundShader: KapTriggerSound_base
	{
		samples[]=
		{
			
			{
				"KapMod/kap_mod/sounds/KapTriggerSoundSet.ogg",
				1
			}
		};
		volume=1;
	};
};
class CfgSoundSets
{
	class kapTrigger_SoundSet
	{
		spatial=1;
		doppler=0;
		loop=0;
	};
	class kapTriggerSound_SoundSet: kapTrigger_SoundSet
	{
		soundShaders[]=
		{
			"KapTriggerSoundShader"
		};
	};
};