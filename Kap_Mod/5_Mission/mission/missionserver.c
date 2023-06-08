// Script File
modded class MissionServer extends MissionBase{
	override void OnMissionStart()
	{
		super.OnMissionStart();
		if(GetGame().IsServer()){
			vector v = Vector(2651.72, GetGame().SurfaceY(2651.72,1380.47) ,1380.47);
			GetGame().CreateObjectEx("KapTrigger", v, ECE_SETUP);
			Print("Created trigger");
			Debug.Log("Created trigger");
		}
	}
}