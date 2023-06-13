// Script File
modded class MissionServer extends MissionBase{
	void DelayedTriggerCreate(){
		Print("CURR_TICKs: " + GetGame().GetTickTime());		
		Debug.Log("CURR_TICKs: " + GetGame().GetTickTime());
		KapModTriggerCallback kap_cta = new KapModTriggerCallback;
		RestContext ctx = GetRestApi().GetRestContext("https://kapayji.tech/dayz/teleport/trigger-coords");
		ctx.GET(kap_cta,"/");
	}
	override void OnMissionStart()
	{
		super.OnMissionStart();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DelayedTriggerCreate, 60000, false);
	}
}