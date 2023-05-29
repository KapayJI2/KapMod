class CfgPatches
{
	class Kap_Mod
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class FirstMod
	{
		type = "mod";

		class defs
		{

			class gameScriptModule
			{
				value = "";
				files[] = {"FirstMod/Kap_Mod/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"FirstMod/Kap_Mod/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"FirstMod/Kap_Mod/5_Mission"};
			};
		};
	};
};