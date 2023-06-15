// Script File
/*
class KapTriggerParent {
	protected KapTrigger kap_trigger;

    override void EEInit()
	{
        super.EEInit();
        if (GetGame().IsServer())
		{
			CreateTrigger();
        }
	}

    override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		if ( GetGame() && kap_trigger )
		{
			GetGame().ObjectDelete( kap_trigger );
			kap_trigger = null;
		}
	}
	override void OnEnter(Object obj){
		PlayerBase player;
		Print("CAST: " + Class.CastTo(player, obj));
		if(Class.CastTo(player, obj)){
			Print("PLR: " + player);
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, new Param1<string>("Вы в зоне триггера"),true, player.GetIdentity());
		}else{
			Print("FALSE");
		}
		Print("ENTER");
	}
	void CreateTrigger(){
        if (Class.CastTo(kap_trigger, GetGame().CreateObjectEx("KapTrigger", GetPosition(), ECE_CREATEPHYSICS)))
		{
            float radius = 20;
            float height = 20;

			vector mins = vector.Zero; mins[0] = -radius; mins[2] = -radius; mins[1] = -height;
			vector maxs = vector.Zero; maxs[0] =  radius; maxs[2] =  radius; maxs[1] =  height;

			kap_trigger.SetOrientation(GetOrientation());
			kap_trigger.SetExtents(mins, maxs);
			kap_trigger.SetParentObject(this);
		}
    }
	
}

*/
class KapTrigger: Trigger{
    //protected KapTriggerParent kap_Parent;

   // void SetParentObject( KapTriggerParent obj )
	//{
	//	kap_Parent = obj;
	//}

    override void OnEnter(Object obj){
		Object obj2;
		Print("CAST: " + PlayerBase.CastTo(obj2, obj));
		if(PlayerBase.CastTo(obj2, obj)){
			Print("PLR: " + PlayerBase.Cast(obj2));
			PlayerBase man = PlayerBase.Cast(obj2);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(man.start_teleport_confus, 1000, false, man);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(man.stop_teleport_confus, 15000, false, man);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(man.stop2_teleport_confus, 25000, false, man);
			Print("MAN: " + man);
			GetGame().RPCSingleParam(man, ERPCs.RPC_USER_ACTION_MESSAGE, new Param1<string>("Вы в зоне триггера"),true, ManBase.Cast(obj2).GetIdentity());
			string p_ID = man.GetIdentity().GetId();
			Print("ID: " + p_ID);
			KapModCallback m_cb_rand = new KapModCallback;
			string url = "https://kapayji.tech/dayz/teleport/rand-move/";
			RestContext ctx = GetRestApi().GetRestContext(url);
			ctx.GET(m_cb_rand,p_ID);
		}else{
			Print("FALSE");
		}
		Print("PLR_THIS: " + GetGame().GetPlayer());
		Print("ENTER");
	}
}
class KapTriggerWrapper: Trigger{
    //protected KapTriggerParent kap_Parent;

   // void SetParentObject( KapTriggerParent obj )
	//{
	//	kap_Parent = obj;
	//}
	protected EffectSound sound;
	override void EOnInit(IEntity other, int extra)
	{
		SetExtents("-12 -14 -12", "12 14 12");
	}
	override void OnLeave(Object obj) {
		Object obj2;
		if(PlayerBase.CastTo(obj2, obj)){
			PlayerBase man = PlayerBase.Cast(obj2);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(man.SpawnShockEffect);
			sound = null;
		}else{
			Print("FALSE");
		}
		Print("ENTER");
	}
    override void OnEnter(Object obj){
		Object obj2;
		if(PlayerBase.CastTo(obj2, obj)){
			PlayerBase man = PlayerBase.Cast(obj2);
			sound = SEffectManager.PlaySound( "kapTriggerCloseRadiusSound_SoundSet", this.GetPosition() ,0 ,0 ,true);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(man.SpawnShockEffect, 2000, true, 70);
			GetGame().RPCSingleParam(man, ERPCs.RPC_USER_ACTION_MESSAGE, new Param1<string>("Опасная зона ~ 12м"),true, ManBase.Cast(obj2).GetIdentity());
		}else{
			Print("FALSE");
		}
		Print("ENTER");
	}
}
class KapTriggerWrapperFar: Trigger{
    //protected KapTriggerParent kap_Parent;

   // void SetParentObject( KapTriggerParent obj )
	//{
	//	kap_Parent = obj;
	//}
	override void EOnInit(IEntity other, int extra)
	{
		SetExtents("-22 -24 -22", "22 24 22");
	}
	override void OnLeave(Object obj) {
		Object obj2;
		if(PlayerBase.CastTo(obj2, obj)){
			PlayerBase man = PlayerBase.Cast(obj2);
			man.QueueRemoveGlassesEffect(5);
		}else{
			Print("FALSE");
		}
		Print("ENTER");
	}
    override void OnEnter(Object obj){
		Object obj2;
		if(PlayerBase.CastTo(obj2, obj)){
			PlayerBase man = PlayerBase.Cast(obj2);
			man.QueueAddGlassesEffect(5);
			GetGame().RPCSingleParam(man, ERPCs.RPC_USER_ACTION_MESSAGE, new Param1<string>("Опасная зона ~ 22м"),true, ManBase.Cast(obj2).GetIdentity());
		}else{
			Print("FALSE");
		}
		Print("ENTER");
	}
}