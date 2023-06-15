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
		range=125;
	};
	class KapTriggerSoundClose_base
	{
		range=25;
	};
	class KapTriggerSoundPost_base
	{
		range=5;
	};
	class KapTriggerSoundStaticShader: KapTriggerSound_base
	{
		samples[]=
		{
			
			{
				"KapMod\kap_mod\sounds\kapTriggerStaticSound.ogg",
				1
			}
		};
		volume=1;
	};
	class KapTriggerSoundCloseRadiusShader:KapTriggerSoundClose_base
	{
		samples[]=
		{
			
			{
				"KapMod\kap_mod\sounds\kapTriggerCloseRadiusSound.ogg",
				1
			}
		};
		volume=1.1;
	};
	class KapTriggerSoundPostShader:KapTriggerSoundPost_base
	{
		samples[]=
		{
			
			{
				"KapMod\kap_mod\sounds\kapTriggerPostSound.ogg",
				1
			}
		};
		volume=0.7;
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

	class kapTriggerSoundStatic_SoundSet: kapTrigger_SoundSet
	{
		soundShaders[]=
		{
			"KapTriggerSoundStaticShader"
		};
	};
	class kapTriggerCloseRadiusSound_SoundSet: kapTrigger_SoundSet
	{
		soundShaders[]=
		{
			"KapTriggerSoundCloseRadiusShader"
		};
	};
	class kapTriggerPostActivate_SoundSet: kapTrigger_SoundSet
	{
		soundShaders[]=
		{
			"KapTriggerSoundPostShader"
		};
	};
};