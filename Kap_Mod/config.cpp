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